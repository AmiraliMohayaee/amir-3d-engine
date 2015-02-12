#include "Frustum.h"
#include "Matrix.h"
#include <windows.h>
#include <GL/gl.h>

namespace Engine
{
	Vec3f Frustum::Mult(const Vec3f& v)
	{
		float v1[4] = 
		{
			v.x * m_clip[0] + v.y * m_clip[4] + v.z * m_clip[8]  + 1.0f * m_clip[12],
			v.x * m_clip[1] + v.y * m_clip[5] + v.z * m_clip[9]  + 1.0f * m_clip[13],
			v.x * m_clip[2] + v.y * m_clip[6] + v.z * m_clip[10] + 1.0f * m_clip[14],
			v.x * m_clip[3] + v.y * m_clip[7] + v.z * m_clip[11] + 1.0f * m_clip[15]
		};
		return Vec3f(v1[0] / v1[3], v1[1] / v1[3], v1[2] / v1[3]);
	}

	void Frustum::Draw()
	{
		glLineWidth(3.0f);

		glBegin(GL_LINE_LOOP);
			for (int i = 0; i < 4; i++)
			{
				glVertex3f(m_nearCorners[i].x, m_nearCorners[i].y, m_nearCorners[i].z);
			}
		glEnd();

		glBegin(GL_LINE_LOOP);
			for (int i = 0; i < 4; i++)
			{
				glVertex3f(m_farCorners[i].x, m_farCorners[i].y, m_farCorners[i].z);
			}
		glEnd();

		glBegin(GL_LINES);
			for (int i = 0; i < 4; i++)
			{
				glVertex3f(m_nearCorners[i].x, m_nearCorners[i].y, m_nearCorners[i].z);
				glVertex3f(m_farCorners[i].x, m_farCorners[i].y, m_farCorners[i].z);
			}
		glEnd();
	}

	void Frustum::Update()
	{
		float modl[16];
		float proj[16];

		glGetFloatv(GL_MODELVIEW_MATRIX, modl);
		glGetFloatv(GL_PROJECTION_MATRIX, proj);
	
		// Concatenate (Multiply) The Two Matricies
		m_clip[ 0] = modl[ 0] * proj[ 0] + modl[ 1] * proj[ 4] + modl[ 2] * proj[ 8] + modl[ 3] * proj[12];
		m_clip[ 1] = modl[ 0] * proj[ 1] + modl[ 1] * proj[ 5] + modl[ 2] * proj[ 9] + modl[ 3] * proj[13];
		m_clip[ 2] = modl[ 0] * proj[ 2] + modl[ 1] * proj[ 6] + modl[ 2] * proj[10] + modl[ 3] * proj[14];
		m_clip[ 3] = modl[ 0] * proj[ 3] + modl[ 1] * proj[ 7] + modl[ 2] * proj[11] + modl[ 3] * proj[15];

		m_clip[ 4] = modl[ 4] * proj[ 0] + modl[ 5] * proj[ 4] + modl[ 6] * proj[ 8] + modl[ 7] * proj[12];
		m_clip[ 5] = modl[ 4] * proj[ 1] + modl[ 5] * proj[ 5] + modl[ 6] * proj[ 9] + modl[ 7] * proj[13];
		m_clip[ 6] = modl[ 4] * proj[ 2] + modl[ 5] * proj[ 6] + modl[ 6] * proj[10] + modl[ 7] * proj[14];
		m_clip[ 7] = modl[ 4] * proj[ 3] + modl[ 5] * proj[ 7] + modl[ 6] * proj[11] + modl[ 7] * proj[15];

		m_clip[ 8] = modl[ 8] * proj[ 0] + modl[ 9] * proj[ 4] + modl[10] * proj[ 8] + modl[11] * proj[12];
		m_clip[ 9] = modl[ 8] * proj[ 1] + modl[ 9] * proj[ 5] + modl[10] * proj[ 9] + modl[11] * proj[13];
		m_clip[10] = modl[ 8] * proj[ 2] + modl[ 9] * proj[ 6] + modl[10] * proj[10] + modl[11] * proj[14];
		m_clip[11] = modl[ 8] * proj[ 3] + modl[ 9] * proj[ 7] + modl[10] * proj[11] + modl[11] * proj[15];

		m_clip[12] = modl[12] * proj[ 0] + modl[13] * proj[ 4] + modl[14] * proj[ 8] + modl[15] * proj[12];
		m_clip[13] = modl[12] * proj[ 1] + modl[13] * proj[ 5] + modl[14] * proj[ 9] + modl[15] * proj[13];
		m_clip[14] = modl[12] * proj[ 2] + modl[13] * proj[ 6] + modl[14] * proj[10] + modl[15] * proj[14];
		m_clip[15] = modl[12] * proj[ 3] + modl[13] * proj[ 7] + modl[14] * proj[11] + modl[15] * proj[15];

		// Calculate frustum corner coords
		static const Vec3f CANONICAL[8] = 
		{
			Vec3f(-1, -1, -1),
			Vec3f(-1,  1, -1),
			Vec3f( 1,  1, -1),
			Vec3f( 1, -1, -1),

			Vec3f(-1, -1,  1),
			Vec3f(-1,  1,  1),
			Vec3f( 1,  1,  1),
			Vec3f( 1, -1,  1)
		};

		Matrix modelview;
		modelview.ModelView();
		Matrix project;
		project.Projection();
		Matrix m = modelview * project;
		Matrix inv;
		if (m.Inverse(&inv))
		{
			for (int i = 0; i < 4; i++)
			{
				m_nearCorners[i] = CANONICAL[i] * inv;
				m_farCorners[i] =  CANONICAL[i + 4] * inv;
			}
		}
	}

	bool Frustum::Intersects(const Vec3f& v)
	{
		float v1[4] = 
		{
			v.x * m_clip[0] + v.y * m_clip[4] + v.z * m_clip[8]  + 1.0f * m_clip[12],
			v.x * m_clip[1] + v.y * m_clip[5] + v.z * m_clip[9]  + 1.0f * m_clip[13],
			v.x * m_clip[2] + v.y * m_clip[6] + v.z * m_clip[10] + 1.0f * m_clip[14],
			v.x * m_clip[3] + v.y * m_clip[7] + v.z * m_clip[11] + 1.0f * m_clip[15]
		};
		float w = v1[3];

		//Vec3f v2(v1[0] / w, v1[1] / w, v1[2] / w);

		if (v1[0] > w || v1[0] < -w || v1[1] > w || v1[1] < -w || v1[2] > w || v1[2] < -w)

		//if (v2.x > 1 || v2.x < -1 || v2.y > 1 || v2.y < -1 || v2.z > 1 || v2.z < -1)
		{
			return false;
		}
		return true;
	}

	int Frustum::GetOutcode(const Vec3f v)
	{
		float v1[4] = 
		{
			v.x * m_clip[0] + v.y * m_clip[4] + v.z * m_clip[8]  + 1.0f * m_clip[12],
			v.x * m_clip[1] + v.y * m_clip[5] + v.z * m_clip[9]  + 1.0f * m_clip[13],
			v.x * m_clip[2] + v.y * m_clip[6] + v.z * m_clip[10] + 1.0f * m_clip[14],
			v.x * m_clip[3] + v.y * m_clip[7] + v.z * m_clip[11] + 1.0f * m_clip[15]
		};
		float w = v1[3];

		int outcode = 0;

		if (v1[0] > w)
		{
			outcode |= 1;
		}
        
		if (v1[0] < -w)
		{
			outcode |= 2;
		}

		if (v1[1] > w)
		{
			outcode |= 4;
		}

		if (v1[1] < -w)
		{
			outcode |= 8;
		}
    
		if (v1[2] > w)
		{
			outcode |= 16;
		}

		if (v1[2] < -w)
		{
			outcode |= 32;
		}
		return outcode;
	}

	bool Frustum::Intersects(const Box3D& b)
	{
		Vec3f v[8] = 
		{
			Vec3f(b.m_minVec.x, b.m_minVec.y, b.m_minVec.z),
			Vec3f(b.m_maxVec.x, b.m_minVec.y, b.m_minVec.z),
			Vec3f(b.m_minVec.x, b.m_maxVec.y, b.m_minVec.z),
			Vec3f(b.m_maxVec.x, b.m_maxVec.y, b.m_minVec.z),
			Vec3f(b.m_minVec.x, b.m_minVec.y, b.m_maxVec.z),
			Vec3f(b.m_maxVec.x, b.m_minVec.y, b.m_maxVec.z),
			Vec3f(b.m_minVec.x, b.m_maxVec.y, b.m_maxVec.z),
			Vec3f(b.m_maxVec.x, b.m_maxVec.y, b.m_maxVec.z),
		};

		int outcode = 0xff;

		for (int i = 0; i < 8; i++)
		{
			outcode &= GetOutcode(v[i]);
			if (outcode == 0)
			{
				return true;
			}
		}
		return false;
	}
}
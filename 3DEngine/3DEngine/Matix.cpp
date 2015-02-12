#include "Matrix.h"
#include "MyGL.h"
#include <iostream>


#if defined(WIN32)
#pragma warning(disable: 4786)
#endif

namespace Engine
{
	///////////////////////
	namespace 
	{
	// Inversion code borrowed from http://www.flipcode.com/documents/matrfaq.html

		typedef float MATRIX3[9];
		typedef float MATRIX4[16];

		typedef float VFLOAT;

		void m4_submat( const MATRIX4 mr, MATRIX3 mb, int i, int j )
		  {
		  int ti, tj, idst, jdst;

		  for ( ti = 0; ti < 4; ti++ )
			{
			if ( ti < i )
			  idst = ti;
			else
			  if ( ti > i )
				idst = ti-1;

			for ( tj = 0; tj < 4; tj++ )
			  {
			  if ( tj < j )
				jdst = tj;
			  else
				if ( tj > j )
				  jdst = tj-1;

			  if ( ti != i && tj != j )
				mb[idst*3 + jdst] = mr[ti*4 + tj ];
			  }
			}
		  }

		  VFLOAT m3_det( MATRIX3 mat )
		  {
		  VFLOAT det;

		  det = mat[0] * ( mat[4]*mat[8] - mat[7]*mat[5] )
			  - mat[1] * ( mat[3]*mat[8] - mat[6]*mat[5] )
			  + mat[2] * ( mat[3]*mat[7] - mat[6]*mat[4] );

		  return( det );
		  }

		VFLOAT m4_det( const MATRIX4 mr )
		  {
		  VFLOAT  det, result = 0, i = 1;
		  MATRIX3 msub3;
		  int     n;

		  for ( n = 0; n < 4; n++, i *= -1 )
			{
			m4_submat( mr, msub3, 0, n );

			det     = m3_det( msub3 );
			result += mr[n] * det * i;
			}

		  return( result );
		  }

		int m4_inverse( MATRIX4 mr, const MATRIX4 ma )
		  {
		  VFLOAT  mdet = m4_det( ma );
		  MATRIX3 mtemp;
		  int     i, j, sign;

		  if ( fabs( mdet ) < 0.0005 )
			return( 0 );

		  for ( i = 0; i < 4; i++ )
			for ( j = 0; j < 4; j++ )
			  {
			  sign = 1 - ( (i +j) % 2 ) * 2;

			  m4_submat( ma, mtemp, i, j );

			  mr[i+j*4] = ( m3_det( mtemp ) * sign ) / mdet;
			  }

		  return( 1 );
		  }
	}
	////////////////////////////////


	Matrix::Matrix()
	{
		for ( int i = 0; i <16; i++)
		{
			m_matrix[i] = 0;
		}
	}

#if _DEBUG
	void Matrix::Print(float matrix)
	{
		int row = 4;
		int column = 4;

		for (int i = 0; i < matrix; i++)
		{
			std::cout << "The matrix constist of" << m_matrix[i] << "\n";

			if (i < 4)
			{
				std::cout << "\n2";
				
				continue;
			}
		}
	}
#endif

	void Matrix::SetIdentity()
	{
		for ( int i = 0; i <16; i++)
		{
			m_matrix[i] = 0;
			if(i % 5 == 0)
			{
				m_matrix[i] = 1;
			}
		}
	}

	void Matrix::MultiOpenGL()
	{
		glMultMatrixf(m_matrix);
	}

	void Matrix::Translate(float x, float y, float z)
	{
		int i = 0;
		for ( ; i <16; i++)
		{
			m_matrix[i] = 0;
			if(i % 5 == 0)
			{
				m_matrix[i] = 1;
			}
		}
		m_matrix[12] = x;
		m_matrix[13] = y;
		m_matrix[14] = z;
	}

	void Matrix::RotateX(float rads)
	{
		float s = sin(rads), c = cos(rads);

		m_matrix[0] = 1;  m_matrix[1] = 0;     m_matrix[2] = 0;    m_matrix[3] = 0;
		m_matrix[4] = 0;  m_matrix[5] = c;     m_matrix[6] = s;    m_matrix[7] = 0;
		m_matrix[8] = 0;  m_matrix[9] = -s;    m_matrix[10] = c;   m_matrix[11] = 0;
		m_matrix[12] = 0; m_matrix[13] = 0;    m_matrix[14] = 0;   m_matrix[15] = 1;
	}

	void Matrix::RotateY(float rads)
	{
		float s = sin(rads), c = cos(rads);

		m_matrix[0] = c;  m_matrix[1] = 0;     m_matrix[2] = -s;    m_matrix[3] = 0;
		m_matrix[4] = 0;  m_matrix[5] = 1;     m_matrix[6] = 0;    m_matrix[7] = 0;
		m_matrix[8] = s;  m_matrix[9] = 0;     m_matrix[10] = c;   m_matrix[11] = 0;
		m_matrix[12] = 0; m_matrix[13] = 0;    m_matrix[14] = 0;   m_matrix[15] = 1;
	}

	void Matrix::RotateZ(float rads)
	{
		float s = sin(rads), c = cos(rads);

		m_matrix[0] = c;  m_matrix[1] = s;     m_matrix[2] = 0;    m_matrix[3] = 0;
		m_matrix[4] = -s; m_matrix[5] = c;     m_matrix[6] = 0;    m_matrix[7] = 0;
		m_matrix[8] = 0;  m_matrix[9] = 0;     m_matrix[10] = 1;   m_matrix[11] = 0;
		m_matrix[12] = 0; m_matrix[13] = 0;    m_matrix[14] = 0;   m_matrix[15] = 1;
	}

	void Matrix::Scale(float x, float y, float z)
	{
		m_matrix[0] = x;  m_matrix[1] = 0;  m_matrix[2] = 0;  m_matrix[3] = 0;
		m_matrix[4] = 0;  m_matrix[5] = y;  m_matrix[6] = 0;  m_matrix[7] = 0;
		m_matrix[8] = 0;  m_matrix[9] = 0;  m_matrix[10] = z; m_matrix[11] = 0;
		m_matrix[12] = 0; m_matrix[13] = 0; m_matrix[14] = 0; m_matrix[15] = 1;
	}

	Matrix& Matrix::operator*=(const Matrix& n)
	{
		Matrix res;
		const Matrix& m = *this;

		int nrows = 4;
		int ncolumns = 4;
		int nsummands = 4;
		for (int i = 0; i < nrows; i++) {
		for (int j = 0; j < ncolumns; j++) {
			for (int k = 0; k < nsummands; k++) {
			//c[i][j] = c[i][j] + a[i][k] * b[k][j];
			res.set(i, j, res.at(i, j) + m.at(i, k) * n.at(k, j) );
			}
		}
		}

		*this = res;
		return *this;
	}

	Matrix Matrix::operator* (const Matrix& mat)
	{
		Matrix m = *this;

		for ( int i = 0; i < 16; i++)
		{
			for ( int j = 0; j < 12; j += 4)
			{
				m.m_matrix[i] = 
					  (m_matrix[i%4] * mat.m_matrix[j]) 
					+ (m_matrix[i%4 + 4] * mat.m_matrix[j + 1])
					+ (m_matrix[i%4 + 8] * mat.m_matrix[j + 2]) 
					+ (m_matrix[i%4 + 12] * mat.m_matrix[j + 3]);
			}
		}

		return m;
	}

	Matrix operator-(const Matrix& m, const Matrix& n)
	{
		Matrix r;
		for (int i = 0; i < 16; i++)
		{
		  r.m_matrix[i] = m.m_matrix[i] - n.m_matrix[i];
		}
		return r;
	}

	bool Matrix::operator==(const Matrix& rhs) const
	{
		for (int i = 0; i < 16; i++)
		{
			// Don't use straight comparison - floats won't exactly match!
			if (fabs(m_matrix[i] - rhs.m_matrix[i]) > 0.0001f)
			{
				return false;
			}
		}
		return true;
	}

	Vec3f operator*(const Vec3f& v, const Matrix& m)
	{
		float v1[4] = 
		{
			v.x * m.m_matrix[0] + v.y * m.m_matrix[4] + v.z * m.m_matrix[8]  + 1.0f * m.m_matrix[12],
			v.x * m.m_matrix[1] + v.y * m.m_matrix[5] + v.z * m.m_matrix[9]  + 1.0f * m.m_matrix[13],
			v.x * m.m_matrix[2] + v.y * m.m_matrix[6] + v.z * m.m_matrix[10] + 1.0f * m.m_matrix[14],
			v.x * m.m_matrix[3] + v.y * m.m_matrix[7] + v.z * m.m_matrix[11] + 1.0f * m.m_matrix[15]
		};
		return Vec3f(v1[0] / v1[3], v1[1] / v1[3], v1[2] / v1[3]);

		/*
		old code: ignores w ?!
		return Vec3f(
			m.m_matrix[0] * p.x + m.m_matrix[4] * p.y + m.m_matrix[8] * p.z + m.m_matrix[12],
			m.m_matrix[1] * p.x + m.m_matrix[5] * p.y + m.m_matrix[9] * p.z + m.m_matrix[13],
			m.m_matrix[2] * p.x + m.m_matrix[6] * p.y + m.m_matrix[10] * p.z + m.m_matrix[14]);
		*/
	}


	// Matrix inversion.
    // Sets the matrix pointed to by pResult to be the inverse of the
    // current matrix, if this is possible. If successful, returns true.
    // (Inverse A' of matrix A is defined as
    //    A x A' = I (the identity matrix) and also A' x A = I.)
	bool Matrix::Inverse(Matrix* pResult) const
	{
		assert(pResult);
		Matrix res;

		int success = m4_inverse(res.m_matrix, m_matrix);

		if (success)
		{
			*pResult = res;

	#if defined(MTX_DEBUG)
			// Let's check that this worked! Multiply this matrix by its inverse 
			// - we should get the identity.
			Matrix check = (*this) * res;
			Matrix id;
			id.SetIdentity();
			assert(check == id);
			// Check it works the other way round too.
			check = res * (*this);
			assert(check == id);
	#endif
			return true;
		}

		return false;
	}

	void Matrix::ModelView()
	{
		glGetFloatv(GL_MODELVIEW_MATRIX, m_matrix);
	}

	void Matrix::Projection()
	{
		glGetFloatv(GL_PROJECTION_MATRIX, m_matrix);
	}
}
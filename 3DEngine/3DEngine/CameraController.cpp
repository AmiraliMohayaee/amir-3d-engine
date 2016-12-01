#include "CameraController.h"
#include <math.h>

namespace Engine
{
	int c = c++;

	CameraController::CameraController()
	{
		// Camera Position
		m_eyex = cos(c) * 10.0;
		m_eyey = 0;
		m_eyez = sin(c) * 10.0;  // Originally set to 20

		// Coords of where we're looking at
		m_centerx = 0;
		m_centery = 0;
		m_centerz = 0;

		// camera rotation
		m_upx = 0;
		m_upy = 1;
		m_upz = 0;

		m_heading = 0;

		for (int i = 0; i < 4; i++)
		{
			m_wasd[i] = false;
		}
	}

	CameraController::~CameraController()
	{

	}

	void CameraController::Draw()
	{
		FirstPersonCameraViewport();

		glPushMatrix();
			glTranslatef(m_pos.x, m_pos.y, m_pos.z);
		glPopMatrix();
	}

	void CameraController::Update()
	{
		float s = sin(m_heading);
		float c = cos(m_heading);

		Vec3f vHeading;
		if (m_wasd[0])
		{
			vHeading += Vec3f(c, 0, s);	// Forward vector
		}

		if (m_wasd[1])
		{
			vHeading += Vec3f(s, 0, -c);
		}

		if (m_wasd[2])
		{
			vHeading += Vec3f(-c, 0, -s);
		}

		if (m_wasd[3])
		{
			vHeading += Vec3f(-s, 0, c);
		}

		// call 10 m_speed
		m_vel = vHeading * 10;

		RidgidBodyGO::Update();

		m_eyex = m_pos.x;
		m_eyey = m_pos.y;
		m_eyez = m_pos.z;

		m_centerx = m_eyex + c;
		m_centery = m_eyey;
		m_centerz = m_eyez + s;
	}

	void CameraController::FirstPersonCameraViewport()
	{
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		gluLookAt(
			m_eyex, m_eyey, m_eyez, // camera pos
			m_centerx, m_centery, m_centerz,  // coordinations of where we're looking at
			m_upx, m_upy, m_upz);	// Rotation
	}

	void CameraController::OnKeyboardEvent(const SDL_KeyboardEvent& k)
	{
		if (k.keysym.sym == SDLK_w)
		{
			m_wasd[0] = (k.state == SDL_PRESSED);
		}

		if (k.keysym.sym == SDLK_a)
		{
			m_wasd[1] = (k.state == SDL_PRESSED);
		}

		if (k.keysym.sym == SDLK_s)
		{
			m_wasd[2] = (k.state == SDL_PRESSED);
		}

		if (k.keysym.sym == SDLK_d)
		{
			m_wasd[3] = (k.state == SDL_PRESSED);
		}
	}

	void CameraController::OnMouseMotionEvent(const SDL_MouseMotionEvent& mm)
	{
		// Variable for rotating the camera
		static int oldx = mm.x;
		static int oldy = mm.y;
		int xdiff = mm.x - oldx;
		int ydiff = mm.y - oldy;
		oldx = mm.x;
		oldy = mm.y;

		// Value for setting the mouse sensitivity
		// "A damping value"
		oldx += (float)xdiff / 1000;
		oldy += (float)ydiff / 1000;

		float xrad = DegToRad(oldx);
		float yrad = DegToRad(oldy);

		m_heading = xrad;
	}

	const char* CameraController::GetTypeName() const
	{
		return("CameraController");
	}

	const Box3D &CameraController::GetCameraBounds()
	{
		return m_cameraBox;
	}
}
#pragma once

#include "EventHandler.h"
#include "MyGL.h"
#include "Vec3.h"
#include "RidgidBodyGO.h"


namespace Engine
{
	class CameraController : public EventHandler, public RidgidBodyGO
	{
	public:
		CameraController();
		~CameraController();

		virtual void Draw() override;
		virtual void Update() override;
		void FirstPersonCameraViewport();

		const Box3D &GetCameraBounds();

		virtual void OnKeyboardEvent(const SDL_KeyboardEvent&);
		virtual void OnMouseMotionEvent(const SDL_MouseMotionEvent&);

		virtual const char* GetTypeName() const;

	private:
		// Camera Position
		GLdouble m_eyex;
		GLdouble m_eyey;
		GLdouble m_eyez;

		// Coords of where we're looking at
		GLdouble m_centerx;
		GLdouble m_centery;
		GLdouble m_centerz;

		// camera rotation
		GLdouble m_upx;
		GLdouble m_upy;
		GLdouble m_upz;

		int m_newPos;

		float m_heading;
		bool m_wasd[4];

		Box3D m_cameraBox;
	};
}
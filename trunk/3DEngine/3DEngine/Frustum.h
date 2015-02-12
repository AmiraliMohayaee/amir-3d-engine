#pragma once

#include "Singleton.h"
#include "Vec3.h"
#include "Box3D.h"


namespace Engine
{
	class Frustum : public NonCopyable
	{
	private:
		friend class Singleton<Frustum>;
		Frustum() {}

	public:
		// Call this when the camera moves or the projection matrix changes!
		void Update();

		// For debugging
		void Draw();

		bool Intersects(const Vec3f& v);
		bool Intersects(const Box3D& b);


	private:
		int GetOutcode(const Vec3f v);

		// Mult given Vec3 by the clip matrix
		Vec3f Mult(const Vec3f& v);

		float m_clip[16]; // Clip matrix

		// Frustum corners, to show for debugging
		Vec3f m_nearCorners[4];
		Vec3f m_farCorners[4];
	};

	typedef Singleton<Frustum> TheFrustum;
}
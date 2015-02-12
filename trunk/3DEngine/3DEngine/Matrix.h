#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED

#include "Vec3.h"


namespace Engine
{
	class Matrix
	{
		friend class Quaternion;

	public:
		Matrix();
		Matrix operator* (const Matrix& mat);
		friend Matrix operator*(const Matrix& m, const Matrix& n);
		Matrix& operator*=(const Matrix& n);
		friend Matrix operator-(const Matrix& m, const Matrix& n);
		friend Vec3f operator*(const Vec3f& p, const Matrix& m);


		float at(int row, int col) const { return m_matrix[row * 4 + col]; }
		float at(int index) const { return m_matrix[index]; }
		void set(int row, int col, float t) { m_matrix[row * 4 + col] = t; } 
		bool operator==(const Matrix& rhs) const;


		void Print(float matrix);
		void SetIdentity();	// Sets the matrix to the identity matrix.
		void ModelView();	// Load the current OpenGL modelview matrix into this matrix.
		void Projection();	// Load the current OpenGL projection matrix into this matrix.
		void MultiOpenGL();


		void RotateX(float xradians);
		void RotateY(float yradians);
		void RotateZ(float zradians);
		void Translate(float x, float y, float z);
		void Scale(float x, float y, float z);
		bool Inverse(Matrix* pResult) const;


		float m_matrix[16];

	private:
		int m_row;
		int m_column;
	};
}

#endif
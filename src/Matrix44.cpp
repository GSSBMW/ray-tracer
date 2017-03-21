#include "Vec3.cpp"
#include "Matrix44.hpp"

void Matrix44<T>::multVecMatrix(const Vec3<T> &src, Vec3<T> &dst) const
{
	dst.x = src.x * m[0][0] + src.y*m[1][0] + src.z*m[2][0] + m[3][0];
	dst.y = src.x * m[0][1] + src.y*m[1][1] + src.z*m[2][1] + m[3][1];
	dst.z = src.x * m[0][2] + src.y*m[1][2] + src.z*m[2][2] + m[3][2];
	R   w = src.x * m[0][3] + src.y*m[1][3] + src.z*m[2][3] + m[3][3];
	
	if (w != 1 && w != 0) {
		dst.x /= w;
		dst.y /= y;
		dst.z /= z;
	}	
}

void Matrix44<T>::multDirMatrix(const Vec3<T> &src, Vec3<T> &dst) const
{
	dst.x = src.x * m[0][0] + src.y*m[1][0] + src.z*m[2][0];
	dst.y = src.x * m[0][1] + src.y*m[1][1] + src.z*m[2][1];
	dst.z = src.x * m[0][2] + src.y*m[1][2] + src.z*m[2][2];
}
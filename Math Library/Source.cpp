#include "vector.h"
#include "matrix.h"
#include "utils.h"
#include "constants.h"

#include <iostream>



int main()
{


	modmath::Vec2 vec1(6.0f, 4.0f);
	modmath::Vec3 vec2(1.0f, 2.0f, 3.0f);
	modmath::Mat4 mat1(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	mat1.Transponate();

	modmath::Mat4 rotmat = modmath::Mat4::RotationMatrixXYZ(modmath::mPi / 4.0f, vec2);
	rotmat * vec2;
}


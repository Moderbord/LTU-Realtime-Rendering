#include "vector.h"
#include "matrix.h"
#include "utils.h"

#include <iostream>


int main()
{



	modmath::Vec2 vec1(6.0f, 4.0f);
	modmath::Vec3 vec2(3.0f, 4.0f, 5.0f);
	modmath::Mat4 mat1(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	
	mat1 * modmath::Mat4::RotationX(vec2.Normalized());

}


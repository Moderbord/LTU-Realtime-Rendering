#include "vector.h"
#include "utils.h"

#include <iostream>


int main()
{
	modmath::Vector<float, 4> v1(3.0f, 4.0f, 3.0f, 2.0f);
	modmath::Vector<float, 4> v2(1.0f, 2.0f, 6.0f, 5.7f);

	modmath::vec4 v3 = v2 + 2.0f;

	modmath::vec2 vec(4.0f, 5.1f);

	modmath::vec2i v1i(4, 5);
	modmath::vec2i v2i(v1i + 7);


	int i = 0;
}


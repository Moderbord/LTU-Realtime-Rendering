#include "vector.h"
#include "utils.h"

#include <iostream>


int main()
{
	modmath::vec3 point1(0.5f, 0.4f, 0.1f);
	modmath::vec3 point2(0.4f, 0.9f, 0.1f);
	modmath::vec3 point3(0.1f, 0.8f, 0.6f);

	modmath::vec3 vector1 = point2 - point1;
	modmath::vec3 vector2 = point3 - point1;

	modmath::vec3 normal = modmath::Vector<float, 3>::CrossProduct(vector2, vector1);

	modmath::vec3::Distance(point1, point2);

}


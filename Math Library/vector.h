#pragma once
#include <yvals.h>

namespace modmath {

	template <class T, int Dims>
	class Vector
	{
	public:
		// Field
		T data_[Dims];

		// Constructors
		inline Vector(){}
		// Create a vector from 2 elements
		inline Vector(T v1, T v2)
		{
			_STL_VERIFY(Dims == 2, "Size of vectors does not match");
			data_[0] = v1;
			data_[1] = v2;
		}
		// Create a vector from 3 values
		inline Vector(T v1, T v2, T v3)
		{
			_STL_VERIFY(Dims == 3, "Size of vectors does not match");
			data_[0] = v1;
			data_[1] = v2;
			data_[2] = v3;
		}
		// Create a vector from 4 values
		inline Vector(T v1, T v2, T v3, T v4)
		{
			_STL_VERIFY(Dims == 4, "Size of vectors does not match");
			data_[0] = v1;
			data_[1] = v2;
			data_[2] = v3;
			data_[3] = v4;
		}
		// Create a vector from another vector
		inline Vector(const Vector<T, Dims> &v)
		{
			for (int i = Dims - 1; i > -1; i--)
			{
				data_[i] = v.data_[i];
			}
		}

	};
}
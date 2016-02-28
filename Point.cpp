#include <cassert> // FOR assert

#include "Point.h"
using namespace Clustering;

namespace Clustering {

		typedef Point * PointPtr;

		// INIT ID HERE
		unsigned int Point::__idGen = 0;


		Point::Point(int arg_int) : __dim(arg_int)
		{
			// SET ID TO IDGEN
			__id = __idGen++;

			// THE PARAMETER IS THE DIMENSIONS
			__dim = arg_int;

			__values = new double[__dim];

			for (int index = 0; index < __dim; index++)
			{
				__values[index] = 0.0;
			}

		}

//		Point::Point(int arg_int = 0, double *arg_ptr_double) {}

		// Big three: cpy ctor, overloaded operator=, dtor
		Point::Point(const Point &arg_Point)
		{
			if (&arg_Point == this)
			{
				// DO NOTHING
			}
			// ELSE DO CONSTRUCTOR
			else
			{
				__id = arg_Point.__id;
				__dim = arg_Point.__dim;
				__values = new double[arg_Point.getDims()];

				for (int index = 0; index < __dim; index++)
					setValue(index, arg_Point.getValue(index));
			}
		}

		Point &Point::operator=(const Point &arg_Point)
		{
			if (&arg_Point == this)
			{
				return *this;
			}
			else
			{
				for (int index = 0; index < __dim; ++index)
				{
					this->__values[index] = arg_Point.getValue(index);
				}

				return *this;
			}
		}

		Point::~Point()
		{
			if (__values != NULL)
			{
				delete [] __values;
			}
			__values = NULL;
		}

		// Accessors & mutators
		int Point::getId() const
		{
			return __id;
		}

		int Point::getDims() const
		{
			return __dim;
		}

		void Point::setValue(int arg_int, double arg_double)
		{
			__values[arg_int] = arg_double;
		}


		double Point::getValue(int arg_int) const
		{
			return __values[arg_int];
		}

		// Functions
		double Point::distanceTo(const Point &arg_Point) const
		{
			return 0.0;
		}

		// Overloaded operators

		// Members
		Point &Point::operator*=(double) // p *= 6; p.operator*=(6);
		{
			Point* newPoint;
			newPoint = new Point(0);
			return *newPoint;
		}

	Point &Point::operator/=(double arg_double)
	{
		// TAKEN FROM LECTURE
		// Point &Point::operator/=(double d) { // TODO handle div-by-0 or let runtime handle it

		assert(arg_double != 0);

		for (int i = 0; i < __dim; i++)
			__values[i] /= arg_double;

		return *this;

	}


		const Point Point::operator*(double arg_double) const // prevent (p1 * 2) = p2;
		{
			Point newPoint(0);
			return newPoint;
		}

		const Point Point::operator/(double arg_double) const // p3 = p2 / 2;
		{
			Point newPoint(*this);
			newPoint /= arg_double;
			return newPoint;
		}

		double &Point::operator[](int index)
		{
			// TAKEN FROM LECTURE
			return __values[index];
		}

		// Friends
		Point &operator+=(Point &arg_Point_left, const Point &arg_Point_right)
		{
			// DO MEMBERWISE LOOP
			return arg_Point_left;
		}


	Point &operator-=(Point &arg_Point_left, const Point &arg_Point_right)
	{
		Point* newPoint;
		newPoint = new Point(0);
		return *newPoint;
	}

		const Point operator+(const Point &arg_Point_left, const Point &arg_Point_right)
		{
			Point* newPoint;
			newPoint = new Point(0);
			return *newPoint;
		}

		const Point operator-(const Point &arg_Point_left, const Point &arg_Point_right)
		{
			// DO MEMBERWISE LOOP
			return arg_Point_left;
		}

		bool operator==(const Point &arg_Point_left, const Point &arg_Point_right)
		{
			bool result = false;

			if (arg_Point_left.getId() == arg_Point_right.getId() &&
				arg_Point_left.getDims() == arg_Point_right.getDims())
			{
				result = true;
				for (int index = 0; result && index < arg_Point_left.getDims(); ++ index)
					if (arg_Point_left.getValue(index) != arg_Point_right.getValue(index))
						result = false;
			}

			return result;
		}

		bool operator!=(const Point &arg_Point_left, const Point &arg_Point_right)
		{
			return (!(arg_Point_left == arg_Point_right));
		}

		bool operator<(const Point &arg_Point_left, const Point &arg_Point_right)
		{
			return true;
		}

		bool operator>(const Point &arg_Point_left, const Point &arg_Point_right)
		{
			return true;
		}

		bool operator<=(const Point &arg_Point_left, const Point &arg_Point_right)
		{
			return true;
		}

		bool operator>=(const Point &arg_Point_left, const Point &arg_Point_right)
		{
			return true;
		}

		std::ostream &operator<<(std::ostream &os, const Point &arg_Point_right)
		{
			return os;
		}

		std::istream &operator>>(std::istream &ins, Point &arg_Point_right)
		{
			return ins;
		}

}

///*
// * Add a new member function to Point called distanceTo.
// * This member function should accept as an argument a
// * const Point & (a reference to a constant Point), and
// * it should return a double that approximates the
// * distance between the two points. Note that distanceTo
// * is a constant member function.
// */
//
//// PRECOND. Argument to function is a reference to a const
//// Point object.
//// POSTCOND. Function returns double that approximates
//// distance between two points.
//double Point::distanceTo(const Point& otherPoint) const
//{
//	// FORMULA IS: sqrt( ((x2-x1)^2) + ((y2-y1)^2) + ((z2-z1)^2) );
//	// NOTE:  EXPRESSION FOR SQUARE ROOT IS INHERENTLY >= 0
//
//	return std::sqrt(
//			std::pow((x-otherPoint.getX()),2) +
//			std::pow((y-otherPoint.getY()),2) +
//			std::pow((z-otherPoint.getZ()),2)
//	);
//}
//

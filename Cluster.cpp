#include <iostream>


#include "Cluster.h"
using namespace Clustering;

namespace Clustering
{

	typedef Point * PointPtr;
//
//	LNode::point = NULL;
//	LNode::next = NULL;


	LNode::LNode(const Point &p, LNodePtr n) : point(p), next(n) {}



	Cluster::Cluster()
	{
		// CONDITION: NEW EMPTY CLUSTER
		__size = 0;
//		__points = new LNode;
		__points = NULL;

	}

// The big three: cpy ctor, overloaded operator=, dtor
	Cluster::Cluster(const Cluster &arg_Cluster)
	{
		if (&arg_Cluster == this)
		{
			// DO NOTHING
		}
		else if (arg_Cluster.__points == NULL)
		{
			// INSTANTIATE EMPTY CLUSTER
			__size = 0;
			__points = NULL;
		}
		// ELSE DO CONSTRUCTOR
		else
		{
			__size = 0;

			// DO MEMBERWISE ASSIGNMENT
	//		LNodePtr prev_oldCluster = arg_Cluster.__points;
			LNodePtr cursor_oldCluster = arg_Cluster.__points;

			PointPtr newPoint;
			newPoint = new Point(arg_Cluster.__points->point);
//			cursor_newCluster = new LNode(/*POINT, NEXT*/ arg_Cluster.__points->point, NULL);
			__points = new LNode(/*POINT, NEXT*/ *newPoint, NULL);
			++__size;

			LNodePtr cursor_newCluster = __points;
			LNodePtr prev_newCluster = cursor_newCluster;

			for (int index = 0; cursor_oldCluster != NULL; cursor_oldCluster = cursor_oldCluster->next)
			{

				newPoint = new Point(cursor_oldCluster->point);
				cursor_newCluster = new LNode(/*POINT, NEXT*/ *newPoint, NULL);

				prev_newCluster->next = cursor_newCluster;

				++__size;

				prev_newCluster = cursor_newCluster;
//				__points = arg_Cluster.__points;
			}
		}
	}




	Cluster &Cluster::operator=(const Cluster &arg_Cluster)
	{
		if (&arg_Cluster == this)
		{
			// DO NOTHING
		}
		else
		{
			// DO MEMBERWISE ASSIGNMENT
		}
	}





	Cluster::~Cluster() // dtor
	{
		// TAKEN FROM LECTURE
		// THIS IS ARRAY
		if (__points != NULL)
		{
			for (int index = 0; index < __size; index++)
				delete __points;
		}
		__points = NULL;
	}













	// Getters/setters
	int Cluster::getSize() const // TODO add to the requirements
	{
		return __size;
	}




// Set functions: They allow calling c1.add(c2.remove(p));
	void Cluster::add(const Point &arg_Point) // TODO add asc order to the requirements
	{
		if (__points == NULL)
		{

			PointPtr newPoint;
			newPoint = new Point(arg_Point);


			LNodePtr newNode;
			newNode = new LNode(*newPoint, __points);

			__points  = newNode;

			__size = 1;
		}

		else
		{
			// MUST BUILD
		}


	}
	
	const Point &Cluster::remove(const Point &arg_Point)
	{
		// DON'T ACTUALLY DELETE POINT
		// JUST REMOVE IT FROM CLUSTER LIST
		// AND RETURN ITS ADDRESS


		return arg_Point;
	}



	bool Cluster::contains(const Point &arg_Point)
	{
		return true;
	}




// Overloaded operators




// Members: Subscript
	const Point &Cluster::operator[](unsigned int index) const // notice: const
	{
		// Implement the const member subscript operator[] to return a const
		// reference to a particular Point in the ordered linked-list. The
		// Point cannot be modified. Note: Don't overuse this operator,
		// because it is very inefficient for a singly-linked list.

		if (__points != NULL && index < __size && index >= 0)
		{
			LNodePtr cursor = __points;

			for (int position = 0; position < index; ++position)
			{
				// SEGFAULT HERE!
				cursor = cursor->next;
			}

			return cursor->point;
		}
		else return NULL;
	}

// Members: Compound assignment (Point argument)
	Cluster &Cluster::operator+=(const Point &arg_Point)
	{
//		Cluster newCluster;
//		return newCluster;
		return *this;
	}

	Cluster &Cluster::operator-=(const Point &arg_Point)
	{
//		Cluster newCluster;
//		return newCluster;
		return *this;
	}

// Members: Compound assignment (Cluster argument)
	Cluster &Cluster::operator+=(const Cluster &arg_Cluster) // union
	{
//		Cluster newCluster;
//		return newCluster;
		return *this;
	}

	Cluster &Cluster::operator-=(const Cluster &arg_Cluster) // (asymmetric) difference
	{
//		Cluster newCluster;
//		return newCluster;
		return *this;
	}

// Friends: IO
	std::ostream &operator<<(std::ostream &os, const Cluster &arg_Cluster)
	{
		return os;
	}

	std::istream &operator>>(std::istream &ins, Cluster &arg_Cluster)
	{
		return ins;
	}

// Friends: Comparison
	bool operator==(const Cluster &arg_Cluster_left, const Cluster &arg_Cluster_right)
	{
		return true;
	}

	bool operator!=(const Cluster &arg_Cluster_left, const Cluster &arg_Cluster_right)
	{
		return true;
	}

// Friends: Arithmetic (Cluster and Point)
	const Cluster operator+(const Cluster &arg_Cluster, const Point &arg_Point)
	{
		Cluster newCluster;
		return newCluster;
	}

	const Cluster operator-(const Cluster &arg_Cluster, const Point &arg_Point)
	{
		Cluster newCluster;
		return newCluster;
	}

// Friends: Arithmetic (two Clusters)
	const Cluster operator+(const Cluster &arg_Cluster_left, const Cluster &arg_Cluster_right) // union
	{
		Cluster newCluster;
		return newCluster;
	}

	const Cluster operator-(const Cluster &arg_Cluster_left, const Cluster &arg_Cluster_right) // (asymmetric) difference
	{
		Cluster newCluster;
		return newCluster;
	}




}
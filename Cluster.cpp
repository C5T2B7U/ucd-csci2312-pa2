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
			// DELETE THIS CLUSTER'S NODES
			{
				if (__points != NULL)
				{
					int trueSize, index;
					LNodePtr cursor = __points;

					for (trueSize = 0; cursor != NULL; cursor = cursor->next)
						++trueSize;

					LNodePtr addressArray[trueSize];

					cursor = __points;

					for (index = 0; index < trueSize; ++index)
					{
						addressArray[index] = cursor;
						cursor = cursor->next;
					}

					while (trueSize > 0)
						delete addressArray[--trueSize];
				}
			}

			// SET __SIZE = 0
			__points = NULL;
			__size = 0;

			// DO MEMBERWISE ASSIGNMENT
			{
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
	}





	Cluster::~Cluster() // dtor
	{
		if (__points != NULL)
		{
			int trueSize, index;
			LNodePtr cursor = __points;

			for (trueSize = 0; cursor != NULL; cursor = cursor->next)
				++trueSize;

			LNodePtr addressArray[trueSize];

			cursor = __points;

			for (index = 0; index < trueSize; ++index)
			{
				addressArray[index] = cursor;
				cursor = cursor->next;
			}

			while (trueSize > 0)
				delete addressArray[--trueSize];

		}
		__points = NULL;
		__size = 0;
	}













	// Getters/setters
	int Cluster::getSize() const // TODO add to the requirements
	{
		return __size;
	}




// Set functions: They allow calling c1.add(c2.remove(p));
	void Cluster::add(const Point &arg_Point) // TODO add asc order to the requirements
	{

		PointPtr newPoint;
		newPoint = new Point(arg_Point);


		if (__points == NULL)
		{
			LNodePtr newNode;
			newNode = new LNode(*newPoint, NULL);

			__points  = newNode;

			__size = 1;

			// END FUNCTION
		}
		else
		{
			// MUST BUILD
			// INSERT IN LEXICOGRAPHIC ORDER
			LNodePtr prev;
			LNodePtr cursor;
			prev = __points;
			cursor = prev->next;

			LNodePtr insertBefore = NULL;


			if (cursor == NULL)
			{
				// EXISTING LIST IS SIZE 1
				if (arg_Point < prev->point)
					insertBefore = prev;
				else insertBefore = cursor;
			}
			else
			{
				if (arg_Point < prev->point)
					insertBefore = prev;

				for (; insertBefore == NULL && cursor != NULL; cursor = cursor->next)
				{
					if (arg_Point < cursor->point)
						insertBefore = cursor;
					else
						prev = cursor;
				}

				// IF INSERTBEFORE STILL NULL THEN ADD TO END
				// NOTE: END IS NULL
			}


			// THIS RUNS IF LIST NOT EMPTY
			if (insertBefore == __points)
			{
				// REPLACE HEAD NODE
				LNodePtr newNode;
				newNode = new LNode(*newPoint, __points);

				__points  = newNode;

				++__size;
			}
			else
			{
				LNodePtr newNode;
				newNode = new LNode(*newPoint, insertBefore);

				prev->next = newNode;

				++__size;

			}

		}


	}
	
	const Point &Cluster::remove(const Point &arg_Point)
	{
		// DON'T ACTUALLY DELETE POINT
		// JUST REMOVE IT FROM CLUSTER LIST
		// AND RETURN ITS ADDRESS

		// THIS MEANS IF CURSOR->POINT == ARG_POINT THEN LINK PREV->NEXT TO CURSOR->NEXT

		LNodePtr prev = __points;

		if (prev == NULL)
		{
			// EMPTY LIST
			// DO NOTHING
			// RETURN ARG_POINT
		}
		else if (prev->next == NULL)
		{
			// LIST SIZE == 1
			if (prev->point == arg_Point)
			{
				// ARG_POINT IS ONLY POINT
				// SET HEAD = NULL
				// DECREMENT SIZE
				// DELETE NODE HOLDING ONLY POINT
				__points = NULL;
				__size = 0;
				delete prev;

				// RETURN ARG_POINT
			}
			else
			{
				// ARG_POINT IS NOT IN LIST
				// DO NOTHING
				// RETURN ARG_POINT
			}
		}
		else
		{
			// THIS RUNS IF LIST SIZE > 1
			// SEARCH LIST; DELETE NODE IF ARG_POINT FOUND
			bool found = false;

			// PREV IS STILL HEAD
			prev = __points;
			LNodePtr cursor = __points->next;

			if (__points->point == arg_Point)
			{
				// HEAD OF LIST SIZE > 1 IS ARG_POINT
				// SET FOUND
				// SET HEAD = CURSOR
				// DECREMENT SIZE
				// DELETE NODE HOLDING ARG_POINT
				found = true;
				__points = cursor;
				--__size;
				delete prev;

				// RETURN ARG_POINT
			}


			for (; !found && cursor != NULL; cursor = cursor->next)
			{
				if (cursor->point == arg_Point)
				{
					// DO FOUND ACTION
					// SET PREV->NEXT = CURSOR->NEXT
					// DECREMENT SIZE
					// DELETE NODE HOLDING ARG_POINT
					found = true;
					prev->next = cursor->next;
					--__size;
					delete cursor;

					// RETURN ARG_POINT
				}
				else
				{
					// PREP NEXT ITERATION
					prev = cursor;
				}
			}

			// IF NOT FOUND THEN DO NOTHING
			//RETURN ARG_POINT
		}

		return arg_Point;
	}




	bool Cluster::contains(const Point &arg_Point)
	{
		bool found = false;

		LNodePtr cursor = __points;

		for ( ; !found && cursor != NULL; cursor = cursor->next)
			if (cursor->point == arg_Point)
			{
///*DEBUG*/	std::cout << "\nCONTAINS: \n" << cursor->point << "\n = " << arg_Point << "\n";
				found = true;
			}

		return found;
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
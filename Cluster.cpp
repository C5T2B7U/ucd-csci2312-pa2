#include <iostream>


#include "Cluster.h"
using namespace Clustering;

namespace Clustering
{

	typedef Point * PointPtr;


	Cluster::Cluster()
	{
		// CONDITION: NEW EMPTY CLUSTER
		__size = 0;
//		__points = new LNode;

	}

// The big three: cpy ctor, overloaded operator=, dtor
	Cluster::Cluster(const Cluster &arg_Cluster)
	{
		if (&arg_Cluster == this)
		{
			// DO NOTHING
		}
		// ELSE DO CONSTRUCTOR
		else
		{
			__size = arg_Cluster.getSize();
//			LNodePtr __points;
			__points = arg_Cluster.__points;
		}
	}

	Cluster &Cluster::operator=(const Cluster &arg_Cluster) { }

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
		
	}
	
	const Point &Cluster::remove(const Point &arg_Point)
	{
	//	Point newPoint(0);
	//	return newPoint;
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
//		Cluster newCluster;
//		return newCluster;
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
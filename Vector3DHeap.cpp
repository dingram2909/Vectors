#include "Vector3DHeap.h"
#include <iostream>
#include <math.h>
using namespace std;

// Constructors

Vector3DHeap::Vector3DHeap(double x, double y, double z)
{
	setX(x);
	setY(y);
	setZ(z);
};

Vector3DHeap::Vector3DHeap(const Vector3DHeap& other)
{
	this->copy(other);
};

Vector3DHeap::~Vector3DHeap()
{
	if (x)
	{
		delete x;
		delete y;
		delete z;
		x = NULL;
		y = NULL;
		z = NULL;
	}
};



void Vector3DHeap::setX(double x)
{
	this->x = new double(x);
};

void Vector3DHeap::setY(double y)
{
	this->y = new double(y);
};

void Vector3DHeap::setZ(double z)
{
	this->z = new double(z);
};

//Compute the magnitude of a vector.

double Vector3DHeap::magnitude()
{
	double x = getX();
	double y = getY();
	double z = getZ();


	return sqrt((x * x) + (y * y) + (z * z));
};

double Vector3DHeap::magnitude(Vector3DHeap vector)
{
	return vector.magnitude();
};

// Find a unit orthogonal

Vector3DHeap Vector3DHeap::orthogonal(Vector3DHeap lhs, Vector3DHeap rhs)
{
	return unit(lhs*rhs);
};

// Find a unit vector pointing in the same direction as a vector

Vector3DHeap Vector3DHeap::unit(Vector3DHeap vector)
{
	double mag = magnitude(vector);

	return (vector / mag);
};

// Add and subtract vectors:

Vector3DHeap Vector3DHeap::operator+ (Vector3DHeap rhs)
{
	double lx = getX();
	double ly = getY();
	double lz = getZ();

	double rx = rhs.getX();
	double ry = rhs.getY();
	double rz = rhs.getZ();

	return Vector3DHeap(lx + rx,
		ly + ry,
		lz + rz);
};

Vector3DHeap Vector3DHeap::operator- (Vector3DHeap rhs)
{
	double lx = getX();
	double ly = getY();
	double lz = getZ();

	double rx = rhs.getX();
	double ry = rhs.getY();
	double rz = rhs.getZ();

	return Vector3DHeap(lx - rx, ly - ry, lz - rz);
};

// Multiply and divide by scalars:

Vector3DHeap Vector3DHeap::operator* (double rhs)
{
	double lx = getX();
	double ly = getY();
	double lz = getZ();

	return Vector3DHeap(lx * rhs, ly * rhs, lz * rhs);
};

Vector3DHeap Vector3DHeap::operator/ (double rhs)
{
	// NEED ERROR CATCH FOR IF ZERO

	return Vector3DHeap(getX() / rhs, getY() / rhs, getZ() / rhs);
};

// Scalar (Cross) Product

Vector3DHeap Vector3DHeap::operator* (Vector3DHeap rhs)
{
	double cx = ((getY() * rhs.getZ()) - (getZ() * rhs.getY()));
	double cy = ((getZ() * rhs.getX()) - (getX() * rhs.getZ()));
	double cz = ((getX() * rhs.getY()) - (getY() * rhs.getX()));

	return Vector3DHeap(cx, cy, cz);
};

// Vector (dot) Product

double Vector3DHeap::operator% (Vector3DHeap rhs)
{
	return ((getX() * rhs.getX()) + (getY() * rhs.getY()) + (getZ() * rhs.getZ()));
};

// Assignment Operator

Vector3DHeap& Vector3DHeap::operator= (const Vector3DHeap& copy)
{
	if (this == &copy)
	{
		return *this;
	}
	this->copy(copy);
	return *this;
};

// Copy method called by Copy Constructor.

void Vector3DHeap::copy(const Vector3DHeap& copy)
{
	x = new double(*copy.x);
	y = new double(*copy.y);
	z = new double(*copy.z);

	return;
	
};
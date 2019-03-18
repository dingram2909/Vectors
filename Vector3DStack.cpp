#include "Vector3DStack.h"
#include <iostream>
#include <math.h>
using namespace std;

// Constructors

Vector3DStack::Vector3DStack(double x, double y, double z) 
{
	setX(x);
	setY(y);
	setZ(z);
};

void Vector3DStack::setX(double x)
{
	this->x = x;
};

void Vector3DStack::setY(double y)
{
	this->y = y;
};

void Vector3DStack::setZ(double z)
{
	this->z = z;
};

//Compute the magnitude of a vector.

double Vector3DStack::magnitude()
{
	return sqrt((getX() * getX()) + (getY() * getY()) + (getZ() * getZ()));
};

double Vector3DStack::magnitude(Vector3DStack vector)
{
	return vector.magnitude();
};

// Find a unit orthogonal

Vector3DStack Vector3DStack::orthogonal(Vector3DStack lhs, Vector3DStack rhs)
{
	return unit(lhs*rhs);
};

// Find a unit vector pointing in the same direction as a vector

Vector3DStack Vector3DStack::unit(Vector3DStack vector)
{
	double mag = magnitude(vector);

	return (vector / mag);
};

// Add and subtract vectors:

Vector3DStack Vector3DStack::operator+ (Vector3DStack rhs)
{
	
	return Vector3DStack(getX() + rhs.getX(),
							getY() + rhs.getY(), 
								getZ() + rhs.getZ());


};

Vector3DStack Vector3DStack::operator- (Vector3DStack rhs)
{
	return Vector3DStack(getX() - rhs.getX(),
							getY() - rhs.getY(),
								getZ() - rhs.getZ());
};

// Multiply and divide by scalars:

Vector3DStack Vector3DStack::operator* (double rhs)
{
	return Vector3DStack(getX() * rhs, getY() * rhs, getZ() * rhs);
};

Vector3DStack Vector3DStack::operator/ (double rhs)
{
	// NEED ERROR CATCH FOR IF ZERO

	return Vector3DStack(getX() / rhs, getY() / rhs, getZ() / rhs);
};

// Scalar (Cross) Product

Vector3DStack Vector3DStack::operator* (Vector3DStack rhs)
{
	double cx = ((getY() * rhs.getZ()) - (getZ() * rhs.getY()));
	double cy = ((getZ() * rhs.getX()) - (getX() * rhs.getZ()));
	double cz = ((getX() * rhs.getY()) - (getY() * rhs.getX()));

	return Vector3DStack(cx, cy, cz);
};

// Vector (dot) Product

double Vector3DStack::operator% (Vector3DStack rhs)
{
	return ((getX() * rhs.getX()) + (getY() * rhs.getY()) + (getZ() * rhs.getZ()));
};

// Assignment Operator :D

Vector3DStack Vector3DStack::operator= (Vector3DStack rhs)
{
	x = rhs.getX();
	y = rhs.getY();
	z = rhs.getZ();
	return Vector3DStack(x, y, z);
};
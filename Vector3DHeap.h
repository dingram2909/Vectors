#ifndef VECTOR3DHEAP_H
#define VECTOR3DHEAP_H

class Vector3DHeap
{
public:

	// Constructors

	Vector3DHeap(double x = 0, double y = 0, double z = 0);

	// Copy Constructor

	Vector3DHeap (const Vector3DHeap& other);

	// Destructor

	~Vector3DHeap();

	// Assignment Operator
	Vector3DHeap& operator= (const Vector3DHeap&);

	// Member Functions
	// Return an x, y or z component of the vector.
	double getX(){ return *x; };
	double getY(){ return *y; };
	double getZ(){ return *z; };
	void setX(double x);
	void setY(double y);
	void setZ(double z);

	double magnitude();
	double magnitude(Vector3DHeap vector);

	// Orthogonal (Perpendicular) Vector - Use Unit Vector method.
	Vector3DHeap orthogonal(Vector3DHeap lhs, Vector3DHeap rhs);

	// Unit Vector
	Vector3DHeap unit(Vector3DHeap vector);

	// Arithmetic Operators

	// Add and divide two vectors
	Vector3DHeap operator+ (Vector3DHeap rhs);
	Vector3DHeap operator- (Vector3DHeap rhs);

	// Multiply and divide by scalar
	Vector3DHeap operator* (double rhs);
	Vector3DHeap operator/ (double rhs);

	// Cross (Vector) Product (Multiply two vectors)
	Vector3DHeap operator* (Vector3DHeap rhs);

	// Dot (Scalar) Product
	double operator% (Vector3DHeap rhs);

private:
	void copy(const Vector3DHeap& copy);

	double* x = new double;
	double* y = new double;
	double* z = new double;

};

#endif
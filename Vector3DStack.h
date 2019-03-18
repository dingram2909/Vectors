#ifndef VECTOR3DSTACK_H
#define VECTOR3DSTACK_H

class Vector3DStack
{	
	public:

		// Constructors

		Vector3DStack(double x = 0, double y = 0, double z = 0);

		// Copy Constructor

		//Vector3DStack (const Vector3DStack& other);

		// Destructor

		//~Vector3DStack();

		// Assignment Operator
		Vector3DStack operator= (Vector3DStack rhs);

		// Member Functions
		// Return an x, y or z component of the vector.
		double getX(){ return x; };
		double getY(){	return y; };
		double getZ(){ return z; };
		void setX (double x);
		void setY (double y);
		void setZ (double z);

		double magnitude ();
		double magnitude (Vector3DStack vector);

		// Orthogonal (Perpendicular) Vector - Use Unit Vector method.
		Vector3DStack orthogonal (Vector3DStack lhs, Vector3DStack rhs);

		// Unit Vector
		Vector3DStack unit (Vector3DStack vector);

		// Arithmetic Operators

			// Add and divide two vectors
		Vector3DStack operator+ (Vector3DStack rhs);
		Vector3DStack operator- (Vector3DStack rhs);
		
			// Multiply and divide by scalar
		Vector3DStack operator* (double rhs);
		Vector3DStack operator/ (double rhs);

			// Cross (Vector) Product (Multiply two vectors)
		Vector3DStack operator* (Vector3DStack rhs);
		
			// Dot (Scalar) Product
		double operator% (Vector3DStack rhs);

	private:

		double x;
		double y;
		double z;

};

#endif
#include "Vector3DStack.h"
#include "Vector3DHeap.h"
#include <iostream>

using namespace std;

int main()
{
	Vector3DStack blank;
	cout << "Default Constructor Test: " << blank.getX() << ", " 
			<< blank.getY() << ", " << blank.getZ() << endl;
	Vector3DStack dave(3, 2, 1);
	Vector3DStack bob(1, 7, 2);
	cout << "Dave and Bob are our vectors, located in 3D space." << endl;
	cout << "Dave is located at: " << dave.getX() << ", " << dave.getY() << ", " << dave.getZ() << endl;
	cout << "Bob can be found at: " << bob.getX() << ", " << bob.getY() << ", " << bob.getZ() << endl;
	blank = (bob + dave);
	cout << "If we add Bob and Dave together we get the vector: " << blank.getX() << ", " 
		<< blank.getY() << ", " << blank.getZ() << endl;
	blank = (bob - dave);
	cout << "If we remove Bob from Dave we get the vector: " << blank.getX() << ", "
		<< blank.getY() << ", " << blank.getZ() << endl;
	blank = bob * 2;
	cout << "If we multiply Bob by a scaler of 2 we get the vector: " << blank.getX() << ", "
		<< blank.getY() << ", " << blank.getZ() << endl;
	blank = dave / 2;
	cout << "If we divide Dave by a scaler of 2 we get the vector: " << blank.getX() << ", "
		<< blank.getY() << ", " << blank.getZ() << endl;
	blank = bob * dave;
	cout << "The scalar product of Bob and Dave is: " << blank.getX() << ", "
		<< blank.getY() << ", " << blank.getZ() << endl;
	cout << "The Vector Product of Bob and Dave is: " << (bob % dave) << endl;
	cout << "The magnitude of Bob is: " << bob.magnitude() << endl;
	cout << "The magnitude of Dave is: " << dave.magnitude() << endl;
	blank = dave.unit(dave);
	cout << "A unit vector for Dave is: " << blank.getX() << ", "
		<< blank.getY() << ", " << blank.getZ() << endl;
	blank = dave.orthogonal(bob, dave);
	cout << "A unit vector which is orthogonal to Dave and Bob is: " << blank.getX() << ", "
		<< blank.getY() << ", " << blank.getZ() << endl;
	system("pause");

	cout << "---------------------------" << endl;
	cout << "--BEGIN Vector3DHeap Test--" << endl;
	cout << "---------------------------" << endl;

	Vector3DHeap empty;
	cout << "Default Constructor Test: " << empty.getX() << ", "
		<< empty.getY() << ", " << empty.getZ() << endl;
	Vector3DHeap beth(5, 8, 3);
	Vector3DHeap amy(7, 4, 2);
	cout << "Beth and Amy are our vectors, located in 3D space." << endl;
	cout << "Beth is located at: " << beth.getX() << ", " << beth.getY() << ", " << beth.getZ() << endl;
	cout << "Amy can be found at: " << amy.getX() << ", " << amy.getY() << ", " << amy.getZ() << endl;
	empty = (amy + beth);
	cout << "If we add Amy and Beth together we get the vector: " << empty.getX() << ", "
		<< empty.getY() << ", " << empty.getZ() << endl;
	empty = Vector3DHeap(amy - beth);
	cout << "If we remove Amy from Beth we get the vector: " << empty.getX() << ", "
		<< empty.getY() << ", " << empty.getZ() << endl;
	empty = amy * 2;
	cout << "If we multiply Amy by a scaler of 2 we get the vector: " << empty.getX() << ", "
		<< empty.getY() << ", " << empty.getZ() << endl;
	empty = beth / 2;
	cout << "If we divide Beth by a scaler of 2 we get the vector: " << empty.getX() << ", "
		<< empty.getY() << ", " << empty.getZ() << endl;
	empty = amy * beth;
	cout << "The scalar product of Amy and Beth is: " << empty.getX() << ", "
		<< empty.getY() << ", " << empty.getZ() << endl;
	cout << "The Vector Product of Amy and Beth is: " << (amy % beth) << endl;
	cout << "The magnitude of Amy is: " << amy.magnitude() << endl;
	cout << "The magnitude of Beth is: " << beth.magnitude() << endl;
	empty = beth.unit(beth);
	cout << "A unit vector for Beth is: " << empty.getX() << ", "
		<< empty.getY() << ", " << empty.getZ() << endl;
	empty = beth.orthogonal(amy, beth);
	cout << "A unit vector which is orthogonal to Beth and Amy is: " << empty.getX() << ", "
		<< empty.getY() << ", " << empty.getZ() << endl;
	system("pause");
}
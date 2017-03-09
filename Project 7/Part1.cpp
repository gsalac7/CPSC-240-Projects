/*Angelo Salac
Busslinger Michael
3/9/17
Project 7, Part 1
*/

#include <iostream>

using namespace std;

float a, b, c, h, tperim, tarea, rperim, rarea, l, w, two = 2, temp;

void displayInitial() {
	cout << "     /|\\    " << endl;
	cout << "    / | \\   " << endl;
	cout << " a /  |  \\ b " << endl;
	cout << "  /  h|   \\  " << endl;
	cout << " /    |    \\ " << endl;
	cout << "-------------" << endl;
	cout << "      c       " << endl;
	cout << endl;

	cout << " ---------------" << endl;
	cout << " |             |" << endl;
	cout << " |             |" << endl;
	cout << "w|             |" << endl;
	cout << " |             |" << endl;
	cout << " |             |" << endl;
	cout << " ---------------" << endl;
	cout << "        l       " << endl;
}

int main() {
	displayInitial();
	cout << "Enter the values of a, b, c, and h for the triangle: ";
	cin >> a >> b >> c >> h;

	cout << "Enter the length and the width of the rectangle: ";
	cin >> l >> w;

	_asm { 
		//find perimeeter of the triangle first
		fld		a; //st = a
		fld		b; //st = b, st[1] = a
		fadd; //st = a + b
		fld		c; //st = c, st[1] = a + b
		fadd; //st = a + b + c
		fstp	tperim; //tperim = st

		//now find the area
		fld		h; //st = h
		fld		c; //st = c, st[1] = h
		fmul; //st = h * c
		fld		two; //st = 2, st[1] = h * c
		fdiv; //st = h * c /2
		fstp	tarea; // tarea = st
	}

	_asm {

		//find area of rectangle
		fld		w //st = w
		fld		l //st = l, st[1] = w
		fmul //st = w * l
		fstp	rarea //area = st



		//find perimeter of rectnagle
		fld		w //st = w
		fld		l //st = l, st[1] = w
		fadd  //st = w + l
		fld		w //st = w
		fadd	//st = w + w + l
		fld		l //st = l, st[1] = w + w + l
		fadd	 //st = 2w + 2l
		fstp	rperim //rperim = st
		
		
	}

	cout << "Triangle " << endl;
	cout << "\tArea = " << tarea << endl;
	cout << "\tPerimeter = " << tperim << endl;

	cout << "Rectangle " << endl;
	cout << "\tArea = " << rarea << endl;
	cout << "\tPerimeter = " << rperim << endl;


	return 0;
}

/*Angelo Salac
Michael Busslinger
2/9/17
Project 2, Part 2
*/

#include <iostream>
using namespace std;

int main() {
	int a, b, c, h, w, l, Tarea, Tperim, Rarea, Rperim;

	cout << "     /|\\ " << endl;
	cout << "    / | \\ " << endl;
	cout << "  a/  |  \\ b" << endl;
	cout << "  /  h|   \\ " << endl;
	cout << " /____|____\\ " <<  endl;

	cout << "Enter the values of a, b, c, and h fo the triangle: ";
	cin >> a >> b >> c >> h;

	cout << "--------------" << endl;
	cout << "|            |" <<  endl;
	cout << "|            |" << endl;
	cout << "|            | w" << endl;
	cout << "|            |" << endl;
	cout << "|            |" << endl;
	cout << "--------------" << endl;

	cout << "     l        " << endl;
	cout << "Enter the length and witdh of the rectangle: ";
	cin >> l >> w;

	_asm { // Triangle Perimeter
		mov eax, a; // assign a to eax
		add eax, b; // add b to a
		add eax, c; // add c to a
		mov Tperim, eax; // eax assigned to Tperim
	}

	_asm { // Triangle Area
		mov eax, c; // assign c to eax
		mov ebx, 2; // assign 2 to ebx
		imul h; // multiply h by eax
		cwd; // change numerator to 64 bits
		idiv ebx; // divide eax by ebx(2)
		mov Tarea, eax; // eax assigned to Tarea

	}

	_asm { // Rectangle Perimeter
		mov eax, l; // assign l to eax
		add eax, eax; // 2l
		add eax, w; // add w to eax
		add eax, w; // add w to eax
		mov Rperim, eax; // eax assigned to Rperim
	}

	_asm { // Rectangle Area
		mov eax, l; // assign l to eax
		imul w; // multipley w to eax
		mov Rarea, eax; // eax assigned to Rarea
	}

	cout << "Triangle" << endl;
	cout << "\tArea................" << Tarea << endl;
	cout << "\tPerimeter..........." << Tperim << endl;

	cout << "Rectangle" << endl;
	cout << "\tArea................" << Rarea << endl;
	cout << "\tPerimeter..........." << Rperim << endl;

	return 0;
}

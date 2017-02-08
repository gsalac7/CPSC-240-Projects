/*Angelo Salac
Michael Busslinger
2/9/17
Project 2, Part 3
*/

#include <iostream>
using namespace std;

int main() {
	short f, c;
	cout << "Enter the temperature in Fahrenheit: ";
	cin >> f;

	_asm { // convert farenheit to celsius
		mov ax, f; // assign f to eax
		mov bx, 5; // assign this for multipilying
		mov cx, 9; // assign this for dividing
		sub ax, 32; // subtract ax by 32, f - 32
		imul bx; // multply ax by bx, 5(f - 32)
		cwd; // change to 32 bits
		idiv cx; // divide ax by cx, 5(f - 32)/9
		mov c, ax; // assign ax to c
	}

	cout << f << "F is " << c << " C" << endl;
	return 0;
}

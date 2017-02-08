/*Angelo Salac
Michael Busslinger
2/9/17
Project 2, Part 4
*/

#include <iostream>
using namespace std;

int main() {
	int d, hund, ten, one, sum;
	cout << "Enter a 3 digit int number: ";

	cin >> d;

	_asm { // find sum of the digits
		mov eax, d; // assign d to eax
		mov ecx, 100; // assign 100 to ecx
		cwd; // change to 64 bits
		idiv ecx; // divide eax by ecx, d/100
		mov hund, eax; // assign hund to eax
		mov eax, edx; // assign edx to eax
		mov ecx, 10; // assign 10 to ecx for division
		cwd; // change to 64 bits
		idiv ecx; // divide eax by ecx
		mov ten, eax; // assign eax to ten
		mov one, edx; // assign edx to one
		add edx, ten; // add ten + edx
		add edx, hund; // add hund + edx
		mov sum, edx; // assign edx to sum
	}

	cout << "\tThe total of the digits in " << d << " is " << sum << endl;
	return 0;
}

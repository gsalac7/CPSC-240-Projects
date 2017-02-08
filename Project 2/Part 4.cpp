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

	_asm {
		mov eax, d;
		mov ecx, 100;
		cwd;
		idiv ecx;
		mov hund, eax;
		mov eax, edx;
		mov ecx, 10;
		cwd;
		idiv ecx;
		mov ten, eax;
		mov one, edx;
		add edx, ten;
		add edx, hund;
		mov sum, edx;
	}
	
	cout << "\tThe total of the digits in " << d << " is " << sum << endl;
	return 0;
}

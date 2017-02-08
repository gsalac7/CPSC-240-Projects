/*Angelo Salac
Michael Busslinger
2/9/17
Project 2, Part 1
*/

#include <iostream>
using namespace std;

int main() {
	short d, s, r;

	cout << "----------Menu----------" << endl;
	cout << "Drinks................$2" << endl;
	cout << "Sandwiches............$4" << endl;
	cout << "     How many Drinks?";
	cin >> d;
	cout << "     How many Sandwiches?";
	cin >> s;

	_asm{
		mov ax, 2; // ax = d
		imul d; // ax *= d
		mov bx, 4; // assign 4 to bx
		imul bx, s; // bx *= s
		add ax, bx; // ax += bx
		mov r, ax; // assign ax to r
	}
	cout << "        Your Total bill $" << r << endl;
}

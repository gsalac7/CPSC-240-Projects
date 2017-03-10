/*Angelo Salac
Busslinger Michael
3/9/17
Project 7, Part 2
*/

#include <iostream>
#include <iomanip>
using namespace std;

float a, b, c, x, y, minus1 = -1, four = 4, two = 2;

void displayInitial() {
	cout << fixed << showpoint << setprecision(2);
	cout << "To see the two real roots of aX^2 + bX + c = 0, enter the a, b, and c values: ";
	cin >> a >> b >> c;
}

int main() {
	displayInitial();

	_asm {
		//first part
		fld		b; //st = b
		fld		b; //st = b, st[1] = b
		fmul	//st = b*b
		fld		four //st = four, st[1] = b*b
		fld		a //st = a, st[1] = four , st[2] = b*b
		fmul		//st = a * four, st[1] = b * b
		fld		c //st = c, st[1] = a * four, st[2] = b * b
		fmul	//st = c * a * four, st[1] = b * b
		fsub //st = b * b - 4ac
		fsqrt //st = sqrt(b*b-4ac)
		fld		b //st = b, st[1] = sqrt(b*b-4ac)
		fld		minus1 //st = -1, st[1] = b, st[2] = sqrt(b*b-4ac)
		fmul	//st = -b, st[1] = sqrt(b*b-4ac)
		fadd  //st = -b+sqrt(b*b-4ac)
		fld		two //st = 2, st[1] = -b+sqrt(b*b-4ac)
		fld		a  //st = a, st[1] = 2, st[2] = -b+sqrt(b*b-4ac)
		fmul	//st = 2a, st[1] = -b+sqrt(b*b-4ac)
		fdiv	//st = -b+sqrt(b*b-4ac)/2a
		fstp	x //x = st

		fld		b; //st = b
		fld		b; //st = b, st[1] = b
		fmul	//st = b*b
		fld		four //st = four, st[1] = b*b
		fld		a //st = a, st[1] = four , st[2] = b*b
		fmul		//st = a * four, st[1] = b * b
		fld		c //st = c, st[1] = a * four, st[2] = b * b
		fmul	//st = c * a * four, st[1] = b * b
		fsub //st = b * b - 4ac
		fsqrt //st = sqrt(b*b-4ac)
		fld		b //st = b, st[1] = sqrt(b*b-4ac)
		fld		minus1 //st = -1, st[1] = b, st[2] = sqrt(b*b-4ac)
		fmul	//st = -b, st[1] = sqrt(b*b-4ac)
		fsub  //st = -b-sqrt(b*b-4ac)
		fld		two //st = 2, st[1] = -b-sqrt(b*b-4ac)
		fld		a  //st = a, st[1] = 2, st[2] = -b-sqrt(b*b-4ac)
		fmul	//st = 2a, st[1] = -b-sqrt(b*b-4ac)
		fdiv	//st = -b-sqrt(b*b-4ac)/2a
		fstp	y //y = st
	}

	cout << "X1 = " << x << endl;
	cout << "X2 = " << y << endl;

	return 0;
}

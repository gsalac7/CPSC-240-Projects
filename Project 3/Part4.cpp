/*
Angelo Salac
Michael Busslinger
2/16/17
Project 3, Part 4
*/

#include <iostream>

using namespace std;

short a, b, c, d, e, f, X, Y, ynum, ydem, xnum, xdem;

void displayMenu() {
	cout << "This program solves the system" << endl;
	cout << "\taX + bY = c" << endl;
	cout << "\tdX + eY = f" << endl;
}

void readData() {
	cout << "Enter the values for a, b, and c: ";
	cin >> a >> b >> c;
	cout << "Enter the values for d, e, and f: ";
	cin >> d >> e >> f;
}

void displayAnswers() {
	cout << "\tX = " << X << "\tY = " << Y << endl;
}

int main() {
	_asm {
		call	displayMenu;	//call displayMenu
		call	readData;		//readData
		mov		ax, a;			//move a to ax
		imul	ax, f;			//multiply a by f
		mov		bx, c;			//move c to bx
		imul	bx, d;			//multiply c by d
		sub		ax, bx;			//subtract a*f with c*d
		mov		ynum, ax;		//this becomes y numerator

		mov		ax, a;			//move a to ax
		imul	ax, e;			//multiply a by e
		mov		bx, b;			//move b to bx
		imul	bx, d;			//multiply b by d
		sub		ax, bx;			//subtract a*e by b*d
		mov		ydem, ax;		//this becomes y demoninator
		mov		xdem, ax;		//as well as x denominator

		mov		ax, c;			//move c to ax
		imul	ax, e;			//multiply c by e
		mov		bx, b;			//move b to bx
		imul	bx, f;			//multply b by f
		sub		ax, bx;			//subtract c*e by b*f
		mov		xnum, ax;		//this becomes x Numerator

		//calculate
		mov		ax, ynum;		//move ynum to ax
		cwd;					
		idiv	ydem;			//divide by ydem
		mov		Y, ax;			//move ax to Y

		mov		ax, xnum;		//move xnum to ax
		cwd;
		idiv	xdem;			//divide by xdem
		mov		X, ax			//move ax to X

		call	displayAnswers;	//display the answers
	}

	return 0;
}

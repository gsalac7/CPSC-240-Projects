/*Angelo Salac
Busslinger Michael
3/9/17
Project 7, Part 2
*/

#include <iostream>
#include <iomanip>
using namespace std;

double drinkNum, sandNum, totalBill, sodaprice = 2.25, waterprice = 1.75, ten = 3.45, twelve = 5.25, c = 0, d = 0, e = 0, f = 0;
char  dType;
short sType;

void displayInitial() {
	cout << "--------------7-11 Convenient Store--------------" << endl;
	cout << "Drinks\n";
	cout << "\tSoda(S)...................................$2.25\n";
	cout << "\tWater(W)..................................$1.75\n";
	cout << "Sandwiches\n";
	cout << "\t10 inches.................................$3.45\n";
	cout << "\t12 inches.................................$5.25\n";

	cout << "How many drinks? ";
	cin >> drinkNum;
	cout << "\tWhat kind of drink(S = soda, W = water)? ";
	cin >> dType;
	
	cout << "How many sandwiches? ";
	cin >> sandNum;
	cout << "\tWhat size of sandwich (10/12 inches)? ";
	cin >> sType;

}

int main() {
	displayInitial();
	
	_asm {
		cmp		dType, 'S'; //check what kind of drink
		je		soda; //calculate for soda
		jmp		water; //else calculate for water

	soda:
		fld		sodaprice; //st = sodaprice
		fld		drinkNum; //st = drnkNum, st[1] = sodaprice
		fmul; //st = num * price
		fstp	c; //c = st
		jmp		tenInches;
	water:
		fld		waterprice; //st = waterprice
		fld		drinkNum; //st = drinkNum, st[1] = waterprice
		fmul; //st = num * price
		fstp	d; //e = st

		cmp		sType, 10; //check if 10
		je		tenInches; //if true go to ten inches
		jmp		twelveInches; //else go to twelve inches

	tenInches:
		fld		ten; //st = ten
		fld		sandNum; //st = sandNum, st[1] = ten
		fmul;	//st = sandNum * ten
		fstp	e; //e = st
		jmp		total;
	twelveInches:
		fld		twelve; //st = twelve
		fld		sandNum; //st = sandNum, st[1] = twelve
		fmul;	//st = sandNum * twelve
		fstp	f; //f = st
		
	total:
		fld		c; //st = c
		fld		d; //st = d, st[1] = c
		fadd;	//st = d + c
		fld		e; //st = e, st[1] = d + c
		fadd; //st = d + c + e
		fld		f; //st = f, st[1] = d + c + e
		fadd; //st = f + d + c + e
		fstp	totalBill; //totalBill = st
	}
	
	cout << fixed << showpoint << setprecision(2) << "Your total bill = $" << totalBill << endl;


	return 0;
}

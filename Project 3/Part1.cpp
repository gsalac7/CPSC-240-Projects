/*
Angelo Salac
Michael Busslinger
2/16/17
Project 3, Part 1
*/

#include <iostream>
using namespace std;

short sandwich;
char drink;
short dAmount, sAmount, total = 0;

void displayMenu() {
	cout << "---------------7-11 Convenient Store---------------" << endl;
	cout << "Drinks" << endl;
	cout << "\tSoda(s).........................................$2" << endl;
	cout << "\tWater(w)........................................$1" << endl;
	cout << "Sandwiches" << endl;
	cout << "\t10 Inches.......................................$3" << endl;
	cout << "\t12 inches.......................................$5" << endl;
}

int main() {
	displayMenu();
	cout << "How many Drinks? ";
	cin >> dAmount;
	cout << "What kind of drink(s = soda, w = water): ";
	cin >> drink;

	_asm {
		mov		ax, dAmount;	//assign ax with amount of drinks
		cmp		drink, 's';		//compare drinks with 's'
		jne		false1;			//if its not 's', go to false1
		
	true1:
		imul	ax, 2;			//if it is 's', multiply amount of drinks by 2
		jmp		done;			//done with this calculation
	false1:
		imul	ax, 1;			//multiply amount of drinks by 1
	done:
		add		total, ax;		//add to the total, ax;
	}

	cout << "How many sandwiches? ";
	cin >> sAmount;
	cout << "what size of sandwich? (10/12 inches) ";
	cin >> sandwich;
	
	_asm {
		mov		ax, sAmount;	//assign ax, with amount of sandwiches
		cmp		sandwich, 10;	//compare drinks with 10
		jne		false2;			//if ts not 10, go to false2
	true2:
		imul	ax, 3;			//if it is 10, multply by 3
		jmp		done1;			//done with this calculation
	false2:
		imul	ax, 5;			//else if it is anything other than 10, multiplay amount by 5
	done1:
		add		total, ax;		//add to the total, ax
	}

	cout << "Your total bill is: $" << total << endl;
	return 0;
}

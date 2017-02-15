/*
Angelo Salac
Michael Busslinger
2/16/17
Project 3, Part 3
*/

#include <iostream> 

using namespace std;
short age;
char gender;
short amount;

void displayMenu() {
	cout << "-----------Ace Club-----------" << endl;
	cout << "Male" << endl;
	cout << "\tAdult(age > 19)...........$100" << endl;
	cout << "\tTeenager(age 13 - 19).....$75" << endl;
	cout << "Female" << endl;
	cout << "\tAdult(age > 19)...........$80" << endl;
	cout << "\tTeenager(age 13 - 19).....$85" << endl;
}

void readData() {
	cout << "Enter value for gender: ";
	cin >> gender;
	cout << "Enter value for age: ";
	cin >> age;
}

void displayNotAllowed() {
	cout << "Not allowed" << endl;
}

void displayAmount() {
	cout << "Your total bill is: $" << amount << endl;
}

int main() {
	displayMenu();
	_asm {
		call	readData;		//read data first
		mov		ax, age;		//assign age to ax register 
		cmp		gender, 'm';	//compare gender with male 
		jne		false1;			//if its not male, go to false1
	true1:
		cmp		 ax, 19;		//check age if its greather than 19
		jng		 false3;		//if its not greater than 19, then check if its greater than 13.
	true3:
		mov		amount, 100;	//set amount to 100
		call	displayAmount;  //display the amount
		jmp		done;			//finished calculating
	false1:
		cmp		ax, 19;			//compare age with 19
		jng		false2;			//check if its greater, if not go to false 2
		jmp		true2;			//if it iis greater, go to true2
	true2:
		mov		amount, 80;		//set amount to 80
		call	displayAmount;	//display amount
		jmp		done;			//finished calculating
	false2:
		cmp		ax, 13;			//check if age is greater than 13
		jng		false5;			//if not go to false5
		mov		amount, 85;		//if it is, set amount to 85
		call	displayAmount;	//show amount
		jmp		done;			//finished calculating
	false3:
		cmp		ax, 13;			//check if age is greater than 13
		jng		false4;			//jump to false 4 if not older than 13. 
		mov		amount, 75;		//set amount to 75
		call	displayAmount;	//display amount
		jmp		done;			//finished calculating
	false4:
		call	displayNotAllowed;	//age is not good male
		jmp		done;				//finished calculating
	false5:
		call	displayNotAllowed;	//age is not good female
	done:

	}
	system("pause");
	return 0;
}

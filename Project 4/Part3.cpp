/*Angelo Salac
Michael Busslinger
2/23/17
Project 4, Part 3
*/
#include <iostream>
#include <ctime>
using namespace std;

char choice, YesNo;
int x, y, z, correctAns, wrongAns;

void generateXY() {
	srand(time(0));
	x = rand() % 100;
	y = rand() % 100;
}

void displayMenu() {
	cout << "---------Practice Addition & Subtraction---------" << endl;
	cout << "a.\tPractice Addition" << endl;
	cout << "b.\tPractice Subtraction" << endl;
	cout << "\t\tEnter your choice: ";
	cin >> choice;
}

void displayFinished() {
	cout << "\t\tAre you done(y/n) ";
	cin >> YesNo;
}

void displayCorrect() {
	cout << "\t\t\t\tCorrect\n";
}

void displayWrong() {
	cout << "\t\t\t\tWrong\n";
}

void continue1() {
	cout << "\t\t\t\tContinue(y/n)? ";
	cin >> YesNo;
}

void displayRightWrong() {
	cout << "\t\tNo. of CORRECT answers = ";
	cout << correctAns << endl;
	cout << "\t\tNo. of WRONG answers = ";
	cout << wrongAns << endl;
}

void displayAddQuestion() {
	cout << "\t\t\t" << x << " + " << y << " = ? ";
	cin >> z;
}

void displaySubQuestion() {
	cout << "\t\t\t" << x << " - " << y << " = ? ";
	cin >> z;
}

void bye() {
	cout << "\t\t\tHave a nice day" << endl;
}

int main() {
	_asm {
	start: //beginning label
		mov		correctAns, 0;
		mov		wrongAns, 0; //set the counters
		call	displayMenu; //display the menu first
		cmp		choice, 'a'; //compare choice with a
		je		addition; //if its a, then addition
		jmp		subtraction; //else subtraction

	addition:
		call	generateXY; //generate x and y
		call	displayAddQuestion; //ask the question
		mov		eax, x; //move x to eax register
		add		eax, y; //add y to x
		cmp		eax, z; //compare user answer to x + y
		je		correct; //if equal go to correct
		jne		wrong; //else go to wrong

	subtraction:
		call	generateXY; //generate x and y
		call	displaySubQuestion; //ask question
		mov		eax, x; // move x to eax register
		sub		eax, y; //add y to x
		cmp		eax, z; //compare user answer to x and y
		je		correct; //if equal go to correct
		jne		wrong; //else go to wrong

	correct:
		call	displayCorrect; //display correct
		inc		correctAns; //add 1 to cCounter
		cmp		choice, 'a'; //if the choice is a
		je		continueAdd; //go to continue addition
		jmp		continueSub; //else go to continue subtractions
	wrong: 
		call	displayWrong; //display wrong
		inc		wrongAns; //add 1 to wCounter
		cmp		choice, 'a'; //if choice is a 
		je		continueAdd; //go to continue addition
		jmp		continueSub; //else go to continue subtractions
	continueAdd:
		call	continue1; //call continue
		cmp		YesNo, 'y'; //continue
		je		addition; //go to addition
		jmp		done;
	continueSub:
		call	continue1; //call continue
		cmp		YesNo, 'y'; //continue
		je		subtraction; //repeat sub
		jmp		done;
	done:
		call	displayRightWrong; //display the final total scores
		call	displayFinished; //ask if finished
		cmp		YesNo, 'n'; //if no repeat
		je		start; //go back to menu and ask user again
		jmp		finished;
	finished:
		call	bye; //done
	}
	return 0;
}

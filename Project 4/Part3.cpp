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
	start:
		mov correctAns, 0;
		mov wrongAns, 0;
		call displayMenu;
		cmp choice, 'a';
		je addition;
		jmp subtraction;

	addition:
		call generateXY;
		call displayAddQuestion;
		mov eax, x;
		add eax, y;
		cmp eax, z;
		je correct;
		jne wrong;

	subtraction:
		call generateXY;
		call displaySubQuestion;
		mov eax, x;
		sub eax, y;
		cmp eax, z;
		je correct;
		jne wrong;

	correct:
		call displayCorrect;
		inc correctAns;
		cmp choice, 'a';
		je continueAdd;
		jmp continueSub;
	wrong:
		call displayWrong;
		inc wrongAns;
		cmp choice, 'a';
		je continueAdd;
		jmp continueSub;
	continueAdd:
		call continue1;
		cmp YesNo, 'y';
		je addition;
		jmp done;
	continueSub:
		call continue1;
		cmp YesNo, 'y';
		je subtraction;
		jmp done;
	done:
		call displayRightWrong;
		call displayFinished;
		cmp YesNo, 'n';
		je start;
		jmp finished;
	finished:
		call bye;
	}
	return 0;
}

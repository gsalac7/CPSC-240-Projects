#include <iostream>
#include <ctime>
using namespace std;

char choice, YesNo;
int x, y, z, correctAns = 0, wrongAns = 0;
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

int main() {
	_asm {
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
		jmp continue2;
	wrong:
		call displayWrong;
		inc wrongAns;
		jmp continue2;
	continue2:
		call continue1;
		cmp choice, 'a';
		cmp YesNo, 'y';
		je addition;
		cmp choice, 'b';
		cmp YesNo, 'y';
		je subtraction;
		jmp done;
	done:
		call displayRightWrong;
	}
	return 0;
}

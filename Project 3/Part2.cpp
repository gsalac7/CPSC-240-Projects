#include <iostream>

using namespace std;
int counter = 1, score = 0, average;

void readData() {
	cout << "Enter your score (-1 to stop): ";
	cin >> score;
}

void displayAverage() {
	cout << "Your average is " << average;
}

int main() {
	_asm {
		mov eax, score; //assign score to eax register
		mov ebx, average;
		mov ecx, counter;
	compare:
		cmp score, -1;
		jne readData;
		sub ecx, 1;
		add eax, 1;
		jmp done;
	readData:
		call readData;
		add ecx, 1;
		jmp compare;
		add eax, score;
	done:
		cqd;
		idiv ecx;
		mov ecx, average;
		call displayAverage;

	}
}

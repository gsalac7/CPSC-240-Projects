#include <iostream>
using namespace std;

int counter = 1, score = 0, average;

void readData() {
	cout << "Enter your score (-1 to stop): ";
	cin >> score;
}

void displayAverage() {
	cout << "Your average is " << average << endl;
}

int main() {
	_asm {
		mov eax, score; //assign score to eax register
		mov ebx, average;
		mov ecx, counter;
		call readData;
	compare:
		cmp score, -1;		//compare the data just read(score) to - 1
		jne readData;		//if the score is not equal to - 1, keep reading data.
		add eax, score;	
		sub ecx, 1;			//else if the scoer is equal to -1, then take 1 away from the counter.
		add	score, 1;		// and since 1 was subtracted from the score, add 1.

		jmp done;
	readData:
		call readData;
		add counter, 1;		//add 1 to the counter
		add	eax, score;	//add the score to the same score register.
		jmp compare;	//go back to comparng to see if the next read data is or isn't -1
	done:
		cdq;
		idiv counter;
		mov average, eax;
		call displayAverage;
	}
	return 0;
}

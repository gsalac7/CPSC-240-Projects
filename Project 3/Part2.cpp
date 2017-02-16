#include <iostream>
using namespace std;

int counter = 0, score = 0, average = 0, sum = 0;

void readData() {
	cout << "Enter your score (-1 to stop): ";
	cin >> score;
}

void addData() {
	sum += score;
}

void displayAverage() {
	cout << "Your average is " << sum << endl;
}

int main() {
	_asm {
		mov		eax, sum; //assign sum to eax register
		mov		ebx, counter; //assgn counter to ebx

	read:
		call	readData; //call the readData function
		call	addData;  //add score to sum...
		add		ebx, 1;		//add 1 to the counter
		
	compare:
		cmp		score, -1; //check if the score is -1
		jne		read; //if score isn't -1 go to readdata again
		sub		ebx, 1;	//subtract 1 from the counter since -1 doesnt count
		add		eax, 1; //add 1 to the score to nullify the -1 added to the score

	done:
		cdq;
		idiv	ebx; //divide eax (sum) with ebx (counter) to get average in eax
		mov		sum, eax; //move eax to average
		call	displayAverage; //display the average
	}
	return 0;
}

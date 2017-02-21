/*Angelo Salac
Michael Busslinger
2/23/17
Project 4, Part 1
*/
#include <iostream>

using namespace std;

int i = 0, yesCounter = 0, noCounter = 0;
char c;

void printStar() {
	cout << "*";
}
void readData() {
	cin.get(c);
}

void yesVotes() {
	cout << "No. of YES votes = " << yesCounter << " ";
	_asm { //loop to print the stars
		mov		i, 0;
	forloop:
		call	printStar; //print the star
		inc		i; //increment i by 1
		mov		eax, i;
		cmp		eax, yesCounter; //compare i to the counter
		jne		forloop; //if its not equal then keep repeating
	done:
	}
	cout << endl;
}

void noVotes() {
	cout << "No. of NO votes = " << noCounter << " ";
	_asm { //loop to print stars
		mov		i, 0;
	forloop:
		call	printStar;  //print the star
		inc		i;			//increment i by 1
		mov		eax, i;		//move i to register
		cmp		eax, noCounter;//check if i is counter
		jne		forloop;	//if it is not, then repeat
	done:
	}
	cout << endl;
}

int main() {
	cout << "Enter a string of votes: ";
	_asm {
	forloop:
		call	readData; //call read data
		cmp		c, 'y'; //check to see if char is y
		je		addY; //if it is, then add 1 to y
		jmp		addN; //if it is not then add 1 to n
	addY:
		inc		yesCounter; //add 1 to the ycounter
		inc		i; //the vote counter
		cmp		i, 10; //if its 10 votes, then its done
		je		done;
		jmp		forloop;

	addN:
		inc		noCounter; //add 1 to the ncounter
		inc		i; //the vote counter
		cmp		i, 10; //if its 10 votes, then its done
		je		done;
		jmp		forloop;

	done:
		call	yesVotes; //display the yesvotes
		call	noVotes; //display the no votes
	}

	return 0;
}

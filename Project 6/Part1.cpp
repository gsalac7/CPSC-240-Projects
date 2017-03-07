#include <iostream>

using namespace std;

int tshirts[4][4] = {
	{10, 20, 30, 40},
	{20, 10, 40, 30},
	{5, 15, 20, 25},
	{30, 25, 20, 15} 
};
int i;
int totalShirts = 0, largeShirts = 0, blackShirts = 0;



void displayTotalShirts() {
	cout << "The total number of shirts are: " << totalShirts << endl;
}

void displayLargeShirts() {
	cout << "The total number of large shirts are: " << largeShirts << endl;
}

void displayBlackShirts() {
	cout << "The total number of black shirts are: " << blackShirts << endl;
}

int main() {
	_asm {
		mov ebx, 0;
		mov ecx, 0;
		mov i, 0;
	loop1:
		add ecx, [tshirts + ebx];
		inc i;
		cmp i, 3; //if i is 3, then we are done.
		je done1;
		add ebx, 4; 
		jmp loop1;
	done1:
		mov totalShirts, ecx;
		call displayTotalShirts;
		mov ebx, 8;
		mov ecx, 0;
		mov i, 0;
	loop2:
		add ecx, [tshirts + ebx];
		inc i;
		cmp i, 3;
		je done2;
		add ebx, 16;
		jmp loop2;
	done2:
		mov largeShirts, ecx;
		call displayLargeShirts;
		mov ebx, 48;
		mov ecx, 0;
		mov i, 0;
	loop3:
		add ecx, [tshirts + ebx];
		inc i;
		cmp i, 3;
		je done3;
		add ebx, 4;
		jmp loop3;
	done3:
		call displayBlackShirts;

	}

	return 0;
}

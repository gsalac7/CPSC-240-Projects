#include <iostream>

using namespace std;

int tshirts[4][4] = {
	{ 10, 20, 30, 40 },
	{ 20, 10, 40, 30 },
	{ 5, 15, 20, 25 },
	{ 30, 25, 20, 15 }
};

int i, j;
int totalShirts = 0, largeShirts = 0, blackShirts = 0;

void display() {
	cout << j << " ";
}

void displayTotalShirts() {
	cout << "The total number of shirts are: " << totalShirts << endl;
	i = 0;
}

void displayLargeShirts() {
	cout << "The total number of large shirts are: " << largeShirts << endl;
	i = 0;
}

void displayBlackShirts() {
	cout << "The total number of black shirts are: " << blackShirts << endl;
}

int main() {
	_asm {
		mov i, 0;
		mov eax, 0;
		mov ebx, 0;

	loop1:
		cmp i, 16;
		je done1;
		add ecx, [tshirts + ebx];
		inc i;
		add ebx, 4;
		jmp loop1;
	done1:
		mov totalShirts, ecx;
		call displayTotalShirts;

		mov i, 0;
		mov ebx, 8;
		mov ecx, 0;

	loop2:
		cmp i, 4;
		je done2;
		add ecx, [tshirts + ebx];
		inc i;
		add ebx, 16;  //jump to next part in array with large t shirt
		jmp loop2;
	done2:
		mov largeShirts, ecx;
		call displayLargeShirts;

		mov i, 0;

		
		mov ecx, 0;
		mov ebx, 48;

	loop3:
		cmp i, 4;
		je done3;
		add ecx, [tshirts + ebx];
		inc i;
		add ebx, 4;
		jmp loop3;
	done3:
		mov blackShirts, ecx;
		call displayBlackShirts;

	}

	return 0;
}

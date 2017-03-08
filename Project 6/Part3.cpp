#include <iostream>

using namespace std;

int a[3][3][2] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18 };
int i;
int totalShirts = 0, totalMedium = 0, totalShort = 0, totalRED = 0;

void displayTotalShirts() {
	cout << i << endl;
	cout << "There are " << totalShirts << " T-Shirts. " << endl;
}

void displayMedium() {
	cout << i << endl;
	cout << "There are " << totalMedium << " Medium T-shirts." << endl;
}

void displayShort() {
	cout << i << endl;
	cout << "There are " << totalShort << " Small T-shirts." << endl;
}


void displayRED() {
	cout << i << endl;
	cout << "There are " << totalRED << " Red T-shirts. " << endl;
}


int main() {
	_asm {
		mov ebx, 0;
		
		mov i, 0;

	loop1: //add all t shirts
		cmp i, 17;
		je done;
		mov ecx, [a + ebx];
		add totalShirts, ecx;
		add ebx, 4;
		inc i;
		jmp loop1;
	done:
		call displayTotalShirts;


		mov ebx, 4;
		mov i, 0;
		
	loop2:
		cmp i, 9;
		je done2;
		mov ecx, [a + ebx];
		add totalMedium, ecx;
		add ebx, 16;
		inc i;
		jmp loop2;
	done2:
		call displayMedium;

		mov ebx, 0;
		mov i, 0;

	loop3:
		cmp i, 8;
		je done3;
		mov ecx, [a + ebx];
		add totalShort, ecx;
		add ebx, 4;
		inc i;
		jmp loop3;
	done3:
		call displayShort;

		mov ebx, 0;
		mov ecx, 0;
		mov i, 0;


	loop4:
		cmp i, 3;
		je nextLoop;
		mov ecx, [a + ebx];
		add totalRED, ecx;
		add ebx, 4;
		inc i;
		jmp loop4;

	nextLoop:
		mov i, 0;
		mov ebx, 40;
	nextLoop2:
		cmp i, 3;
		je done4;
		mov ecx, [a + ebx];
		add totalRED, ecx;
		add ebx, 4;
		inc i;
		jmp nextloop2;

	done4:
		call displayRED;
	}
	return 0;
}

#include <iostream>

using namespace std;

int a[5] = { 9, 3, 22, 8, 1 };
int i = 0, temp;

void display() {
	cout << temp << " ";
}

int main() {
	_asm {
	set:
		mov ecx, 0;
		mov ebx, 0;
	loop1:
		cmp i, 25; //do iteration i^2 times
		je done;
		inc i; //traverse the array
		cmp ebx, 16; //once first iteration is done
		je set; //set value to 0 again
		mov edx, [a + ebx]; //move first value to eax
		add ebx, 4; //traverse array with ebx
		cmp edx, [a + ebx]; // if eax is greater than then swap
		jge swap; //swap function
		jmp loop1; //continue

	swap: //got this from wikipedia
		//mov ecx, [a + ebx];
		//xor eax, ecx;
		//xor ecx, eax;
		//xor eax, ecx;
		//mov[a + ebx], ecx;
		jmp loop1;

	done:
		call display;
	}
	return 0;
}

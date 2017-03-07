#include <iostream>

using namespace std;

int a[5] = { 9, 3, 22, 8, 1 };
int i;
int main() {
	_asm {
		mov eax, [a];
		mov ebx, 0;
		
		mov i, 0;
	loop1:
		cmp eax, [a + 4];
		jg swap;

		mov eax, [a + 4];
	swap:
		mov ecx, eax;
		mov eax, [a + 4];
		

	}
	return 0;
}

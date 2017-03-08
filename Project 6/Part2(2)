#include <iostream>

using namespace std;

int a[5] = { 9, 3, 22, 8, 1 };
int i = 0, temp;

void display() {
	for (int i = 0; i < 5; i++) {
		cout << a[i] << " ";
	}
}
int main() {
	_asm {       
		mov ecx, 0;
		mov edx, 0;
		lea esi, a;     // <=====================

	innerloop:
		inc ecx
		cmp ecx, 5
		je outerloop
		mov eax, [esi]
		cmp eax, [esi + 4]
		Jbe noexchange         // <=============== ASCENDING ORDER.
		xchg eax, [esi + 4]
		mov[esi], eax

	noexchange :
		add esi, 4
		jmp innerloop

	outerloop :
		lea esi, a      // <=====================
		mov ecx, 0
		inc edx
		cmp edx, 5
		jne innerloop	
		mov edx, 0		
		lea esi, a       // <=====================

	loop3:
		mov eax, [esi]
		push edx
		//invoke printf, addr fmtmsg1, eax
		pop edx

		add esi, 4
		inc edx
		cmp edx, 5
		jne loop3

		//invoke printf, addr fmtmsg2
	}

	display();
}

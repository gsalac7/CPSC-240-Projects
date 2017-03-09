/*Angelo Salac
Michael Busslinger
3/9/17
Project 6 Part 3
*/
#include <iostream>

using namespace std;

int a[5] = { 9, 3, 22, 8, 1 };
int i = 0, temp;

void display() {
	for (int i = 0; i < 5; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}
int main() {
	cout << "Current Array: ";
	display();
	_asm {
		mov edx, 0;
		lea ecx, a;  //load pointer to esi   

	innerloop:
		inc i //increment i
		cmp i, 5 //check if i == 0
		je outerloop //if it is go to the outer loop
		mov eax, [ecx] //assign eax the ecx pointer
		cmp eax, [ecx + 4] //compare eax with next number in array
		Jng noexchange         //if eax is not greater than, then dont exchange
		xchg eax, [ecx + 4] //if its true, the exchcange the values
		mov[ecx], eax //assign eaxy to ecx.

	noexchange :
		add ecx, 4	//go to next number in array
		jmp innerloop //then repeat iteration in inner loop

	outerloop :
		lea ecx, a    //assign pointer to ecx,
		mov i, 0 //put 0 into i
		inc edx  //increment edx
		cmp edx, 5 //check if 5 times since O(n^2) iterations
		jne innerloop //if not go back to the inner loop
		mov edx, 0 //set edx back to 0
		lea ecx, a     //first address of a to ecx
	}
	cout << "Sorted Array: ";
	display();
	
}

#include <iostream> 
 

 using namespace std; 
 short age; 
 char gender; 
 short amount; 
 
 
 

 void readData() { 
 	cout << "Enter value for gender: "; 
 	cin >> gender; 
 	cout << "Enter value for age: "; 
 	cin >> age; 
 } 
 
 void displayNotAllowed() { 
 	cout << "Not allowed" << endl; 
 } 
 
 void displayAmount() { 
 	cout << amount << endl; 
 } 
 
 int main() { 
 	_asm { 
 		call readData; 
 		mov ax, age;		//assign age to ax register 
 		cmp gender, 'm';	//compare gender with male 
 		jne false1;
	true1: 
 		cmp ax, 19; 
 		jng false3; 
 	true3: 
 		mov amount, 100;	//if he is above 100 
 		call displayAmount; 
		jmp done;
 	false1: 
 		cmp ax, 19; 
 		jng false2; 
		jmp true2;
	true2:
		mov amount, 80;
		call displayAmount;
		jmp done;
 	false2: 
 		cmp ax, 13; 
 		jng false5; 
 		mov amount, 85; 
 		call displayAmount; 
		jmp done;
 	false3: 
 		cmp ax, 13; 
 		jng false4;	//jump to false 4 if not older than 13. 
 		mov amount, 75; 
 		call displayAmount; 
		jmp done;
 	false4: 
 		call displayNotAllowed; 
		jmp done;
 	false5: 
 		call displayNotAllowed; 
done:
		
 	} 
	system("pause");
	return 0;
 } 

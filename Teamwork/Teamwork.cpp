#include <iostream>
using namespace std;
extern "C" bool IsValidAssembly(int a, int b, int c);

#include <iostream>
using namespace std;

void FailedTest(char s[]) {
	cout << s << endl;
	exit(0);
}

void ControlInAsmblyFile() {
	cout << "ControlInAsmblyFile() " << endl;
	int num1, num2, num3;
	cout << "num1: ";
	cin >> num1;
	cout << "num2: ";
	cin >> num2;
	cout << "num3: ";
	cin >> num3;

	if (!IsValidAssembly(num1, num2, num3)) FailedTest("Eso no es correcto");
}

void ControlWithInlineAssembly(){
	int check;
	int status = 0;
	cout << "ControlWithInlineAssembly() ";
	cin >> check;
	cout << endl;
	__asm {
		mov eax, check
		mov ebx, check
		and eax, 0xFFFF0000
		and ebx, 0x0000FFFF
		shr eax, 16
		cmp eax, ebx
		je true
		jmp final

		true:
		inc status
		final:
	}

	if (!((bool)status)) FailedTest("Eso no es correcto");
}

void ControlString() {

}

void BitControl() {

}

int main() {
	ControlString();
	BitControl();
	ControlInAsmblyFile();
	ControlWithInlineAssembly();

	cout << "Correcto" << endl;
	// Si se llega a esta línea es que ningún método ha
	// hecho exit(), con lo que se han completado todas
	// las etapas satisfactoriamente.

	return 0;
}

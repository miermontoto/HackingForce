#include <iostream>
using namespace std;
extern "C" bool IsValidAssembly(int a, int b, int c);

#include <iostream>
using namespace std;

void FailedTest() {
	cout << "Se han introducido valores incorrectos." << endl;
	exit(0);
}

void ControlInAsmblyFile() {
	int num1, num2, num3;
	cin >> num1;
	cin >> num2;
	cin >> num3;

	if (!IsValidAssembly(num1, num2, num3)) {
		cout << 0 << endl;
		FailedTest();
	}
}

void ControlWithInlineAssembly() {
	int check;
	cin >> check;
	__asm {

	}
}

int main() {
	//ControlString();
	//BitControl();
	ControlInAsmblyFile();
	ControlWithInlineAssembly();

	cout << "Correcto." << endl;
	// Si se llega a esta línea es que ningún método ha
	// hecho exit(), con lo que se han completado todas
	// las etapas satisfactoriamente.

	return 0;
}

#include <iostream>
using namespace std;
extern "C" bool IsValidAssembly(int a, int b, int c);

#include <iostream>
using namespace std;

void ControlWithInlineAssembly() {
	int check;
	cin >> check;
	__asm {

	}
}

void ControlInAsmblyFile() {}


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

#include <iostream>
#define maxSizeString 10 // Longitud máxima de las cadenas a leer.
using namespace std;
extern "C" bool IsValidAssembly(int a, int b, int c);

void FailedTest(char s[]) {
	cout << s << endl;
	exit(1);
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
	char cadena1[maxSizeString];
	cout << "ControlString()" << endl << "Cadena 1: ";
	cin.getline(cadena1, maxSizeString); // Se lee la cadena.
	if (strcmp(cadena1, "otiPqhXcD") != 0) FailedTest("Sayonara, baby"); // Se compara con la cadena deseada.
	// strcmp() devolverá 0 solo cuando las cadenas comparadas sean iguales.

	char cadena2[maxSizeString];
	cout << "Cadena 2: ";
	cin.getline(cadena2, maxSizeString); // Se lee la cadena.
	if (strlen(cadena2) < 6 || cadena2[3] != cadena2[5]) FailedTest("Sayonara, baby");
	// Se evalúa si la cadena tiene menos de 6 de longitud o si los caracteres de la
	// posición 3 y la 5 son diferentes.
}

void BitControl() {
	unsigned int num1;
	unsigned int num2;

	unsigned int temp1;
	unsigned int temp2;
	unsigned int temp3;

	// Se leen ambos números al principio, como indicado.
	cout << "BitControl()" << endl << "Número 1: ";
	cin >> num1;
	cout << "Número 2: ";
	cin >> num2;
	
	temp1 = (num2 & 0x0000001C) >> 2; // Se coge desde la posición 4 hasta la 2 y se desplazan.
	if (temp1 != 1) FailedTest("Sayonara, baby"); // Si no vale 1 en binario natural (1 en decimal), da fallo.


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

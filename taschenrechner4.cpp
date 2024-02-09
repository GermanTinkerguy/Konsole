#include <iostream>, <cstdlib>

// Variablen
int wert1 = 0, wert2 = 0, erg = 0, rest = 0;
char rechenart = 0;
char prozent = 0;

int main() {

	{
		std::cout << "**************************************************************\n";
		std::cout << "\n";
		std::cout << "Taschenrechner V1.00\n";
		std::cout << "by Oliver\n";
		std::cout << "\n";
		std::cout << "**************************************************************\n";
		std::cout << "\n";
		std::cout << "Anleitung:\n";
		std::cout << "\n";
		std::cout << "Der Rechner verwendet fuer unser deutsches Komma einen Punkt!\n";
		std::cout << "\n";
//		std::cout << "Du willst beispielsweise ausrechnen wie viel 40% von 170 sind.\n";
//		std::cout << "Dann tippe in den Taschenrechner: 170 * 40 % .\n";
//		std::cout << "\n";
		std::cout << "**************************************************************\n";
		std::cout << "\n";

		// Programm wird neu gestartet
		while (true) {

			// Term einlesen
			std::cout << "Rechenterm eingeben:\n";

			std::cin >> wert1 >> rechenart >> wert2 >> prozent;

			// Berechnung und Anzeige
			switch (rechenart) {
			case '+':
				// Addition
				erg = wert1 + wert2;
				std::cout << "\n";
				std::cout << wert1 << " + " << wert2 << " = " << erg << "\n";
				std::cout << "\n";
				break;
			case '-':
				// Subrtaktion
				erg = wert1 - wert2;
				std::cout << "\n";
				std::cout << wert1 << " - " << wert2 << " = " << erg << "\n";
				std::cout << "\n";
				break;
			case '*':
				// Multiplikation
				erg = wert1 * wert2;
				std::cout << "\n";
				std::cout << wert1 << " x " << wert2 << " = " << erg << "\n";
				std::cout << "\n";
				break;
			case '/':
				// Division
				erg = wert1 / wert2;
				rest = wert1 % wert2;
				std::cout << "\n";
				std::cout << wert1 << " : " << wert2 << " = " << erg << ", Rest " << rest << "\n";
				std::cout << "\n";
				break;
			}
		}
	}
}

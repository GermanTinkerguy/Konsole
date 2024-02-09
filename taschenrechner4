#include <iostream>, <cstdlib>

int main() {

	{
		std::cout << "Taschenrechner V1.00\n";
		std::cout << "by Oliver\n";
		std::cout << "\n";

		// Programm wird neu gestartet
		while (true) {

			// Eingabewerte
			int wert1 = 0, wert2 = 0;
			char rechenart = 0;

			// Ergebnisse
			int sum = 0, sub = 0, mul = 0, div = 0, rest = 0;

			// Term einlesen
			std::cout << "Rechenterm eingeben:\n";
			std::cin >> wert1 >> rechenart >> wert2;

			// Berechnung und Anzeige
			switch (rechenart) {
			case '+':
				// Addition
				sum = wert1 + wert2;
				std::cout << "\n";
				std::cout << wert1 << " + " << wert2 << " = " << sum << "\n";
				std::cout << "\n";
				break;
			case '-':
				// Subrtaktion
				sub = wert1 - wert2;
				std::cout << "\n";
				std::cout << wert1 << " - " << wert2 << " = " << sub << "\n";
				std::cout << "\n";
				break;
			case '*':
				// Multiplikation
				mul = wert1 * wert2;
				std::cout << "\n";
				std::cout << wert1 << " x " << wert2 << " = " << mul << "\n";
				std::cout << "\n";
				break;
			case '/':
				// Division
				div = wert1 / wert2;
				rest = wert1 % wert2;
				std::cout << "\n";
				std::cout << wert1 << " : " << wert2 << " = " << div << ", Rest " << rest << "\n";
				std::cout << "\n";
				break;
			}
		}
	}
}

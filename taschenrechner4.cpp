#include <iostream>, <cstdlib>
#include <iomanip>																					// Bib für E Notation

// Variablen
long double wert1 = 0.0, wert2 = 0.0, ergebnis = 0.0;
char rechenart, rechenzeichen;
bool prozent;


int main() {
		std::cout << std::setiosflags(std::ios_base::fixed) << std::setprecision(0);				// Deaktivierung der E-Notation bzw der Scientific Notation
	
		std::cout << "**************************************************************\n";
		std::cout << "\n";
		std::cout << "Taschenrechner V1.00\n";
		std::cout << "by Oliver\n";
		std::cout << "\n";
		std::cout << "**************************************************************\n";
		std::cout << "\n";
		std::cout << "Anleitung:\n";
		std::cout << "\n";
		std::cout << "- Der Rechner verwendet fuer Komma einen Punkt!\n";
		std::cout << "- Variable als long double deklariert, deswegen keine Werte mit\n";
		std::cout << "  mehr als 19 Stellen verwenden!\n";
		std::cout << "- Du willst beispielsweise ausrechnen, wie viel 40% von 170\n";
		std::cout << "  sind, dann tippe in den Rechner: '170*40% .\n";
		std::cout << "\n";
		std::cout << "**************************************************************\n";
		std::cout << "\n";

		// Term einlesen
		std::cout << "Rechenterm eingeben:\n";
		std::cout << "z.B.: '40+2='\n";
		std::cout << "\n";

		// Programm wird neu gestartet
		while (true) {

			std::cin >> wert1 >> rechenart >> wert2 >> rechenzeichen;

			// Char to Bool um Term mit % zu erkennen
			if (rechenzeichen == '%') {
				prozent = true;

				ergebnis = wert1 / 100 * wert2;
				std::cout << "\n";
				std::cout << wert1 << " x " << wert2 << "% = " << ergebnis << "\n";
				std::cout << "\n";
			}
			if (rechenzeichen == '='){
				prozent = false;

				// Berechnung und Anzeige
				switch (rechenart) {
					case '+':
						// Addition
						ergebnis = wert1 + wert2;
						std::cout << "\n";
						std::cout << wert1 << " + " << wert2 << " = " << ergebnis << "\n";
						std::cout << "\n";
						break;
					case '-':
						// Subrtaktion
						ergebnis = wert1 - wert2;
						std::cout << "\n";
						std::cout << wert1 << " - " << wert2 << " = " << ergebnis << "\n";
						std::cout << "\n";
						break;
					case '*':
					case 'x':
					case 'X':
						// Multiplikation
						ergebnis = wert1 * wert2;
						std::cout << "\n";
						std::cout << wert1 << " x " << wert2 << " = " << ergebnis << "\n";
						std::cout << "\n";
						break;
					case '/':
					case ':':
						// Division
						ergebnis = wert1 / wert2;
						std::cout << "\n";
						std::cout << wert1 << " : " << wert2 << " = " << ergebnis << "\n";
						std::cout << "\n";
						break;
				}
			}
		}
}

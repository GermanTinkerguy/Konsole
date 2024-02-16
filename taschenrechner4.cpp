// Bibliotheken

#include <iostream>					// In/out Streams
#include <cstdlib>					// Kontrollierte Programmenden
#include <iomanip>					// E-Notation deaktivieren
#include <stdlib.h>					// Konsole leeren


// Variablen

long double wert1 = 0.0, wert2 = 0.0, ergebnis = 0.0;
char rechenart, rechenzeichen;
bool prozent;
int menue;


// Funktionen

void taschenrechner() {

	// Konsole leeren
	system("cls");

	std::cout << "Rechenterm eingeben:\n";
	std::cout << "\n";

	// Term einlesen
	std::cin >> wert1;
	std::cin >> rechenart;
	std::cin >> wert2;
	std::cin >> rechenzeichen;

	// Char to Bool um Term mit % zu erkennen
	if (rechenzeichen == '%') {
		prozent = true;

		// Berechnung des Prozentterms und Ausgabe
		ergebnis = wert1 / 100 * wert2;
		std::cout << "=\n";
		std::cout << ergebnis << "\n";
		std::cout << "\n";
	}
	if (rechenzeichen == '=') {
		prozent = false;

		// Berechnung der Grundrechenarten und Ausgabe
		switch (rechenart) {
		case '+':
			// Addition
			ergebnis = wert1 + wert2;
			std::cout << ergebnis << "\n";
			std::cout << "\n";
			break;
		case '-':
			// Subrtaktion
			ergebnis = wert1 - wert2;
			std::cout << ergebnis << "\n";
			std::cout << "\n";
			break;
		case '*':
		case 'x':
		case 'X':
			// Multiplikation
			ergebnis = wert1 * wert2;
			std::cout << ergebnis << "\n";
			std::cout << "\n";
			break;
		case '/':
		case ':':
			// Division
			ergebnis = wert1 / wert2;
			std::cout << ergebnis << "\n";
			std::cout << "\n";
			break;
		}
	}
}


void anleitung() {

	// Konsole leeren
	system("cls");

	std::cout << "*******************************************************************\n";
	std::cout << "*                                                                 *\n";
	std::cout << "*                           Anleitung:                            *\n";
	std::cout << "*                                                                 *\n";
	std::cout << "* 1. Ein normaler Rechenterm wird so ausgefuehrt:                 *\n";
	std::cout << "*    40  Enter                                                    *\n";
	std::cout << "*    +   Enter                                                    *\n";
	std::cout << "*    -2  Enter                                                    *\n";
	std::cout << "*    =   Enter                                                    *\n";
	std::cout << "* 2. Der Rechner verwendet fuer Komma einen Punkt!                *\n";
	std::cout << "* 3. Es koennen Minus-Zahlen in Termen genutzt werden.            *\n";
	std::cout << "* 4. Variable als long double deklariert, deswegen keine Werte    *\n";
	std::cout << "*    mit mehr als 19 Stellen verwenden!                           *\n";
	std::cout << "* 5. Berechnung des Wertes von 40% von 170 wird so ausgefuehrt:   *\n";
	std::cout << "*    170 Enter                                                    *\n";
	std::cout << "*    *   Enter                                                    *\n";
	std::cout << "*    40  Enter                                                    *\n";
	std::cout << "*    %   Enter                                                    *\n";
	std::cout << "*                                                                 *\n";
	std::cout << "*******************************************************************\n";
}


// Hauptprogramm

int main() {

	// Deaktivierung der E-Notation bzw der Scientific Notation
	std::cout << std::setiosflags(std::ios_base::fixed) << std::setprecision(0);

	system("cls");	// Konsole leeren

	std::cout << "*******************************************************************\n";
	std::cout << "*                                                                 *\n";
	std::cout << "*                      Taschenrechner V1.00                       *\n";
	std::cout << "*                           by Oliver                             *\n";
	std::cout << "*                                                                 *\n";
	std::cout << "*******************************************************************\n";

	// Programm wird neu gestartet
	while (true) {

		std::cout << "\n";
		std::cout << "(1) Taschenrechner starten\n";
		std::cout << "(2) Anleitung lesen\n";
		std::cout << "(3) Programm beenden\n";
		std::cout << "\n";
		std::cin >> menue;
		if (std::cin.fail()) {
			std::cerr << "Fehler bei der Eingabe\n";
			return EXIT_FAILURE;
		}

		switch (menue) {
		case 1:
			// Programm starten
			taschenrechner();
			break;
		case 2:
			// Anleitung lesen
			anleitung();
			break;
		case 3:
			// Programm beenden
			return 0;
		default:
			std::cout << "Falsche Eingabe" << std::endl;
		}


	}
}

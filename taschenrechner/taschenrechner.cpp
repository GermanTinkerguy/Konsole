/*
 *
 *  Calculator
 *  Oliver - 2024
 *
 */


#include <iostream>					// In/out Streams
#include <cstdlib>					// Kontrollierte Programmenden
#include <iomanip>					// E-Notation deaktivieren
#include <stdlib.h>					// Konsole leeren


// Variablen

long double wert1 = 0.0, wert2 = 0.0, ergebnis = 0.0;
char rechenart, rechenzeichen;
bool prozent;
char menue;


/***************************************************
 *  Name:        main
 *
 *  Returns:     Nothing.
 *
 *  Parameters:  None.
 *
 *  Description: Main program.
 *
 ***************************************************/
int main(){

	// Deaktivierung der E-Notation bzw der Scientific Notation
	std::cout << std::setiosflags(std::ios_base::fixed) << std::setprecision(0);

	system("cls");	// Konsole leeren

	std::cout << "*******************************************************************\n";
	std::cout << "*                                                                 *\n";
	std::cout << "*                      Taschenrechner V1.00                       *\n";
	std::cout << "*                           by Oliver                             *\n";
	std::cout << "*                                                                 *\n";
	std::cout << "*******************************************************************\n";

	// Dauerschleife
	while (true){

		// Menueausgabe
		std::cout << "\n";
		std::cout << "(T)aschenrechner\n";
		std::cout << "(P)rogramm beenden\n";
		std::cout << "\n";

		// Menueauswahl
		std::cin >> menue;
		switch (menue){
			case 't':
			case 'T':
				// Konsole leeren
				system("cls");

				std::cout << "Rechenterm eingeben:\n";
				std::cout << "\n";

				// Term einlesen
				std::cin >> wert1;
				std::cin >> rechenart;
				std::cin >> wert2;
				std::cin >> rechenzeichen;

				// Falscheingabe
				if (std::cin.fail()) {
					std::cerr << "Fehler bei der Eingabe - Buchstabe\n";
					return EXIT_FAILURE;
				}

				// Char to Bool um Term mit % zu erkennen
				if (rechenzeichen == '%') {
					prozent = true;

					// Berechnung des Prozentterms und Ausgabe
					ergebnis = wert1 / 100 * wert2;
					std::cout << "=\n";
					std::cout << ergebnis << "\n";
					std::cout << "\n";
				}

				// Char to Bool um normalen Rechenterm zu erkennen
				if (rechenzeichen == '='){
					prozent = false;

					// Berechnung der Grundrechenarten
					switch (rechenart){

						// Addition
						case '+':
							ergebnis = wert1 + wert2;
							break;

						// Subrtaktion
						case '-':
							ergebnis = wert1 - wert2;
							break;

						// Multiplikation
						case '*':
						case 'x':
						case 'X':
							ergebnis = wert1 * wert2;
							break;

						// Division
						case '/':
						case ':':
							ergebnis = wert1 / wert2;
							break;
					}

					// Ausgabe des Ergebnisses
					std::cout << ergebnis << "\n";
					std::cout << "\n";
				}
				break;

			// Programm beenden
			case 'p':
			case 'P':
				return 0;
			default:
				std::cout << "Falsche Eingabe - Zahl" << std::endl;
				return EXIT_FAILURE;
		}
	}
}

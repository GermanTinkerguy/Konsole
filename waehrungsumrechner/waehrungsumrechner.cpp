// libraries

#include <iostream>			// in/out streams
#include <cstdlib>			// controlled closing
#include <conio.h>			// used for _getch() command
#include <windows.h>		// used for buffer clear
#include <stdlib.h>			// clear console command
#include <iomanip>			// E-Notation deaktivieren


// function

void warten() {

	// clear buffer
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));

	//  read next button click
	_getch();
}


// main program

int main() {

	// deactivate e-notation or scientific notation
	std::cout << std::setiosflags(std::ios_base::fixed) << std::setprecision(0);

	// infinite loop
	while (1) {

		// variables
		long double betrag = 0.0, ergebnis = 0.0;
		int waehrung = 0;

		// currency converter values
		long double eurinrsd = 117.16;
		long double rsdineur = 0.0085;
		long double eurinusd = 1.08;
		long double usdineur = 0.93;

		// input
		std::cout << "Achtung: Punkt statt Komma!\n";
		std::cout << "\n";
		std::cout << "Bitte Geldbetrag eingeben: ";
		std::cin >> betrag;

		// if wrong input, console closes
		if (betrag <= 0) {
			system("cls");	// clear console
			std::cerr << "Fehler bei der Eingabe - Negativwert oder Null\n";
			return EXIT_FAILURE;	// close program
		}
		if (std::cin.fail()) {
			system("cls");	// clear console
			std::cerr << "Fehler bei der Eingabe - Buchstabe\n";
			return EXIT_FAILURE;	// close program
		}

		std::cout << "\n";
		std::cout << "     Waehrung   Umrechnungskurs\n";
		std::cout << "\n";
		std::cout << "(1) EUR -> RSD    117.16\n";
		std::cout << "(2) RSD -> EUR      0.0085\n";
		std::cout << "(3) EUR -> USD      1.08\n";
		std::cout << "(4) USD -> EUR      0.93\n";
		std::cout << "\n";
		std::cout << "Umrechner: ";
		std::cin >> waehrung;

		// if wrong input, console closes
		if (betrag <= 0) {
			system("cls");	// clear console
			std::cerr << "Fehler bei der Eingabe - Negativwert oder Null\n";
			return EXIT_FAILURE;	// close program
		}
		if (std::cin.fail()) {
			system("cls");	// clear console
			std::cerr << "Fehler bei der Eingabe - Buchstabe\n";
			return EXIT_FAILURE;	// close program
		}

		// calculation and display
		switch (waehrung) {
		case 1:
			ergebnis = betrag * eurinrsd;
			std::cout << "\n";
			std::cout << betrag << " EUR sind umgerechnet " << ergebnis << " RSD\n";
			break;
		case 2:
			ergebnis = betrag * rsdineur;
			std::cout << "\n";
			std::cout << betrag << " RSD sind umgerechnet " << ergebnis << " EUR\n";
			break;
		case 3:
			ergebnis = betrag * eurinusd;
			std::cout << "\n";
			std::cout << betrag << " USD sind umgerechnet " << ergebnis << " USD\n";
			break;
		case 4:
			ergebnis = betrag * usdineur;
			std::cout << "\n";
			std::cout << betrag << " USD sind umgerechnet " << ergebnis << " EUR\n";
			break;
		}

		std::cout << "\n";
		std::cout << "\n";
		std::cout << "Weiter mit Enter";
		warten();

		// clear console
		system("cls");

	}

	// instead of a "return EXIT_SUCCESS;", to prevent an prematurely closing of the console.
	// needs the <iostream> library!
	int r;
	std::cin >> r;

	// closes with 0 faults
	return 0;
}

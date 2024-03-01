/*
 *
 *  Currency Converter
 *  Oliver - 2024
 *
 */


#include <iostream>			// in/out streams
#include <cstdlib>			// controlled closing
#include <conio.h>			// used for _getch() command
#include <windows.h>		// used for buffer clear
#include <stdlib.h>			// clear console command
#include <iomanip>			// E-Notation deaktivieren


 /***************************************************
  *  Name:        wait
  *
  *  Returns:     Nothing.
  *
  *  Parameters:  None.
  *
  *  Description: Wait for input.
  *
  ***************************************************/
void wait() {

	// clear buffer
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));

	//  read next button click
	_getch();
}


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
int main() {

	// deactivate e-notation or scientific notation
	std::cout << std::setiosflags(std::ios_base::fixed) << std::setprecision(0);

	// infinite loop
	while (1) {

		// variables
		long double value = 0.0, result = 0.0;
		int currency = 0;

		// currency converter values
		long double eurinrsd = 117.16;
		long double rsdineur = 0.0085;
		long double eurinusd = 1.08;
		long double usdineur = 0.93;

		// input
		std::cout << "Achtung: Punkt statt Komma!\n";
		std::cout << "\n";
		std::cout << "Bitte Geldbetrag eingeben: ";
		std::cin >> value;

		// if wrong input, console closes
		if (value <= 0) {
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
		std::cin >> currency;

		// if wrong input, console closes
		if (std::cin.fail() || value <= 0) {
			system("cls");	// clear console
			std::cerr << "Fehler bei der Eingabe\n";
			return EXIT_FAILURE;	// close program
		}

		// calculation and display
		switch (currency) {
		case 1:
			result = value * eurinrsd;
			std::cout << "\n";
			std::cout << value << " EUR sind umgerechnet " << result << " RSD\n";
			break;
		case 2:
			result = value * rsdineur;
			std::cout << "\n";
			std::cout << value << " RSD sind umgerechnet " << result << " EUR\n";
			break;
		case 3:
			result = value * eurinusd;
			std::cout << "\n";
			std::cout << value << " USD sind umgerechnet " << result << " USD\n";
			break;
		case 4:
			result = value * usdineur;
			std::cout << "\n";
			std::cout << value << " USD sind umgerechnet " << result << " EUR\n";
			break;
		}

		std::cout << "\n";
		std::cout << "\n";
		std::cout << "Weiter mit Enter";
		wait();

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

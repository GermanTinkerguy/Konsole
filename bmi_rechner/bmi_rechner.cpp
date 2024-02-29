// libraries

#include <iostream>			// in/out streams
#include <cstdlib>			// controlled closing
#include <conio.h>			// used for _getch() command
#include <windows.h>		// used for buffer clear
#include <stdlib.h>			// clear console command


// function

void warten() {

	// clear buffer
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));

	//  read next button click
	_getch();
}


// main program

int main() {

	// infinite loop
	while (1) {

		// variables
		double groesse = 0.0, gewicht = 0.0, bmi = 0.0;

		// input data
		std::cout << "BMI Rechner (Maenner)\n";
		std::cout << "\n";
		std::cout << "Achtung: Bitte Punkt statt Komma!\n";
		std::cout << "Geben sie Ihre Groesse in m ein: ";
		std::cin >> groesse;
		std::cout << "Geben sie Ihr Gewicht in kg ein: ";
		std::cin >> gewicht;

		// error message, if input fails
		if (std::cin.fail()) {
			std::cerr << "Fehler bei Eingabe - Buchstabe\n";
			return EXIT_FAILURE;
		}
		if ( groesse <= 0 || gewicht <=0 ) {
			std::cerr << "Fehler bei Eingabe - Falscher Zahlenwert\n";
			return EXIT_FAILURE;
		}

		// calculation
		bmi = gewicht / (groesse * groesse);

		// output result
		std::cout << "\n";
		std::cout << "Ihr BMI Wert:" << "\n";
		std::cout << bmi << "\n";
		std::cout << "\n";

		// output of personal tabel for men
		if (18.5 > bmi) {
			std::cout << " unter 18.5  " << " Untergewicht" << "\n";
		}
		if (18.5 <= bmi && bmi <= 25) {
			std::cout << "18.5 - 25    " << " Normalgewicht" << "\n";
		}
		if (25 <= bmi && bmi <= 30) {
			std::cout << "  25 - 30    " << " Uebergewicht" << "\n";
		}
		if (30 <= bmi && bmi <= 35) {
			std::cout << "  30 - 35    " << " Adipositas Grad I" << "\n";
		}
		if (35 <= bmi && bmi <= 40) {
			std::cout << "  35 - 40    " << " Adipositas Grad II" << "\n";
		}
		if (bmi > 40) {
			std::cout << "  40 und mehr" << " Adipositas Grad III" << "\n";
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

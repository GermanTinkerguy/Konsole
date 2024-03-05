/*
 *
 *  BMI Calculator
 *  Oliver - 2024
 *
 */


#include <iostream>			// in/out streams
#include <cstdlib>			// controlled closing
#include <conio.h>			// used for _getch() command
#include <windows.h>		// used for buffer clear
#include <stdlib.h>			// clear console command
#include <iomanip>			// deactivate e-notation


 /***************************************************
  *  Name:        showHeader
  *
  *  Returns:     Nothing.
  *
  *  Parameters:  None.
  *
  *  Description: Wait for input.
  *
  ***************************************************/
void showHeader(const std::string& text) {
	for (int i = 0; i < text.size(); i++) {
		std::cout << "#";
	}
	std::cout << "\n" << text << "\n";
	for (int i = 0; i < text.size(); i++) {
		std::cout << "#";
	}
	std::cout << "\n";
}


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

	// infinite loop
	while (1) {

		// variables
		double height = 0.0, weight = 0.0, bmi = 0.0;

		// show header
		showHeader("BMI Rechner (M\204nner)");

		// input data
		std::cout << "Achtung:\nPunkt statt Komma!\n";
		std::cout << "\n";
		std::cout << "Gr\224sse in m:  ";
		std::cin >> height;
		std::cout << "Gewicht in kg: ";
		std::cin >> weight;

		// error message, if input fails - letters instead of numbers or signed numbers or zero
		if (std::cin.fail() || height <= 0 || weight <= 0) {
			std::cerr << "Fehler bei Eingabe\n";
			return EXIT_FAILURE;
		}

		// calculation
		bmi = weight / (height * height);

		// deactivate e-notation or also called scientific notation
		std::cout << std::setiosflags(std::ios_base::fixed) << std::setprecision(0);

		// output result
		std::cout << "\n";
		std::cout << "Ihr BMI Wert:" << "\n";
		std::cout << bmi << "\n";
		std::cout << "\n";

		// output of personal tabel for men
		if (18.5 > bmi) {
			std::cout << " unter 18.5    Untergewicht\n";
		}
		if (18.5 <= bmi && bmi <= 25) {
			std::cout << "18.5 - 25      Normalgewicht\n";
		}
		if (25 <= bmi && bmi <= 30) {
			std::cout << "  25 - 30      \232bergewicht\n";
		}
		if (30 <= bmi && bmi <= 35) {
			std::cout << "  30 - 35      Adipositas Grad I\n";
		}
		if (35 <= bmi && bmi <= 40) {
			std::cout << "  35 - 40      Adipositas Grad II\n";
		}
		if (bmi > 40) {
			std::cout << "  40 und mehr  Adipositas Grad III\n";
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

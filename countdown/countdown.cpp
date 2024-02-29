// libraries

#include <iostream>					// i/o streams
//#include <cstdlib>				// works without too...
#include <windows.h>				// sleep function


// main program

int main() {

	// variables
	int timer;
	bool repeat = true;

	// input
	std::cin >> timer;

	// wrong input, cin.fail must be first! if together the failure is not seperated
	if ( std::cin.fail() ) {
		std::cerr << "Fehler bei der Eingabe - Buchstabe";
		return EXIT_FAILURE;
	}
	if (timer <= 0) {
		std::cerr << "Fehler bei der Eingabe - Negativer Wert oder Null";
		return EXIT_FAILURE;
	}

	// loop until repeat will be false
	while (repeat){

		// countdown program
		if ( timer > 0 ) {												// as long as timer is not 0
			if ( timer < 10 ) {											// the part where you get "09" instead of "9"
				std::cout << "0" << timer << " Sekunden" << "\n";
			}
			else {
				std::cout << timer << " Sekunden" << "\n";
			}
			Sleep ( 1000 );												// 1000 ms delay 
			timer = timer--;											// timer -1
		}
		else {															// if the countdown is over
			std::cout << "Fertig\n";
			repeat = false;												// change the loop to false
		}
	}
	return 0;															// normal program ending with 0 failures
}

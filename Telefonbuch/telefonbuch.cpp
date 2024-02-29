// Bibliotheken

#include <fstream>							// Bib für externe Datei 
#include <iostream>							// Bib für In/Out Befehle
#include <cstdlib>							// Bib für Fehlermeldung
#include <string>							// Bib für Strings


// Variablen und Arrays

int menue;
int deleteid;

struct Liste {
	int id;
	std::string vorname;
	std::string nachname;
	std::string telefon;
};


// Datei erstellen

const auto filename = "buch.txt";


// Beispielwerte die später entfernt werden

Liste Kontakt{ 1, "Max", "Mustermann", "012345" };								


// Funktionen

void neuerKontakt() {
	// Werte einlesen
	std::cout << "\n";
	std::cout << "ID:       ";
	std::cin >> Kontakt.id;
	std::cout << "Vorname:  ";
	std::cin >> Kontakt.vorname;
	std::cout << "Nachname: ";
	std::cin >> Kontakt.nachname;
	std::cout << "Telefon:  ";
	std::cin >> Kontakt.telefon;

	// Werte in Datei speichern
	std::ofstream ofile(filename);
	ofile << Kontakt.id << " " << Kontakt.vorname << " " << Kontakt.nachname << " " << Kontakt.telefon << "\n";
	std::cout << "Gespeichert in: " << filename << "\n";
	ofile.close();
}

void Kontaktdetails() {
	std::cout << "Kontaktdetails";
}

void Kontaktsuche() {
	std::cout << "Kontakt suchen";
}

void Kontaktliste() {
	std::cout << Kontakt.id << " " << Kontakt.vorname << " " << Kontakt.nachname << " " << Kontakt.telefon << "\n";
}

void Kontaktloeschen() {
	std::cout << "Gib die ID des zu loeschenden Kontakts an:\n";
	std::cin >> deleteid;
	std::cout << "Kontakt mit der ID " << deleteid << " geloescht...\n";
	std::cout << "\n";
	std::cout << "\n";
	std::cout << "...NICHT! HAHAHAHA!\n";
}


// Hauptprogramm

int main() {
	// Standardtitel
	std::cout << "Projekt Alpha V1.00\n";
	std::cout << "by Oliver\n";
	std::cout << "\n";

	// Programm wird neu gestartet
	while(true) {

		// Menü anzeigen
		std::cout << "\n";
		std::cout << "(1) Neuer Kontakt\n";
		std::cout << "(2) Kontaktdetails\n";
		std::cout << "(3) Kontaktliste anzeigen\n";
		std::cout << "(4) Kontakt suchen\n";
		std::cout << "(5) Kontakt loeschen\n";
		std::cout << "(6) Programm beenden\n";
		std::cout << "\n";

		// Menü auswählen
		std::cout << "Was moechtest du tun? \n";
		std::cin >> menue;

		//  Menüauswahl
		switch(menue) {
			case 1:
				// Neuer Kontakt
				neuerKontakt();
				break;
			case 2:
				// Kontaktdetails
				Kontaktdetails();
				break;
			case 3:
				// Kontaktliste anzeigen
				Kontaktliste();
				break;
			case 4:
				// Kontakt suchen
				Kontaktsuche();
				break;
			case 5:
				// Kontakt löschen
				Kontaktloeschen();
				break;
			case 6:
				// Programm beenden
				return 0;
			default:																// Wenn eine Zahl eingegeben wird die es nicht gibt, kontrolliertes Programmende
				std::cout << "Falsche Eingabe" << std::endl;
		}
	}
}

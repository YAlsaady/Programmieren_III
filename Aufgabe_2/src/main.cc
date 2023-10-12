/**
 * @file main.cc
 * @authors Yaman Alsaady, Oliver Schmidt
 * @brief Hauptprogramm fuer Lagerverwaltung.
 * @version 0.1
 * @date 2023-10-04
 * 
 * Dieses Programm dient zur Verwaltung von Lagerbestaenden verschiedener Produkte.
 * Es erstellt Produkte unterschiedlicher Typen und zeigt Informationen zu ihnen an.
 * 
 * @copyright Copyright (c) 2023
 *
 */

#include "lager.hh"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

/**
 * @brief Zeigt Informationen zu einem Artikel an.
 * 
 * @param produkt Der Artikel, dessen Informationen angezeigt werden sollen.
 */
void printInfo(Artikel produkt);
/**
 * @brief Zeigt Informationen zu einem Schuettgut an.
 * 
 * @param produkt Das Schuettgut, dessen Informationen angezeigt werden sollen.
 */
void printInfo(Schuettgut produkt);
void printInfo(Fluessigkeit produkt);

// Warengruppen g;
// Warengruppen Artikel::gruppe = g;

int main() {
  // Initialisieren der Warengruppen
  Warengruppen gruppe;
  gruppe.defaultList();
  gruppe.addGruppe("4100", "etwas");
  gruppe.changeGruppe("4370", "Nicht Kaffee");

  // Zuweisen der Warengruppen zu den Artikeln
  Artikel::gruppe = gruppe;
  // Artikel::setGruppe(gruppe);

    string filename("waren.txt");


    ifstream input_file(filename);
    if (!input_file.is_open()) {
        cerr << "Could not open the file - '" << filename << "'" << endl;
        return EXIT_FAILURE;
    }
    input_file.close();

    string line;

    while (std::getline(input_file, line)) {
     std::cout << line << '\n';
    }  
    input_file.close();

  return 0;
}

// Weitere Funktionen printInfo(Artikel) und printInfo(Schuettgut) sind ebenfalls vorhanden.
void printInfo(Artikel produkt) {
  cout << "Name:\t\t" << produkt.getName() << endl;
  cout << "Artikelnummer:\t" << produkt.getArtikelnummer() << endl;
  //cout << "Masseinheit:\t" << produkt.getMasseinheit() << endl;
  cout << "Lagerbestand:\t" << produkt.getLagerabstand() << " " << produkt.getMasseinheit() << endl;
  cout << "Normpreis:\t" << produkt.getNormpreis() << " Euro" << endl;
  cout << "Verkaufpreis:\t" << produkt.getVerkaufpreis() << " Euro"  << endl;
  cout << "Gruppe:\t\t" << produkt.getGruppe() << endl;
  cout << endl;
}

void printInfo(Schuettgut produkt) {
  cout << "Name:\t\t" << produkt.getName() << endl;
  cout << "Artikelnummer:\t" << produkt.getArtikelnummer() << endl;
  // cout << "Masseinheit:\t" << produkt.getMasseinheit() << endl;
  cout << "Lagerbestand:\t" << produkt.getLagerabstand() << endl;
  cout << "Normpreis:\t" << produkt.getNormpreis() << " Euro"  << endl;
  cout << "Verkaufpreis:\t" << produkt.getVerkaufpreis() << " Euro"  << endl;
  cout << "Gruppe:\t\t" << produkt.getGruppe() << endl;
  cout << "Losgroesse:\t" << produkt.getLosgroesse() << " "<< produkt.getMasseinheit() << endl;
  cout << endl;
}

void printInfo(Fluessigkeit produkt) {
  cout << "Name:\t\t" << produkt.getName() << endl;
  cout << "Artikelnummer:\t" << produkt.getArtikelnummer() << endl;
  // cout << "Masseinheit:\t" << produkt.getMasseinheit() << endl;
  cout << "Lagerbestand:\t" << produkt.getLagerabstand() << endl;
  cout << "Normpreis:\t" << produkt.getNormpreis() << " Euro"  << endl;
  cout << "Verkaufpreis:\t" << produkt.getVerkaufpreis() << " Euro"  << endl;
  cout << "Gruppe:\t\t" << produkt.getGruppe() << endl;
  cout << "Volumen:\t" << produkt.getVolume() << " "<< produkt.getMasseinheit() << endl;
  cout << endl;
}

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

  Schuettgut produkt1("Zwiebeln, rot", "4000010000", 1, 1.26, 2343);
  Schuettgut produkt2("Champignons", "4100028070", 0.2, 9.95, 300);
  Schuettgut produkt3("Cafe Crema Slow Roast", "4370060991", 1, 14.99, 536);
  Schuettgut produkt4("Cafe Crema Slow Roast", "4370060992", 0.5, 15.96, 305);
  Stueckgut produkt5("Kinderfahrrad Little Wheels", "1005002100", 129, 7);
  Stueckgut produkt6("Gurke", "4106633223", 0.79, 655);
  Fluessigkeit produkt7("Beutlin's Bio-Milch", "5031440120", 1, 1.15);
  Fluessigkeit produkt8("Wheatly Weizengetraenk", "5500648201", 1, 1.29, 95);
  // Setzen der Losgroessen fuer bestimmte Produkte
  produkt8.setVolume(2.5);
  produkt1.setLosgroesse(0.5);
  // Informationen zu den Produkten anzeige
  printInfo(produkt1);
  printInfo(produkt2);
  printInfo(produkt3);
  printInfo(produkt4);
  printInfo(produkt5);
  printInfo(produkt6);
  printInfo(produkt7);
  printInfo(produkt8);
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

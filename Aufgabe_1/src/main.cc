/**
 * @file main.cc
 * @authors Yaman Alsaady, Oliver Schmidt
 * @brief 
 * @version 0.1
 * @date 2023-10-04
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "lager.hh"
#include <iostream>
#include <string>

using namespace std;

void printInfo(Artikel produkt);
void printInfo(Schuettgut produkt);

// Warengruppen g;
// Warengruppen Artikel::gruppe = g;

int main() {
  Warengruppen gruppe;
  gruppe.init();
  gruppe.addGruppe("4100", "etwas");
  gruppe.changeGruppe("4370", "Nicht Kaffee");

  Artikel::gruppe = gruppe;
  // Artikel::setGruppe(gruppe);

  Schuettgut  produkt1("Zwiebeln, rot", "4000010000", 1.26, 1.26, 2343);
  Schuettgut  produkt2("Champignons", "4100028070", 2, 9.95, 300);
  Schuettgut  produkt3("Cafe Crema Slow Roast", "4370060991", 14.99, 14.99, 536);
  Schuettgut  produkt4("Cafe Crema Slow Roast", "4370060992", 7.98, 15.96, 305);
  Stueckgut   produkt5("Kinderfahrrad Little Wheels", "1005002100", 129, 7);
  Stueckgut   produkt6("Gurke", "4106633223", 0.79, 655);
  Fluessigkeit produkt7("Beutlin's Bio-Milch", "5031440120", 1.15);
  Fluessigkeit produkt8("Wheatly Weizengetraenk", "5500648201", 1.29, 95);

  produkt1.setLosgroesse(0.3);
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

void printInfo(Artikel produkt) {
  cout << "Name:\t\t" << produkt.getName() << endl;
  cout << "Artikelnummer:\t" << produkt.getArtikelnummer() << endl;
  cout << "Masseinheit:\t" << produkt.getMasseinheit() << endl;
  cout << "Lagerbestand:\t" << produkt.getLagerabstand() << endl;
  cout << "Normpreis:\t" << produkt.getNormpreis() << endl;
  cout << "Verkaufpreis:\t" << produkt.getVerkaufpreis() << endl;
  cout << "Gruppe:\t\t" << produkt.getGruppe() << endl;
  cout << endl;
}

void printInfo(Schuettgut produkt) {
  cout << "Name:\t\t" << produkt.getName() << endl;
  cout << "Artikelnummer:\t" << produkt.getArtikelnummer() << endl;
  cout << "Masseinheit:\t" << produkt.getMasseinheit() << endl;
  cout << "Lagerbestand:\t" << produkt.getLagerabstand() << endl;
  cout << "Normpreis:\t" << produkt.getNormpreis() << endl;
  cout << "Verkaufpreis:\t" << produkt.getVerkaufpreis() << endl;
  cout << "Gruppe:\t\t" << produkt.getGruppe() << endl;
  cout << "Losgroeße:\t" << produkt.getLosgroesse() << endl;
  cout << endl;
}

/**
 * @file main.cc
 * @authors Yaman Alsaady, Oliver Schmidt
 * @brief Implementierung des Lagerverwaltungssystems.
 * @version 0.2
 * @date 2023-10-19
 *
 * Dieses Programm implementiert ein Lagerverwaltungssystem, das es ermoeglicht,
 * Artikelinformationen aus Dateien zu lesen und sie nach Artikeltyp zu
 * gruppieren. Die Informationen werden entweder auf der Konsole ausgegeben oder
 * in eine Ausgabedatei geschrieben. Der Name der Ausgabedatei wird als
 * Befehlszeilenargument uebergeben.

 * @copyright Copyright (c) 2023
 *
 */
#include "kasse.hh"
#include "laden.hh"
#include "lager.hh"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <map>
#include <ostream>
#include <string>
#include <vector>

using namespace std;
#define CLEAR u8"\033[2J\033[1;1H"
int main() {
  char wahl;
  string vorname;
  string name;
  Lager lager;
  vector<Regal> regale;
  lager.readFile("waren.txt");
  Regal gemueseRegal("Gemuese", lager, {40, 41});
  Regal getraenkeRegal("Getrinke", lager, {43, 50, 55});
  Regal sonderRegal("Sonderartikel", lager, 10);
  regale.push_back(gemueseRegal);
  regale.push_back(getraenkeRegal);
  regale.push_back(sonderRegal);
  while (true) {
  cout << CLEAR;
  cout << "Wählen Sie aus!" << endl;
  cout << setw(20) << left << "\tEinkaufen: "
       << "n" << endl;
  cout << setw(20) << left << "\tFeierabend: "
       << "q" << endl;
  cout << "\nAuswahl:";
    cin >> wahl;
    if (wahl == 'q') {
      break;
    }
    if (wahl == 'n') {
      cout << "Geben Ihre Name!" << endl;
      cin >> vorname;
      cin >> name;
      Kunde kunde(vorname + string(" ") + name, regale);
      kunde.kundeUI();
      cout << CLEAR;
      // Kasse kasse(kunde, lager);
      // kasse.rechnung(cout);
    } else {
      break;
    }
  }

  return 0;
}

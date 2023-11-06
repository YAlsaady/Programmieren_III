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
int main()
{
  Lager lager;
  vector<Regal> regale;
  lager.readFile("waren.txt");
  // lager.write(cout);
  // cout << lager.getArtikel("1005002100") << endl;
  Regal gemueseRegal("Gemuese", lager, {40, 41});
  Regal getraenkeRegal("Getrinke", lager, {43, 50, 55});
  Regal sonderRegal("Sonderartikel", lager, 10);
  regale.push_back(gemueseRegal);
  regale.push_back(getraenkeRegal);
  regale.push_back(sonderRegal);
  Kunde kunde(regale);
  kunde.kundeUI();

  return 0;
}

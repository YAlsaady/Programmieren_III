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

void printInfo(Schuettgut produkt);
void printInfo(Fluessigkeit produkt);

int main(int argc, char argv) {
  
  Warengruppen gruppe;
  string line;  

  string filename_input("eingang.txt");
  string filename_output("ausgang.txt");
  
  gruppe.defaultList();
  gruppe.addGruppe("4100", "etwas");
  gruppe.changeGruppe("4370", "Nicht Kaffee");

  Artikel::gruppe = gruppe;
    
    ifstream file_input(filename_input);    
    if (!file_input) {
      cerr << "Die Datei '" << filename_input << "' konnte nicht geoeffnet werden" << endl;
      return -1;
    }

    while (getline(file_input, line)) {
     cout << line << '\n';
    }
    file_input.close();


  return 0;
}

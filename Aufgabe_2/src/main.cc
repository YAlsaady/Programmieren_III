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
#include <sstream>


using namespace std;

void printInfo(Schuettgut produkt);
void printInfo(Fluessigkeit produkt);

//int argc, char *argv[]
int main() {

  
  Warengruppen gruppe;
  string line; 
  vector<vector<string>> productMatrix;

  string filename_input("eingang.txt");
  string filename_output("ausgang.txt");
  
  gruppe.defaultList();
  gruppe.addGruppe("4100", "etwas");
  gruppe.changeGruppe("4370", "Nicht Kaffee");

  Artikel::gruppe = gruppe;
    
  ifstream file_input(filename_input);    
  if (!file_input.is_open()) {
    cerr << "Die Datei '" << filename_input << "' konnte nicht geoeffnet werden" << endl;
    return -1;
  }


  Artikel produkt;
  while (!file_input.eof()) {
    int error = 0;

    try {
      file_input >> produkt;
    }

    catch (invalid_argument &e) {
    error = -1;
    } 

    catch (int &e) {
      error = -1;
    }
    
    if (!error){
     cout << produkt <<endl;
    }
  }
  file_input.close();
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
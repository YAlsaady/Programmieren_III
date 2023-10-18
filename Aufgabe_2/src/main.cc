/**
 * @file main.cc
 * @authors Yaman Alsaady, Oliver Schmidt
 * @brief Hauptprogramm fuer Lagerverwaltung.
 * @version 0.1
 * @date 2023-10-04
 *
 * Dieses Programm dient zur Verwaltung von Lagerbestaenden verschiedener
 * Produkte. Es erstellt Produkte unterschiedlicher Typen und zeigt
 * Informationen zu ihnen an.
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "lager.hh"
#include <cstddef>
#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

void printInfo(Schuettgut produkt);
void printInfo(Fluessigkeit produkt);
void read(string filename);
void readwrite(string, string);

int main(int argc, char *argv[]) {

  Warengruppen gruppe;
  string line;
  vector<vector<string>> productMatrix;

  vector<string> name_input;
  vector<string> name_output;
  Artikel::gruppe = gruppe;
  read("eingang.txt");
  readwrite("eingang.txt", "ausgabe.txt");
  int i = 0;
  int err = 0;
  ifstream file_input;
  ofstream file_output;
  /*
  if (argc == 1) {
    return -1;
  }
  for (i = 1; i < argc; i++) {
    if (string(argv[i]) == "-i") {
      name_input[i] = argv[i + 1];
    }
    if (string(argv[i]) == "-o") {
      name_output[i] = argv[i + 1];
    }
    ifstream file_input(name_input[i]);
    ofstream file_output(name_output[i]);
    if (!file_input.is_open()) {
      cerr << "Die Datei '" << name_input[i]
           << "' konnte nicht geoeffnet werden" << endl;
      err += 1;
    }
    if (!file_output.is_open()) {
      cerr << "Die Datei '" << name_output[i]
           << "' konnte nicht geoeffnet werden" << endl;
      err += 1;
    }
  }

  if (!err) {
    return -1;
  }
  for (size_t i = 0; i < name_input.size(); i++) {

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

      if (!error) {
        file_output << produkt << endl;
      }
    }
  }
  */
  return 0;
}
void read(string filename) {
  ifstream file_input(filename);
  vector<Artikel> produkt;
  Artikel tmp;
  if (!file_input.is_open()) {
    cerr << "Die Datei '" << filename << "' konnte nicht geoeffnet werden"
         << endl;
    exit(EXIT_FAILURE);
  }
  while (!file_input.eof()) {
    bool error = false;
    try {
      file_input >> tmp;
    } catch (invalid_argument &e) {
      error = true;
    } catch (int &e) {
      error = true;
    }
    if (!error) {
      produkt.push_back(tmp);
    }
  }
  if (produkt.size() == 0)
    return;
  for (size_t i = 0; i < produkt.size(); i++) {
    cout << produkt[i] << endl;
  }
  file_input.close();
}

void readwrite(string filename, string filewirte) {
  ifstream file_input(filename);
  ofstream file_output(filewirte);
  vector<Artikel> produkt;
  Artikel tmp;
  if (!file_input.is_open()) {
    cerr << "Die Datei '" << filename << "' konnte nicht geoeffnet werden"
         << endl;
    exit(EXIT_FAILURE);
  }
  if (!file_output.is_open()) {
    cerr << "Die Datei '" << filewirte << "' konnte nicht geoeffnet werden"
         << endl;
    exit(EXIT_FAILURE);
  }
  while (!file_input.eof()) {
    bool error = false;
    try {
      file_input >> tmp;
    } catch (invalid_argument &e) {
      error = true;
    } catch (int &e) {
      error = true;
    }
    if (!error) {
      produkt.push_back(tmp);
    }
  }
  if (produkt.size() == 0)
    return;
  for (size_t i = 0; i < produkt.size(); i++) {
    file_output << produkt[i] << endl;
  }
}
// Weitere Funktionen printInfo(Artikel) und printInfo(Schuettgut) sind
// ebenfalls vorhanden.
void printInfo(Artikel produkt) {
  cout << "Name:\t\t" << produkt.getName() << endl;
  cout << "Artikelnummer:\t" << produkt.getArtikelnummer() << endl;
  // cout << "Masseinheit:\t" << produkt.getMasseinheit() << endl;
  cout << "Lagerbestand:\t" << produkt.getLagerabstand() << " "
       << produkt.getMasseinheit() << endl;
  cout << "Normpreis:\t" << produkt.getNormpreis() << " Euro" << endl;
  cout << "Verkaufpreis:\t" << produkt.getVerkaufpreis() << " Euro" << endl;
  cout << "Gruppe:\t\t" << produkt.getGruppe() << endl;
  cout << endl;
}

void printInfo(Schuettgut produkt) {
  cout << "Name:\t\t" << produkt.getName() << endl;
  cout << "Artikelnummer:\t" << produkt.getArtikelnummer() << endl;
  // cout << "Masseinheit:\t" << produkt.getMasseinheit() << endl;
  cout << "Lagerbestand:\t" << produkt.getLagerabstand() << endl;
  cout << "Normpreis:\t" << produkt.getNormpreis() << " Euro" << endl;
  cout << "Verkaufpreis:\t" << produkt.getVerkaufpreis() << " Euro" << endl;
  cout << "Gruppe:\t\t" << produkt.getGruppe() << endl;
  cout << "Losgroesse:\t" << produkt.getLosgroesse() << " "
       << produkt.getMasseinheit() << endl;
  cout << endl;
}

void printInfo(Fluessigkeit produkt) {
  cout << "Name:\t\t" << produkt.getName() << endl;
  cout << "Artikelnummer:\t" << produkt.getArtikelnummer() << endl;
  // cout << "Masseinheit:\t" << produkt.getMasseinheit() << endl;
  cout << "Lagerbestand:\t" << produkt.getLagerabstand() << endl;
  cout << "Normpreis:\t" << produkt.getNormpreis() << " Euro" << endl;
  cout << "Verkaufpreis:\t" << produkt.getVerkaufpreis() << " Euro" << endl;
  cout << "Gruppe:\t\t" << produkt.getGruppe() << endl;
  cout << "Volumen:\t" << produkt.getVolume() << " " << produkt.getMasseinheit()
       << endl;
  cout << endl;
}
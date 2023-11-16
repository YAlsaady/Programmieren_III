/**
 * @file main.cc
 * @authors Yaman Alsaady, Oliver Schmidt
 * @brief Hauptprogramm für das Lagerverwaltungssystem.
 * @version 0.3
 * @date 2023-11-13
 *
 * Diese Datei dient als Einstiegspunkt für das Lagerverwaltungssystem. Sie
 * liest Befehlszeilenargumente,
 * initialisiert das Lager und die Regale, ermoeglicht dem Benutzer das
 * Einkaufen und fuehrt die entsprechenden Operationen aus.
 *
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

/**
 * @def CLEAR
 * @brief Definition fuer den Befehl zum Loeschen des Konsolenbildschirms.
 */
#define CLEAR u8"\033[2J\033[1;1H"

/**
 * @brief Hauptfunktion des Programms.
 *
 * Diese Funktion dient als Einstiegspunkt fuer das Lagerverwaltungssystem. Sie
 * liest Befehlszeilenargumente, initialisiert das Lager und die Regale,
 * ermoeglicht dem Benutzer das Einkaufen und fuehrt die entsprechenden
 * Operationen aus.
 *
 * @param argc Die Anzahl der Befehlszeilenargumente.
 * @param argv Ein Array von Zeichenketten, das die Befehlszeilenargumente
 * enthaelt.
 * @return Eine Ganzzahl, die den Programmstatus zurueckgibt (0 fuer Erfolg,
 * andere Werte fuer Fehler).
 */
int main(int argc, char *argv[]) {
  string filewrite = "";
  string fileread = "";
  char wahl;
  string vorname;
  string name;
  Lager lager;
  vector<Regal> regale;
  for (int i = 1; i < argc; i++) {
    string arg = argv[i];
    if (arg == "-o") {
      filewrite = argv[i + 1];
    } else if (string(argv[i]) == "-i") {
      fileread = argv[i + 1];
    }
  }

  if (fileread == "") {
    exit(EXIT_FAILURE);
  }

  // Lager aus der Eingabedatei lesen
  lager.readFile(fileread);

  // Regale initialisieren
  Regal gemueseRegal(R"(Gemuese)", lager, {40, 41});
  Regal getraenkeRegal("Getraenke", lager, {43, 50, 55});
  Regal sonderRegal("Sonderartikel", lager, 10);

  regale.push_back(gemueseRegal);
  regale.push_back(getraenkeRegal);
  regale.push_back(sonderRegal);

  // Hauptbenutzerschleife
  while (true) {
    cout << CLEAR;
    cout << "Waehlen Sie aus!" << endl;
    cout << setw(20) << left << "\tEinkaufen: "
         << "n" << endl;
    cout << setw(20) << left << "\tFeierabend: "
         << "q" << endl;
    cout << "\nAuswahl:";
    cin >> wahl;

    // Programm beenden, wenn 'q' ausgewaehlt wird
    if (wahl == 'q') {
      break;
    }

    // Einkaufen starten, wenn 'n' ausgewaehlt wird
    if (wahl == 'n') {
      cout << "Geben Ihre Name!" << endl;
      cin >> vorname;
      cin >> name;
      Kunde kunde(vorname + string(" ") + name, regale);
      kunde.kundeUI();
      cout << CLEAR;
    } else {
      break;
    }

    // Lager aktualisieren und speichern
    if (filewrite == "") {
      lager.write("");
    } else {
      lager.write(filewrite);
    }
  }

  return 0;
}

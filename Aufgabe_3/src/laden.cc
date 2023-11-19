/**
 * @file laden.hh
 * @authors Yaman Alsaady, Oliver Schmidt
 * @brief Enthaelt die Deklaration der Klasse Regal und der Klasse Kunde.
 * @version 0.3
 * @date 2023-11-13
 *
 * Dieses Header-Datei enthaelt die Definitionen von Klassen und Funktionen zur
 * Verwaltung von Regale und Kunden und Warengruppen in einem C++-Programm.
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "laden.hh"
#include "kasse.hh"
#include "lager.hh"
#include <iomanip>
#include <iostream>
#include <string>
#include <unistd.h>
// #include <vector>

using namespace std;
#define CLEAR u8"\033[2J\033[1;1H"

Regal::Regal(string name, Lager &lager, int warengruppe)
    : regalname(name), lager(lager) {
  waren.insert(warengruppe);
}
Regal::Regal(string name, Lager &lager, std::set<int> warengruppen)
    : regalname(name), lager(lager) {
  waren.merge(warengruppen);
}

string Regal::getName() const { return regalname; }
std::set<int> Regal::getWaren() const { return waren; }

Artikel Regal::getArtikel(string num) const { return lager.getArtikel(num); }

vector<string> Regal::getImRegal() const {
  Lager::artikelMap map = lager.getMap();
  vector<string> imRegal;
  for (int ware : waren) {
    Lager::artikelMap::iterator it = map.begin();
    while (it != map.end()) {
      int num = (*it->second).getGruppe();
      num /= 100;
      if (ware == num) {
        imRegal.push_back(it->first);
        // cout << typeid(*it->second).name() << endl;
      }
      it++;
    }
  }
  return imRegal;
}

Lager &Regal::getLager() { return lager; }

ostream &operator<<(ostream &os, Regal regal) {
  vector<string> imRegal = regal.getImRegal();
  int i = 0;
  for (auto num : imRegal) {
    // cout << Lager(regal.lager).getArtikel(num) << endl;
    Artikel artikel = regal.lager.getArtikel(num);
    i++;
    cout << setw(5) << "";
    cout << i << setw(9) << ":" << left;
    cout << setw(30) << artikel.getName();
    cout << setw(20) << artikel.getLagerbestand();
    cout << artikel.getVerkaufpreis() << "/"
         << artikel.getVerkaufpreis() / artikel.getNormpreis() << setw(20)
         << artikel.getStrMasseinheit() << endl;
  }
  return os;
}

Kunde::Kunde(string name, vector<Regal> const &regale)
    : name(name), regale(regale) {}

vector<Kunde::waren> Kunde::getWarenkorb() const { return warenkorb; }

string Kunde::getName() const { return name; }

void Kunde::kundeUI() {
  string wahl;
  size_t wahlNum;
  cout << CLEAR;
  int i = 0;
  cout << "Warenkorb: " << warenkorb.size() << endl;
  cout << "Waehlen Sie einen Regal aus\n" << left << endl;
  cout << setw(2) << "";
  cout << "Wahl" << setw(9) << ":" << left;
  cout << setw(30) << "Bezeichnung" << endl;
  cout << setw(5) << "";
  cout << "0" << setw(9) << ":" << left;

  cout << "Warenkorb" << left;
  cout << endl;
  for (auto regal : regale) {
    i++;
    cout << setw(5) << "";
    cout << i << setw(9) << ":" << left;
    cout << regal.getName() << endl;
  }
  cout << setw(5) << "";
  cout << "q" << setw(9) << ":" << left;

  cout << "Beenden" << left;
  cout << endl;
  cout << endl;
  while (true) {
    cout << "Auswahl: ";
    cin >> wahl;
    if (wahl[0] == 'q')
      return;
    try {
      wahlNum = stoi(wahl);
      if (wahlNum > regale.size()) {
        cout << "Falsche Eingabe!" << endl;
      } else if (wahlNum == 0) {
        printWarenkorb();
        break;
      } else {
        printArtikel(wahlNum - 1);
        break;
      }
    } catch (const std::exception &) {
      cout << "Falsche Eingabe!!" << endl;
    }
  }
}

void Kunde::printArtikel(int num) {
  cout << CLEAR;
  string wahl1, wahl2;
  size_t wahl1Num;
  double wahl2num;
  cout << "Warenkorb: " << warenkorb.size() << endl;
  cout << "Waehlen Sie einen Artikel aus\n" << left << endl;
  cout << setw(15) << "";
  cout << setw(30) << "Bezeichnung";
  cout << setw(20) << "Lagerbestand";
  cout << setw(20) << "Preis/Einheit" << endl;

  cout << regale[num];
  cout << setw(5) << "";
  cout << "." << setw(9) << ":" << left;
  cout << "Zurueck" << left;
  cout << endl;
  cout << setw(5) << "";
  cout << "q" << setw(9) << ":" << left;
  cout << "Beenden" << left;
  cout << endl;
  cout << endl;
  while (true) {
    cout << "Auswahl: ";
    cin >> wahl1;
    if (wahl1[0] == 'q') {
      break;
    }
    if (wahl1[0] == '.') {
      kundeUI();
      break;
    }
    try {

      wahl1Num = stoi(wahl1);
      if (wahl1Num > Regal(regale[num]).getImRegal().size()) {
      } else {
        wahl1Num--;
        string artnum = Regal(regale[num]).getImRegal()[wahl1Num];
        Artikel artikel = Regal(regale[num]).getArtikel(artnum);
        cout << artikel.getName() << endl;
        cout << "Geben Sie die Menge" << endl;
        cin >> wahl2;
        wahl2num = stof(wahl2);
        if (wahl2num <= artikel.getLagerbestand()) {
          warenkorb.push_back({artnum, wahl2num});
          cout << CLEAR;
          float menge = warenkorb[warenkorb.size() - 1].menge;
          cout << menge << " * " << artikel.getName() << endl;
          sleep(1);
          printArtikel(num);
          break;
        }
      }
    } catch (const std::exception &) {
    }
    cout << "Falsche Eingabe!" << endl;
  }
}
void Kunde::printWarenkorb() {
  string wahl;
  int i = 0;
  cout << CLEAR;
  cout << "Warenkorb: " << warenkorb.size() << endl;
  cout << "Waehlen Sie aus\n" << left << endl;
  for (auto ware : warenkorb) {
    Artikel artikel = regale[0].getArtikel(ware.artikelnummer);
    i++;
    cout.imbue(locale("de_DE.UTF-8"));
    cout << setw(5) << "";
    cout << i << setw(9) << ":" << left;
    cout << setw(30) << artikel.getName();
    cout << setw(6) << artikel.getVerkaufpreis() << "/" << setw(4)
         << artikel.getVerkaufpreis() / artikel.getNormpreis();
    cout << setw(20) << artikel.getStrMasseinheit();
    cout << setw(20) << ware.menge;
    cout << setw(20) << showbase << (artikel.getNormpreis() * ware.menge)
         << endl;
  }
  cout << setw(5) << "";
  cout << "k" << setw(9) << ":" << left;
  cout << "Kasse" << left;
  cout << endl;
  cout << setw(5) << "";
  cout << "." << setw(9) << ":" << left;
  cout << "Zurueck" << left;
  cout << endl;
  cout << setw(5) << "";
  cout << "q" << setw(9) << ":" << left;
  cout << "Beenden" << left << endl;
  cout << "Auswahl: ";
  while (true) {
    cin >> wahl;
    if (wahl[0] == 'q') {
      break;
    }
    if (wahl[0] == '.') {
      kundeUI();
      break;
    }
    if (wahl[0] == 'k') {
      Kasse kasse(*this, Regal(regale[0]).getLager());
      kasse.rechnung(cout);
      break;
    }
    cout << "Falsche Eingabe!" << endl;
  }
}

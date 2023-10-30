#include "laden.hh"
#include "lager.hh"
#include <iomanip>
#include <string>
#include <unistd.h>
#include <vector>

using namespace std;
#define CLEAR u8"\033[2J\033[1;1H"

Regal::Regal(string name, Lager const &lager, int warengruppe)
    : regalname(name), lager(lager) {
  waren.insert(warengruppe);
}
Regal::Regal(string name, Lager const &lager, std::set<int> warengruppen)
    : regalname(name), lager(lager) {
  waren.merge(warengruppen);
}

string Regal::getName() const { return regalname; }
std::set<int> Regal::getWaren() const { return waren; }

Artikel Regal::getArtikel(string num) const {
  return Lager(lager).getArtikel(num);
}

vector<string> Regal::getImRegal() {
  Lager::artikelMap map = Lager(lager).getMap();
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

ostream &operator<<(ostream &os, Regal regal) {
  vector<string> imRegal = regal.getImRegal();
  int i = 0;
  for (auto num : imRegal) {
    // cout << Lager(regal.lager).getArtikel(num) << endl;
    Artikel artikel = Lager(regal.lager).getArtikel(num);
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

Kunde::Kunde(vector<Regal> const &regale) : regale(regale) {}
void Kunde::kundeUI() {
  printRegale();
  // char wahl;
  // do {
  //   cout << CLEAR;
  //   int i = 0;
  //   cout << "Wählen Sie einen Regal aus\n" << endl;
  //   for (auto regal : regale) {
  //     i++;
  //     cout << i << "   " << regal.getName() << endl;
  //   }
  //   cout << endl;
  //   cout << "Auswahl: ";
  //   cin >> wahl;
  //   switch (wahl) {
  //   case '1':
  //     cout << CLEAR;
  //     cout << "Wählen Sie einen Artikel aus\n" << endl;
  //     cout << regale[0];
  //     cout << "Auswahl: ";
  //     cin >> wahl;
  //     break;
  //   case '2':
  //     cout << regale[1];
  //     break;
  //   case '3':
  //     cout << regale[2];
  //     break;
  //   case 'q':
  //     break;
  //   default:
  //     cout << "Falsche Eingabe" << endl;
  //     break;
  //   }
  // } while (wahl != 'q');
}
void Kunde::printRegale() {
  string wahl;
  size_t wahlNum;
  cout << CLEAR;
  int i = 0;
  cout << "Warenkorb: " << warenkorb.size() << endl;
  cout << "Wählen Sie einen Regal aus\n" << left << endl;
  cout << setw(15) << "";
  cout << setw(30) << "Bezeichnung" << endl;
  for (auto regal : regale) {
    i++;
    cout << setw(5) << "";
    cout << i << setw(9) << ":" << left;
    cout << regal.getName() << endl;
  }
  cout << setw(5) << "";
  cout << "q" << setw(9) << ":" << left;
  cout << "Quit" << left;
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
        cout << "Falsche Eingabe" << endl;
      } else {
        printArtikel(wahlNum - 1);
        break;
      }
    } catch (const std::exception &) {
      cout << "Falsche Eingabe" << endl;
    }
  }
}

void Kunde::printArtikel(int num) {
  cout << CLEAR;
  string wahl1, wahl2;
  size_t wahl1Num;
  double wahl2num;
  cout << "Warenkorb: " << warenkorb.size() << endl;
  cout << "Wählen Sie einen Artikel aus\n" << left << endl;
  cout << setw(15) << "";
  cout << setw(30) << "Bezeichnung";
  cout << setw(20) << "Lagerbestand";
  cout << setw(20) << "Preis/Einheit" << endl;

  cout << regale[num];
  cout << setw(5) << "";
  cout << "." << setw(9) << ":" << left;
  cout << "back" << left;
  cout << endl;
  cout << setw(5) << "";
  cout << "q" << setw(9) << ":" << left;
  cout << "Quit" << left;
  cout << endl;
  cout << endl;
  while (true) {
    cout << "Auswahl: ";
    cin >> wahl1;
    if (wahl1[0] == 'q') {
      break;
    }
    if (wahl1[0] == '.') {
      printRegale();
      break;
    }
    try {
      wahl1Num = stoi(wahl1);
      if (wahl1Num > Regal(regale[num]).getImRegal().size()) {
      } else {
        wahl1Num--;
        cout << Regal(regale[num]).getImRegal()[wahl1Num] << endl;
        cout << "Geben Sie die Menge" << endl;
        cin >> wahl2;
        wahl2num = stof(wahl2);
        if (wahl2num <=
            regale[num]
                .getArtikel(Regal(regale[num]).getImRegal()[wahl1Num])
                .getLagerbestand()) {
          warenkorb.push_back(
              {Regal(regale[num]).getImRegal()[wahl1Num], wahl2num});
          cout << warenkorb[0].menge << " * " << warenkorb[0].artikelnummer
               << endl;
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
  for (auto ware : warenkorb) {
    Artikel a = regale[0].getArtikel(ware.artikelnummer);
    cout << regale[0].getArtikel(ware.artikelnummer) << endl;
  }
}

// template <class OutputIterator>
// void Regal::products(OutputIterator out) const {
//   // for () {
//   // }
//   out = "";
// }

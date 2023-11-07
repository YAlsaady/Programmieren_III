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
  return lager.getArtikel(num);
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

Kunde::Kunde(vector<Regal> const &regale) : regale(regale) {
    name = "kunde Name";    
}
vector<Kunde::waren> Kunde::getWarenkorb() const{
  return warenkorb;
}
string Kunde::getName()const{return name;}
void Kunde::kundeUI() { printRegale(); }
void Kunde::printRegale() {
  string wahl;
  size_t wahlNum;
  cout << CLEAR;
  int i = 0;
  cout << "Warenkorb: " << warenkorb.size() << endl;
  cout << "Wählen Sie einen Regal aus\n" << left << endl;
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
        cout << "Falsche Eingabe" << endl;
      } else if (wahlNum == 0) {
        printWarenkorb();
        break;
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
  cout << "Zurück" << left;
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
      printRegale();
      break;
    }
    try {

      wahl1Num = stoi(wahl1);
      if (wahl1Num > Regal(regale[num]).getImRegal().size()) {
      } else {
        wahl1Num--;
        Artikel artikel =
            Regal(regale[num])
                .getArtikel(Regal(regale[num]).getImRegal()[wahl1Num]);
        cout << artikel.getName() << endl;
        // cout << Regal(regale[num]).getImRegal()[wahl1Num] << endl;
        cout << "Geben Sie die Menge" << endl;
        cin >> wahl2;
        wahl2num = stof(wahl2);
        if (wahl2num <= artikel.getLagerbestand()) {
          warenkorb.push_back(
              {Regal(regale[num]).getImRegal()[wahl1Num], wahl2num});
          cout << CLEAR;
          cout << warenkorb[warenkorb.size() - 1].menge << " * "
               << Regal(regale[num])
                      .getArtikel(warenkorb[warenkorb.size() - 1].artikelnummer)
                      .getName()
               << endl;
          sleep(2);
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
  cout << "Wählen Sie aus\n" << left << endl;
  for (auto ware : warenkorb) {
    Artikel artikel = regale[0].getArtikel(ware.artikelnummer);
    i++;
    cout << setw(5) << "";
    cout << i << setw(9) << ":" << left;
    cout << setw(30) << artikel.getName();
    cout << artikel.getVerkaufpreis() << "/"
         << artikel.getVerkaufpreis() / artikel.getNormpreis() << setw(30)
         << artikel.getStrMasseinheit();
    cout << setw(20) << ware.menge;
    cout << setw(20) << artikel.getVerkaufpreis() * ware.menge << endl;
  }
  cout << setw(5) << "";
  cout << "." << setw(9) << ":" << left;
  cout << "Zurück" << left;
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
      printRegale();
      break;
    }
    cout << "Falsche Eingabe!" << endl;
  }
}

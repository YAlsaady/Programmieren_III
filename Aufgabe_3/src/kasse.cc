
#include "kasse.hh"
#include "laden.hh"
#include "lager.hh"
#include <iomanip>
#include <string>
#include <unistd.h>
#include <vector>

using namespace std;

Kasse::Kasse(Kunde const &kunde, Lager const &lager)
    : kunde(kunde), lager(lager) {}

void Kasse::rechnung(ostream &os) {
  cout << kunde.getName() << endl;
  double sum = 0;
  for (Kunde::waren ware : kunde.getWarenkorb()) {
    Artikel artikel;
    artikel = lager.getArtikel(ware.artikelnummer);
    os << ware.menge << artikel.getStrMasseinheit() << endl;
    os << artikel.getName() << endl;
    os << artikel.getNormpreis() << endl;
    os << artikel.getNormpreis() * ware.menge << endl;
    sum += artikel.getNormpreis() * ware.menge;
  }
  os << sum << "€" << endl;
}
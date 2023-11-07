
#include "kasse.hh"
#include "laden.hh"
#include "lager.hh"
#include <iomanip>
#include <string>
#include <unistd.h>
#include <vector>

using namespace std;

Kasse::Kasse(Kunde const &kunde, Lager const &lager) : kunde(kunde), lager(lager){}

void Kasse::rechnung(ostream &os) {


  for (Kunde::waren ware : kunde.getWarenkorb()) {
    Artikel artikel;
    artikel = lager.getArtikel(ware.artikelnummer);

    os << ware.artikelnummer << endl;



  }
}
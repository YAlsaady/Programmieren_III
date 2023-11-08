#include "laden.hh"
#include "lager.hh"
#include <iomanip>
#include <string>
#include <unistd.h>
#include <vector>

class Kasse {
public:
  Kasse(Kunde const &kunde, Lager const &lager);
  void rechnung(ostream &os);
  void printRechnung(ostream &os, const string &date,
                     const string &rechnungsnummer, bool print_auswahl);

private:
  Kunde const &kunde;
  Lager const &lager;
};

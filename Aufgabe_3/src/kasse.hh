#ifndef KASSE_HH
#define KASSE_HH

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
                     const string &rechnungsnummer, double sum);

private:
  Kunde const &kunde;
  Lager const &lager;
};
#endif // !KASSE_HH

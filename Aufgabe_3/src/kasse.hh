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


private:
  Kunde const &kunde;
  Lager const &lager;
};



#include <iostream>
#include <string>

using namespace std;

class Artikel {
protected:
  string artikelname;
  string nummer;
  unsigned int lagerbestand;
  enum masseinheit{kg, liter, stueck};
  double verkaufpreis;
  double normpreis;

public:
  Artikel(string name, string num, unsigned int bestand,
          masseinheit einheit, double vp, double np);
  ~Artikel();

  // getter
  string getName();
  string getNummer();
  unsigned int getLagerabstand();
  string getMasseinheit();
  double getVerkaufpreis();
  double getNormpreis();

  // setter
  void setName(string name);
  void setNummer(string num);
  void setLagerbestand(unsigned int bestand);
  void setMasseinheit(masseinheit einheit);
  void setVerkaufpreis(double vp);
  void setNorpreis(double np);
};

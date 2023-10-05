#include <iostream>
#include <string>

using namespace std;
enum masseinheit { stk, kg, l };
typedef double preis;

namespace Warengruppen {
void init();
string getGruppe(string code);
void addGruppe(string code, string name);
void delGruppe(string code);
void changeGruppe(string code, string name);
void clear();
} // namespace Warengruppen

class Artikel {
protected:
  string artikelname;
  string artikelnummer;
  unsigned int lagerbestand;
  masseinheit einheit;
  preis verkaufpreis;
  preis normpreis;

public:
  Artikel(string name, string num, unsigned int bestand, masseinheit einheit,
          preis vp, preis np);
  ~Artikel();

  // getter
  string getName();
  string getArtikelnummer();
  unsigned int getLagerabstand();
  string getMasseinheit();
  preis getVerkaufpreis();
  preis getNormpreis();
  string getGruppe();

  // setter
  void setName(string name);
  void setArtikelnummer(string num);
  void setLagerbestand(unsigned int bestand);
  void setMasseinheit(masseinheit einheit);
  void setVerkaufpreis(preis vp);
  void setNormpreis(preis np);
};

class Schuettgut : public Artikel {
private:
  double losgroesse;

public:
  Schuettgut(string name, string num, double groesse, preis np,
             unsigned int bestand = 1);
  double getLosgroesse();
  void setVerkaufpreis(preis vp);
  void setLosgroesse(double groesse);
};

class Stueckgut : public Artikel {
private:
public:
  Stueckgut(string name, string num, preis vp, unsigned int bestand = 1);
};

class Flüßigkeit : public Artikel {
private:
public:
  Flüßigkeit(string name, string num, preis vp, unsigned int bestand = 1);
};

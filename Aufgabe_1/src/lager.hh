#include <iostream>
#include <string>

using namespace std;
enum masseinheit { kg, liter, stueck };

class Artikel {
protected:
  string artikelname;
  string nummer;
  unsigned int lagerbestand;
  masseinheit einheit;
  double verkaufpreis;
  double normpreis;

public:
  Artikel(string name, string num, unsigned int bestand, masseinheit einheit,
          double vp, double np);
  ~Artikel();

  // getter
  string getName();
  string getNummer();
  unsigned int getLagerabstand();
  masseinheit getMasseinheit();
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

class Schuettgut : public Artikel {
private:
public:
};

class Stueckgut : public Artikel {
private:
public:
};

class Fluessigkeit : public Artikel {
private:
public:
};

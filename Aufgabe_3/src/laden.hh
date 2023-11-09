#ifndef LADEN_HH
#define LADEN_HH

#include "lager.hh"
#include <set>
#include <vector>

class Regal {
public:
  Regal(string name, Lager &lager, int warengruppe);
  Regal(string name, Lager &lager, std::set<int> warengruppen);
  Lager &getLager();
  string getName() const;
  std::set<int> getWaren() const;
  Artikel getArtikel(string num) const;
  // template <class OutputIterator>
  // void products(OutputIterator out) const;
  vector<string> getImRegal();

private:
  string regalname;
  Lager &lager;
  std::set<int> waren;
  friend ostream &operator<<(ostream &os, Regal regal);
  // vector<string> imGemueseRegal;
};

class Kunde {
public:
  Kunde(string name,vector<Regal> const &regale);
  void kundeUI();
  string getName() const;
  void printRegale();
  void printArtikel(int num);
  void printWarenkorb();
  typedef struct {
    string artikelnummer;
    double menge;
  } waren;
  vector<waren> getWarenkorb() const;

private:
  string name;
  vector<Regal> const &regale;
  vector<waren> warenkorb;
};

#endif // !LADEN_HH

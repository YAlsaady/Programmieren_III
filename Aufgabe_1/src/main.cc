#include "lager.hh"
#include <iostream>
#include <string>

using namespace std;

int main() {
  Artikel apfel("apfel", "1111000000", 100, volumen ,10.5, 21.0);

  string preis = apfel.getName();
  cout << apfel.getName() << endl;
  cout << apfel.getNummer() << endl;
  cout << apfel.getMasseinheit() << endl;
  cout << apfel.getLagerabstand() << endl;
  cout << apfel.getNormpreis() << endl;
  cout << apfel.getVerkaufpreis() << endl;

  apfel.setName("Nicht Apfel");
  apfel.setNummer("00001111111");
  apfel.setMasseinheit(gewicht);
  apfel.setVerkaufpreis(30.7);
  apfel.setLagerbestand(1);
  apfel.setVerkaufpreis(45.11);

  cout << endl;
  cout << apfel.getName() << endl;
  cout << apfel.getNummer() << endl;
  cout << apfel.getMasseinheit() << endl;
  cout << apfel.getLagerabstand() << endl;
  cout << apfel.getNormpreis() << endl;
  cout << apfel.getVerkaufpreis() << endl;
  return 0;
}

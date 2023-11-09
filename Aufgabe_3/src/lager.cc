/**
 * @file lager.cc
 * @authors Yaman Alsaady, Oliver Schmidt
 * @brief Implementierung der Lagerverwaltungsfunktionen.
 * @version 0.2
 * @date 2023-10-19
 *
 * Dies ist die Implementierung der Funktionen fuer die Lagerverwaltung,
 * einschliesslich der Warengruppenverwaltung und der Artikelklassen.
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "lager.hh"
// #include <cmath>
#include <cmath>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

static double rounding(double);

void Lager::readFile(string filename) {
  ifstream file(filename);
  if (file.is_open()) {
    Artikel tmp;
    do {
      try {
        file >> tmp;
        switch (tmp.getMasseinheit()) {
        case 0:
          lagerMap.insert({tmp.getArtikelnummer(), new Stueckgut(tmp)});
          // cout << typeid(*lagerMap[tmp.getArtikelnummer()]).name() << endl;
          break;
        case 1:
          lagerMap.insert({tmp.getArtikelnummer(), new Schuettgut(tmp)});
          break;
        case 2:
          lagerMap.insert({tmp.getArtikelnummer(), new Fluessigkeit(tmp)});
          break;
        }
      } catch (const int &ex) {
      } catch (std::invalid_argument const &ex) {
      }
    } while (!file.eof());
    file.close();
  }
}

void Lager::write(ostream &os) {
  artikelMap::iterator it = lagerMap.begin();
  while (it != lagerMap.end()) {
    os << *it->second << endl;
    it++;
  }
}

void Lager::write(string filename) {
  ofstream file(filename);
  if (file.is_open()) {
    artikelMap::iterator it = lagerMap.begin();
    while (it != lagerMap.end()) {
      file << *it->second << endl;
      it++;
    }
  }
}

Artikel Lager::getArtikel(string artikelnummer) const {
  
  return *artikelMap(lagerMap)[artikelnummer];
}

Lager::artikelMap Lager::getMap() { return lagerMap; }

Artikel::Artikel() {}
Artikel::Artikel(string name, string num, unsigned int bestand,
                 masseinheit einheit, preis vp, preis np)
    : artikelname(name), artikelnummer(num), lagerbestand(bestand),
      einheit(einheit), verkaufpreis(vp), normpreis(np) {}
Artikel::~Artikel() {}

// void Artikel::setGruppe(Warengruppen g) { gruppe = g; }
string Artikel::getName() const { return artikelname; }
string Artikel::getArtikelnummer() const { return artikelnummer; }
unsigned int Artikel::getLagerbestand() const { return lagerbestand; }
masseinheit Artikel::getMasseinheit() const { return einheit; }
string Artikel::getStrMasseinheit() const {
  switch (einheit) {
  case 0:
    return "Stk";
  case 1:
    return "kg";
  case 2:
    return "l";
  default:
    return "None";
  }
}

preis Artikel::getVerkaufpreis() const { return verkaufpreis; }
preis Artikel::getNormpreis() const { return normpreis; }
int Artikel::getGruppe() const {
  string artnum = artikelnummer;
  artnum = artnum.erase(4);
  return stoi(artnum);
  // return artnum;
}

void Artikel::setName(string name) { artikelname = name; }
void Artikel::setArtikelnummer(string num) { artikelnummer = num; }
void Artikel::setLagerbestand(unsigned int bestand) { lagerbestand = bestand; }
void Artikel::setMasseinheit(masseinheit einheit) { this->einheit = einheit; }
void Artikel::setVerkaufpreis(preis vp) { verkaufpreis = vp; }
void Artikel::setNormpreis(preis np) { normpreis = np; }

std::ostream &Artikel::print(std::ostream &os) {
  return os << artikelname << "|" << artikelnummer << "|" << lagerbestand << "|"
            << verkaufpreis << "|" << getStrMasseinheit() << "|" << normpreis;
}

std::ostream &operator<<(std::ostream &os, Artikel produkt) {
  return produkt.print(os);
}

void operator>>(istream &is, Artikel &produkt) {
  vector<string> beschreibung;
  string text, name, num;
  int bestand = 0;
  preis vp = 0, np = 0;
  masseinheit einheit;

  getline(is, text);
  stringstream ss(text);

  if (!text[0]) {
    throw(-1);
  }
  text = "";
  for (size_t i = 0; getline(ss, text, '|') && i < 6; i++) {
    beschreibung.push_back(text);
  }
  // cout << beschreibung.size()<< endl;
  if (beschreibung.size() < 5)
    throw -1;
  name = beschreibung[0];
  num = beschreibung[1];

  if (beschreibung[4] == "kg")
    einheit = kg;
  else if (beschreibung[4] == "l")
    einheit = l;
  else if (beschreibung[4] == "stk")
    einheit = stk;
  else {
    einheit = stk;
  }

  for (size_t i = 1; i < 6; i++) {
    for (size_t j = 0; j < beschreibung[i].length(); j++) {
      if (beschreibung[i][j] == ' ') {
        beschreibung[i].erase(beschreibung[i].begin() + j);
        j--;
      }
    }
  }

  if (name == "" || num == "" || num.length() != 10) {
    throw(-1);
  }
  if (beschreibung[3] == "" && beschreibung[4] == "") {
    throw(-1);
  }

  if (beschreibung[2] != "") {
    bestand = stoi(beschreibung[2]);
  } else {
    bestand = 0;
  }
  if (beschreibung[3] != "") {
    vp = stof(beschreibung[3]);
  }

  if (beschreibung.size() > 5 && beschreibung[5] != "") {
    np = stof(beschreibung[5]);
  }
  if (vp == 0)
    vp = np;
  if (np == 0)
    np = vp;

  produkt.setMasseinheit(einheit);
  produkt.setName(beschreibung[0]);
  produkt.setArtikelnummer(beschreibung[1]);
  produkt.setLagerbestand(bestand);
  produkt.setVerkaufpreis(vp);
  produkt.setNormpreis(np);
}

Stueckgut::Stueckgut(Artikel produkt)
    : Stueckgut(produkt.getName(), produkt.getArtikelnummer(),
                produkt.getVerkaufpreis(), produkt.getLagerbestand()) {}
Stueckgut::Stueckgut(string name, string num, preis vp, unsigned int bestand)
    : Artikel(name, num, bestand, stk, vp, vp) {}

Schuettgut::Schuettgut(Artikel produkt)
    : Schuettgut(produkt.getName(), produkt.getArtikelnummer(),
                 rounding(produkt.getVerkaufpreis() / produkt.getNormpreis()),
                 produkt.getNormpreis(), produkt.getLagerbestand()) {}
Schuettgut::Schuettgut(string name, string num, double groesse, preis np,
                       unsigned int bestand)
    : Artikel(name, num, bestand, kg, (groesse * np), np), losgroesse(groesse) {
}
double Schuettgut::getLosgroesse() const { return losgroesse; }
void Schuettgut::setLosgroesse(double groesse) {
  losgroesse = groesse;
  verkaufpreis = rounding(verkaufpreis);
}
void Schuettgut::setVerkaufpreis(preis vp) {
  verkaufpreis = vp;
  losgroesse = rounding(losgroesse);
}

Fluessigkeit::Fluessigkeit(Artikel produkt)
    : Fluessigkeit(produkt.getName(), produkt.getArtikelnummer(),
                   rounding(produkt.getVerkaufpreis() / produkt.getNormpreis()),
                   produkt.getNormpreis(), produkt.getLagerbestand()) {}
Fluessigkeit::Fluessigkeit(string name, string num, double vol, preis np,
                           unsigned int bestand)
    : Artikel(name, num, bestand, l, (vol * np), np), volume(vol) {}
double Fluessigkeit::getVolume() const { return volume; }
void Fluessigkeit::setVolume(double vol) {
  volume = vol;
  verkaufpreis = rounding(verkaufpreis);
}
void Fluessigkeit::setVerkaufpreis(preis vp) {
  verkaufpreis = vp;
  volume = rounding(volume);
}

static double rounding(double num){
  num *= 100;
  num += 0.5;
  num = int(num);
  num /= 100;
  return num;
}

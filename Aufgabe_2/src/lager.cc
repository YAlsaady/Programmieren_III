/**
 * @file lager.cc
 * @authors Yaman Alsaady, Oliver Schmidt
 * @brief Implementierung der Lagerverwaltungsfunktionen.
 * @version 0.1
 * @date 2023-10-04
 *
 * Dies ist die Implementierung der Funktionen fuer die Lagerverwaltung,
 * einschliesslich der Warengruppenverwaltung und der Artikelklassen.
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "lager.hh"
#include <cmath>
#include <iostream>
#include <map>
#include <sstream>
#include <string>

Warengruppen::Warengruppen() {}
void Warengruppen::defaultList() {
  mapGruppe["1005"] = "Fahrrad";
  mapGruppe["4000"] = "Gemuese";
  mapGruppe["4106"] = "Gemuese";
  mapGruppe["4370"] = "Kaffee";
  mapGruppe["5500"] = "Bier";
  mapGruppe["5031"] = "Milch";
}
string Warengruppen::getGruppe(string code) {
  if (mapGruppe[code] != "")
    return mapGruppe[code];
  else {
    return code;
  }
}

void Warengruppen::addGruppe(string code, string name) {
  mapGruppe.insert({code, name});
}
void Warengruppen::changeGruppe(string code, string name) {
  mapGruppe.insert_or_assign(code, name);
}
void Warengruppen::delGruppe(string code) { mapGruppe.erase(code); }

void Warengruppen::clear() { mapGruppe.clear(); }

Warengruppen Artikel::gruppe;
Artikel::Artikel() {}
Artikel::Artikel(string name, string num, unsigned int bestand,
                 masseinheit einheit, preis vp, preis np)
    : artikelname(name), artikelnummer(num), lagerbestand(bestand),
      einheit(einheit), verkaufpreis(vp), normpreis(np) {}
Artikel::~Artikel() {}

void Artikel::setGruppe(Warengruppen g) { gruppe = g; }
string Artikel::getName() const { return artikelname; }
string Artikel::getArtikelnummer() const { return artikelnummer; }
unsigned int Artikel::getLagerabstand() const { return lagerbestand; }
string Artikel::getMasseinheit() const {
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
string Artikel::getGruppe() const {
  string artnum = artikelnummer;
  artnum = artnum.erase(4);
  return gruppe.getGruppe(artnum);
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
            << ((verkaufpreis != 0) ? (verkaufpreis) : -1) << "|"
            << getMasseinheit() << "|" << normpreis;
}

std::ostream &operator<<(std::ostream &os, Artikel produkt) {
  return produkt.print(os);
}

void operator>>(istream &os, Artikel &a) {
  string line;
  getline(os, line);
  if (line == "")
    throw(-1);
  vector<string> productAttributes;
  istringstream lineStream(line);
  string attribute;
  while (getline(lineStream, attribute, '|')) {
    productAttributes.push_back(attribute);
  }
  a.setName(productAttributes[0]);
  a.setArtikelnummer(productAttributes[1]);
  a.setLagerbestand(stoi(productAttributes[2]));

  if (productAttributes[3] != "") {
    a.setVerkaufpreis(stof(productAttributes[3]));
  } else {
    a.setVerkaufpreis(stof(productAttributes[5]));
  }
  a.setNormpreis(stof(productAttributes[5]));

  if (productAttributes[4] == "stk") {
    a.setMasseinheit(stk);
  } else if (productAttributes[4] == "kg") {
    a.setMasseinheit(kg);
  } else if (productAttributes[4] == "l") {
    a.setMasseinheit(l);
  } else {
    a.setMasseinheit(stk);
  }
}

Stueckgut::Stueckgut(string name, string num, preis vp, unsigned int bestand)
    : Artikel(name, num, bestand, stk, vp, vp) {}

Schuettgut::Schuettgut(string name, string num, double groesse, preis np,
                       unsigned int bestand)
    : Artikel(name, num, bestand, kg, ceil(groesse * np), np),
      losgroesse(groesse) {}
double Schuettgut::getLosgroesse() const { return losgroesse; }
void Schuettgut::setLosgroesse(double groesse) {
  losgroesse = groesse;
  verkaufpreis = int((losgroesse * normpreis) * 100 + 0.5);
  verkaufpreis /= 100;
}
void Schuettgut::setVerkaufpreis(preis vp) {
  verkaufpreis = vp;
  losgroesse = int((verkaufpreis / normpreis) * 100 + 0.5);
  losgroesse /= 100;
}

Fluessigkeit::Fluessigkeit(string name, string num, double vol, preis np,
                           unsigned int bestand)
    : Artikel(name, num, bestand, l, (vol * np), np), volume(vol) {}
double Fluessigkeit::getVolume() const { return volume; }
void Fluessigkeit::setVolume(double vol) {
  volume = vol;
  verkaufpreis = int((volume * normpreis) * 100 + 0.5);
  verkaufpreis /= 100;
}
void Fluessigkeit::setVerkaufpreis(preis vp) {
  verkaufpreis = vp;
  volume = int((verkaufpreis / normpreis) * 100 + 0.5);
  volume /= 100;
}
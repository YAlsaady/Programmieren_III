/**
 * @file lager.cc
 * @authors Yaman Alsaady, Oliver Schmidt
 * @brief Implementierung der Lagerverwaltungsfunktionen.
 * @version 0.1
 * @date 2023-10-04
 *
 * Dies ist die Implementierung der Funktionen für die Lagerverwaltung,
 * einschließlich der Warengruppenverwaltung und der Artikelklassen.
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "lager.hh"
#include <cmath>
#include <iostream>
#include <map>
#include <string>

Warengruppen::Warengruppen() {
}
void Warengruppen::init() {
  mapGruppe["1005"] = "Fahrrad";
  mapGruppe["4000"] = "Gemüse";
  // mapGruppe["4100"] = "";
  mapGruppe["4106"] = "Gemüse";
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
Artikel::Artikel(string name, string num, unsigned int bestand,
                 masseinheit einheit, preis vp, preis np)
    : artikelname(name), artikelnummer(num), lagerbestand(bestand),
      einheit(einheit), verkaufpreis(vp), normpreis(np) {}
Artikel::~Artikel() {}

void Artikel::setGruppe(Warengruppen g) {
  gruppe =g;
}
string Artikel::getName() const { return artikelname; }
string Artikel::getArtikelnummer() const { return artikelnummer; }
unsigned int Artikel::getLagerabstand() const { return lagerbestand; }
string Artikel::getMasseinheit() const {
  switch (einheit) {
  case 0:
    return "Stueck";
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
string Artikel::getGruppe() {
  // string gruppe = artikelnummer.erase(4);
  return gruppe.getGruppe(artikelnummer.erase(4));
}

void Artikel::setName(string name) { artikelname = name; }
void Artikel::setArtikelnummer(string num) { artikelnummer = num; }
void Artikel::setLagerbestand(unsigned int bestand) { lagerbestand = bestand; }
void Artikel::setMasseinheit(masseinheit einheit) { this->einheit = einheit; }
void Artikel::setVerkaufpreis(preis vp) { verkaufpreis = vp; }
void Artikel::setNormpreis(preis np) { normpreis = np; }

Schuettgut::Schuettgut(string name, string num, double groesse, preis np,
                       unsigned int bestand)
    : Artikel(name, num, bestand, kg, ceil(groesse * np), np), losgroesse(groesse) {}
double Schuettgut::getLosgroesse() { return losgroesse; }
void Schuettgut::setLosgroesse(double groesse) {
  losgroesse = groesse;
  verkaufpreis = ceil(losgroesse * normpreis);
}
void Schuettgut::setVerkaufpreis(preis vp) {
  verkaufpreis = vp;
  losgroesse = ceil(verkaufpreis / normpreis);
}

Stueckgut::Stueckgut(string name, string num, preis vp, unsigned int bestand)
    : Artikel(name, num, bestand, stk, vp, vp) {}

Fluessigkeit::Fluessigkeit(string name, string num, preis vp,
                           unsigned int bestand)
    : Artikel(name, num, bestand, l, vp, 0) {}

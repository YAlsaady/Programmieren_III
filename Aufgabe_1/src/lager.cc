#include "lager.hh"
#include <iostream>
#include <map>
#include <string>

namespace Warengruppen {
map<string, string> mapGruppe;
map<string, string>::iterator iter;
void init() {
  mapGruppe["1005"] = "Fahrrad";
  mapGruppe["4000"] = "Gemüse";
  // mapGruppe["4100"] = "";
  mapGruppe["4106"] = "Gemüse";
  mapGruppe["4370"] = "Kaffee";
  mapGruppe["5500"] = "Bier";
  mapGruppe["5031"] = "Milch";
}

string getGruppe(string code) {
  if (mapGruppe[code] != "")
    return mapGruppe[code];
  else {
    return code;
  }
}

void addGruppe(string code, string name) { 
  mapGruppe.insert({code, name}); 
}
void changeGruppe(string code, string name) { 
  mapGruppe.insert_or_assign(code, name);
}
void delGruppe(string code) { mapGruppe.erase(code); }

void clear() { mapGruppe.clear(); }
} // namespace Warengruppen

Artikel::Artikel(string name, string num, unsigned int bestand,
                 masseinheit einheit, preis vp, preis np)
    : artikelname(name), artikelnummer(num), lagerbestand(bestand),
      einheit(einheit), verkaufpreis(vp), normpreis(np) {}
Artikel::~Artikel() {}

string Artikel::getName() { return artikelname; }
string Artikel::getArtikelnummer() { return artikelnummer; }
unsigned int Artikel::getLagerabstand() { return lagerbestand; }
string Artikel::getMasseinheit() {
  switch (einheit) {
  case 0:
    return "Stück";
  case 1:
    return "kg";
  case 2:
    return "l";
  default:
    return "None";
  }
}
preis Artikel::getVerkaufpreis() { return verkaufpreis; }
preis Artikel::getNormpreis() { return normpreis; }
string Artikel::getGruppe() {
  // string gruppe = artikelnummer.erase(4);
  return Warengruppen::getGruppe(artikelnummer.erase(4));
}

void Artikel::setName(string name) { artikelname = name; }
void Artikel::setArtikelnummer(string num) { artikelnummer = num; }
void Artikel::setLagerbestand(unsigned int bestand) { lagerbestand = bestand; }
void Artikel::setMasseinheit(masseinheit einheit) { this->einheit = einheit; }
void Artikel::setVerkaufpreis(preis vp) { verkaufpreis = vp; }
void Artikel::setNormpreis(preis np) { normpreis = np; }

Schuettgut::Schuettgut(string name, string num, double groesse, preis np,
                       unsigned int bestand)
    : Artikel(name, num, bestand, kg, groesse*np, np), losgroesse(groesse) {}
double Schuettgut::getLosgroesse() { return losgroesse; }
void Schuettgut::setLosgroesse(double groesse) {
  losgroesse = groesse;
  verkaufpreis = losgroesse * normpreis;
}
void Schuettgut::setVerkaufpreis(preis vp) {
  verkaufpreis = vp;
  losgroesse = verkaufpreis / normpreis;
}

Stueckgut::Stueckgut(string name, string num, preis vp, unsigned int bestand)
    : Artikel(name, num, bestand, stk, vp, vp) {}

Flüßigkeit::Flüßigkeit(string name, string num, preis vp, unsigned int bestand)
    : Artikel(name, num, bestand, l, vp, 0) {}

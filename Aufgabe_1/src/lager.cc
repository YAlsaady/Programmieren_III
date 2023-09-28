#include "lager.hh"
#include <iostream>

Artikel::Artikel(string name, string num, unsigned int bestand,
                 masseinheit einheit, double vp, double np)
    : artikelname(name), nummer(num), lagerbestand(bestand), einheit(einheit),
      verkaufpreis(vp), normpreis(np) {}
Artikel::~Artikel() {}

string Artikel::getName() { return this->artikelname; }
string Artikel::getNummer() { return this->nummer; }
unsigned int Artikel::getLagerabstand() { return this->lagerbestand; }
masseinheit Artikel::getMasseinheit() {
  return this->einheit;
}
double Artikel::getVerkaufpreis() { return this->verkaufpreis; }
double Artikel::getNormpreis() { return this->normpreis; }

void Artikel::setName(string name) { this->artikelname = name; }
void Artikel::setNummer(string num) { this->nummer = num; }
void Artikel::setLagerbestand(unsigned int bestand) {}
void Artikel::setMasseinheit(masseinheit einheit) {}
void Artikel::setVerkaufpreis(double vp) {}
void Artikel::setNorpreis(double np) {}

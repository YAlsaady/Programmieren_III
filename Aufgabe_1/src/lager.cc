#include "lager.hh"
#include <iostream>

Artikel::Artikel(string name, string num, unsigned int bestand,
                 masseinheit einheit, double vp, double np)
    : artikelname(name), nummer(num), lagerbestand(bestand), einheit(einheit),
      verkaufpreis(vp), normpreis(np) {}
Artikel::~Artikel() {}

string Artikel::getName() { return artikelname; }
string Artikel::getNummer() { return nummer; }
unsigned int Artikel::getLagerabstand() { return lagerbestand; }
masseinheit Artikel::getMasseinheit() { return einheit; }
double Artikel::getVerkaufpreis() { return verkaufpreis; }
double Artikel::getNormpreis() { return normpreis; }

void Artikel::setName(string name) { artikelname = name; }
void Artikel::setNummer(string num) { nummer = num; }
void Artikel::setLagerbestand(unsigned int bestand) {lagerbestand=bestand;}
void Artikel::setMasseinheit(masseinheit einheit) {this->einheit = einheit;}
void Artikel::setVerkaufpreis(double vp) {verkaufpreis=vp;}
void Artikel::setNormpreis(double np) {normpreis=np;}

#include "lager.hh"
#include <iostream>
#include <string>


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





Schuettgut::Schuettgut(string name, string num, unsigned int bestand, double np){
    Artikel(name, num, bestand, gewicht, 0, np);
}

Stueckgut::Schuettgut(string name, string num, unsigned int bestand, double vp){
    Artikel(name, num, bestand, anzahl, vp, 0);
}

Fluessigkeit::Fluessigkeit(string name, string num,unsigned int bestand, double vp ){
    Artikel(name, num, bestand, anzahl, vp, 0)
}
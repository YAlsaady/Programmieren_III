#include <iostream>
#include "lager.hh"

Artikel::Artikel(string name, unsigned int num, unsigned int lagerbestand,
          unsigned int masseinheit, double verkaufpreis, double normpreis){
}

 
string Artikel getName(){
    return this->artikelname;
}
string Artikel getNummer(){
    return this->nummer;
}
unsigned int Artikel getLagerabstand(){
    return this->lagerbestand;
}
string Artikel getMasseinheit(){
    return this->{kg, liter, stueck};
}
double Artikel getVerkaufpreis(){
    return this->verkaufpreis;
}
double Artikel getNormpreis(){
    return this->normpreis;
}

void Artikel setName(string name){
    this->artikelname = name;
}
void Artikel setNummer(string num){
    this->
}
  void setLagerbestand(unsigned int bestand);
  void setMasseinheit(masseinheit einheit);
  void setVerkaufpreis(double vp);
  void setNorpreis(double np);
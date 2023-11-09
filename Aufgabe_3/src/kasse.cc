
#include "kasse.hh"
#include "laden.hh"
#include "lager.hh"
#include <ctime>
#include <fstream>
#include <iomanip>
#include <ios>
#include <iostream>
#include <ostream>
#include <string>
#include <unistd.h>
#include <vector>

using namespace std;

static double rounding(double);

Kasse::Kasse(Kunde const &kunde, Lager const &lager)
    : kunde(kunde), lager(lager) {}

void Kasse::rechnung(ostream &os) {
    // Aktuelles Datum und Uhrzeit abrufen
    time_t now = time(0);
    struct tm currentTime;
    localtime_r(&now, &currentTime);
    int year = currentTime.tm_year + 1900; // Jahr seit 1900
    int month = currentTime.tm_mon + 1;    // Monat von 0 bis 11
    int day = currentTime.tm_mday;         // Tag des Monats
    string date = to_string(year) + "-" + to_string(month) + "-" + to_string(day);
    string rechnungsnummer = to_string(month) + to_string(year) + to_string(day);
    double sum = 0;

    printRechnung(os, date, rechnungsnummer, sum);

    os << "Beenden q:" << endl;
    os << "Drucken p:" << endl;
    os << "Auswahl: ";
    string wahl;
    while (true) {
        cin >> wahl;
        if (wahl[0] == 'q') {
            os << "\n" << endl;
            break;
        }
        if (wahl[0] == 'p') {
            os << "\n" << endl;
            string dateiname = kunde.getName() + ".txt";
            ofstream datei(dateiname);
            if (datei.is_open()) {
                printRechnung(datei, date, rechnungsnummer, sum);
            }
            break;
        }
        cout << "Falsche Eingabe!" << endl;
    }
}

void Kasse::printRechnung(ostream &os, const string &date, const string &rechnungsnummer, double sum) {
    string one_long = "------------------------------------------------------";
    string double_short = "-----------------------\n-----------------------";

    os << "Rechnung des Warenwirtschaftssystems" << endl;
    os << "Rechnungsnummer: " << rechnungsnummer << endl;
    os << "Kunde: " << kunde.getName() << endl;
    os << "Rechnungdatum: " << date << "\n" << endl;

    for (Kunde::waren ware : kunde.getWarenkorb()) {
        Artikel artikel = lager.getArtikel(ware.artikelnummer);
        os << one_long << endl;
        os << artikel.getName() << "\t" << artikel.getNormpreis() << " x " << ware.menge
            << " " << artikel.getStrMasseinheit() << "/€"
            << "\t" << artikel.getNormpreis() * ware.menge << "€" << endl;
        sum += artikel.getNormpreis() * ware.menge ;
    }

    cout.imbue(locale("de_DE.UTF-8"));
    os << "\n"
       << "Summe Netto:\t"  << showbase << put_money(sum) << endl;
    os << "MwSt. 19%:\t" << showbase  << put_money(sum * 0.19) << endl;
    os << double_short << endl;
    os << "Gesamt:\t\t"  << showbase << put_money(sum * (1 - 0.19))<< endl;

}

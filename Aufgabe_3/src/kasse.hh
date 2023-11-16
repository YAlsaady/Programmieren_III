/**
 * @file laden.hh
 * @authors Yaman Alsaady, Oliver Schmidt
 * @brief Enthaelt die Deklaration der Klasse Kasse.
 * @version 0.3
 * @date 2023-11-13
 *
 * Dieses Header-Datei enthaelt die Definitionen von Klassen und
 * Funktionen zur Verwaltung von der Kasse in einem C++-Programm.
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef KASSE_HH
#define KASSE_HH

#include "laden.hh"
#include "lager.hh"
#include <iomanip>
#include <string>
#include <unistd.h>
#include <vector>

/**
 * @class Kasse
 * @brief Repraesentiert eine Kasse fuer Einkaeufe und erstellt Rechnungen.
 *
 * Die Klasse Kasse ermoeglicht es, eine Rechnung fuer die Einkaeufe eines
 * Kunden zu erstellen. Sie verwendet Informationen ueber den Kunden und das
 * Lager, um die Rechnung zu generieren.
 */
class Kasse {
public:
  /**
   * @brief Konstruktor fuer die Kasse mit einem Kunden und einem Lager.
   *
   * @param kunde Eine Konstante Referenz auf einen Kunden, dessen Einkaeufe
   * abgerechnet werden sollen.
   * @param lager Eine Referenz auf ein Lager, das fuer die Rechnung benoetigt
   * wird.
   */
  Kasse(Kunde const &kunde, Lager &lager);

  /**
   * @brief Erstellt die Rechnung fuer die Einkaeufe und gibt sie auf den
   * angegebenen Ausgabestrom aus.
   *
   * @param os Der Ausgabestrom, auf dem die Rechnung ausgegeben werden soll.
   */
  void rechnung(ostream &os);

  /**
   * @brief Gibt die Rechnungsdetails auf den angegebenen Ausgabestrom aus.
   *
   * @param os Der Ausgabestrom, auf dem die Rechnungsdetails ausgegeben werden
   * sollen.
   * @param date Das Datum der Rechnung.
   * @param rechnungsnummer Die Rechnungsnummer.
   * @param print_auswahl Gibt an, ob detaillierte Informationen zu den
   * ausgewaehlten Artikeln gedruckt werden sollen.
   */
  void printRechnung(ostream &os, const string &date,
                     const string &rechnungsnummer, bool print_auswahl);

private:
  Kunde const &kunde; ///< Konstante Referenz auf den Kunden fuer die Rechnung.
  Lager &lager;       ///< Referenz auf das Lager fuer die Rechnung.
};
#endif // !KASSE_HH

/**
 * @file laden.hh
 * @authors Yaman Alsaady, Oliver Schmidt
 * @brief Enthaelt die Deklaration der Klasse Regal und der Klasse Kunde.
 * @version 0.3
 * @date 2023-11-13
 *
 * Dieses Header-Datei enthaelt die Definitionen von Klassen und Funktionen zur
 * Verwaltung von Regale und Kunden und Warengruppen in einem C++-Programm.
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef LADEN_HH
#define LADEN_HH

#include "lager.hh"
#include <set>
#include <vector>

/**
 * @class Regal
 * @brief Repraesentiert ein Regal im Lager.
 *
 * Die Klasse Regal stellt Informationen ueber ein Regal im Lager zur
 * Verfuegung, einschliesslich des Regalnamens, des zugeordneten Lagers, der
 * zugehoerigen Warengruppen und der im Regal befindlichen Artikel.
 */
class Regal {
public:
  /**
   * @brief Konstruktor fuer ein Regal mit einer einzelnen Warengruppe.
   *
   * @param name Der Name des Regals.
   * @param lager Referenz auf das Lager, zu dem das Regal gehoert.
   * @param warengruppe Die Warengruppe, die dem Regal zugeordnet ist.
   */
  Regal(string name, Lager &lager, int warengruppe);

  /**
   * @brief Konstruktor fuer ein Regal mit mehreren Warengruppen.
   *
   * @param name Der Name des Regals.
   * @param lager Referenz auf das Lager, zu dem das Regal gehoert.
   * @param warengruppen Die Menge der Warengruppen, die dem Regal zugeordnet
   * sind.
   */
  Regal(string name, Lager &lager, std::set<int> warengruppen);

  /**
   * @brief Template-Funktion zum Abrufen von Produkten im Regal
   *
   * Diese Funktion ruft Produkte aus dem Regal ab und gibt die Ergebnisse an den angegebenen Ausgabeiterator aus.
   *
   * @param out Der Ausgabeiterator, der das Ziel faer die Produkte
   * repraesentiert.
   */
  template <class OutputIterator> 
  void products(OutputIterator out) const;

  /**
   * @brief Gibt eine Referenz auf das Lager zurueck, zu dem das Regal gehoert.
   *
   * @return Eine Referenz auf das Lager.
   */
  Lager &getLager();

  /**
   * @brief Gibt den Namen des Regals zurueck.
   *
   * @return Der Name des Regals.
   */
  string getName() const;

  /**
   * @brief Gibt die Menge der Warengruppen zurueck, die dem Regal zugeordnet
   * sind.
   *
   * @return Eine Menge von Warengruppen.
   */
  set<int> getWaren() const;

  /**
   * @brief Gibt einen Artikel im Regal anhand der Artikelnummer zurueck.
   *
   * @param num Die Artikelnummer des gesuchten Artikels.
   * @return Der gefundene Artikel im Regal.
   */
  Artikel getArtikel(string num) const;

  /**
   * @brief Gibt eine Liste der Artikel im Regal zurueck.
   *
   * @return Ein Vektor von Artikelnummern im Regal.
   */
  vector<string> getImRegal() const;

  /**
   * @brief ueberschriebener Ausgabeoperator fuer die Klasse Regal.
   *
   * @param os Der Ausgabestrom.
   * @param regal Das Regal, das ausgegeben werden soll.
   * @return Der Ausgabestrom.
   */
  friend ostream &operator<<(ostream &os, Regal regal);

private:
  ///< Der Name des Regals.
  string regalname;
  ///< Referenz auf das Lager, zu dem das Regal gehoert.
  Lager &lager;
  ///< Die Menge der Warengruppen, die dem Regal zugeordnet sind.
  std::set<int> waren;
};

/**
 * @class Kunde
 * @brief Repraesentiert einen Kunden mit Einkaufsfunktionen.
 *
 * Die Klasse Kunde stellt einen Kunden dar, der Einkaufsaktionen in einem Lager
 * durchfuehren kann. Ein Kunde hat einen Namen, eine Liste von Regalen, die er
 * durchsuchen kann, und einen Warenkorb, um Artikel hinzuzufuegen.
 */
class Kunde {
public:
  /**
   * @brief Konstruktor fuer einen Kunden mit einem Namen und einer Liste von
   * Regalen.
   *
   * @param name Der Name des Kunden.
   * @param regale Eine Referenz auf eine Liste von Regalen, die der Kunde
   * durchsuchen kann.
   */
  Kunde(string name, vector<Regal> const &regale);

  /**
   * @brief Oeffnet die Benutzeroberflaeche des Kunden fuer Einkaufsaktionen.
   */
  void kundeUI();

  /**
   * @brief Gibt den Namen des Kunden zurueck.
   *
   * @return Der Name des Kunden.
   */
  string getName() const;

  /**
   * @brief Gibt die Artikel in einem bestimmten Regal aus.
   *
   * @param num Die Nummer des Regals, das durchsucht werden soll.
   */
  void printArtikel(int num);

  /**
   * @brief Gibt den aktuellen Warenkorb des Kunden aus.
   */
  void printWarenkorb();

  /**
   * @brief Struktur zur Darstellung von Waren im Warenkorb.
   */
  typedef struct {
    string artikelnummer; ///< Die Artikelnummer.
    double menge;         ///< Die Menge des Artikels im Warenkorb.
  } waren;

  /**
   * @brief Gibt den aktuellen Warenkorb des Kunden zurueck.
   *
   * @return Ein Vektor von Waren im Warenkorb.
   */
  vector<waren> getWarenkorb() const;

private:
  string name;
  vector<Regal> const &regale;
  vector<waren> warenkorb;
};

#endif // !LADEN_HH

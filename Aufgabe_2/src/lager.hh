/**
 * @file lager.hh
 * @authors Yaman Alsaady, Oliver Schmidt
 * @brief Definitionen der Lagerverwaltungsfunktionen.
 * @version 0.2
 * @date 2023-10-19
 *
 * Dieses Header-Datei enthaelt die Definitionen von Klassen und
 * Funktionen zur Verwaltung von Artikeln und Warengruppen in einem
 * C++-Programm.
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef LAGER_HH
#define LAGER_HH

#include <iostream>
#include <map>
#include <string>

using namespace std;
enum masseinheit { stk, kg, l };
typedef double preis;

class Warengruppen {
private:
  map<string, string> mapGruppe;
  map<string, string>::iterator iter;

public:
  /**
   * @brief Konstruktor fuer die Klasse "Warengruppen".
   *
   * Dieser Konstruktor initialisiert eine leere Warengruppenliste.
   */
  Warengruppen();

  /**
   * @brief Setzt eine Standard-Warengruppenliste.
   */
  void defaultList();

  /**
   * @brief Gibt den Namen der Warengruppe fuer einen gegebenen Code zurueck.
   *
   * @param code Der Warengruppencode.
   * @return Der Name der Warengruppe oder der Code, falls keine Warengruppe
   * gefunden wurde.
   */
  string getGruppe(string code);

  /**
   * @brief Fuegt eine neue Warengruppe hinzu.
   *
   * @param code Der Warengruppencode.
   * @param name Der Name der Warengruppe.
   */
  void addGruppe(string code, string name);

  /**
   * @brief Loescht eine Warengruppe anhand ihres Codes.
   *
   * @param code Der Warengruppencode.
   */
  void delGruppe(string code);

  /**
   * @brief Aendert den Namen einer vorhandenen Warengruppe.
   *
   * @param code Der Warengruppencode.
   * @param name Der neue Name der Warengruppe.
   */
  void changeGruppe(string code, string name);

  /**
   * @brief Loescht alle Warengruppen und setzt sie zurck.
   */
  void clear();
};

/**
 * @brief Die Klasse "Artikel" repraesentiert einen Artikel mit verschiedenen
 * Eigenschaften.
 */
class Artikel {
protected:
  string artikelname;
  string artikelnummer;
  unsigned int lagerbestand;
  masseinheit einheit;
  preis verkaufpreis;
  preis normpreis;

public:
  /**
   * @brief Standardkonstruktor fuer die Klasse "Artikel".
   */
  Artikel();

  /**
   * @brief Konstruktor fuer die Klasse "Artikel".
   *
   * @param name Der Name des Artikels.
   * @param num Die Artikelnummer des Artikels.
   * @param bestand Der Lagerbestand des Artikels.
   * @param einheit Die Einheit des Artikels (stk, kg, l).
   * @param vp Der Verkaufspreis des Artikels.
   * @param np Der Normalpreis des Artikels.
   */
  Artikel(string name, string num, unsigned int bestand, masseinheit einheit,
          preis vp, preis np);

  // Getter-Funktionen

  /**
   * @brief Destruktor fuer die Klasse "Artikel".
   */
  ~Artikel();

  /**
   * @brief Statische Warengruppen-Instanz, die fuer alle Artikel gemeinsam
   * genutzt wird.
   */
  static Warengruppen gruppe;

  /**
   * @brief Setzt die Warengruppe fuer Artikel.
   *
   * @param g Die Warengruppe, die zugewiesen werden soll.
   */
  static void setGruppe(Warengruppen g);

  /**
   * @brief Gibt den Namen des Artikels zurueck.
   *
   * @return Der Name des Artikels.
   */
  string getName() const;

  /**
   * @brief Gibt die Artikelnummer des Artikels zurueck.
   *
   * @return Die Artikelnummer des Artikels.
   */
  string getArtikelnummer() const;

  /**
   * @brief Gibt den Lagerbestand des Artikels zurueck.
   *
   * @return Der Lagerbestand des Artikels.
   */
  unsigned int getLagerabstand() const;

  /**
   * @brief Gibt die Masseinheit des Artikels als Wert aus der Enumeration
   * zurueck.
   *
   * @return Die Masseinheit des Artikels als Wert aus der Enumeration (stk, kg,
   * l).
   */
  masseinheit getMasseinheit() const;

  /**
   * @brief Gibt die Masseinheit des Artikels als Zeichenkette zurueck.
   *
   * @return Die Masseinheit des Artikels als Zeichenkette ("stk", "kg", "l").
   */
  string getStrMasseinheit() const;

  /**
   * @brief Gibt den Verkaufspreis des Artikels zurueck.
   *
   * @return Der Verkaufspreis des Artikels.
   */
  preis getVerkaufpreis() const;

  /**
   * @brief Gibt den Normalpreis des Artikels zurueck.
   *
   * @return Der Normalpreis des Artikels.
   */
  preis getNormpreis() const;

  /**
   * @brief Gibt die Warengruppe des Artikels zurueck.
   *
   * @return Die Warengruppe des Artikels oder die Artikelnummer, falls keine
   * Warengruppe gefunden wurde.
   */
  string getGruppe() const;

  // Setter-Funktionen

  /**
   * @brief Setzt den Namen des Artikels.
   *
   * @param name Der neue Name des Artikels.
   */
  void setName(string name);

  /**
   * @brief Setzt die Artikelnummer des Artikels.
   *
   * @param num Die neue Artikelnummer des Artikels.
   */
  void setArtikelnummer(string num);

  /**
   * @brief Setzt den Lagerbestand des Artikels.
   *
   * @param bestand Der neue Lagerbestand des Artikels.
   */
  void setLagerbestand(unsigned int bestand);

  /**
   * @brief Setzt die Masseinheit des Artikels.
   *
   * @param einheit Die neue Masseinheit des Artikels (stk, kg, l).
   */
  void setMasseinheit(masseinheit einheit);

  /**
   * @brief Setzt den Verkaufspreis des Artikels.
   *
   * @param vp Der neue Verkaufspreis des Artikels.
   */
  void setVerkaufpreis(preis vp);

  /**
   * @brief Setzt den Normalpreis des Artikels.
   *
   * @param np Der neue Normalpreis des Artikels.
   */
  void setNormpreis(preis np);

  /**
   * @brief Gibt die Artikelinformationen aus.
   *
   * Diese Funktion gibt die Informationen des Artikels aus, einschliesslich
   * Artikelname, Artikelnummer, Lagerbestand, Verkaufspreis, Masseinheit und
   * Normpreis.
   *
   * @param os Die Ausgabestromreferenz, in die die Informationen geschrieben
   * werden.
   * @return Die Ausgabestromreferenz, in die die Informationen geschrieben
   * wurden.
   */
  ostream &print(ostream &outstream);
};
/**
 * @brief ueberladen des Ausgabeoperators fuer die Artikelklasse.
 *
 * Diese Funktion ermoeglicht das Ausgeben eines Artikels mit dem Ausgabeoperator
 * '<<'.
 *
 * @param os Die Ausgabestromreferenz, in die die Informationen geschrieben
 * werden.
 * @param produkt Der Artikel, der ausgegeben werden soll.
 * @return Die Ausgabestromreferenz, in die die Informationen geschrieben
 * wurden.
 */
ostream &operator<<(ostream &os, Artikel produkt);

/**
 * @brief ueberladen des Eingabeoperators fuer die Artikelklasse.
 *
 * Diese Funktion ermoeglicht das Einlesen von Artikelinformationen mit dem
 * Eingabeoperator '>>'.
 *
 * @param is Die Eingabestromreferenz, aus der die Informationen eingelesen
 * werden.
 * @param produkt Der Artikel, in den die Informationen eingelesen werden
 * sollen.
 */
void operator>>(istream &is, Artikel &produkt);

/**
 * @brief Die Klasse "Stueckgut" erbt von der Klasse "Artikel" und spezialisiert
 * sie fuer Stueckgut-Artikel.
 */
class Stueckgut : public Artikel {
private:
public:
  /**
   * @brief Konstruktor fuer die Klasse "Stueckgut".
   *
   * @param name Der Name des Stueckgut-Artikels.
   * @param num Die Artikelnummer des Stueckgut-Artikels.
   * @param vp Der Verkaufspreis des Stueckgut-Artikels.
   * @param bestand Der Lagerbestand des Stueckgut-Artikels (Standardwert: 1).
   */
  Stueckgut(Artikel produkt);
  Stueckgut(string name, string num, preis vp, unsigned int bestand = 1);
};

/**
 * Die Klasse "Schuettgut" erbt von der Klasse "Artikel" und spezialisiert sie
 * fuer Schuettgut-Artikel.
 * Die Klasse "Schuettgut" erweitert die Basisfunktionalitaet der Klasse
 * "Artikel" um die Beruecksichtigung der Losgroesse.
 */
class Schuettgut : public Artikel {
private:
  double losgroesse;

public:
  /**
   * @brief Konstruktor fuer die Klasse "Schuettgut" unter Verwendung eines
   * bereits existierenden Artikels.
   *
   * @param produkt Der Artikel, aus dem ein Schuettgut-Artikel erstellt wird.
   */
  Schuettgut(Artikel produkt);

  /**
   * @brief Konstruktor fuer die Klasse "Schuettgut".
   *
   * @param name Der Name des Schuettgut-Artikels.
   * @param num Die Artikelnummer des Schuettgut-Artikels.
   * @param groesse Die Losgroesse des Schuettgut-Artikels.
   * @param np Der Normalpreis des Schuettgut-Artikels.
   * @param bestand Der Lagerbestand des Schuettgut-Artikels (Standardwert: 1).
   */
  Schuettgut(string name, string num, double groesse, preis np,
             unsigned int bestand = 1);

  /**
   * @brief Gibt die Losgroesse des Schuettgut-Artikels zurueck.
   *
   * @return Die Losgroesse des Artikels.
   */
  double getLosgroesse() const;

  /**
   * @brief Setzt den Verkaufspreis des Schuettgut-Artikels basierend auf der
   * Losgroesse.
   *
   * @param vp Der Verkaufspreis, der gesetzt werden soll.
   */
  void setVerkaufpreis(preis vp);

  /**
   * @brief Setzt die Losgroesse des Schuettgut-Artikels.
   *
   * @param groesse Die neue Losgroesse.
   */
  void setLosgroesse(double groesse);
};

/**
 * @brief Die Klasse "Fluessigkeit" erbt von der Klasse "Artikel" und
 * spezialisiert sie fuer Fluessigkeits-Artikel.
 *
 * Die Klasse "Fluessigkeit" erweitert die Basisfunktionalitaet der Klasse
 * "Artikel" um die Beruecksichtigung des Volumens.
 */
class Fluessigkeit : public Artikel {
private:
  double volume;

public:
  /**
   * @brief Konstruktor fuer die Klasse "Fluessigkeit" unter Verwendung eines
   * bereits existierenden Artikels.
   *
   * @param produkt Der Artikel, aus dem ein Fluessigkeits-Artikel erstellt
   * wird.
   */
  Fluessigkeit(Artikel produkt);

  /**
   * @brief Konstruktor fuer die Klasse "Fluessigkeit".
   *
   * @param name Der Name des Fluessigkeits-Artikels.
   * @param num Die Artikelnummer des Fluessigkeits-Artikels.
   * @param vol Das Volumen des Fluessigkeits-Artikels.
   * @param np Der Normalpreis des Fluessigkeits-Artikels.
   * @param bestand Der Lagerbestand des Fluessigkeits-Artikels (Standardwert:
   * 1).
   */
  Fluessigkeit(string name, string num, double vol, preis np,
               unsigned int bestand = 1);

  /**
   * @brief Gibt das Volumen des Fluessigkeits-Artikels zurueck.
   *
   * @return Das Volumen des Artikels.
   */
  double getVolume() const;

  /**
   *
   * @param vp Der Verkaufspreis, der gesetzt werden soll.
   */
  void setVerkaufpreis(preis vp);

  /**
   * @brief Setzt das Volumen des Fluessigkeits-Artikels.
   *
   * @param vol Das neue Volumen.
   */
  void setVolume(double vol);
};

#endif // !LAGER_HH

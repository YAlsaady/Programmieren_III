  /**
  * @file lager.hh
  * @authors Yaman Alsaady, Oliver Schmidt
  * @brief
  * Dieses Header-Datei enthaelt die Definitionen von Klassen und
  * Funktionen zur Verwaltung von Artikeln und Warengruppen in einem
  * C++-Programm.
  * @version 0.1
  * @date 2023-10-04
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
  * @brief Setzt eine Standard-Warengruppenliste (nicht implementiert).
  */
  void defaultList();

  /**
  * @brief Gibt den Namen der Warengruppe fuer einen gegebenen Code zurueck.
  * 
  * @param code Der Warengruppencode.
  * @return Der Name der Warengruppe oder der Code, falls keine Warengruppe gefunden wurde.
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
 * @brief Die Klasse "Artikel" repraesentiert einen Artikel mit verschiedenen Eigenschaften.
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
  * @brief Statische Warengruppen-Instanz, die fuer alle Artikel gemeinsam genutzt wird.
  */
  static Warengruppen gruppe;

  /**
  * @brief Setzt die Warengruppe fuer Artikel.
  * 
  * @param g Die Warengruppe, die zugewiesen werden soll.
  */
  static void setGruppe(Warengruppen g);

/**
 * @brief Gibt den Namen des Artikels zurück.
 *
 * @return Der Name des Artikels.
 */
string getName() const;

/**
 * @brief Gibt die Artikelnummer des Artikels zurück.
 *
 * @return Die Artikelnummer des Artikels.
 */
string getArtikelnummer() const;

/**
 * @brief Gibt den Lagerbestand des Artikels zurück.
 *
 * @return Der Lagerbestand des Artikels.
 */
unsigned int getLagerabstand() const;

/**
 * @brief Gibt die Masseinheit des Artikels zurück.
 *
 * @return Die Masseinheit des Artikels (stk, kg, l).
 */
string getMasseinheit() const;

/**
 * @brief Gibt den Verkaufspreis des Artikels zurück.
 *
 * @return Der Verkaufspreis des Artikels.
 */
preis getVerkaufpreis() const;

/**
 * @brief Gibt den Normalpreis des Artikels zurück.
 *
 * @return Der Normalpreis des Artikels.
 */
preis getNormpreis() const;

/**
 * @brief Gibt die Warengruppe des Artikels zurück.
 *
 * @return Die Warengruppe des Artikels oder die Artikelnummer, falls keine Warengruppe gefunden wurde.
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

};

/**
* @brief Die Klasse "Stueckgut" erbt von der Klasse "Artikel" und spezialisiert sie fuer Stueckgut-Artikel.
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
  Stueckgut(string name, string num, preis vp, unsigned int bestand = 1);
};

/**
 * Die Klasse "Schuettgut" erbt von der Klasse "Artikel" und spezialisiert sie fuer Schuettgut-Artikel.
 */
class Schuettgut : public Artikel {
private:
  double losgroesse;

public:
  /**
  * @brief Konstruktor fuer die Klasse "Schuettgut".
  * 
  * @param name Der Name des Schuettgut-Artikels.
  * @param num Die Artikelnummer des Schuettgut-Artikels.
  * @param groesse Die Losgroeße des Schuettgut-Artikels.
  * @param np Der Normalpreis des Schuettgut-Artikels.
  * @param bestand Der Lagerbestand des Schuettgut-Artikels (Standardwert: 1).
  */
  Schuettgut(string name, string num, double groesse, preis np,
             unsigned int bestand = 1);
  /**
  * @brief Gibt die Losgroeße des Schuettgut-Artikels zurueck.
  * 
  * @return Die Losgroeße des Artikels.
  */
  double getLosgroesse() const;

  /**
  * @brief Setzt den Verkaufspreis des Schuettgut-Artikels basierend auf der Losgroeße.
  * 
  * @param vp Der Verkaufspreis, der gesetzt werden soll.
  */
  void setVerkaufpreis(preis vp);

  /**
  * @brief Setzt die Losgroeße des Schuettgut-Artikels.
  * 
  * @param groesse Die neue Losgroeße.
  */
  void setLosgroesse(double groesse);
};

/**
 * @brief Die Klasse "Fluessigkeit" erbt von der Klasse "Artikel" und spezialisiert sie fuer Fluessigkeits-Artikel.
 */
class Fluessigkeit : public Artikel {
private:
  double volume;
public:
  /**
   * @brief Konstruktor fuer die Klasse "Fluessigkeit".
   * 
   * @param name Der Name des Fluessigkeits-Artikels.
   * @param num Die Artikelnummer des Fluessigkeits-Artikels.
   * @param vol Das Volumen des Fluessigkeits-Artikels.
   * @param np Der Normalpreis des Fluessigkeits-Artikels.
   * @param bestand Der Lagerbestand des Fluessigkeits-Artikels (Standardwert: 1).
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

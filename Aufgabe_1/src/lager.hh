/**
 * @file lager.hh
 * @authors Yaman Alsaady, Oliver Schmidt
 * @brief Dieses Header-Datei enthaelt die Definitionen von Klassen und Funktionen zur Verwaltung von Artikeln und Warengruppen in einem C++-Programm.
 * @version 0.1
 * @date 2023-10-04
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <string>

using namespace std;
enum masseinheit { stk, kg, l };
typedef double preis;

namespace Warengruppen {
void init();
string getGruppe(string code);
void addGruppe(string code, string name);
void delGruppe(string code);
void changeGruppe(string code, string name);
void clear();
} // namespace Warengruppen


/**
 * Die Klasse "Artikel" repraesentiert einen Artikel mit verschiedenen Eigenschaften.
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
* Konstruktor fuer die Klasse "Artikel".
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
  ~Artikel();

    // Getter-Funktionen
    string getName();               /**< Gibt den Namen des Artikels zurueck. */
    string getArtikelnummer();      /**< Gibt die Artikelnummer des Artikels zurueck. */
    unsigned int getLagerabstand(); /**< Gibt den Lagerbestand des Artikels zurueck. */
    string getMasseinheit();        /**< Gibt die Einheit des Artikels zurueck. */
    preis getVerkaufpreis();        /**< Gibt den Verkaufspreis des Artikels zurueck. */
    preis getNormpreis();           /**< Gibt den Normalpreis des Artikels zurueck. */
    string getGruppe();             /**< Gibt die Warengruppe des Artikels zurueck. */

    // Setter-Funktionen
    void setName(string name);                    /**< Setzt den Namen des Artikels. */
    void setArtikelnummer(string num);            /**< Setzt die Artikelnummer des Artikels. */
    void setLagerbestand(unsigned int bestand);   /**< Setzt den Lagerbestand des Artikels. */
    void setMasseinheit(masseinheit einheit);     /**< Setzt die Einheit des Artikels. */
    void setVerkaufpreis(preis vp);               /**< Setzt den Verkaufspreis des Artikels. */
    void setNormpreis(preis np);                  /**< Setzt den Normalpreis des Artikels. */
};


/**
 * Die Klasse "Schuettgut" erbt von der Klasse "Artikel" und spezialisiert sie
 * fuer Schuettgut-Artikel.
 */
class Schuettgut : public Artikel {
private:
  double losgroesse;

public:
/**
* Konstruktor fuer die Klasse "Schuettgut".
*
* @param name Der Name des Schuettgut-Artikels.
* @param num Die Artikelnummer des Schuettgut-Artikels.
* @param vp Der Verkaufspreis des Schuettgut-Artikels.
* @param np Der Normalpreis des Schuettgut-Artikels.
* @param bestand Der Lagerbestand des Schuettgut-Artikels (Standardwert: 1).
*/
Schuettgut(string name, string num, double groesse, preis np,
             unsigned int bestand = 1);
  double getLosgroesse();
  void setVerkaufpreis(preis vp);
  void setLosgroesse(double groesse);
};

/**
 * Die Klasse "Stueckgut" erbt von der Klasse "Artikel" und spezialisiert sie
 * fuer Stueckgut-Artikel.
 */
class Stueckgut : public Artikel {
private:
public:
/**
* Konstruktor fuer die Klasse "Stueckgut".
*
* @param name Der Name des Stueckgut-Artikels.
* @param num Die Artikelnummer des Stueckgut-Artikels.
* @param vp Der Verkaufspreis des Stueckgut-Artikels.
* @param bestand Der Lagerbestand des Stueckgut-Artikels (Standardwert: 1).
*/
  Stueckgut(string name, string num, preis vp, unsigned int bestand = 1);
};

/**
 * Die Klasse "Flueßigkeit" erbt von der Klasse "Artikel" und spezialisiert sie
 * fuer Fluessigkeits-Artikel.
 */
class Fluessigkeit : public Artikel {
private:
public:
/**
* Konstruktor fuer die Klasse "Flueßigkeit".
*
* @param name Der Name des Fluessigkeits-Artikels.
* @param num Die Artikelnummer des Fluessigkeits-Artikels.
* @param vp Der Verkaufspreis des Fluessigkeits-Artikels.
* @param bestand Der Lagerbestand des Fluessigkeits-Artikels (Standardwert: 1).
*/
  Fluessigkeit(string name, string num, preis vp, unsigned int bestand = 1);
};

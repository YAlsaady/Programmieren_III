#ifndef STATS_H_
#define STATS_H_
#include <random>

/**
 * @brief Klasse fuer die Generierung von Zufallszahlen im angegebenen Intervall.
 */
class Data {
  std::mt19937 rng;
  std::uniform_int_distribution<unsigned int> dist;

public:
  /**
   * @brief Konstruktor fuer die Initialisierung des Zufallszahlengenerators und
   * der Verteilung.
   * @param a Untere Grenze des Intervalls.
   * @param b Obere Grenze des Intervalls.
   */
  Data(unsigned int a, unsigned int b)
      : rng(std::random_device()()), dist(a, b) {}

  /**
   * @brief Operatorfunktion zum Generieren einer Zufallszahl.
   * @return Zufallszahl im spezifizierten Intervall.
   */
  auto operator()(void) { return dist(rng); }
};

#endif /* STATS_H_ */

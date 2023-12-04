#include <algorithm>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <stdexcept>
#include <vector>

#include "stats.h"

using namespace std;
using namespace std::placeholders;

/**
 * @brief Hauptfunktion des Programms.
 *
 * - Füllt einen Vektor mit Zufallszahlen.
 * - Sortiert den Vektor aufsteigend und gibt ihn aus.
 * - Ermittelt die Häufigkeit der Zufallszahlen und stellt sie als Balkengrafik
 * dar.
 * - Berechnet den Durchschnitt der Häufigkeiten.
 *
 * @return Rückgabewert 0 bei erfolgreicher Ausführung.
 */
int main() {
  vector<unsigned int> v;

  // 1. Füllen von v mit 3902365 Zufallswerten.
  generate_n(back_inserter(v), 3902365, Data(1, 100));

  // 2. aufsteigend sortieren und mit ostream_iterator ausgeben.
  sort(v.begin(), v.end());
  copy(v.begin(), v.end(), ostream_iterator<unsigned int>(cout, ", "));
  cout << endl;

  // 3. Häufigkeit ermitteln.
  map<unsigned int, unsigned int> frequencyMap;
  for_each(v.begin(), v.end(),
           [&frequencyMap](unsigned int val) { frequencyMap[val]++; });

  // 4. Häufigkeit als Balkengrafik darstellen.
  for (const auto &entry : frequencyMap) {
    cout << setw(3) << entry.first << ": " << setw(6) << entry.second << " ";
    for (unsigned int i = 0; i < entry.second / 1000; ++i) {
      cout << "#";
    }
    cout << endl;
  }

  // 5. Durchschnitt berechnen und ausgeben.
  double average = accumulate(frequencyMap.begin(), frequencyMap.end(), 0.0,
                              [](double sum, const auto &entry) {
                                return sum + entry.second;
                              }) /
                   frequencyMap.size();
  cout << "Durchschnittliche Häufigkeit: " << average << endl;

  double average_value = accumulate(begin(v), end(v), 0.0) / v.size();

  cout << "Durchschnitt der Zufallszahlen: " << average_value << endl;

  return 0;
}

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

int main() {
  vector<unsigned int> v;

  /* 1. Füllen von v mit 3902365 Zufallswerten. */
  generate_n(back_inserter(v), 3902365, Data(1, 100));
  cout << "Vektor voll" << endl;

  /* 2. aufsteigend sortieren und mit ostream_iterator ausgeben. */
  sort(v.begin(), v.end());

  sort(v.begin(), v.end());
  copy(v.begin(), v.end(), ostream_iterator<unsigned int>(cout, ", "));
  cout << endl;

  /* 3. Häufigkeit ermitteln. */
  /* 4. Häufigkeit als Balkengrafik darstellen. */

  map<unsigned int, unsigned int> frequency_map;
  for (const auto &num : v) {
    frequency_map[num]++;
  }

  cout << "Häufigkeit der Werte und Balkendiagramm:" << endl;
  for (const auto &pair : frequency_map) {
    double balken_ = pair.second / (double)1000;

    if (pair.first < 10) {
      cout << "00" << pair.first << ": " << pair.second << " ";
    } else if (pair.first < 100) {
      cout << "0" << pair.first << ": " << pair.second << " ";
    } else {
      cout << pair.first << ": " << pair.second << " ";
    }

    for (int i = 0; i <= balken_; i++) {
      cout << "#";
    }
    cout << endl;
  }

  /* 5. Durchschnitt berechnen und ausgeben. */
  double average_frequency =
      accumulate(begin(frequency_map), end(frequency_map), 0.0,
                 [](double acc, const pair<unsigned int, unsigned int> &p) {
                   return acc + p.second;
                 }) /
      frequency_map.size();

  cout << "Durchschnitt der Häufigkeiten: " << average_frequency << endl;
  double average_value = accumulate(begin(v), end(v), 0.0) / v.size();

  cout << "Durchschnitt der Zufallszahlen: " << average_value << endl;
}

/* 6. Zusatzaufgabe nicht vergessen! */
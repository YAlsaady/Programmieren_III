#ifndef STATS_H_
#define STATS_H_
#include <random>

class Data {
  std::mt19937 rng;
  std::uniform_int_distribution<unsigned int> dist;
public:
  Data(unsigned int a, unsigned int b)
    : rng(std::random_device()()), dist(a,b) {}

  auto operator()(void) {
    return dist(rng);
  }
};

#endif /* STATS_H_ */

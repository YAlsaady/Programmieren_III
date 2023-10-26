#include "lager.hh"
#include <set>

class Regal {
public:
  Regal(const Lager &lager, Artikel::Nummer warengruppe);
  Regal(const Lager &lager, std::set<Artikel::Nummer> warengruppen);
  template <class OutputIterator> void products(OutputIterator out) const;

private:
  const Lager &lager;
  std::set<Artikel::Nummer> waren;
};

template <class OutputIterator> // int out {}

void Regal::products(OutputIterator out) const {}

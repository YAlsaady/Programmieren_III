#include "lager.hh"
#include <fstream>
#include <iostream>
#include <ostream>
#include <string>

using namespace std;
void read(string filename);
void readWrite(string read, string write);
int main(int argc, char *argv[]) {
  string filewrite = "";
  Warengruppen gruppe;
  gruppe.defaultList();
  Artikel::gruppe = gruppe;

  for (int i = 1; i < argc; i++) {
    string arg = argv[i];
    if (arg == "-o") {
      filewrite = argv[i + 1];
      break;
    }
  }

  for (int i = 1; i < argc; i++) {
    string arg = argv[i];
    if (arg == "-i") {
      if (filewrite != "") {
        readWrite(argv[i + 1], filewrite);
      } else {
        read(argv[i + 1]);
      }
    }
  }

  return 0;
}

void read(string filename) {
  ifstream file(filename);
  if (file.is_open()) {
    Artikel a[10];
    size_t i;
    for (i = 0; !file.eof(); i++) {
      try {
        file >> a[i];
      } catch (const int &ex) {
        i--;
      }
    }
    for (size_t k = 0; k < i; k++) {
      std::cout << a[k] << std::endl;
    }
    file.close();
  }
}

void readWrite(string read, string write) {
  ifstream readFile(read);
  ofstream writeFile(write);
  if (readFile.is_open() && writeFile.is_open()) {
    Artikel a[10];
    size_t i;
    for (i = 0; !readFile.eof(); i++) {
      try {
        readFile >> a[i];
      } catch (const int &ex) {
        i--;
      }
    }
    for (size_t k = 0; k < i; k++) {
      writeFile << a[k] << std::endl;
    }
    readFile.close();
    writeFile.close();
  }
}

#include "lager.hh"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <ostream>
#include <string>
#include <vector>

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
      ofstream file(filewrite);
      if (!file) exit(EXIT_FAILURE);
      file << "";
      break;
    }
  }

  for (int i = 1; i < argc; i++) {
    if (string(argv[i]) == "-i") {
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
    vector<Fluessigkeit> fluessigkeit;
    vector<Schuettgut> schuettgut;
    vector<Stueckgut> stueckgut;
    Artikel tmp;
    do {
      try {
        file >> tmp;
        switch (tmp.getMasseinheit()) {
          case 0:
            stueckgut.push_back(tmp);
            break;
          case 1:
            schuettgut.push_back(tmp);
            break;
          case 2:
            fluessigkeit.push_back(tmp);
            break;
        }
      } catch (const int &ex) {
      } catch (std::invalid_argument const &ex) {
      }
    } while(!file.eof());
    for(auto schuett : schuettgut){
      std::cout << schuett << std::endl;
    }
    std::cout << std::endl;
    for(auto stueck : stueckgut){
      std::cout << stueck << std::endl;
    }
    std::cout << std::endl;
    for(auto fluessig : fluessigkeit){
      std::cout << fluessig << std::endl;
    }
    file.close();
  }
}

void readWrite(string read, string write) {
  ifstream readFile(read);
  ofstream writeFile(write, std::ios::app);
  if (readFile.is_open() && writeFile.is_open()) {
    vector<Fluessigkeit> fluessigkeit;
    vector<Schuettgut> schuettgut;
    vector<Stueckgut> stueckgut;
    Artikel tmp;
    do {
      try {
        readFile >> tmp;
        switch (tmp.getMasseinheit()) {
          case 0:
            stueckgut.push_back(tmp);
            break;
          case 1:
            schuettgut.push_back(tmp);
            break;
          case 2:
            fluessigkeit.push_back(tmp);
            break;
        }
      } catch (const int &ex) {
      } catch (std::invalid_argument const &ex) {
      }
    } while(!readFile.eof());
    for(auto schuett : schuettgut){
      writeFile << schuett << std::endl;
    }
    // writeFile << std::endl;
    for(auto stueck : stueckgut){
      writeFile << stueck << std::endl;
    }
    // writeFile << std::endl;
    for(auto fluessig : fluessigkeit){
      writeFile << fluessig << std::endl;
    }
    readFile.close();
    writeFile.close();
  }
}

/*
void readWrite_old(string read, string write) {
  ifstream readFile(read);
  ofstream writeFile(write, std::ios::app);
  if (readFile.is_open() && writeFile.is_open()) {
    Artikel a[10];
    size_t i,j=1;
    for (i = 0; !readFile.eof(); i++, j++) {
      try {
        readFile >> a[i];
      } catch (const int &ex) {
        i--;
        cerr << "Falsche Inforamtionen in Zeile: " << j << endl;
      } catch (std::invalid_argument const &ex) {
        i--;
        cerr << "Falsche Inforamtionen in Zeile: " << j << endl;
      }
    }
    for (size_t k = 0; k < i; k++) {
      writeFile << a[k] << std::endl;
    }
    readFile.close();
    writeFile.close();
  }
}

void read_old(string filename) {
  ifstream file(filename);
  if (file.is_open()) {
    Artikel a[10];
    size_t i;
    for (i = 0; !file.eof(); i++) {
      try {
        file >> a[i];
      } catch (const int &ex) {
        i--;
      } catch (std::invalid_argument const &ex) {
        i--;
      }
    }
    for (size_t k = 0; k < i; k++) {
      std::cout << a[k] << std::endl;
    }
    file.close();
  }
}
*/

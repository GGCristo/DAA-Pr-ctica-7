// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include "../include/data.hpp"

Data& Data::getInstance() {
  static Data instance;
  return instance;
}

Data::Data() {
  if (fichero_ == "") {
    throw "Especifíca el fichero\n";
  }
  std::fstream fichero;
  fichero.open(fichero_, std::ios::in);
  if (!fichero) {
    throw std::string("No se pudo abrir el fichero ") + fichero_  + '\n';
  }
  std::string linea;
  while(getline(fichero, linea)) {
    switch(linea[0]) {
      case 'n': {
                  std::string n;
                  std::stringstream linea_stream(linea);
                  linea_stream >> n;
                  linea_stream >> n;
                  n_ = std::stoi(n);
                }
                break;
      case 'm': {
                  std::string m;
                  std::stringstream linea_stream(linea);
                  linea_stream >> m;
                  linea_stream >> m;
                  m_ = std::stoi(m);
                }
                break;
      case 'P': {
                  times(linea);
                }
                break;
      case 'S': {
                  setups(fichero);
                }
      default:
                break;
    }
  }
  fichero.close();
}

int Data::getN() {
  return n_;
}

int Data::getM() {
  return m_;
}

bool Data::areAllTaskReady() {
  for (int i = 0; i < n_; ++i) {
    if (times_[i].second == false) {
      return false;
    }
  }
  return true;
}

void Data::times(const std::string& linea) {
  std::vector<std::pair<int, bool>> times;
  std::string numero;
  std::stringstream linea_stream(linea);
  while (linea_stream >> numero) {
    if(numero[numero.size() - 1] == ']') {
      break;
    }
    continue;
  }
  while(linea_stream >> numero) {
    times.emplace_back(std::stoi(numero), false);
  }
  times_ = times;
}

std::vector<std::pair<int, bool>>& Data::getTimes() {
  return times_;
}

void Data::setups(std::fstream& fichero) {
  std::string linea;
  // std::stringstream linea_stream(linea);
  // while (linea_stream >> ignorar) {
  //   if(ignorar[ignorar.size() - 1] == ']') {
  //     break;
  //   }
  //   continue;
  // }
  std::string number;
  while(getline(fichero ,linea)) {
    std::vector<int> row;
    row.reserve(n_ + 1);
    std::stringstream linea_stream_inner(linea);
    while(linea_stream_inner >> number) {
      row.push_back(std::stoi(number));
    }
    setups_.push_back(row);
  }
}


void Data::reset() {
  for (size_t i = 0; i < times_.size(); ++i) {
    times_[i].second = false;
  }
}

const std::vector<std::vector<int>>& Data::getSetups(){
  return setups_;
}

void Data::showTimes() {
  for (size_t i = 0; i < times_.size(); ++i){
    std::cout << times_[i].first << ' ';
  }
  std::cout << '\n';
}

void Data::showSetups() {
  for (size_t i = 0; i < setups_.size(); ++i) {
    for (size_t j = 0; j < setups_[i].size(); ++j) {
      std::cout << setups_[i][j] << ' ';
    }
    std::cout << '\n';
  }
}

#include "../include/datos.hpp"

Datos::Datos() {
  std::fstream fichero;
  fichero.open("I40j_2m_S1_1.txt", std::ios::in);
  if (!fichero)
  {
    throw "No se ha podido cargar el programa";
  }
  std::string linea;
  while(getline(fichero, linea)) {
    // std::cout << "Linea: " << linea << '\n';
    // std::cin.get();
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
                  // std::cout << "Voy a mostrar los tiempos\n" << '\n';
                  // for (size_t i = 0; i < tiempos.size(); ++i) {
                  // std::cout << tiempos[i] << '\n';
                  // }
                }
                break;
      case 'S': {
                  setups(fichero, linea);
                  // std::cout << "Voy a mostrar los setups\n" << '\n';
                  // for (size_t i = 0; i < setup.size(); ++i) {
                  // std::cout << setup[i] << '\n';
                  // }
                }

      default:
                break;
    }
  }
  fichero.close();
}

int Datos::getN() {
  return n_;
}

int Datos::getM() {
  return m_;
}

void Datos::times(const std::string& linea) {
  std::vector<int> times;
  std::string numero;
  std::stringstream linea_stream(linea);
  while (linea_stream >> numero) {
    if(numero[numero.size() - 1] == ']') {
      break;
    }
    continue;
  }
  while(linea_stream >> numero) {
    times.emplace_back(std::stoi(numero));
  }
  times_ = times;
}

const std::vector<int>& Datos::getTimes() {
  return times_;
}

void Datos::setups(std::fstream& fichero,std::string& linea) {
  std::vector<std::vector<int>> setups;
  std::string numero;
  std::stringstream linea_stream(linea);
  while (linea_stream >> numero) {
    if(numero[numero.size() - 1] == ']') {
      break;
    }
    continue;
  }
  std::vector<int> row;
  row.reserve(n_ + 1);
  while(getline(fichero ,linea)) {
    std::stringstream linea_stream(linea);
    while(linea_stream >> numero) {
      row.emplace_back(std::stoi(numero));
    }
    setups.emplace_back(row);
    row.clear();
  }
  setups_ = setups;
}

const std::vector<std::vector<int>>& Datos::getSetups(){
  return setups_;
}

void Datos::showTimes() {
  for (size_t i = 0; i < times_.size(); ++i){
    std::cout << times_[i] << ' ';
  }
  std::cout << '\n';
}

void Datos::showSetups() {
  for (size_t i = 0; i < setups_.size(); ++i) {
    for (size_t j = 0; j < setups_[i].size(); ++j) {
      std::cout << setups_[i][j] << ' ';
    }
    std::cout << '\n';
  }
}

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
                  std::cout << "n: " << n << '\n';
                }
                break;
      case 'm': {
                  std::string m;
                  std::stringstream linea_stream(linea);
                  linea_stream >> m;
                  linea_stream >> m;
                  m_ = std::stoi(m);
                  std::cout << "m: " << m << '\n';

                }
                break;
      case 'P': {
                  times_ = times(linea);
                  // std::cout << "Voy a mostrar los tiempos\n" << '\n';
                  // for (size_t i = 0; i < tiempos.size(); ++i) {
                  // std::cout << tiempos[i] << '\n';
                  // }
                }
                break;
      case 'S': {
                  setups_ = setups(fichero, linea);
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

std::vector<int> Datos::times(const std::string& linea) {
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
  std::cout << "times: " << &times << '\n';
  return times;
}

const std::vector<int>& Datos::get_times() {
  std::cout << "times_: " << &times_ << '\n';
  return times_;
}

std::vector<int> Datos::setups(std::fstream& fichero,std::string& linea) {
  std::vector<int> setups;
  std::string numero;
  std::stringstream linea_stream(linea);
  while (linea_stream >> numero) {
    if(numero[numero.size() - 1] == ']') {
      break;
    }
    continue;
  }
  while(linea_stream >> numero) {
    setups.emplace_back(std::stoi(numero));
  }
  while(getline(fichero ,linea)) {
    std::stringstream linea_stream(linea);
    while(linea_stream >> numero) {
      setups.emplace_back(std::stoi(numero));
    }
  }
  std::cout << "setups: " << &setups << '\n';
  return setups;
}

const std::vector<int>& Datos::get_setups(){
  std::cout << "setups_: " << &setups_ << '\n';
  return setups_;
}

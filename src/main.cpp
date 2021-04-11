#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

#include "../include/datos.hpp"
#include "../include/maquina.hpp"

// TODO Hacer la lectura de líneas más robusta, asegurarte de cuando parar de
// leer Pi y pasar a Sij y demás
int main() {
  std::vector<Maquina> maquinas;
  for (int i = 0; i < Datos::getInstance().getM(); ++i) {
    maquinas.emplace_back(Maquina());
  }
  std::cout << "Hay " << maquinas.size() << " creadas\n";
  // datos.showTimes();
  // std::cout << "\n";
  // datos.showSetups();
  return 0;
}

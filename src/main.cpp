#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

#include "../include/datos.hpp"
#include "../include/maquina.hpp"
#include "../include/voraz.hpp"

// TODO Hacer la lectura de líneas más robusta, asegurarte de cuando parar de
// leer Pi y pasar a Sij y demás
int main() {
  std::vector<Maquina> maquinas;
  for (int i = 0; i < Datos::getInstance().getM(); ++i) {
    maquinas.emplace_back(Maquina());
  }
  std::cout << "Hay " << maquinas.size() << " maquinas creadas\n";
  try {
    voraz(maquinas);
  } catch (const std::string message) {
    std::cout << message;
    return 1;
  }
  for (size_t i = 0; i < maquinas.size(); ++i) {
    std::cout << "Maquina " << i + 1 << ": ";
    maquinas[i].show();
    std::cout << "\nTCTlocal: " << maquinas[i].getTime() << '\n';
  }
  std::cout << "\n";
  return 0;
}

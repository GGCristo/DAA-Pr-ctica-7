// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

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
  try {
    // Datos::fichero_ = "I40j_2m_S1_1.txt";
    // Datos::fichero_ = "I40j_2mS1_1.txt"; // empty
    // Datos::fichero_ = "I40j_4m_S1_1.txt";
    // Datos::fichero_ = "I40j_6m_S1_1.txt";
    Datos::fichero_ = "I40j_8m_S1_1.txt";
    std::vector<Maquina> maquinas;
    for (int i = 0; i < Datos::getInstance().getM(); ++i) {
      maquinas.emplace_back(Maquina());
    }
    std::cout << "Hay " << maquinas.size() << " maquinas creadas\n";
    voraz(maquinas);
    for (size_t i = 0; i < maquinas.size(); ++i) {
      std::cout << "Maquina " << i + 1 << ": ";
      maquinas[i].show();
      std::cout << "\nTCTlocal: " << maquinas[i].getTime() << '\n';
    }
    std::cout << "\n";
  } catch (const std::string& message) {
    std::cout << message;
    return 1;
  } catch(const char* message) {
    std::cout << message;
    return 1;
  }
  return 0;
}

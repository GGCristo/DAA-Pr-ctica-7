// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <memory>

#include "../include/datos.hpp"
#include "../include/maquina.hpp"
#include "../include/solucion.hpp"

void mainTryCatch() {
  // Datos::fichero_ = "I40j_2m_S1_1.txt";
  // Datos::fichero_ = "I40j_2mS1_1.txt"; // empty
  Datos::fichero_ = "I40j_4m_S1_1.txt";
  // Datos::fichero_ = "I40j_6m_S1_1.txt";
  // Datos::fichero_ = "I40j_8m_S1_1.txt";
  // Datos::fichero_ = "prueba.txt";

  Solucion solucion(std::make_unique<Voraz>(Voraz()));
  solucion.ejecutar();
  solucion.show(std::cout);
  std::cout << solucion.getZ() << '\n';

  // Solucion solucion1(std::make_unique<Voraz>(Voraz()));
  // solucion1.ejecutar();
  // solucion1.show(std::cout);
  // std::cout << solucion1.getZ() << '\n';
}

int main() {
  try {
    mainTryCatch();
  } catch (const std::string& message) {
    std::cout << message;
    return 1;
  } catch(const char* message) {
    std::cout << message;
    return 1;
  }
  return 0;
}

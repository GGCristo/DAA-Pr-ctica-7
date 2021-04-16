// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <memory>

#include "../include/datos.hpp"
#include "../include/solucion.hpp"
#include "../include/greedy_time.hpp"
#include "../include/greedy_TCT.hpp"
#include "../include/grasp.hpp"

void mainTryCatch() {
  // Datos::fichero_ = "I40j_2m_S1_1.txt";
  // Datos::fichero_ = "I40j_2mS1_1.txt"; // empty
  // Datos::fichero_ = "I40j_4m_S1_1.txt";
  // Datos::fichero_ = "I40j_6m_S1_1.txt";
  // Datos::fichero_ = "I40j_8m_S1_1.txt";
  Datos::fichero_ = "prueba.txt";

  Solucion solucion0(Datos::getInstance().getM(), std::make_unique<GreedyTime>());
  solucion0.ejecutar();
  solucion0.showWithTCTs(std::cout);

  // solucion0.extraSwap(0, 1, 0, 3);
  // solucion0.showWithTCTs(std::cout);

  // Solucion solucion1(Datos::getInstance().getM(), std::make_unique<GreedyTCT>());
  // solucion1.ejecutar();
  // solucion1.showWithTCTs(std::cout);

  // Solucion solucion2(Datos::getInstance().getM(), std::make_unique<Grasp>());
  // solucion2.ejecutar();
  // solucion2.showWithTCTs(std::cout);
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

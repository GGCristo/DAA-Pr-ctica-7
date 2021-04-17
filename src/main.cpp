// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include <iostream>
#include <memory>

#include "../include/testing.hpp"
#include "../include/datos.hpp"
#include "../include/solucion.hpp"
#include "../include/greedy_time.hpp"
#include "../include/greedy_TCT.hpp"
#include "../include/grasp.hpp"

enum Movements { reInsert, move, innerSwap, extraSwap };
enum Stop_Criterion {iterations, iterationsSinceImprovement};

void mainTryCatch() {
  // Datos::fichero_ = "I40j_2m_S1_1.txt";
  // Datos::fichero_ = "I40j_2mS1_1.txt"; // empty
  // Datos::fichero_ = "I40j_4m_S1_1.txt";
  // Datos::fichero_ = "I40j_6m_S1_1.txt";
  // Datos::fichero_ = "I40j_8m_S1_1.txt";
  Datos::fichero_ = "prueba.txt";

  std::unique_ptr<ParallelInterface> greedyTime = std::make_unique<GreedyTime>();
  Solucion solucion0(greedyTime->run(Datos::getInstance().getM()));
  solucion0.showWithTCTs(std::cout);

  // solucion0.extraSwap(0, 1, 0, 3);
  // solucion0.showWithTCTs(std::cout);

  std::unique_ptr<ParallelInterface> greedyTct = std::make_unique<GreedyTCT>();
  Solucion solucion1(greedyTct->run(Datos::getInstance().getM()));
  solucion1.showWithTCTs(std::cout);

  std::unique_ptr<ParallelInterface> grasp_reInsert = std::make_unique<Grasp>(reInsert);
  Solucion solucion2(grasp_reInsert->run(Datos::getInstance().getM()));
  solucion2.showWithTCTs(std::cout);

  std::unique_ptr<ParallelInterface> grasp_move = std::make_unique<Grasp>(move);
  Solucion solucion3(grasp_move->run(Datos::getInstance().getM()));
  solucion3.showWithTCTs(std::cout);

  std::unique_ptr<ParallelInterface> grasp_innerSwap = std::make_unique<Grasp>(innerSwap);
  Solucion solucion4(grasp_innerSwap->run(Datos::getInstance().getM()));
  solucion4.showWithTCTs(std::cout);

  std::unique_ptr<ParallelInterface> grasp_extraSwap = std::make_unique<Grasp>(extraSwap);
  Solucion solucion5(grasp_extraSwap->run(Datos::getInstance().getM()));
  solucion5.showWithTCTs(std::cout);
}

int main() {
  try {
    mainTryCatch();
    // testing();
  } catch (const std::string& message) {
    std::cout << message;
    return 1;
  } catch(const char* message) {
    std::cout << message;
    return 1;
  }
  return 0;
}

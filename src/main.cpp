// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include <iostream>
#include <memory>

#include "../include/testing.hpp"
#include "../include/data.hpp"
#include "../include/solution.hpp"
#include "../include/greedy_time.hpp"
#include "../include/greedy_TCT.hpp"
#include "../include/multiboot.hpp"

enum Movements { reInsert, move, innerSwap, extraSwap };

void mainTryCatch() {
  // Datos::fichero_ = "I40j_2m_S1_1.txt";
  // Datos::fichero_ = "I40j_2mS1_1.txt"; // empty
  // Datos::fichero_ = "I40j_4m_S1_1.txt";
  // Datos::fichero_ = "I40j_6m_S1_1.txt";
  // Datos::fichero_ = "I40j_8m_S1_1.txt";
  Data::fichero_ = "prueba.txt";

  // std::unique_ptr<ParallelInterface> greedyTime = std::make_unique<GreedyTime>();
  // Solution solucion0(greedyTime->run(Datos::getInstance().getM()));
  // solucion0.showWithTCTs(std::cout);

  // solucion0.extraSwap(0, 1, 0, 3);
  // solucion0.showWithTCTs(std::cout);

  // std::unique_ptr<ParallelInterface> greedyTct = std::make_unique<GreedyTCT>();
  // Solution solucion1(greedyTct->run(Datos::getInstance().getM()));
  // solucion1.showWithTCTs(std::cout);

  // std::unique_ptr<ParallelInterface> multiboost_reInsert = std::make_unique<Multiboot>(reInsert);
  // Solution solucion2(multiboost_reInsert->run(Datos::getInstance().getM()));
  // solucion2.showWithTCTs(std::cout);

  // std::unique_ptr<ParallelInterface> multiboost_move = std::make_unique<Multiboot>(move);
  // Solution solucion3(multiboost_move->run(Datos::getInstance().getM()));
  // solucion3.showWithTCTs(std::cout);

  std::unique_ptr<ParallelInterface> multiboost_innerSwap = std::make_unique<Multiboot>(innerSwap);
  Solution solucion4(multiboost_innerSwap->run(Data::getInstance().getM()));
  solucion4.showWithTCTs(std::cout);

  // std::unique_ptr<ParallelInterface> multiboost_extraSwap = std::make_unique<Multiboot>(extraSwap);
  // Solution solucion5(multiboost_extraSwap->run(Datos::getInstance().getM()));
  // solucion5.showWithTCTs(std::cout);
}

int main() {
  try {
    // mainTryCatch();
    testing();
  } catch (const std::string& message) {
    std::cout << message;
    return 1;
  } catch(const char* message) {
    std::cout << message;
    return 1;
  }
  return 0;
}

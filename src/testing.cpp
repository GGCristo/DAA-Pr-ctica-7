// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include "../include/testing.hpp"

enum Movements { reInsert, move, innerSwap, extraSwap };
enum Stop_Criterion {iterations, iterationsSinceImprovement};

void testing() {
  // Datos::fichero_ = "I40j_2m_S1_1.txt"; std::cout << "(2 files)\n";
  // Datos::fichero_ = "I40j_4m_S1_1.txt"; std::cout << "(4 files)\n";
  // Datos::fichero_ = "I40j_6m_S1_1.txt"; std::cout << "(6 files)\n";
  Datos::fichero_ = "I40j_8m_S1_1.txt"; std::cout << "(8 files)\n";
  std::cout << "||| GreedyTime|||\n";
  testing_greedyTime();
  std::cout << "||| GreedyTct |||\n";
  testing_greedyTct();
  std::cout << "||| MultiBootReinsert (iterations)|||\n";
  testing_reinsert(iterations);
  std::cout << "||| MultiBootReinsert (iterationsSinceImprovement)|||\n";
  testing_reinsert(iterationsSinceImprovement);
  std::cout << "||| MultiBootMove (iterations)|||\n";
  testing_move(iterations);
  std::cout << "||| MultiBootMove (iterationsSinceImprovement)|||\n";
  testing_move(iterationsSinceImprovement);
  std::cout << "||| MultiBootInnerSwap (iterations)|||\n";
  testin_innerSwap(iterations);
  std::cout << "||| MultiBootInnerSwap (iterationsSinceImprovement)|||\n";
  testin_innerSwap(iterationsSinceImprovement);
  std::cout << "||| MultiBootExtraSwap (iterations)|||\n";
  testing_extraSwap(iterations);
  std::cout << "||| MultiBootExtraSwap (iterationsSinceImprovement)|||\n";
  testing_extraSwap(iterationsSinceImprovement);
}

void testing_greedyTime() {
  std::unique_ptr<ParallelInterface> greedyTime = std::make_unique<GreedyTime>();

  auto t1 = std::chrono::high_resolution_clock::now();
  Solucion solucion0(greedyTime->run(Datos::getInstance().getM()));
  auto t2 = std::chrono::high_resolution_clock::now();
  std::cout << "TEST1 time: "
    << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count() << " microsegundos | "
    << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count()/1000.0 << " milisegundos | "
    << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count()/1000000.0 << " segundos\n";

  solucion0.showOnlyZ(std::cout);
}

void testing_greedyTct() {
  std::unique_ptr<ParallelInterface> greedyTct = std::make_unique<GreedyTCT>();

  auto t1 = std::chrono::high_resolution_clock::now();
  Solucion solucion1(greedyTct->run(Datos::getInstance().getM()));
  auto t2 = std::chrono::high_resolution_clock::now();
  std::cout << "TEST1 time: "
    << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count() << " microsegundos | "
    << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count()/1000.0 << " milisegundos | "
    << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count()/1000000.0 << " segundos\n";

  solucion1.showOnlyZ(std::cout);
}

void testing_reinsert(int stopCriterion) {
  std::unique_ptr<ParallelInterface> grasp_reInsert = std::make_unique<Grasp>(reInsert, stopCriterion);

  auto t1 = std::chrono::high_resolution_clock::now();
  Solucion solucion2(grasp_reInsert->run(Datos::getInstance().getM()));
  auto t2 = std::chrono::high_resolution_clock::now();
  std::cout << "TEST1 time: "
    << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count() << " microsegundos | "
    << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count()/1000.0 << " milisegundos | "
    << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count()/1000000.0 << " segundos\n";

  solucion2.showOnlyZ(std::cout);
}

void testing_move(int stopCriterion) {
  std::unique_ptr<ParallelInterface> grasp_move = std::make_unique<Grasp>(move, stopCriterion);

  auto t1 = std::chrono::high_resolution_clock::now();
  Solucion solucion3(grasp_move->run(Datos::getInstance().getM()));
  auto t2 = std::chrono::high_resolution_clock::now();
  std::cout << "TEST1 time: "
    << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count() << " microsegundos | "
    << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count()/1000.0 << " milisegundos | "
    << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count()/1000000.0 << " segundos\n";

  solucion3.showOnlyZ(std::cout);
}

void testin_innerSwap(int stopCriterion) {
  std::unique_ptr<ParallelInterface> grasp_innerSwap = std::make_unique<Grasp>(innerSwap, stopCriterion);

  auto t1 = std::chrono::high_resolution_clock::now();
  Solucion solucion4(grasp_innerSwap->run(Datos::getInstance().getM()));
  auto t2 = std::chrono::high_resolution_clock::now();

  std::cout << "TEST1 time: "
    << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count() << " microsegundos | "
    << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count()/1000.0 << " milisegundos | "
    << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count()/1000000.0 << " segundos\n";
  solucion4.showOnlyZ(std::cout);
}

void testing_extraSwap(int stopCriterion) {
  std::unique_ptr<ParallelInterface> grasp_extraSwap = std::make_unique<Grasp>(extraSwap, stopCriterion);

  auto t1 = std::chrono::high_resolution_clock::now();
  Solucion solucion5(grasp_extraSwap->run(Datos::getInstance().getM()));
  auto t2 = std::chrono::high_resolution_clock::now();
  std::cout << "TEST1 time: "
    << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count() << " microsegundos | "
    << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count()/1000.0 << " milisegundos | "
    << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count()/1000000.0 << " segundos\n";

  solucion5.showOnlyZ(std::cout);
}

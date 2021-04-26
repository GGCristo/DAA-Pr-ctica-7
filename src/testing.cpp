// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include "../include/testing.hpp"

enum Movements { reInsert, move, innerSwap, extraSwap };
enum Stop_Criterion { iterations, iterationsSinceImprovement };

void testing() {
  // Data::file_ = "I40j_2m_S1_1.txt"; std::cout << "(2 machines)\n";
  // Data::file_ = "I40j_4m_S1_1.txt"; std::cout << "(4 machines)\n";
  // Data::file_ = "I40j_6m_S1_1.txt"; std::cout << "(6 machines)\n";
  Data::file_ = "I40j_8m_S1_1.txt"; std::cout << "(8 machines)\n";
  // Data::file_ = "prueba.txt"; std::cout << "(2 machines)\n";

  // std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
  // std::cout << "||| GreedyTime|||\n";
  // testing_greedyTime();
  // std::cout << "||| GreedyTct |||\n";
  // testing_greedyTct();
  // std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
  // // MultiBoot
  // std::cout << "||| MultiBootReinsert (iterations)|||\n";
  // testing_reinsert(iterations);
  // std::cout << "||| MultiBootReinsert (iterationsSinceImprovement)|||\n";
  // testing_reinsert(iterationsSinceImprovement);
  // std::cout << "||| MultiBootMove (iterations)|||\n";
  // testing_move(iterations);
  // std::cout << "||| MultiBootMove (iterationsSinceImprovement)|||\n";
  // testing_move(iterationsSinceImprovement);
  // std::cout << "||| MultiBootInnerSwap (iterations)|||\n";
  // testin_innerSwap(iterations);
  // std::cout << "||| MultiBootInnerSwap (iterationsSinceImprovement)|||\n";
  // testin_innerSwap(iterationsSinceImprovement);
  // std::cout << "||| MultiBootExtraSwap (iterations)|||\n";
  // testing_extraSwap(iterations);
  // std::cout << "||| MultiBootExtraSwap (iterationsSinceImprovement)|||\n";
  // testing_extraSwap(iterationsSinceImprovement);
  // GVNS
  std::cout << "||| GVNSReInsertAndMove (iterations)|||\n";
  testing_gvnsReInsertAndMove(iterations);
  // std::cout << "||| GVNSReInsertAndMove (iterationsSinceImprovement)|||\n";
  // testing_gvnsReInsertAndMove(iterationsSinceImprovement);
  // std::cout << "||| GVNSReInsertAndExtraSwap (iterations)|||\n";
  // testing_gvnsReInsertAndExtraSwap(iterations);
  // std::cout << "||| GVNSReInsertAndExtraSwap (iterationsSinceImprovement)|||\n";
  // testing_gvnsReInsertAndExtraSwap(iterationsSinceImprovement);
  // std::cout << "||| GVNSExtraSwapAndMove (iterations)|||\n";
  // testing_gvnsExtraSwapAndMove(iterations);
  // std::cout << "||| GVNSExtraSwapAndMove (iterationsSinceImprovement)|||\n";
  // testing_gvnsExtraSwapAndMove(iterationsSinceImprovement);
  // std::cout << "||| GVNSExtraSwapAndExtraSwap (iterations)|||\n";
  // testing_gvnsExtraSwapAndExtraSwap(iterations);
  // std::cout << "||| GVNSExtraSwapAndExtraSwap (iterationsSinceImprovement)|||\n";
  // testing_gvnsExtraSwapAndExtraSwap(iterationsSinceImprovement);

  // Anxious
  // MultiBoot
  // std::cout << "||| MultiBootReinsert (iterations && anxious)|||\n";
  // testing_reinsert(iterations, true);
  // std::cout << "||| MultiBootReinsert (iterationsSinceImprovement && anxious)|||\n";
  // testing_reinsert(iterationsSinceImprovement, true);
  // std::cout << "||| MultiBootMove (iterations && anxious)|||\n";
  // testing_move(iterations, true);
  // std::cout << "||| MultiBootMove (iterationsSinceImprovement && anxious)|||\n";
  // testing_move(iterationsSinceImprovement, true);
  // std::cout << "||| MultiBootInnerSwap (iterations && anxious)|||\n";
  // testin_innerSwap(iterations, true);
  // std::cout << "||| MultiBootInnerSwap (iterationsSinceImprovement && anxious)|||\n";
  // testin_innerSwap(iterationsSinceImprovement, true);
  // std::cout << "||| MultiBootExtraSwap (iterations && anxious)|||\n";
  // testing_extraSwap(iterations, true);
  // std::cout << "||| MultiBootExtraSwap (iterationsSinceImprovement && anxious)|||\n";
  // testing_extraSwap(iterationsSinceImprovement, true);
  // // GVNS
  // std::cout << "||| GVNSReInsertAndMove (iterations && anxious)|||\n";
  // testing_gvnsReInsertAndMove(iterations, true);
  // std::cout << "||| GVNSReInsertAndMove (iterationsSinceImprovement && anxious)|||\n";
  // testing_gvnsReInsertAndMove(iterationsSinceImprovement, true);
  // std::cout << "||| GVNSReInsertAndExtraSwap (iterations && anxious)|||\n";
  // testing_gvnsReInsertAndExtraSwap(iterations, true);
  // std::cout << "||| GVNSReInsertAndExtraSwap (iterationsSinceImprovement && anxious)|||\n";
  // testing_gvnsReInsertAndExtraSwap(iterationsSinceImprovement, true);
  // std::cout << "||| GVNSExtraSwapAndMove (iterations && anxious)|||\n";
  // testing_gvnsExtraSwapAndMove(iterations, true);
  // std::cout << "||| GVNSExtraSwapAndMove (iterationsSinceImprovement && anxious)|||\n";
  // testing_gvnsExtraSwapAndMove(iterationsSinceImprovement, true);
  // std::cout << "||| GVNSExtraSwapAndExtraSwap (iterations && anxious)|||\n";
  // testing_gvnsExtraSwapAndExtraSwap(iterations, true);
  // std::cout << "||| GVNSExtraSwapAndExtraSwap (iterationsSinceImprovement && anxious)|||\n";
  // testing_gvnsExtraSwapAndExtraSwap(iterationsSinceImprovement, true);

}

void testing_gvnsReInsertAndMove(int stopCriterion, bool anxious) {
  std::unique_ptr<ParallelInterface> gvnsReInsertAndMove =
    std::make_unique<GVNS>(reInsert, move, stopCriterion, anxious);

  auto t1 = std::chrono::high_resolution_clock::now();
  Solution solucion2(gvnsReInsertAndMove->run(Data::getInstance().getM()));
  auto t2 = std::chrono::high_resolution_clock::now();
  std::cout << "Time: "
    << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count() << " microsegundos | "
    << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count()/1000.0 << " milisegundos | "
    << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count()/1000000.0 << " segundos\n";

  solucion2.showOnlyZ(std::cout);
}

void testing_gvnsReInsertAndExtraSwap(int stopCriterion, bool anxious) {
  std::unique_ptr<ParallelInterface> gvnsReInsertAndMove =
    std::make_unique<GVNS>(reInsert, extraSwap, stopCriterion, anxious);

  auto t1 = std::chrono::high_resolution_clock::now();
  Solution solucion2(gvnsReInsertAndMove->run(Data::getInstance().getM()));
  auto t2 = std::chrono::high_resolution_clock::now();
  std::cout << "Time: "
    << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count() << " microsegundos | "
    << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count()/1000.0 << " milisegundos | "
    << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count()/1000000.0 << " segundos\n";

  solucion2.showOnlyZ(std::cout);
}

void testing_gvnsExtraSwapAndMove(int stopCriterion, bool anxious) {
  std::unique_ptr<ParallelInterface> gvnsReInsertAndMove =
    std::make_unique<GVNS>(extraSwap, move, stopCriterion, anxious);

  auto t1 = std::chrono::high_resolution_clock::now();
  Solution solucion2(gvnsReInsertAndMove->run(Data::getInstance().getM()));
  auto t2 = std::chrono::high_resolution_clock::now();
  std::cout << "Time: "
    << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count() << " microsegundos | "
    << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count()/1000.0 << " milisegundos | "
    << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count()/1000000.0 << " segundos\n";

  solucion2.showOnlyZ(std::cout);
}

void testing_gvnsExtraSwapAndExtraSwap(int stopCriterion, bool anxious) {
  std::unique_ptr<ParallelInterface> gvnsReInsertAndMove =
    std::make_unique<GVNS>(extraSwap, extraSwap, stopCriterion, anxious);

  auto t1 = std::chrono::high_resolution_clock::now();
  Solution solucion2(gvnsReInsertAndMove->run(Data::getInstance().getM()));
  auto t2 = std::chrono::high_resolution_clock::now();
  std::cout << "Time: "
    << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count() << " microsegundos | "
    << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count()/1000.0 << " milisegundos | "
    << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count()/1000000.0 << " segundos\n";

  solucion2.showOnlyZ(std::cout);
}

void testing_greedyTime() {
  std::unique_ptr<ParallelInterface> greedyTime = std::make_unique<GreedyTime>();

  auto t1 = std::chrono::high_resolution_clock::now();
  Solution solucion0(greedyTime->run(Data::getInstance().getM()));
  auto t2 = std::chrono::high_resolution_clock::now();
  std::cout << "Time: "
    << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count() << " microsegundos | "
    << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count()/1000.0 << " milisegundos | "
    << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count()/1000000.0 << " segundos\n";

  solucion0.showOnlyZ(std::cout);
}

void testing_greedyTct() {
  std::unique_ptr<ParallelInterface> greedyTct = std::make_unique<GreedyTCT>();

  auto t1 = std::chrono::high_resolution_clock::now();
  Solution solucion1(greedyTct->run(Data::getInstance().getM()));
  auto t2 = std::chrono::high_resolution_clock::now();
  std::cout << "Time: "
    << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count() << " microsegundos | "
    << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count()/1000.0 << " milisegundos | "
    << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count()/1000000.0 << " segundos\n";

  solucion1.showOnlyZ(std::cout);
}

void testing_reinsert(int stopCriterion, bool anxious) {
  std::unique_ptr<ParallelInterface> multiboost_reInsert =
    std::make_unique<Multiboot>(reInsert, stopCriterion, anxious);

  auto t1 = std::chrono::high_resolution_clock::now();
  Solution solucion2(multiboost_reInsert->run(Data::getInstance().getM()));
  auto t2 = std::chrono::high_resolution_clock::now();
  std::cout << "Time: "
    << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count() << " microsegundos | "
    << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count()/1000.0 << " milisegundos | "
    << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count()/1000000.0 << " segundos\n";

  solucion2.showOnlyZ(std::cout);
}

void testing_move(int stopCriterion, bool anxious) {
  std::unique_ptr<ParallelInterface> multiboost_move =
    std::make_unique<Multiboot>(move, stopCriterion, anxious);

  auto t1 = std::chrono::high_resolution_clock::now();
  Solution solucion3(multiboost_move->run(Data::getInstance().getM()));
  auto t2 = std::chrono::high_resolution_clock::now();
  std::cout << "Time: "
    << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count() << " microsegundos | "
    << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count()/1000.0 << " milisegundos | "
    << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count()/1000000.0 << " segundos\n";

  solucion3.showOnlyZ(std::cout);
}

void testin_innerSwap(int stopCriterion, bool anxious) {
  std::unique_ptr<ParallelInterface> multiboost_innerSwap =
    std::make_unique<Multiboot>(innerSwap, stopCriterion, anxious);

  auto t1 = std::chrono::high_resolution_clock::now();
  Solution solucion4(multiboost_innerSwap->run(Data::getInstance().getM()));
  auto t2 = std::chrono::high_resolution_clock::now();

  std::cout << "Time: "
    << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count() << " microsegundos | "
    << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count()/1000.0 << " milisegundos | "
    << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count()/1000000.0 << " segundos\n";
  solucion4.showOnlyZ(std::cout);
}

void testing_extraSwap(int stopCriterion, bool anxious) {
  std::unique_ptr<ParallelInterface> multiboost_extraSwap =
    std::make_unique<Multiboot>(extraSwap, stopCriterion, anxious);

  auto t1 = std::chrono::high_resolution_clock::now();
  Solution solucion5(multiboost_extraSwap->run(Data::getInstance().getM()));
  auto t2 = std::chrono::high_resolution_clock::now();
  std::cout << "Time: "
    << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count() << " microsegundos | "
    << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count()/1000.0 << " milisegundos | "
    << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count()/1000000.0 << " segundos\n";

  solucion5.showOnlyZ(std::cout);
}

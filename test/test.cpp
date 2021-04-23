#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "../include/data.hpp"
#include "../include/machine.hpp"
#include "../include/solution.hpp"
#include "../include/greedy_time.hpp"
#include "../include/greedy_TCT.hpp"

unsigned long FormulaTCT(const Machine& maquina);

void TEST_SIZES() {
    Data* datos = &Data::getInstance();
    SUBCASE("The vector that contain the times") {
      CHECK(datos->getTimes().size() == datos->getN());
    }
    SUBCASE("The matrix with the setups times") {
      CHECK(datos->getSetups().size() == datos->getN() + 1);
      for (size_t i = 0; i < datos->getSetups().size(); ++i) {
        CHECK(datos->getSetups()[i].size() == datos->getN() + 1);
      }
    }
}

void NUMBER_OF_TASK_IN_MACHINES(Solution& solucion) {
  SUBCASE("The total number of tasks that are in a machine must be equal to the number of tasks") {
    int totalTests = 0;
    for(size_t i = 0; i < solucion.getMachines().size(); ++i) {
      totalTests += solucion.getMachines()[i].size();
    }
    CHECK(totalTests == Data::getInstance().getN());
  }
}

void FINAL_TCT(Solution& solucion) {
  SUBCASE("TCT it should be the same as if you calculate ot with the formula") {
    for (size_t i = 0; i < solucion.getMachines().size(); ++i) {
      CHECK(solucion.getMachines()[i].getTCT() == FormulaTCT(solucion.getMachines()[i]));
    }
  }
}


void TESTS(Solution& solucion) {
  TEST_SIZES();
  NUMBER_OF_TASK_IN_MACHINES(solucion);
  FINAL_TCT(solucion);
}

TEST_CASE("GreedyTCT") {
  SUBCASE("2 machines") {
    Data::file_ = "I40j_2m_S1_1.txt";
    std::unique_ptr<ParallelInterface> algorithm = std::make_unique<GreedyTCT>();
    Solution solucion(algorithm->run(Data::getInstance().getM()));
    TESTS(solucion);
  }

  SUBCASE("4 machines") {
    SUBCASE("GreedyB") {
      Data::file_ = "I40j_4m_S1_1.txt";
      std::unique_ptr<ParallelInterface> algorithm = std::make_unique<GreedyTCT>();
      Solution solucion(algorithm->run(Data::getInstance().getM()));
      TESTS(solucion);
    }
  }

  SUBCASE("8 machines") {
    Data::file_ = "I40j_8m_S1_1.txt";
    std::unique_ptr<ParallelInterface> algorithm = std::make_unique<GreedyTCT>();
    Solution solucion(algorithm->run(Data::getInstance().getM()));
    TESTS(solucion);
  }
}

TEST_CASE("GreedyTime") {
  SUBCASE("2 machines") {
    Data::file_ = "I40j_2m_S1_1.txt";
    std::unique_ptr<ParallelInterface> algorithm = std::make_unique<GreedyTime>();
    Solution solucion(algorithm->run(Data::getInstance().getM()));
    TESTS(solucion);
  }

  SUBCASE("4 machines") {
    SUBCASE("GreedyB") {
      Data::file_ = "I40j_4m_S1_1.txt";
      std::unique_ptr<ParallelInterface> algorithm = std::make_unique<GreedyTime>();
      Solution solucion(algorithm->run(Data::getInstance().getM()));
      TESTS(solucion);
    }
  }

  SUBCASE("8 machines") {
    Data::file_ = "I40j_8m_S1_1.txt";
    std::unique_ptr<ParallelInterface> algorithm = std::make_unique<GreedyTime>();
    Solution solucion(algorithm->run(Data::getInstance().getM()));
    TESTS(solucion);
  }
}

unsigned long FormulaTCT(const Machine& maquina) {
  unsigned long tct = 0;
  for (size_t i = 0; i < maquina.size(); ++i) {
    tct += (maquina.size() - i) * maquina[i].getTime();
  }
  return tct;
}

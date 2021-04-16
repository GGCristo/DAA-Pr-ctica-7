#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "../include/datos.hpp"
#include "../include/maquina.hpp"
#include "../include/solucion.hpp"
#include "../include/greedy_time.hpp"
#include "../include/greedy_TCT.hpp"

unsigned long FormulaTCT(const Maquina& maquina);

void TEST_SIZES() {
    Datos* datos = &Datos::getInstance();
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

void NUMBER_OF_TASK_IN_MACHINES(Solucion& solucion) {
  SUBCASE("The total number of tasks that are in a machine must be equal to the number of tasks") {
    int totalTests = 0;
    for(size_t i = 0; i < solucion.getMachines().size(); ++i) {
      totalTests += solucion.getMachines()[i].size();
    }
    CHECK(totalTests == Datos::getInstance().getN());
  }
}

void FINAL_TCT(Solucion& solucion) {
  SUBCASE("TCT it should be the same as if you calculate ot with the formula") {
    for (size_t i = 0; i < solucion.getMachines().size(); ++i) {
      CHECK(solucion.getMachines()[i].getTCT() == FormulaTCT(solucion.getMachines()[i]));
    }
  }
}


void TESTS(Solucion& solucion) {
  TEST_SIZES();
  NUMBER_OF_TASK_IN_MACHINES(solucion);
  FINAL_TCT(solucion);
}

TEST_CASE("GreedyTCT") {
  SUBCASE("2 máquinas") {
    Datos::fichero_ = "I40j_2m_S1_1.txt";
    std::unique_ptr<ParallelInterface> algorithm = std::make_unique<GreedyTCT>();
    Solucion solucion(algorithm->run(Datos::getInstance().getM()));
    TESTS(solucion);
  }

  SUBCASE("4 máquinas") {
    SUBCASE("GreedyB") {
      Datos::fichero_ = "I40j_4m_S1_1.txt";
      std::unique_ptr<ParallelInterface> algorithm = std::make_unique<GreedyTCT>();
      Solucion solucion(algorithm->run(Datos::getInstance().getM()));
      TESTS(solucion);
    }
  }

  SUBCASE("8 máquinas") {
    Datos::fichero_ = "I40j_8m_S1_1.txt";
    std::unique_ptr<ParallelInterface> algorithm = std::make_unique<GreedyTCT>();
    Solucion solucion(algorithm->run(Datos::getInstance().getM()));
    TESTS(solucion);
  }
}

TEST_CASE("GreedyTime") {
  SUBCASE("2 máquinas") {
    Datos::fichero_ = "I40j_2m_S1_1.txt";
    std::unique_ptr<ParallelInterface> algorithm = std::make_unique<GreedyTime>();
    Solucion solucion(algorithm->run(Datos::getInstance().getM()));
    TESTS(solucion);
  }

  SUBCASE("4 máquinas") {
    SUBCASE("GreedyB") {
      Datos::fichero_ = "I40j_4m_S1_1.txt";
      std::unique_ptr<ParallelInterface> algorithm = std::make_unique<GreedyTime>();
      Solucion solucion(algorithm->run(Datos::getInstance().getM()));
      TESTS(solucion);
    }
  }

  SUBCASE("8 máquinas") {
    Datos::fichero_ = "I40j_8m_S1_1.txt";
    std::unique_ptr<ParallelInterface> algorithm = std::make_unique<GreedyTime>();
    Solucion solucion(algorithm->run(Datos::getInstance().getM()));
    TESTS(solucion);
  }
}

unsigned long FormulaTCT(const Maquina& maquina) {
  unsigned long tct = 0;
  for (size_t i = 0; i < maquina.size(); ++i) {
    tct += (maquina.size() - i) * maquina[i].getTime();
  }
  return tct;
}

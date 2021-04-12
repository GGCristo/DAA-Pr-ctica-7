#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "../include/datos.hpp"
#include "../include/maquina.hpp"
#include "../include/solucion.hpp"
#include "../include/voraz.hpp"

    // Datos::fichero_ = "I40j_2m_S1_1.txt";
    // Datos::fichero_ = "I40j_2mS1_1.txt"; // empty
    // Datos::fichero_ = "I40j_4m_S1_1.txt";
    // Datos::fichero_ = "I40j_6m_S1_1.txt";
    // Datos::fichero_ = "I40j_8m_S1_1.txt";
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
    // std::vector<Maquina> maquinas;
    solucion.ejecutar();
    int totalTests = 0;
    for(size_t i = 0; i < solucion.getMachines().size(); ++i) {
      totalTests += solucion.getMachines()[i].size();
    }
    CHECK(totalTests == Datos::getInstance().getN());
  }
}

TEST_CASE("2 máquinas") {
  Datos::fichero_ = "I40j_2m_S1_1.txt";
  Solucion solucion(std::make_unique<Voraz>(Voraz()));
  TEST_SIZES();
  NUMBER_OF_TASK_IN_MACHINES(solucion);
}

TEST_CASE("4 máquinas") {
  SUBCASE("GreedyB") {
    Datos::fichero_ = "I40j_4m_S1_1.txt";
    Solucion solucion(std::make_unique<Voraz>(Voraz()));
    TEST_SIZES();
    NUMBER_OF_TASK_IN_MACHINES(solucion);
  }
}

TEST_CASE("8 máquinas") {
  Datos::fichero_ = "I40j_8m_S1_1.txt";
  Solucion solucion(std::make_unique<Voraz>(Voraz()));
  TEST_SIZES();
  NUMBER_OF_TASK_IN_MACHINES(solucion);
}

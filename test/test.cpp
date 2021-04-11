#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "../include/datos.hpp"
#include "../include/maquina.hpp"
#include "../include/voraz.hpp"

TEST_CASE("SIZES") {
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

TEST_CASE("The total number of tasks that are in a machine must be equal to the number of tasks") {
  std::vector<Maquina> maquinas;
  for (int i = 0; i < Datos::getInstance().getM(); ++i) {
    maquinas.emplace_back(Maquina());
  }
  voraz(maquinas);
  int totalTests = 0;
  for(size_t i = 0; i < maquinas.size(); ++i) {
    totalTests += maquinas[i].size();
  }
  CHECK(totalTests == Datos::getInstance().getN());
}

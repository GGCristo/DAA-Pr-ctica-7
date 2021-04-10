#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "../include/datos.hpp"

TEST_CASE("SIZES") {
  Datos datos;
  SUBCASE("The vector that contain the times") {
    CHECK(datos.getTimes().size() == datos.getN());
  }
  SUBCASE("The matrix with the setups times") {
    CHECK(datos.getSetups().size() == datos.getN() + 1);
    for (size_t i = 0; i < datos.getSetups().size(); ++i) {
      CHECK(datos.getSetups()[i].size() == datos.getN() + 1);
    }
  }

}

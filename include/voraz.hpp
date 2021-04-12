#pragma once
#include "parallelInterface.hpp"
#include "datos.hpp"
#include "maquina.hpp"

class Voraz: public ParallelInterface {
  public:
    void algorithm(std::vector<Maquina>& maquinas) override;
};

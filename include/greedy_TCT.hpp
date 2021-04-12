#pragma once
#include "parallelInterface.hpp"
#include "datos.hpp"
#include "maquina.hpp"

class GreedyTCT: public ParallelInterface {
  public:
    void algorithm(std::vector<Maquina>& maquinas) override;
};

#pragma once
#include "parallelInterface.hpp"
#include "maquina.hpp"

class GreedyTCT: public ParallelInterface {
  public:
    Solucion run(int m) override;
};

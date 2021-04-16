#pragma once
#include "parallelInterface.hpp"
#include "maquina.hpp"

class GreedyTime: public ParallelInterface {
  public:
    Solucion run(int) override;
};

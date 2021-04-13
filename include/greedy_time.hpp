#pragma once
#include "parallelInterface.hpp"
#include "maquina.hpp"

class GreedyTime: public ParallelInterface {
  public:
    void algorithm(std::vector<Maquina>& maquinas) override;
};

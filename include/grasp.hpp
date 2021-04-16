#pragma once
#include "parallelInterface.hpp"
#include "maquina.hpp"
#include "random.hpp"

class Grasp: public ParallelInterface {
  public:
    void algorithm(std::vector<Maquina>& maquinas) override;
  private:
};

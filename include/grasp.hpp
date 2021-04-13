#pragma once
#pragma once
#include "parallelInterface.hpp"
#include "maquina.hpp"

class Grasp: public ParallelInterface {
  public:
    void algorithm(std::vector<Maquina>& maquinas) override;
  private:
};

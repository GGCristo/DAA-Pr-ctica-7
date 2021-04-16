#pragma once
#include <queue>
#include "parallelInterface.hpp"
#include "maquina.hpp"
#include "random.hpp"

class Grasp: public ParallelInterface {
  public:
    void algorithm(std::vector<Maquina>& maquinas) override;
  private:
    std::vector<Tarea> getBestK(int, size_t k = 3);
};

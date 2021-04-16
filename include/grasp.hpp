#pragma once
#include <queue>
#include "parallelInterface.hpp"
#include "maquina.hpp"
#include "random.hpp"

class Grasp: public ParallelInterface {
  public:
    Solucion run(int) override;
  private:
    std::vector<Tarea> getBestK(int, size_t k = 3);
    Solucion construction(const std::vector<Maquina>&);
};

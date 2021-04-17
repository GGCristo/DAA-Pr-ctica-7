#pragma once
#include <queue>
#include "parallelInterface.hpp"
#include "maquina.hpp"
#include "random.hpp"

class Grasp: public ParallelInterface {
  public:
    Grasp(int, size_t k = 3);
    Solucion run(int) override;
  private:
    size_t k_;
    std::vector<Tarea> getBestK(int);
    Solucion construction(const std::vector<Maquina>&);
    Solucion postProcessing(const std::vector<Maquina>&);
    Solucion postProcessing_reInsert(const std::vector<Maquina>&);

    // Movements
    int typeOfMovement_;
    void reinsert(Maquina& machine, int previousPosition, int newPosition);
    void move(Maquina& previousMachine, int previousPosition,
              Maquina& newMachine, int newPosition);
    void innerSwap(Maquina& machine, int position1, int position2);
    void extraSwap(Maquina& machine1, int position1, Maquina& machine2,
                   int position2);
};

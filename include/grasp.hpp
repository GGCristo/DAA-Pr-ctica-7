#pragma once
#include <queue>
#include "parallelInterface.hpp"
#include "maquina.hpp"
#include "random.hpp"

enum Stop_Criterion {iterations, iterationsSinceImprovement};

class Grasp: public ParallelInterface {
  public:
    explicit Grasp(int, int stopCriterion_ = iterationsSinceImprovement,
                   int iterations = 1000, size_t k = 3);
    Solucion run(int) override;
  private:
    int iterations_;
    size_t k_;
    int stopCriterion_;
    std::vector<Tarea> getBestK(int);
    Solucion construction(const std::vector<Maquina>&);
    Solucion postProcessing(const std::vector<Maquina>&);
    Solucion postProcessing_reInsert(const std::vector<Maquina>&);
    Solucion postProcessing_move(const std::vector<Maquina>&);
    Solucion postProcessing_innerSwap(const std::vector<Maquina>&);
    Solucion postProcessing_extraSwap(const std::vector<Maquina>&);

    // Movements
    int typeOfMovement_;
    void reinsert(Maquina& machine, int previousPosition, int newPosition);
    void move(Maquina& previousMachine, int previousPosition,
              Maquina& newMachine, int newPosition);
    void innerSwap(Maquina& machine, int position1, int position2);
    void extraSwap(Maquina& machine1, int position1, Maquina& machine2,
                   int position2);
    void pseudo_reset(const std::vector<Maquina>&) const;
};

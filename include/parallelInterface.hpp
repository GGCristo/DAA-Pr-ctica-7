#pragma once

#include <vector>
#include "tarea.hpp"
#include "maquina.hpp"
#include "solucion.hpp"
// class Maquina;

class ParallelInterface {
  public:
    ParallelInterface() = default;
    virtual ~ParallelInterface() = default;
    virtual Solucion run(int) = 0;
  protected:
    Tarea getTask(int);
    // (int previousTask, int currentTask)
    int getTime(int, int);
    std::vector<Maquina> preprocesamiento(int);
};

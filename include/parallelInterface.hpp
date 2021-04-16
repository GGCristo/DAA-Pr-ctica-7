#pragma once

#include <vector>
#include "tarea.hpp"
#include "maquina.hpp"
// class Maquina;

class ParallelInterface {
  public:
    ParallelInterface() = default;
    virtual ~ParallelInterface() = default;
    virtual void algorithm(std::vector<Maquina>&) = 0;
  protected:
    Tarea getTask(int);
    // (int previousTask, int currentTask)
    int getTime(int, int);
    void preprocesamiento(std::vector<Maquina>&);
};

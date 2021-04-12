#pragma once

#include <vector>
#include "tarea.hpp"
class Maquina;

class ParallelInterface {
  public:
    ParallelInterface() = default;
    virtual ~ParallelInterface() = default;
    virtual void algorithm(std::vector<Maquina>&) = 0;
  protected:
    const Tarea getTask(int);
};

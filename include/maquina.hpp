#pragma once

#include <vector>
#include "../include/tarea.hpp"

class Maquina {
  public:
    Maquina();
  private:
    double Tf_;
    std::vector<Tarea> queue_;
};

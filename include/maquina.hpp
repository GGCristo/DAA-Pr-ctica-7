#pragma once

#include <vector>
#include "../include/tarea.hpp"

class Maquina {
  public:
    Maquina();
    void add(const Tarea&);
    std::ostream& show(std::ostream& os = std::cout);
  private:
    int Tf_;
    std::vector<Tarea> queue_;
};

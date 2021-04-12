#pragma once

#include <vector>
#include <cassert>
#include "../include/tarea.hpp"
#include "../include/datos.hpp"

class Maquina {
  public:
    Maquina();
    void add(Tarea);
    int getIdLastTask();
    int getTime();
    size_t size() const;
    unsigned long getTCT();
    unsigned long peekTCT(Tarea);
    std::ostream& show(std::ostream& os = std::cout);
  private:
    unsigned long tct_;
    int time_;
    std::vector<Tarea> queue_;
};

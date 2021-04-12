#pragma once

#include <vector>
#include <cassert>
#include "../include/tarea.hpp"
#include "../include/datos.hpp"

class Maquina {
  public:
    Maquina();
    void add(const Tarea&);
    int getIdLastTask();
    int getTime();
    size_t size() const;
    unsigned long getTCT();
    std::ostream& show(std::ostream& os = std::cout);
  private:
    int time_;
    std::vector<Tarea> queue_;
};

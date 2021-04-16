#pragma once

#include <vector>
#include "maquina.hpp"

class Solucion {
  public:
    Solucion(std::vector<Maquina>);
    const std::vector<Maquina>& getMachines();
    void ejecutar();
    unsigned long getZ();
    void reinsert(int, int, int);
    void move(int, int, int, int);
    void innerSwap(int, int , int);
    void extraSwap(int, int, int, int);
    std::ostream& show(std::ostream& os = std::cout);
    std::ostream& showWithTCTs(std::ostream& os = std::cout);

  private:
    std::vector<Maquina> maquinas_;
};

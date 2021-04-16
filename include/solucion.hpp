#pragma once

#include <vector>
#include "maquina.hpp"
#include "../include/parallelInterface.hpp"

class Solucion {
  public:
    Solucion(int, std::unique_ptr<ParallelInterface>);
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
    std::unique_ptr<ParallelInterface> algorithm_;
    unsigned long z_;
};

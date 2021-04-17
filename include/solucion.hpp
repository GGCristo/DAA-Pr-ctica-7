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
    bool operator<(const Solucion&);
    std::ostream& show(std::ostream& os = std::cout);
    std::ostream& showWithTCTs(std::ostream& os = std::cout);
    // Access
    // std::vector<Maquina>::const_iterator begin() const;
    // std::vector<Maquina>::iterator begin();
    // std::vector<Maquina>::const_iterator end() const;
    // std::vector<Maquina>::iterator end();

  private:
    void generateZ();
    std::vector<Maquina> maquinas_;
    unsigned long z_;
};

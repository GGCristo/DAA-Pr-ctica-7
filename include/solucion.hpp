#pragma once

#include <vector>
#include "datos.hpp"
#include "maquina.hpp"
#include "../include/parallelInterface.hpp"
#include "../include/voraz.hpp"

class Solucion {
  public:
    Solucion(std::unique_ptr<ParallelInterface>);
    const std::vector<Maquina>& getMachines();
    void ejecutar();
    unsigned long getZ();
    std::ostream& show(std::ostream& os = std::cout);

  private:
    std::vector<Maquina> maquinas_;
    std::unique_ptr<ParallelInterface> algorithm_;
    unsigned long z_;
};

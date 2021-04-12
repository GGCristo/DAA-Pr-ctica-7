#pragma once

#include <vector>
#include "datos.hpp"
#include "maquina.hpp"
#include "../include/parallelInterface.hpp"
#include "../include/greedy_time.hpp"
#include "../include/greedy_TCT.hpp"

class Solucion {
  public:
    explicit Solucion(std::unique_ptr<ParallelInterface>);
    const std::vector<Maquina>& getMachines();
    void ejecutar();
    unsigned long getZ();
    std::ostream& show(std::ostream& os = std::cout);
    std::ostream& showWithTCTs(std::ostream& os = std::cout);

  private:
    std::vector<Maquina> maquinas_;
    std::unique_ptr<ParallelInterface> algorithm_;
    unsigned long z_;
};

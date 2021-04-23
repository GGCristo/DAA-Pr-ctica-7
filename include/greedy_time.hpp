#pragma once
#include "parallelInterface.hpp"
#include "machine.hpp"

class GreedyTime: public ParallelInterface {
  public:
    /**
     * @brief Start running the algorithm
     *
     * @param {m} Number of machines
     * @return Definitive solution
     */
    Solution run(int) override;
};

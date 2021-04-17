#pragma once
#include "parallelInterface.hpp"
#include "machine.hpp"

class GreedyTime: public ParallelInterface {
  public:
    Solution run(int) override;
};

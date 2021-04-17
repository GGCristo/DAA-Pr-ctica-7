#pragma once
#include "parallelInterface.hpp"
#include "machine.hpp"

class GreedyTCT: public ParallelInterface {
  public:
    Solution run(int m) override;
};

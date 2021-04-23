#pragma once

#include "multiboot.hpp"

class GVNS: public Multiboot{
  public:
    explicit GVNS(int typeOfMovement = 0, int typeOfSaking = 1,
        int stopCriterion = 1, bool ansioso = false, int iterations = 1000,
        int k = 3);
    Solution run(int) override;
  private:
    int typeOfSaking_;

    std::vector<Machine> shaking(const std::vector<Machine>&, int);
    Solution vnd(const std::vector<Machine>&);
};

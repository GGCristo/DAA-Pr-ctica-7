#pragma once

#include <vector>
#include "machine.hpp"

class Solution {
  public:
    Solution();
    explicit Solution(const std::vector<Machine>&);
    const std::vector<Machine>& getMachines();
    unsigned long getZ() const;
    void reinsert(int, int, int);
    void move(int, int, int, int);
    void innerSwap(int, int , int);
    void extraSwap(int, int, int, int);
    bool operator<(const Solution&);
    std::ostream& show(std::ostream& os = std::cout);
    std::ostream& showOnlyZ(std::ostream& os = std::cout);
    std::ostream& showWithTCTs(std::ostream& os = std::cout);

  private:
    void generateZ();
    std::vector<Machine> machines_;
    unsigned long z_;
};

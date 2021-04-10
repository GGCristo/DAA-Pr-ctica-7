#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>

class Datos {
  public:
    Datos();
    const std::vector<int>& get_times();
    const std::vector<int>& get_setups();
  private:
    std::vector<int> times(const std::string&);
    std::vector<int> setups(std::fstream&, std::string&);

    int m_;
    int n_;
    // TODO Return optimization doesn't work
    std::vector<int> times_;
    std::vector<int> setups_;
};

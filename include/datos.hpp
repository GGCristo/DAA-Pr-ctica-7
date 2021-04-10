#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>

class Datos {
  public:
    Datos();
    int getN();
    int getM();
    const std::vector<int>& getTimes();
    const std::vector<std::vector<int>>& getSetups();
    void showTimes();
    void showSetups();
  private:
    void times(const std::string&);
    void setups(std::fstream&, std::string&);

    int m_;
    int n_;
    // TODO Return optimization doesn't work
    std::vector<int> times_;
    std::vector<std::vector<int>> setups_;
};

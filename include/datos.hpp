#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <utility>
#include <vector>

// TODO Make everything const
class Datos {
  public:
    static Datos& getInstance();
    Datos(const Datos&) = delete;
    Datos& operator =(const Datos&) = delete;
    int getN();
    int getM();
    const std::vector<int>& getTimes();
    const std::vector<std::vector<std::pair<int, bool>>>& getSetups();
    void showTimes();
    void showSetups();
  private:
    Datos();
    void times(const std::string&);
    void setups(std::fstream&, std::string&);

    int m_;
    int n_;
    // TODO Return optimization doesn't work
    std::vector<int> times_;
    std::vector<std::vector<std::pair<int, bool>>> setups_;
};

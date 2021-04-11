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
    std::vector<std::pair<int, bool>>& getTimes();
    const std::vector<std::vector<int>>& getSetups();
    void showTimes();
    void showSetups();
    static inline std::string fichero_ = "";
  private:
    Datos();
    void times(const std::string&);
    void setups(std::fstream&, std::string&);

    int m_;
    int n_;
    // TODO Return optimization doesn't work
    std::vector<std::pair<int, bool>> times_;
    std::vector<std::vector<int>> setups_;
};

#pragma once

#include <vector>
#include <cassert>
#include <algorithm>
#include "../include/tarea.hpp"
#include "../include/datos.hpp"

class Maquina {
  public:
    Maquina();
    void reCalculateTimeFrom(int);
    void reCalculateTct();
    Tarea* searchTask(int);
    // Getters
    int getIdPreviousTask(int) const;
    int getIdLastTask() const;
    int getTime() const;
    size_t size() const;
    unsigned long getTCT() const;
    unsigned long peekTCT(Tarea) const;
    // Modifiers
    void add(Tarea);
    Tarea erase(int);
    void insert(Tarea&, int);
    // Show
    std::ostream& show(std::ostream& os = std::cout) const;
    // Operator
    const Tarea& operator[](int) const;
    // Access
    std::vector<Tarea>::const_iterator begin() const;
    std::vector<Tarea>::iterator begin();
    std::vector<Tarea>::const_iterator end() const;
    std::vector<Tarea>::iterator end();
  private:
    int previousTctTask_;
    unsigned long tct_;
    int time_;
    std::vector<Tarea> queue_;
};

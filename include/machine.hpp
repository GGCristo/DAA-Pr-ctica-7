#pragma once

#include <vector>
#include <cassert>
#include <algorithm>
#include "../include/task.hpp"
#include "../include/data.hpp"

class Machine {
  public:
    Machine();
    void reCalculateTimeFrom(int);
    void reCalculateTct();
    Task* searchTask(int);
    // Getters
    int getIdPreviousTask(int) const;
    int getIdLastTask() const;
    int getTime() const;
    size_t size() const;
    unsigned long getTCT() const;
    unsigned long peekTCT(Task) const;
    // Modifiers
    void add(Task);
    Task erase(int);
    void insert(Task&, int);
    // Show
    std::ostream& show(std::ostream& os = std::cout) const;
    // Operator
    const Task& operator[](int) const;
    // Access
    std::vector<Task>::const_iterator begin() const;
    std::vector<Task>::iterator begin();
    std::vector<Task>::const_iterator end() const;
    std::vector<Task>::iterator end();
  private:
    int previousTctTask_;
    unsigned long tct_;
    int time_;
    std::vector<Task> queue_;
};

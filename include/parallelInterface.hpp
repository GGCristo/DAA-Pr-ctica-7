#pragma once

#include <vector>
#include "task.hpp"
#include "machine.hpp"
#include "solution.hpp"

class ParallelInterface {
  public:
    ParallelInterface() = default;
    virtual ~ParallelInterface() = default;
    virtual Solution run(int) = 0;
  protected:
    Task getTask(int) const;
    // (int previousTask, int currentTask)
    int getTime(int, int) const;
    std::vector<Machine> preprocessing(int);
};

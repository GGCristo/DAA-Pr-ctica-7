#pragma once

#include <vector>
#include "task.hpp"
#include "machine.hpp"
#include "solution.hpp"

class ParallelInterface {
  public:
    ParallelInterface() = default;
    virtual ~ParallelInterface() = default;

    /**
     * @brief Start running the algorithm (pure virtual)
     *
     * @param {m} Number of machines
     * @return Definitive solution
     */
    virtual Solution run(int) = 0;

  protected:
    /**
     * @brief Get the best Task in term of times knowing the position
     * of the last task
     *
     * @param {previousTask} Position of the last task
     * @return The best Task in term of time
     */
    Task getTask(int) const;

    /**
     * @brief Return the time (t_ij) of a determinate task
     *
     * @param {previousTask} Position of the previous task
     * @param {currentTask} Position of the current task
     * @return Time of the task
     */
    int getTime(int, int) const;

    /**
     * @brief Load the first tasks of all the machines equitably
     *
     * @param {m} Number of machines
     */
    std::vector<Machine> preprocessing(int);
};

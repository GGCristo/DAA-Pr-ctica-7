#pragma once

#include <iostream>

class Task {
  public:
    /**
     * @brief Create a Task
     *
     * @param {id} ID is the position of the task in the time_ vector, it's
     * unique
     * @param {totalTime} Time of this task (setupTime included)
     */
    Task(int, int);

    /**
     * @brief Return the ID of the Task
     *
     * @return id_
     */
    int getId() const;

    /**
     * @brief Return the total time (setup included) of the Task
     *
     * @return Total time of the Task
     */
    int getTime() const;

    /**
     * @brief Send the value of z_ to the os output
     *
     * @param os ostream, default its std::cout
     */
    std::ostream& show(std::ostream& os = std::cout) const;
  private:
    /**
     * @id_ Position of the Task in the time_ vector
     */
    int id_;

    /**
     * @time_ vector of the times of all the Tasks
     */
    int time_;
    friend class Machine;
};

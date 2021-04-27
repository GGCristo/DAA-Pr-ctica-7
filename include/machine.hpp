#pragma once

#include <vector>
#include <cassert>
#include <algorithm>
#include "../include/task.hpp"
#include "../include/data.hpp"

class Machine {
  public:
    /**
     * @brief Constructor for machine
     *
     * @param id ID to identify the machine
     */
    explicit Machine(int id);

    /**
     * @brief Recalculate the time of all the Task from startPosition to the end
     * of the container
     *
     * @param {startPosition} Position to start with the recalculation of times
     */
    void reCalculateTimeFrom(int);

    /**
     * @brief Recalculate TCT
     *
     */
    void reCalculateTctFrom(int);

    /**
     * @brief Search a Task with and ID
     *
     * @param {id} ID of the Task
     */
    Task* searchTask(int);

    int getId() const;

    // Getters
    /**
     * @brief Get the ID of the previous position
     *
     * @param {position} position
     * @return ID of the previous position
     */
    [[nodiscard]] int getIdPreviousTask(int) const;

    /**
     * @brief Get the ID of the last task
     *
     * @return ID of the last task
     */
    [[nodiscard]] int getIdLastTask() const;
    /**
     * @brief Return the time of all the tasks in the machine
     * Warning: This is only use for greedy methods time doesn't update if a
     * movement have been done
     *
     * @return time_
     */
    [[nodiscard]] int getTime() const;

    /**
     * @brief Get number of Task in the machine
     *
     * @return Number of Task
     */
    [[nodiscard]] size_t size() const;

    /**
     * @brief Return tct_ attribute value
     *
     */
    [[nodiscard]] unsigned long getTCT() const;

    /**
     * @brief Return what it would be the value of TCT if incomingTask is added
     *
     * @param {incomingTask} Incoming Task
     */
    [[nodiscard]] unsigned long peekTCT(const Task&) const;

    // Modifiers
    /**
     * @brief Add a task to the end of the machine
     *
     * @param {task} Incoming Task
     */
    void add(Task);

    /**
     * @brief Delete a task of a given position
     *
     * @param {position} Position where is the Task you want to delete
     * @return Copy of the deleted task
     */
    Task erase(int);

    /**
     * @brief Insert a task in a given position
     *
     * @param {task} Task to be inserted
     * @param {position} Position where the task is going to be
     */
    void insert(const Task&, int);

    // Show
    /**
     * @brief Show all the task in the machine
     *
     * @param os ostream, default its std::cout
     */
    std::ostream& show(std::ostream& os = std::cout) const;

    // Operator
    /**
     * @brief Operator for index acces to a Task
     *
     * @param {index} Position of the task in the machine
     */
    const Task& operator[](int) const;

    // Access
    /**
     * @brief Const iterator to the first Task
     *
     */
    std::vector<Task>::const_iterator begin() const;

    /**
     * @brief Iterator to the first Task
     *
     */
    std::vector<Task>::iterator begin();

    /**
     * @brief Const iterator to the end of the vector of Task
     *
     */
    std::vector<Task>::const_iterator end() const;

    /**
     * @brief Iterator to the end of the vector of Task
     *
     */
    std::vector<Task>::iterator end();

  private:
    /**
     * @previousTctTask_ The Tct of the previous Task
     */
    int previousTctTask_;

    /**
     * @tct_ TCT of this machine
     */
    unsigned long tct_;

    /**
     * @time_ [TODO:description]
     */
    int time_;

    int id_;

    /**
     * @queue_ [TODO:description]
     */
    std::vector<Task> queue_;
};

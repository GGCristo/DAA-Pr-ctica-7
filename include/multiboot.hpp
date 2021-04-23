#pragma once
#include "parallelInterface.hpp"
#include "machine.hpp"
#include "random.hpp"


class Multiboot: public ParallelInterface {
  public:
    /**
     * @brief Constructor of multiboot
     *
     * @param typeOfMovement reInsert, move, innerSwap, extraSwap (enum)
     * @param stopCriterion_ iterations iterationsSinceImprovement (enum)
     * @param anxious bool Determinate if the algorithm is anxious or not
     * @param iterations Number of Iterations in the algorithm
     * @param k Number of elements in RCL
     */
    explicit Multiboot(int, int stopCriterion_ = 1, bool anxious = false,
                   int iterations = 1000, int k = 1);

    /**
     * @brief Start running the algorithm
     *
     * @param {m} Number of machines
     * @return Definitive solution
     */
    Solution run(int) override;

  protected:
    /**
     * @iterations_ Number of iterations or number of iterations since the
     * last improvements, depends on stopCriterion_
     */
    int iterations_;

    /**
     * @k_ Number of best tasks to create the RCL
     */
    int k_;

    /**
     * @stopCriterion_ Stop criterion, iterations or iterations since the last
     * improvements
     */
    int stopCriterion_;

    /**
     * @anxious_ Determinate if the algorithm its anxious or not.
     * If it is anxious it will stop in the postProcessing method of GRASP since
     * the very moment it find a better solution or there are no more
     * combinations
     */
    bool anxious_;

    /**
     * @brief Get the best k tasks (in time)
     *
     * @param {previousTask} previousTask
     */
    std::vector<Task> getBestK(int) const;

    /**
     * @brief In case the incoming solution it's better than the actual one
     * make the icoming solution the new solution
     *
     * @param {solution} actualSolution
     * @param {incomingSolution} incomingSolution
     * @return true if the incoming Solution is the new Solution,
     * false otherwhise
     */
    bool updateSolution(Solution&, const Solution&);

    /**
     * @brief Construction phase of GRASP, create an RCL and get a random
     * task out of it and add it to the respective position, repeat until
     * all tasks are ready
     *
     * @param {preprocessed} Preprocessed vector of machines
     * @return Pseudo-random solution
     */
    Solution construction(const std::vector<Machine>&);

    /**
     * @brief Wrapper for calling all the other postProcessing methods, depending
     * on typeOfMovement attribute
     *
     * @param {constructed} Vector of machines from the construction phase
     * @return Post-processed solution
     */
    Solution postProcessing(const std::vector<Machine>&);

    /**
     * @brief Get the best solution of all the combinations posible with one
     * re-insert movement
     *
     * @param {constructed} Vector of machines from the construction phase
     * @return Post-processed solution
     */
    Solution postProcessing_reInsert(const std::vector<Machine>&);

    /**
     * @brief Get the best solution of all the combinations posible with one
     * move movement
     *
     * @param {constructed} Vector of machines from the construction phase
     * @return Post-processed solution
     */
    Solution postProcessing_move(const std::vector<Machine>&);

    /**
     * @brief Get the best solution of all the combinations posible with one
     * innerSwap movement
     *
     * @param {constructed} Vector of machines from the construction phase
     * @return Post-processed solution
     */
    Solution postProcessing_innerSwap(const std::vector<Machine>&);

    /**
     * @brief Get the best solution of all the combinations posible with one
     * extraSwap movement
     *
     * @param {constructed} Vector of machines from the construction phase
     * @return Post-processed solution
     */
    Solution postProcessing_extraSwap(const std::vector<Machine>&);

    // Movements
    /**
     * @typeOfMovement_ Type of movement to be done in the postProcessing phase
     */
    int typeOfMovement_;

    /**
     * @brief Take a task from one machine and insert it in another position of
     * the same machine
     *
     * @param machine Machine
     * @param previousPosition The position of the task is going to be move
     * @param newPosition The moved task is going to be inserted int this
     * position
     */
    void reinsert(Machine& machine, int previousPosition, int newPosition);

    /**
     * @brief Take a task from one machine and insert it in another machine
     *
     * @param previousMachine Machine where the task come from
     * @param previousPosition The position of the task is going to be move
     * @param newMachine Machine where the task is going to be inserted
     * @param newPosition The moved task is going to be inserted int this
     * position
     */
    void move(Machine& previousMachine, int previousPosition,
              Machine& newMachine, int newPosition);

    /**
     * @brief Take a task from one machine and swap it with another task of
     * the same machine
     *
     * @param machine Machine
     * @param position1 Postion of a task
     * @param position2 Position of a task
     */
    void innerSwap(Machine& machine, int position1, int position2);

    /**
     * @brief Take a task from one machine and swap it with another task of
     * a diferent machine
     *
     * @param machine1 One machine
     * @param position1 The position of a task
     * @param machine2 One machine
     * @param position2 The position of a task
     */
    void extraSwap(Machine& machine1, int position1, Machine& machine2,
                   int position2);
    /**
     * @brief Reset all the tasks to be free of being chosen, but mark as taken
     * the ones that are in the preprocessed vector of machines
     *
     * @param {preprocessed} Preprocessed vector of machines
     */
    void pseudo_reset(const std::vector<Machine>&) const;
};

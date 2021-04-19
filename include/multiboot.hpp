#pragma once
#include <queue>
#include <set>
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
     * @param ansioso_ bool
     * @param iterations Number of Iterations in the algorithm
     * @param k Number of elements in RCL
     */
    explicit Multiboot(int, int stopCriterion_ = 1, bool ansioso_ = false,
                   int iterations = 1000, int k = 3);
    Solution run(int) override;

  private:
    int iterations_;
    int k_;
    int stopCriterion_;
    bool ansioso_;
    std::vector<Task> getBestK(int) const;
    Solution construction(const std::vector<Machine>&);
    Solution postProcessing(const std::vector<Machine>&);
    Solution postProcessing_reInsert(const std::vector<Machine>&);
    Solution postProcessing_move(const std::vector<Machine>&);
    Solution postProcessing_innerSwap(const std::vector<Machine>&);
    Solution postProcessing_extraSwap(const std::vector<Machine>&);

    // Movements
    int typeOfMovement_;
    void reinsert(Machine& machine, int previousPosition, int newPosition);
    void move(Machine& previousMachine, int previousPosition,
              Machine& newMachine, int newPosition);
    void innerSwap(Machine& machine, int position1, int position2);
    void extraSwap(Machine& machine1, int position1, Machine& machine2,
                   int position2);
    void pseudo_reset(const std::vector<Machine>&) const;
};

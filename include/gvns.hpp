#pragma once

#include "multiboot.hpp"

class GVNS: public Multiboot{
  public:
    /**
     * @brief Load all the attributes
     *
     * @param typeOfMovement Type of movement
     * @param typeOfShaking Type of movement to make the jump
     * @param stopCriterion Stop criterion
     * @param anxious Determinate if the algorithm its anxious or not.
     * @param iterations Number of Iterations in the algorithm
     * @param k Number of elements in RCL
     */
    explicit GVNS(int typeOfMovement = 0, int typeOfShaking = 1,
        int stopCriterion = 1, bool anxious = false, int iterations = 1000,
        int k = 3);

    /**
     * @brief Start running the algorithm
     *
     * @param {m} Number of machines
     * @return Definitive solution
     */
    Solution run(int) override;
  private:
    /**
     * @typeOfShaking_ Type of movement to make the jump
     */
    int typeOfShaking_;

    /**
     * @brief Make a "jumo" by moving k tasks
     *
     * @param {machines} Machines already processed by the GRASP algorithm
     * @param {k} Number of movements to make
     */
    std::vector<Machine> shaking(const std::vector<Machine>&, int);

    /**
     * @brief [TODO:description]
     *
     * @param {name} [TODO:description]
     * @return [TODO:description]
     */
    Solution vnd(const std::vector<Machine>&);
    Solution postProcessing(const std::vector<Machine>&, int);
};

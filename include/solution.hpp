#pragma once

#include <vector>
#include "machine.hpp"

/**
 * @brief [TODO:description]
 */
class Solution {
  public:
    /**
     * @brief I don't create empty solutions
     *
     */
    Solution() = delete;

    /**
     * @brief Create a solution from a vector of machines
     *
     * @param {machines} Vector of machines
     */
    explicit Solution(const std::vector<Machine>&);

    /**
     * @brief Copy constructor
     *
     * @param {other} Other solution
     */
    Solution(const Solution&);

    /**
     * @brief Move constructor
     *
     * @param {other} Other solution
     */
    Solution(Solution&&);

    /**
     * @brief Assign operator
     *
     * @param {other} Other solution
     */
    Solution& operator =(const Solution&);

    /**
     * @brief Assign operator
     *
     * @param {other} Other solution
     */
    Solution& operator =(Solution&&);

    /**
     * @brief Return the attribute machines_ (vector of Machine)
     *
     */
    const std::vector<Machine>& getMachines() const;

    /**
     * @brief Calculate what is the size of smallest Machine
     *
     * @return The size of the smallest machine
     */
    size_t getMinimalMachineSize() const;

    /**
     * @brief Return the attribute z_
     *
     */
    unsigned long getZ() const;

    /**
     * @brief A solution is smaller than other if it has a smaller z_
     *
     * @param {other} Other solution
     * @return True if this.z_ is smaller than other.z_, false otherwise
     */
    bool operator <(const Solution&);

    /**
     * @brief Send the content af all the Machines
     *
     * @param os ostream, default its std::cout
     */
    std::ostream& show(std::ostream& os = std::cout);

    /**
     * @brief Send the value of z_ to the os output
     *
     * @param os ostream, default its std::cout
     */
    std::ostream& showOnlyZ(std::ostream& os = std::cout);

    /**
     * @brief Send the content of all the machines, their TCT, and z_
     *
     * @param os ostream, default its std::cout
     */
    std::ostream& showWithTCTs(std::ostream& os = std::cout);

  private:
    /**
     * @brief Generate the value of z_
     *
     */
    void generateZ();

    /**
     * @machines_ Vector of Machine
     */
    std::vector<Machine> machines_;

    /**
     * @z_ Target function, its the sum of all the TCT of all the machines in
     * this solution
     */
    unsigned long z_;
};

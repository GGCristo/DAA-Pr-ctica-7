// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include "../include/greedy_time.hpp"

Solution GreedyTime::run(int m) {
  assert(!Data::getInstance().getTimes()[0].second);
  std::vector<Machine> machines = preprocessing(m);
  // TODO machines.size(), what happends if there are more machines than tasks
  for (size_t i = 0; i < Data::getInstance().getN() - machines.size(); ++i) {
    std::vector<Task> aux;
    aux.reserve(machines.size());
    for (size_t j = 0; j < machines.size(); ++j) {
      aux.push_back(getTask(machines[j].getIdLastTask()));
    }
    int auxMinSum = aux[0].getTime() + machines[0].getTime();
    int minPosition = 0;
    for (size_t j = 1; j < aux.size(); ++j) {
      if (aux[j].getTime() + machines[j].getTime() <
          auxMinSum) {
        minPosition = j;
        auxMinSum = aux[j].getTime() + machines[j].getTime();
      }
    }
    machines[minPosition].add(aux[minPosition]);
  }
  return Solution(machines);
}

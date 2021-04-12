// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include "../include/greedy_time.hpp"

void GreedyTime::algorithm(std::vector<Maquina>& maquinas) {
  assert(!Datos::getInstance().getTimes()[0].second);
  for (size_t i = 0; i < maquinas.size(); ++i) {
    maquinas[i].add(getTask(maquinas[i].getIdLastTask()));
  }
  // TODO maquinas.size(), what happends if there are more machines than tasks
  for (size_t i = 0; i < Datos::getInstance().getN() - maquinas.size(); ++i) {
    std::vector<Tarea> aux;
    aux.reserve(maquinas.size());
    for (size_t j = 0; j < maquinas.size(); ++j) {
      aux.push_back(getTask(maquinas[j].getIdLastTask()));
    }
    int auxMinSum = aux[0].getTime() + maquinas[0].getTime();
    int minPosition = 0;
    for (size_t j = 1; j < aux.size(); ++j) {
      if (aux[j].getTime() + maquinas[j].getTime() <
          auxMinSum) {
        minPosition = j;
        auxMinSum = aux[j].getTime() + maquinas[j].getTime();
      }
    }
    maquinas[minPosition].add(aux[minPosition]);
  }
}

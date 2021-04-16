// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include "../include/greedy_TCT.hpp"

Solucion GreedyTCT::run(int m) {
  assert(!Datos::getInstance().getTimes()[0].second);
  std::vector<Maquina> maquinas = preprocesamiento(m);
  // TODO maquinas.size(), what happends if there are more machines than tasks
  for (size_t i = 0; i < Datos::getInstance().getN() - maquinas.size(); ++i) {
    std::vector<Tarea> aux;
    aux.reserve(maquinas.size());
    for (size_t j = 0; j < maquinas.size(); ++j) {
      aux.push_back(getTask(maquinas[j].getIdLastTask()));
    }
    unsigned long auxMinSum = maquinas[0].peekTCT(aux[0]);
    int minPosition = 0;
    for (size_t j = 1; j < aux.size(); ++j) {
      if (maquinas[j].peekTCT(aux[j]) < auxMinSum) {
        minPosition = j;
        auxMinSum = maquinas[j].peekTCT(aux[j]);
      }
    }
    maquinas[minPosition].add(aux[minPosition]);
  }
  return Solucion(maquinas);
}

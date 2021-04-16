// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include "../include/parallelInterface.hpp"

#include "../include/datos.hpp"

Tarea ParallelInterface::getTask(int previousTask) {
  int auxMinSum = -1;
  int minPosition = -1;
  Datos* datos = &Datos::getInstance();
  size_t i = 0;
  for (; i < datos->getTimes().size(); ++i) {
    if (!datos->getTimes()[i].second) {
      auxMinSum = datos->getTimes()[i].first +
        datos->getSetups()[previousTask + 1][i + 1];
      minPosition = i++;
      break;
    }
  }
  if (auxMinSum == -1) {
    throw "[getTask] No hay más tareas disponibles\n";
  }
  if (minPosition == -1) {
    throw "[getTask] No hay ninguna tarea disponibles\n";
  }
  for(; i < datos->getTimes().size(); ++i) {
    if (!datos->getTimes()[i].second && getTime(previousTask, i) <
        auxMinSum) {
      auxMinSum = datos->getTimes()[i].first +
        datos->getSetups()[previousTask + 1][i + 1];
      minPosition = i;
    }
  }
  return Tarea(minPosition, auxMinSum);
}

int ParallelInterface::getTime(int previousTask, int currentTask) {
  return Datos::getInstance().getTimes()[currentTask].first +
    Datos::getInstance().getSetups()[previousTask + 1][currentTask + 1];
}

std::vector<Maquina> ParallelInterface::preprocesamiento(int m) {
  std::vector<Maquina> maquinas;
  for (int i = 0; i < m; ++i) {
    maquinas.emplace_back(Maquina());
    // TODO -1 instead of maquinas[i].getIdLastTask();
    maquinas[i].add(getTask(maquinas[i].getIdLastTask()));
  }
  return maquinas;
}

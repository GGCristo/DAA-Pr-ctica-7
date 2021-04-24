// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include "../include/parallelInterface.hpp"

#include "../include/data.hpp"

Task ParallelInterface::getTask(int previousTask) const {
  int auxMinSum = -1;
  int minPosition = -1;
  Data* datos = &Data::getInstance();
  size_t i = 0;
  for (; i < datos->getTimes().size(); ++i) {
    if (!datos->isTaskTaken(i)) {
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
    if (!datos->isTaskTaken(i) && getTime(previousTask, i) <
        auxMinSum) {
      auxMinSum = datos->getTimes()[i].first +
        datos->getSetups()[previousTask + 1][i + 1];
      minPosition = i;
    }
  }
  return Task(minPosition, auxMinSum);
}

int ParallelInterface::getTime(int previousTask, int currentTask) const {
  return Data::getInstance().getTimes()[currentTask].first +
    Data::getInstance().getSetups()[previousTask + 1][currentTask + 1];
}

std::vector<Machine> ParallelInterface::preprocessing(int m) {
  std::vector<Machine> machines;
  for (int i = 0; i < m; ++i) {
    machines.emplace_back(Machine());
    // -1 == machines[i].getIdLastTask(), We are in preprocessing so I already
    // know the queue of tasks is empty
    machines[i].add(getTask(-1));
  }
  return machines;
}

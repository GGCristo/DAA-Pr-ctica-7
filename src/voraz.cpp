#include "../include/voraz.hpp"

void voraz(std::vector<Maquina>& maquinas) {
  for (size_t i = 0; i < maquinas.size(); ++i) {
    maquinas[i].add(getTask(maquinas[i].getIdLastTask()));
  }
  // TODO maquinas.size(), what happends if there are more machines than tasks
  for (size_t i = 0; i < Datos::getInstance().getN() - maquinas.size(); ++i) {
    std::vector<Tarea> aux;
    aux.reserve(maquinas.size());
    for (size_t i = 0; i < maquinas.size(); ++i) {
      aux.push_back(getTask(maquinas[i].getIdLastTask()));
    }
    int auxMinSum = aux[0].getTime() + maquinas[0].getTime();
    int minPosition = 0;
    for (size_t i = 1; i < aux.size(); ++i) {
      if (aux[i].getTime() + maquinas[i].getTime() <
          auxMinSum) {
        minPosition = i;
        auxMinSum = aux[i].getTime() + maquinas[i].getTime();
      }
    }
    maquinas[minPosition].add(aux[minPosition]);
  }
}

const Tarea getTask(int previousTask) {
  int auxMinSum;
  int minPosition;
  Tarea tarea;
  Datos* datos = &Datos::getInstance();
  size_t i = 1;
  for (; i < datos->getSetups()[previousTask].size(); ++i) {
    if (!datos->getTimes()[i - 1].second) {
      auxMinSum = datos->getTimes()[i - 1].first +
        datos->getSetups()[previousTask][i];
      minPosition = i++;
      break;
    }
  }
  for(; i < datos->getSetups()[previousTask].size(); ++i) {
    if (!datos->getTimes()[i - 1].second &&
        datos->getTimes()[i -1].first + datos->getSetups()[previousTask][i] <
        auxMinSum) {
      auxMinSum = datos->getTimes()[i - 1].first +
        datos->getSetups()[previousTask][i];
      minPosition = i;
    }
  }
  return Tarea(minPosition - 1, auxMinSum);
}

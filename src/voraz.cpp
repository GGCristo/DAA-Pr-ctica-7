#include "../include/voraz.hpp"

void voraz(std::vector<Maquina>& maquinas) {
  for (size_t i = 0; i < maquinas.size(); ++i) {
    maquinas[i].add(getTask(0));
  }
}

const Tarea getTask(int previousTask) {
  int auxMinSum;
  int minPosition = -1;
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
  datos->getTimes()[minPosition - 1].second = true;
  return Tarea(minPosition, auxMinSum);
}

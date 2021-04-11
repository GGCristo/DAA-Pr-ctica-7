#include "../include/voraz.hpp"

void voraz(std::vector<Maquina>& maquinas) {
  for (size_t i = 0; i < maquinas.size(); ++i) {
    maquinas[i].add(getTask(0));
  }
}

const Tarea getTask(int previousTask) {
  int minPosition = -1;
  Tarea tarea;
  Datos* datos = &Datos::getInstance();
  size_t i = 1;
  for (; i < datos->getSetups()[previousTask].size(); ++i) {
    if (!datos->getTimes()[i].second) {
      minPosition = i;
      break;
    }
  }
  for(; i < datos->getSetups()[previousTask].size(); ++i) {
    if (!datos->getTimes()[i].second &&
        datos->getSetups()[previousTask][i] <
        datos->getSetups()[previousTask][minPosition]) {
      minPosition = i;
    }
  }
  // std::cout << "Meto: MinPosition; " << minPosition << " Times; " << datos->getSetups()[previousTask][minPosition] << '\n';
  datos->getTimes()[minPosition].second = true;
  return Tarea(minPosition,
      datos->getSetups()[previousTask][minPosition] +
      datos->getTimes()[minPosition].first);
}

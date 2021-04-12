#include "../include/parallelInterface.hpp"

#include "../include/datos.hpp"

const Tarea ParallelInterface::getTask(int previousTask) {
  // std::cout << "El anterior es: " << previousTask << '\n';
  int auxMinSum;
  int minPosition;
  Tarea tarea;
  Datos* datos = &Datos::getInstance();
  size_t i = 0;
  for (; i < datos->getTimes().size(); ++i) {
    if (!datos->getTimes()[i].second) {
      auxMinSum = datos->getTimes()[i].first +
        datos->getSetups()[previousTask + 1][i + 1];
      minPosition = i;
      break;
    }
  }
  for(++i; i < datos->getTimes().size(); ++i) {
    if (!datos->getTimes()[i].second &&
        datos->getTimes()[i].first + datos->getSetups()[previousTask + 1][i + 1] <
        auxMinSum) {
      auxMinSum = datos->getTimes()[i].first +
        datos->getSetups()[previousTask + 1][i + 1];
      minPosition = i;
    }
  }
  // std::cout << "La tarea[i]: " << minPosition << " con valor: " << auxMinSum << '\n';
  return Tarea(minPosition, auxMinSum);
}

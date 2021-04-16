// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include "../include/grasp.hpp"

using Random = effolkronium::random_static;

// void Grasp::algorithm(std::vector<Maquina>& maquinas) {
//   // Fase constructiva
//   std::vector<int> copyInteger;
//   copyInteger.reserve(Datos::getInstance().getN());
//   for (int i = 0; i < Datos::getInstance().getN(); ++i){
//     copyInteger.push_back(i);
//   }
//   while(!copyInteger.empty()) {
//     int randomTask = Random::get(0, (int)copyInteger.size() - 1);
//     int randomMachine = Random::get(0,  (int)maquinas.size() - 1);
//     maquinas[randomMachine].add(Tarea(copyInteger[randomTask], getTime(
//             maquinas[randomMachine].getIdLastTask(), copyInteger[randomTask])));
//     copyInteger.erase(copyInteger.begin() + randomTask);
//   }
// }

bool isTaskAlreadyIn(const std::vector<Tarea>& bestK, int id) {
  for(size_t i = 0; i < bestK.size(); ++i) {
    if (bestK[i].getId() == id) {
      return true;
    }
  }
  return false;
}

std::vector<Tarea> Grasp::getBestK(int previousTask, size_t k) {
  std::vector<Tarea> bestK;
  while (bestK.size() != k) {
    int minPosition = -1;
    int auxMinSum = -1;
    int i = 0;
    for (; i < Datos::getInstance().getN(); ++i) {
      if (!Datos::getInstance().getTimes()[i].second) {
        auxMinSum = getTime(previousTask, i);
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
    for (; i < Datos::getInstance().getN(); ++i) {
      if (!isTaskAlreadyIn(bestK, i) && !Datos::getInstance().getTimes()[i].second) {
        if (getTime(previousTask, i) < auxMinSum) {
          minPosition = i;
          auxMinSum = getTime(previousTask, i);
        }
      }
    }
    bestK.push_back(Tarea(minPosition, auxMinSum));
  }
  return bestK;
}

void Grasp::algorithm(std::vector<Maquina>& maquinas) {
  preprocesamiento(maquinas);
  while (!Datos::getInstance().areAllTaskReady()) {
    for (size_t j = 0; j < maquinas.size(); ++j) {
      std::vector<Tarea> rcl = getBestK(maquinas[j].getIdLastTask());
      Tarea candidato = rcl[Random::get(0, (int)rcl.size() - 1)];
      maquinas[j].add(candidato);
    }
  }
}

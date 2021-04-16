// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include "../include/grasp.hpp"

using Random = effolkronium::random_static;

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

Solucion Grasp::construction(const std::vector<Maquina>& maquinas) {
  std::vector<Maquina> construction = maquinas;
  while (!Datos::getInstance().areAllTaskReady()) {
    for (size_t j = 0; j < construction.size(); ++j) {
      std::vector<Tarea> rcl = getBestK(construction[j].getIdLastTask());
      Tarea candidato = rcl[Random::get(0, (int)rcl.size() - 1)];
      construction[j].add(candidato);
    }
  }
  return Solucion(construction);
}

bool updateSolution(Solucion& solution, Solucion& bestSolution) {
    if (bestSolution.getZ() < solution.getZ()) {
      solution = bestSolution;
      return true;
    }
    return false;
}

Solucion Grasp::run(int m) {
  int noImprovementIteraction = 0;
  std::vector<Maquina> maquinas = preprocesamiento(m);
  Solucion bestSolution = construction(maquinas);
  // Local
  Solucion solution = bestSolution;
  while(noImprovementIteraction < 1000) {
    Solucion bestSolution = construction(maquinas);
    // Local():
    if (updateSolution(solution, bestSolution)) {
      noImprovementIteraction = 0;
    } else {
      noImprovementIteraction++;
    }
  }
  return solution;
}

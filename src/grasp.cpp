// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include "../include/grasp.hpp"

using Random = effolkronium::random_static;

Grasp::Grasp(int typeOfMovement, size_t k) {
  typeOfMovement_ = typeOfMovement;
  k_ = k;
}

bool isTaskAlreadyIn(const std::vector<Tarea>& bestK, int id) {
  for(size_t i = 0; i < bestK.size(); ++i) {
    if (bestK[i].getId() == id) {
      return true;
    }
  }
  return false;
}

std::vector<Tarea> Grasp::getBestK(int previousTask) {
  std::vector<Tarea> bestK;
  while (bestK.size() != k_) {
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
      throw "[getBestK] No hay más tareas disponibles\n";
    }
    if (minPosition == -1) {
      throw "[getBestK] No hay ninguna tarea disponibles\n";
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
  Solucion potencialSolution = construction(maquinas);
  Solucion solution = postProcessing(potencialSolution.getMachines());
  while(noImprovementIteraction < 1000) {
    potencialSolution = construction(maquinas);
    potencialSolution = postProcessing(potencialSolution.getMachines());
    if (updateSolution(solution, potencialSolution)) {
      noImprovementIteraction = 0;
    } else {
      noImprovementIteraction++;
    }
  }
  return solution;
}

Solucion Grasp::postProcessing(const std::vector<Maquina>& maquinas) {
  switch(typeOfMovement_) {
    case 0:
      return postProcessing_reInsert(maquinas);
    case 1:
      return postProcessing_move(maquinas);
    case 2:
      return postProcessing_innerSwap(maquinas);
    case 3:
      return postProcessing_extraSwap(maquinas);
    default:
      throw "That movements is not allowed!\n";
  }
}

Solucion Grasp::postProcessing_reInsert(const std::vector<Maquina>& maquinas) {
  std::vector<Solucion> solutions;
  for (int maquina = 0; maquina < maquinas.size(); ++maquina) {
    for (int pivot = 0; pivot < maquinas[maquina].size(); ++pivot) {
      for (int newPosition = 0; newPosition < maquinas[maquina].size(); ++newPosition) {
        if (pivot == newPosition) continue;
        std::vector<Maquina> copyMaquinas = maquinas;
        reinsert(copyMaquinas[maquina], pivot, newPosition);
        solutions.push_back(Solucion(copyMaquinas));
      }
    }
  }
  return *std::min_element(solutions.begin(), solutions.end());
}

Solucion Grasp::postProcessing_move(const std::vector<Maquina>& maquinas) {
  std::vector<Solucion> solutions;
  for (int previousMachine = 0; previousMachine < maquinas.size(); ++previousMachine) {
    for (int previousPosition = 0; previousPosition < maquinas[previousMachine].size(); ++previousPosition) {
      for (int newMachine = 0; newMachine < maquinas.size(); ++newMachine) {
        if (previousMachine == newMachine) continue;
        for (int newPosition = 0; newPosition < maquinas[newMachine].size(); ++newPosition) {
          std::vector<Maquina> copyMaquinas = maquinas;
          move(copyMaquinas[previousMachine], previousPosition, copyMaquinas[newMachine], newPosition);
          solutions.push_back(Solucion(copyMaquinas));
        }
      }
    }
  }
  return *std::min_element(solutions.begin(), solutions.end());
}

Solucion Grasp::postProcessing_innerSwap(const std::vector<Maquina>& maquinas) {
  std::vector<Solucion> solutions;
  for (int maquina = 0; maquina < maquinas.size(); ++maquina) {
    for (int pivot = 0; pivot < maquinas[maquina].size(); ++pivot) {
      for (int newPosition = 0; newPosition < maquinas[maquina].size(); ++newPosition) {
        if (pivot == newPosition) continue;
        std::vector<Maquina> copyMaquinas = maquinas;
        innerSwap(copyMaquinas[maquina], pivot, newPosition);
        solutions.push_back(Solucion(copyMaquinas));
      }
    }
  }
  return *std::min_element(solutions.begin(), solutions.end());
}

Solucion Grasp::postProcessing_extraSwap(const std::vector<Maquina>& maquinas) {
  std::vector<Solucion> solutions;
  for (int previousMachine = 0; previousMachine < maquinas.size(); ++previousMachine) {
    for (int previousPosition = 0; previousPosition < maquinas[previousMachine].size(); ++previousPosition) {
      for (int newMachine = 0; newMachine < maquinas.size(); ++newMachine) {
        if (previousMachine == newMachine) continue;
        for (int newPosition = 0; newPosition < maquinas[newMachine].size(); ++newPosition) {
          std::vector<Maquina> copyMaquinas = maquinas;
          extraSwap(copyMaquinas[previousMachine], previousPosition, copyMaquinas[newMachine], newPosition);
          solutions.push_back(Solucion(copyMaquinas));
        }
      }
    }
  }
  return *std::min_element(solutions.begin(), solutions.end());
}

// Movements
void Grasp::reinsert(Maquina& machine, int previousPosition, int newPosition) {
  Maquina futureSolution = machine;
  Tarea deleted = machine.erase(previousPosition);
  machine.insert(deleted, newPosition);
  machine.reCalculateTimeFrom(std::min(previousPosition, newPosition));
  // TODO better reCalculateTct
  machine.reCalculateTct();
}

void Grasp::move(Maquina& previousMachine, int previousPosition, Maquina& newMachine,
    int newPosition) {
  // TODO create ID for machine
  // if (previousMachine == newMachine) {
  //   std::cout << "Warning: Using a move in the same machine, consider to use reInsert\n";
  // }
  auto deleted = previousMachine.erase(previousPosition);
  newMachine.insert(deleted, newPosition);
  previousMachine.reCalculateTimeFrom(previousPosition);
  newMachine.reCalculateTimeFrom(newPosition);

  previousMachine.reCalculateTct();
  newMachine.reCalculateTct();
}

void Grasp::innerSwap(Maquina& machine, int position1, int position2) {
  std::iter_swap(machine.begin() + position1,
      machine.begin() + position2);
  machine.reCalculateTimeFrom(std::min(position1, position2));
  machine.reCalculateTct();
}

void Grasp::extraSwap(Maquina& machine1, int position1, Maquina& machine2,
    int position2) {
  std::iter_swap(machine1.begin() + position1,
      machine2.begin() + position2);

  machine1.reCalculateTimeFrom(position1);
  machine2.reCalculateTimeFrom(position2);

  machine1.reCalculateTct();
  machine2.reCalculateTct();
}

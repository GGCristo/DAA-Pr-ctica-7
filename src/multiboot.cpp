// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include "../include/multiboot.hpp"

using Random = effolkronium::random_static;

enum Stop_Criterion {iterations, iterationsSinceImprovement};

Multiboot::Multiboot(int typeOfMovement, int stopCriterion, int iterations, int k) {
  typeOfMovement_ = typeOfMovement;
  iterations_ = iterations;
  stopCriterion_ = stopCriterion;
  k_ = k;
}

bool isTaskAlreadyIn(const std::vector<Task>& bestK, int id) {
  for(size_t i = 0; i < bestK.size(); ++i) {
    if (bestK[i].getId() == id) {
      return true;
    }
  }
  return false;
}

std::vector<Task> Multiboot::getBestK(int previousTask) const {
  std::vector<Task> bestK;
  for (int k = 0; k < k_; ++k) {
    int minPosition = -1;
    int auxMinSum = -1;
    int i = 0;
    for (; i < Data::getInstance().getN(); ++i) {
      if (!isTaskAlreadyIn(bestK, i) && !Data::getInstance().getTimes()[i].second) {
        auxMinSum = getTime(previousTask, i);
        minPosition = i++;
        break;
      }
    }
    for (; i < Data::getInstance().getN(); ++i) {
      if (!isTaskAlreadyIn(bestK, i) && !Data::getInstance().getTimes()[i].second) {
        if (getTime(previousTask, i) < auxMinSum) {
          minPosition = i;
          auxMinSum = getTime(previousTask, i);
        }
      }
    }
    if (minPosition != -1) {
      bestK.push_back(Task(minPosition, auxMinSum));
    }
  }
  return bestK;
}

Solution Multiboot::construction(const std::vector<Machine>& machines) {
  std::vector<Machine> construction = machines;
  if (Data::getInstance().areAllTaskReady()) {
    throw "[construction] There are no task available";
  }
  while (!Data::getInstance().areAllTaskReady()) {
    for (size_t j = 0; j < construction.size() &&
            !Data::getInstance().areAllTaskReady(); ++j) {
      std::vector<Task> rcl = getBestK(construction[j].getIdLastTask());

      Task candidato = rcl[Random::get(0, (int)rcl.size() - 1)];
      construction[j].add(candidato);
    }
  }
  return Solution(construction);
}

bool updateSolution(Solution& solution, Solution& bestSolution) {
  if (bestSolution.getZ() < solution.getZ()) {
    solution = bestSolution;
    return true;
  }
  return false;
}

Solution Multiboot::run(int m) {
  int noImprovementIteraction = 0;
  std::vector<Machine> preprocesado = preprocesamiento(m);
  Solution potencialSolution = construction(preprocesado);
  Solution solution = postProcessing(potencialSolution.getMachines());
  while(noImprovementIteraction < iterations_ - 1) {
    pseudo_reset(preprocesado);
    potencialSolution = construction(preprocesado);
    potencialSolution = postProcessing(potencialSolution.getMachines());
    if (updateSolution(solution, potencialSolution)) {
      if (stopCriterion_ == iterationsSinceImprovement) {
        noImprovementIteraction = 0;
      } else {
        noImprovementIteraction++;
      }
    } else {
      noImprovementIteraction++;
    }
  }
  return solution;
}

void Multiboot::pseudo_reset(const std::vector<Machine>& machines) const {
  Data::getInstance().reset();
  for (size_t maquina = 0; maquina < machines.size(); ++maquina) {
    Data::getInstance().getTimes()[machines[maquina].begin()->getId()].second = true;
  }
}

Solution Multiboot::postProcessing(const std::vector<Machine>& machines) {
  switch(typeOfMovement_) {
    case 0:
      return postProcessing_reInsert(machines);
    case 1:
      return postProcessing_move(machines);
    case 2:
      return postProcessing_innerSwap(machines);
    case 3:
      return postProcessing_extraSwap(machines);
    default:
      throw "That movements is not allowed!\n";
  }
}

Solution Multiboot::postProcessing_reInsert(const std::vector<Machine>& machines) {
  std::vector<Solution> solutions;
  for (size_t maquina = 0; maquina < machines.size(); ++maquina) {
    for (size_t pivot = 0; pivot < machines[maquina].size(); ++pivot) {
      for (size_t newPosition = 0; newPosition < machines[maquina].size(); ++newPosition) {
        if (pivot == newPosition) continue;
        std::vector<Machine> copyMaquinas = machines;
        reinsert(copyMaquinas[maquina], pivot, newPosition);
        solutions.push_back(Solution(copyMaquinas));
      }
    }
  }
  return *std::min_element(solutions.begin(), solutions.end());
}

Solution Multiboot::postProcessing_move(const std::vector<Machine>& machines) {
  std::vector<Solution> solutions;
  for (size_t previousMachine = 0; previousMachine < machines.size(); ++previousMachine) {
    for (size_t previousPosition = 0; previousPosition < machines[previousMachine].size(); ++previousPosition) {
      for (size_t newMachine = 0; newMachine < machines.size(); ++newMachine) {
        if (previousMachine == newMachine) continue;
        for (size_t newPosition = 0; newPosition < machines[newMachine].size(); ++newPosition) {
          std::vector<Machine> copyMaquinas = machines;
          move(copyMaquinas[previousMachine], previousPosition, copyMaquinas[newMachine], newPosition);
          solutions.push_back(Solution(copyMaquinas));
        }
      }
    }
  }
  return *std::min_element(solutions.begin(), solutions.end());
}

Solution Multiboot::postProcessing_innerSwap(const std::vector<Machine>& machines) {
  std::vector<Solution> solutions;
  for (size_t maquina = 0; maquina < machines.size(); ++maquina) {
    for (size_t pivot = 0; pivot < machines[maquina].size(); ++pivot) {
      for (size_t newPosition = 0; newPosition < machines[maquina].size(); ++newPosition) {
        if (pivot == newPosition) continue;
        std::vector<Machine> copyMaquinas = machines;
        innerSwap(copyMaquinas[maquina], pivot, newPosition);
        solutions.push_back(Solution(copyMaquinas));
      }
    }
  }
  return *std::min_element(solutions.begin(), solutions.end());
}

Solution Multiboot::postProcessing_extraSwap(const std::vector<Machine>& machines) {
  std::vector<Solution> solutions;
  for (size_t previousMachine = 0; previousMachine < machines.size(); ++previousMachine) {
    for (size_t previousPosition = 0; previousPosition < machines[previousMachine].size(); ++previousPosition) {
      for (size_t newMachine = 0; newMachine < machines.size(); ++newMachine) {
        if (previousMachine == newMachine) continue;
        for (size_t newPosition = 0; newPosition < machines[newMachine].size(); ++newPosition) {
          std::vector<Machine> copyMaquinas = machines;
          extraSwap(copyMaquinas[previousMachine], previousPosition, copyMaquinas[newMachine], newPosition);
          solutions.push_back(Solution(copyMaquinas));
        }
      }
    }
  }
  return *std::min_element(solutions.begin(), solutions.end());
}

// Movements
void Multiboot::reinsert(Machine& machine, int previousPosition, int newPosition) {
  Task deleted = machine.erase(previousPosition);
  machine.insert(deleted, newPosition);
  machine.reCalculateTimeFrom(std::min(previousPosition, newPosition));
  // TODO better reCalculateTct
  machine.reCalculateTct();
}

void Multiboot::move(Machine& previousMachine, int previousPosition, Machine& newMachine,
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

void Multiboot::innerSwap(Machine& machine, int position1, int position2) {
  std::iter_swap(machine.begin() + position1,
      machine.begin() + position2);
  machine.reCalculateTimeFrom(std::min(position1, position2));
  machine.reCalculateTct();
}

void Multiboot::extraSwap(Machine& machine1, int position1, Machine& machine2,
    int position2) {
  std::iter_swap(machine1.begin() + position1,
      machine2.begin() + position2);

  machine1.reCalculateTimeFrom(position1);
  machine2.reCalculateTimeFrom(position2);

  machine1.reCalculateTct();
  machine2.reCalculateTct();
}

// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include "../include/gvns.hpp"

using Random = effolkronium::random_static;

enum Movements { reInsert_enum, move_enum, innerSwap_enum, extraSwap_enum };

enum Stop_Criterion {iterations, iterationsSinceImprovement};

GVNS::GVNS(int typeOfMovement, int typeOfShaking, int stopCriterion, bool anxious,
    int iterations, int k)
  : Multiboot(typeOfMovement, stopCriterion, anxious, iterations, k) {
    if(typeOfMovement_ != reInsert_enum && typeOfMovement_ != extraSwap_enum) {
      std::cerr << "GRASP must be done with reInsert or extraSwap movements\n";
    }
    typeOfShaking_ = typeOfShaking;
    if(typeOfShaking_ != move_enum && typeOfShaking_ != extraSwap_enum) {
      std::cerr << "Shake/Jump must be done with move or extraSwap movements\n";
    }
}

Solution GVNS::run(int m) {
  int noImprovementIteraction = 0;
  // GRASP
  std::vector<Machine> preprocesado = preprocessing(m);
  Solution potencialSolution = construction(preprocesado);
  Solution solution = Multiboot::postProcessing(potencialSolution.getMachines());
  // GVNS
  while(noImprovementIteraction < iterations_) {
    pseudo_reset(preprocesado);
    potencialSolution = construction(preprocesado);
    potencialSolution = Multiboot::postProcessing(potencialSolution.getMachines());
    int k = 2;
    int kmax = std::min((int)potencialSolution.getMinimalMachineSize(), 5);
    while (k < kmax) {
      std::vector<Machine> shaked = shaking(potencialSolution.getMachines(), k);
      if (updateSolution(solution, vnd(shaked))){
        k = 2;
        if (stopCriterion_ == iterationsSinceImprovement) {
          noImprovementIteraction = 0;
        } else {
          ++noImprovementIteraction;
        }
      } else {
        ++k;
        ++noImprovementIteraction;
      }
    }
  }
  return solution;
}

std::vector<Machine> GVNS::shaking(const std::vector<Machine>& machines, int k) {
  std::vector<Machine> shaked = machines;

  for(int i = 0; i < k; ++i) {
    const int PREVIOUS_MACHINE = Random::get(0, (int)shaked.size() - 1);
    const int PREVIOUS_POSITION = Random::get(0,
        (int)shaked[PREVIOUS_MACHINE].size() - 1);

    const int NEW_MACHINE = Random::get(0, (int)shaked.size() - 1);
    const int NEW_POSITION = Random::get(0,
        (int)shaked[NEW_MACHINE].size() - 1);
    switch(typeOfShaking_) {
      case move_enum:
        move(shaked[PREVIOUS_MACHINE], PREVIOUS_POSITION, shaked[NEW_MACHINE],
            NEW_POSITION);
        break;
      case extraSwap_enum:
        extraSwap(shaked[PREVIOUS_MACHINE], PREVIOUS_POSITION, shaked[NEW_MACHINE],
            NEW_POSITION);
        break;
      default:
        throw "[GVNS | shaking] That movement is not allowed\n";
    }
  }
  return shaked;
}

Solution GVNS::postProcessing(const std::vector<Machine>& constructedMachines,
      int l) {
    switch (l) {
      case 0:
        return postProcessing_reInsert(constructedMachines);
      case 1:
        return postProcessing_move(constructedMachines);
      case 2:
        return postProcessing_innerSwap(constructedMachines);
      case 3:
        return postProcessing_extraSwap(constructedMachines);
        break;
      default:
        throw "[GVNS | vnd] There are not that many movements\n";
    }
}

Solution GVNS::vnd(const std::vector<Machine>& shaked){
  int l = 0;
  Solution solution(shaked);
  while (l < 4) {
    Solution probablySolution(postProcessing(solution.getMachines(), l));
    if (!updateSolution(solution, probablySolution)) {
      ++l;
    } else {
      if (anxious_) return solution;
      l = 1;
    }
  }
  return solution;
}

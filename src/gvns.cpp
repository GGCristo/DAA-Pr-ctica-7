// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include "../include/gvns.hpp"

using Random = effolkronium::random_static;

enum Movements { reInsert_enum, move_enum, innerSwap_enum, extraSwap_enum };

enum Stop_Criterion {iterations, iterationsSinceImprovement};

GVNS::GVNS(int typeOfMovement, int typeOfShaking, int stopCriterion, bool ansioso,
    int iterations, int k)
  : Multiboot(typeOfMovement, stopCriterion, ansioso,
    iterations, k) {
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
  Solution solution = postProcessing(potencialSolution.getMachines());
  // GVNS
  while(noImprovementIteraction < iterations_) {
    pseudo_reset(preprocesado);
    potencialSolution = construction(preprocesado);
    potencialSolution = postProcessing(potencialSolution.getMachines());
    int k = 2;
    while (k < 4) {
      std::vector<Machine> shaked = shaking(potencialSolution.getMachines(), k);
      if (updateSolution(solution, vnd(shaked))){
        k = 2;
        if (stopCriterion_ == iterationsSinceImprovement) {
          noImprovementIteraction = 0;
        } else {
          noImprovementIteraction++;
        }
      } else {
        k++;
        noImprovementIteraction++;
      }
    }
  }
  return solution;
}

std::vector<Machine> GVNS::shaking(const std::vector<Machine>& machines, int k) {
  std::vector<Machine> shaked = machines;

  for(size_t i = 0; i < k; ++i) {
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

Solution GVNS::vnd(const std::vector<Machine>& shaked){
  int l = 0;
  Solution solution(shaked);
  Solution probablySolution;
  while (l < 4) {
    switch (l) {
      case 0:
        probablySolution = postProcessing_reInsert(solution.getMachines());
        break;
      case 1:
        probablySolution = postProcessing_move(solution.getMachines());
        break;
      case 2:
        probablySolution = postProcessing_innerSwap(solution.getMachines());
        break;
      case 3:
        probablySolution = postProcessing_extraSwap(solution.getMachines());
        break;
      default:
        throw "[GVNS | vnd] There are not that many movements\n";
    }
    if (!updateSolution(solution, probablySolution)) {
      l++;
    } else {
      if (ansioso_) return solution;
      l = 1;
    }
  }
  return solution;
}

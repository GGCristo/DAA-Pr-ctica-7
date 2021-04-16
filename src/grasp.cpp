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

void Grasp::algorithm(std::vector<Maquina>& maquinas) {
  // preprocesamiento(maquinas);
  // for (int i = 0; i < Datos::getInstance()getN(); ++i) {

  // }
}

// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include "../include/solution.hpp"

Solution::Solution(const std::vector<Machine>& machines) :
  machines_(machines) {
  generateZ();
  Data::getInstance().reset();
}

const std::vector<Machine>& Solution::getMachines() {
  return machines_;
}

// void Solution::ejecutar() {
//   algorithm_->algorithm(machines_);
//   Datos::getInstance().reset();
// }

void Solution::generateZ() {
  unsigned long z = 0;
  for (size_t i = 0; i < machines_.size(); ++i) {
    z += machines_[i].getTCT();
  }
  z_ = z;
}

unsigned long Solution::getZ() {
  return z_;
}

bool Solution::operator<(const Solution& otherSolucion) {
  return z_ < otherSolucion.z_;
}

// std::vector<Maquina>::const_iterator Solution::begin() const {
//   return machines_.begin();
// }

// std::vector<Maquina>::iterator Solution::begin() {
//   return machines_.begin();
// }

// std::vector<Maquina>::const_iterator Solution::end() const {
//   return machines_.end();
// }

// std::vector<Maquina>::iterator Solution::end() {
//   return machines_.end();
// }

std::ostream& Solution::showWithTCTs(std::ostream& os) {
  for (size_t i = 0; i < machines_.size(); ++i) {
    os << "Maquina " << i + 1 << ": ";
    machines_[i].show();
    os << "TCTLocal: " << machines_[i].getTCT() << '\n';
    os << "\n";
  }
  os << "Z: " << getZ() << "\n\n";
  return os;
}

std::ostream& Solution::showOnlyZ(std::ostream& os) {
  os << "Z: " << getZ() << "\n\n";
  return os;
}

std::ostream& Solution::show(std::ostream& os) {
  for (size_t i = 0; i < machines_.size(); ++i) {
    os << "Maquina " << i + 1 << ": ";
    machines_[i].show();
  }
  return os;
}

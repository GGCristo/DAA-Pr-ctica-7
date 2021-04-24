// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include "../include/solution.hpp"

// Solution::Solution() {
//   z_ = -1;
// }

Solution::Solution(const std::vector<Machine>& machines) :
  machines_(machines) {
  generateZ();
  Data::getInstance().reset();
}

Solution::Solution(const Solution& other) {
  machines_ = other.machines_;
  z_ = other.z_;
}

Solution::Solution(Solution&& other) :
  machines_(std::move(other.machines_)),
  z_(std::move(other.z_))
{}

Solution& Solution::operator=(Solution&& other) {
  machines_ = std::move(other.machines_);
  z_ = std::move(other.z_);
  return *this;
}

Solution& Solution::operator=(const Solution& other) {
  machines_ = other.machines_;
  z_ = other.z_;
  return *this;
}

const std::vector<Machine>& Solution::getMachines() const {
  return machines_;
}

size_t Solution::getMinimalMachineSize() const {
  // if (machines_.empty()) {
  //   throw "[Solution::getMinimalMachineSize] machines is empty\n";
  // }
  size_t min = machines_.begin()->size();
  for (auto i = machines_.begin() + 1; i != machines_.end(); ++i) {
    if (i->size() < min) {
      min = i->size();
    }
  }
  return min;
}

void Solution::generateZ() {
  unsigned long z = 0;
  for (size_t i = 0; i < machines_.size(); ++i) {
    z += machines_[i].getTCT();
  }
  z_ = z;
}

unsigned long Solution::getZ() const {
  return z_;
}

bool Solution::operator<(const Solution& other) {
  return z_ < other.z_;
}

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

// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include "../include/solucion.hpp"

Solucion::Solucion(int m, std::unique_ptr<ParallelInterface> algorithm) :
  algorithm_(std::move(algorithm)) {
  for (int i = 0; i < m; ++i) {
    maquinas_.emplace_back(Maquina());
  }
  z_ = 0;
}

const std::vector<Maquina>& Solucion::getMachines() {
  return maquinas_;
}

void Solucion::ejecutar() {
  algorithm_->algorithm(maquinas_);
  Datos::getInstance().reset();
}

unsigned long Solucion::getZ() {
  for (size_t i = 0; i < maquinas_.size(); ++i) {
    z_ += maquinas_[i].getTCT();
  }
  return z_;
}

void Solucion::reinsert(int machine, int previousPosition, int newPosition) {
  Tarea deleted = maquinas_[machine].erase(previousPosition);
  maquinas_[machine].insert(deleted, newPosition);
  maquinas_[machine].reCalculateTimeFrom(std::min(previousPosition, newPosition));
  maquinas_[machine].reCalculateTct();
}

void Solucion::move(int previousMachine, int previousPosition, int newMachine,
    int newPosition) {
  auto deleted = maquinas_[previousMachine].erase(previousPosition);
  maquinas_[newMachine].insert(deleted, newPosition);
  maquinas_[previousMachine].reCalculateTimeFrom(previousPosition);
  maquinas_[newMachine].reCalculateTimeFrom(newPosition);

  maquinas_[previousMachine].reCalculateTct();
  maquinas_[newMachine].reCalculateTct();
}

void Solucion::innerSwap(int machine, int position1, int position2) {
  std::iter_swap(maquinas_[machine].begin() + position1,
      maquinas_[machine].begin() + position2);
  maquinas_[machine].reCalculateTimeFrom(std::min(position1, position2));
  maquinas_[machine].reCalculateTct();
}

void Solucion::extraSwap(int machine1, int position1, int machine2,
    int position2) {
  std::iter_swap(maquinas_[machine1].begin() + position1,
      maquinas_[machine2].begin() + position2);

  maquinas_[machine1].reCalculateTimeFrom(position1);
  maquinas_[machine2].reCalculateTimeFrom(position2);

  maquinas_[machine1].reCalculateTct();
  maquinas_[machine2].reCalculateTct();
}

std::ostream& Solucion::showWithTCTs(std::ostream& os) {
  for (size_t i = 0; i < maquinas_.size(); ++i) {
    std::cout << "Maquina " << i + 1 << ": ";
    maquinas_[i].show();
    std::cout << "TCTLocal: " << maquinas_[i].getTCT() << '\n';
    std::cout << "\n";
  }
  std::cout << "Z: " << getZ() << "\n\n";
  return os;
}

std::ostream& Solucion::show(std::ostream& os) {
  for (size_t i = 0; i < maquinas_.size(); ++i) {
    std::cout << "Maquina " << i + 1 << ": ";
    maquinas_[i].show();
  }
  return os;
}

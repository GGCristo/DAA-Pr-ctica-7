// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include "../include/solucion.hpp"

Solucion::Solucion(std::unique_ptr<ParallelInterface> algorithm) :
  algorithm_(std::move(algorithm)) {
  for (int i = 0; i < Datos::getInstance().getM(); ++i) {
    maquinas_.emplace_back(Maquina());
  }
  z_ = 0;
}

const std::vector<Maquina>& Solucion::getMachines() {
  return maquinas_;
}

void Solucion::ejecutar() {
  algorithm_->algorithm(maquinas_);
  for (size_t i = 0; i < maquinas_.size(); ++i) {
    z_ += maquinas_[i].getTCT();
  }
  Datos::getInstance().reset();
}

unsigned long Solucion::getZ() {
  return z_;
}

std::ostream& Solucion::showWithTCTs(std::ostream& os) {
  for (size_t i = 0; i < maquinas_.size(); ++i) {
    std::cout << "Maquina " << i + 1 << ": ";
    maquinas_[i].show();
    std::cout << "TCTLocal: " << maquinas_[i].getTCT() << '\n';
    std::cout << "\n";
  }
  return os;
}

std::ostream& Solucion::show(std::ostream& os) {
  for (size_t i = 0; i < maquinas_.size(); ++i) {
    std::cout << "Maquina " << i + 1 << ": ";
    maquinas_[i].show();
  }
  return os;
}

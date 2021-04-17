// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include "../include/solucion.hpp"

Solucion::Solucion(const std::vector<Maquina>& maquinas) :
  maquinas_(maquinas) {
  generateZ();
  Datos::getInstance().reset();
}

const std::vector<Maquina>& Solucion::getMachines() {
  return maquinas_;
}

// void Solucion::ejecutar() {
//   algorithm_->algorithm(maquinas_);
//   Datos::getInstance().reset();
// }

void Solucion::generateZ() {
  unsigned long z = 0;
  for (size_t i = 0; i < maquinas_.size(); ++i) {
    z += maquinas_[i].getTCT();
  }
  z_ = z;
}

unsigned long Solucion::getZ() {
  return z_;
}

bool Solucion::operator<(const Solucion& otherSolucion) {
  return z_ < otherSolucion.z_;
}

// std::vector<Maquina>::const_iterator Solucion::begin() const {
//   return maquinas_.begin();
// }

// std::vector<Maquina>::iterator Solucion::begin() {
//   return maquinas_.begin();
// }

// std::vector<Maquina>::const_iterator Solucion::end() const {
//   return maquinas_.end();
// }

// std::vector<Maquina>::iterator Solucion::end() {
//   return maquinas_.end();
// }

std::ostream& Solucion::showWithTCTs(std::ostream& os) {
  for (size_t i = 0; i < maquinas_.size(); ++i) {
    os << "Maquina " << i + 1 << ": ";
    maquinas_[i].show();
    os << "TCTLocal: " << maquinas_[i].getTCT() << '\n';
    os << "\n";
  }
  os << "Z: " << getZ() << "\n\n";
  return os;
}

std::ostream& Solucion::showOnlyZ(std::ostream& os) {
  os << "Z: " << getZ() << "\n\n";
  return os;
}

std::ostream& Solucion::show(std::ostream& os) {
  for (size_t i = 0; i < maquinas_.size(); ++i) {
    os << "Maquina " << i + 1 << ": ";
    maquinas_[i].show();
  }
  return os;
}

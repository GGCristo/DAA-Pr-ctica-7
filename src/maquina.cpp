#include "../include/maquina.hpp"

Maquina::Maquina() {
  Tf_ = 0;
}

void Maquina::add(const Tarea& tarea) {
  Tf_ += tarea.totalTime_;
  // Todo emplace_back
  queue_.push_back(tarea);
}

std::ostream& Maquina::show(std::ostream& os) {
  for (size_t i = 0; i < queue_.size(); ++i) {
    queue_[i].show(os);
  }
  return os;
}

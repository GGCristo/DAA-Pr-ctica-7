// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include "../include/maquina.hpp"

Maquina::Maquina() {
  time_ = 0;
}

int Maquina::getIdLastTask() {
  if (queue_.empty()) {
    return 0;
  }
  return queue_[queue_.size() - 1].id_;
}

int Maquina::getTime() {
  return time_;
}

void Maquina::add(const Tarea& tarea) {
  if (Datos::getInstance().getTimes()[tarea.id_].second) {
    int id = tarea.id_;
    throw "La tarea " + std::to_string(id) +
      " ya esta incluida en otra maquina\n";
  }
  Datos::getInstance().getTimes()[tarea.id_].second = true;
  time_ += tarea.time_;
  // Todo emplace_back
  queue_.push_back(tarea);
}

size_t Maquina::size() {
  return queue_.size();
}

std::ostream& Maquina::show(std::ostream& os) {
  for (size_t i = 0; i < queue_.size(); ++i) {
    os << "{ ";
    queue_[i].show(os);
    os << "} ";
  }
  os << '\n';
  return os;
}

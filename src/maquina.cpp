// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include "../include/maquina.hpp"

Maquina::Maquina() {
  time_ = 0;
  tct_ = 0;
}

int Maquina::getIdLastTask() {
  if (queue_.empty()) {
    return -1;
  }
  return queue_[queue_.size() - 1].id_;
}

int Maquina::getTime() {
  return time_;
}

void Maquina::add(Tarea tarea) {
  if (Datos::getInstance().getTimes()[tarea.id_].second) {
    int id = tarea.id_;
    throw "La tarea " + std::to_string(id) +
      " ya esta incluida en otra maquina\n";
  }
  Datos::getInstance().getTimes()[tarea.id_].second = true;
  const int PREVIOUS_TCT = queue_.empty() ? 0 : queue_[queue_.size() - 1].tct_;
  tarea.tct_ = PREVIOUS_TCT + tarea.time_;
  tct_ += tarea.tct_;
  time_ += tarea.time_;
  // Todo emplace_back
  queue_.push_back(tarea);
}

unsigned long Maquina::peekTCT(Tarea tarea) {
  const int PREVIOUS_TCT = queue_.empty() ? 0 : queue_[queue_.size() - 1].tct_;
  return tct_ + PREVIOUS_TCT + tarea.time_;
}

unsigned long Maquina::getTCT() {
  return tct_;
}

size_t Maquina::size() const{
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

// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include "../include/tarea.hpp"

Tarea::Tarea(int id, int totalTime) : id_(id), time_(totalTime){
}

int Tarea::getId() const {
  return id_;
}

int Tarea::getTime() const {
  return time_;
}

std::ostream& Tarea::show(std::ostream& os) const {
  os << "Tarea " << id_ + 1 << " , Time: " << time_;
  return os;
}

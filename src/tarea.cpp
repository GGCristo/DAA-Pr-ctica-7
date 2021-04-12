// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include "../include/tarea.hpp"

Tarea::Tarea(int id, int totalTime) : id_(id), time_(totalTime){
  tct_ = -1;
}

int Tarea::getTime() {
  return time_;
}

std::ostream& Tarea::show(std::ostream& os) {
  os << "Tarea " << id_ + 1 << " , Time: " << time_;
  return os;
}

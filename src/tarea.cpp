
// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include "../include/tarea.hpp"

Tarea::Tarea(int id, int totalTime) : id_(id), time_(totalTime){
}

int Tarea::getTime() {
  return time_;
}
std::ostream& Tarea::show(std::ostream& os) {
  os << "Tarea " << id_ << " , Time: " << time_;
  return os;
}

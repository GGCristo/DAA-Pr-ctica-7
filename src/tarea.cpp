#include "../include/tarea.hpp"

Tarea::Tarea(int id, int totalTime) : id_(id), totalTime_(totalTime){
}

std::ostream& Tarea::show(std::ostream& os) {
  os << "Tarea " << id_ << " , Time: " << totalTime_ << '\n';
  return os;
}

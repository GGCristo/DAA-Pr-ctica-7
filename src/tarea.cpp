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

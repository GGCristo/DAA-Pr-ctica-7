// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include "../include/task.hpp"

Task::Task(int id, int totalTime) : id_(id), time_(totalTime){
}

int Task::getId() const {
  return id_;
}

int Task::getTime() const {
  return time_;
}

std::ostream& Task::show(std::ostream& os) const {
  os << "Task " << id_ + 1 << " , Time: " << time_;
  return os;
}

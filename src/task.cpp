// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include "../include/task.hpp"

Task::Task(int id, int totalTime) : id_(id), time_(totalTime) {
  tct_ = 0;
  tctUntilNow_ = 0;
}

int Task::getId() const {
  return id_;
}

int Task::getTime() const {
  return time_;
}

void Task::setTct(unsigned long tct) {
  tct_ = tct;
}

void Task::setTctUntilNow(unsigned long tctUntilNow) {
  tctUntilNow_ = tctUntilNow;
}

std::ostream& Task::show(std::ostream& os) const {
  os << "Task " << id_ + 1 << " , Time: " << time_;
  return os;
}

// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include "../include/machine.hpp"

Machine::Machine() {
  time_ = 0;
  tct_ = 0;
  previousTctTask_ = 0;
}

Task* Machine::searchTask(int id) {
  for(size_t i = 0; i < queue_.size(); ++i) {
    if (queue_[i].getId() == id) {
      return &queue_[i];
    }
  }
  return nullptr;
}

void Machine::reCalculateTimeFrom(int startPosition) {
  for (size_t i = startPosition; i < queue_.size(); ++i) {
    queue_[i].time_ = Data::getInstance().getTimes()[i].first +
      Data::getInstance().getSetups()[getIdPreviousTask(i) + 1][i + 1];
  }
}

void Machine::reCalculateTct() {
  unsigned long tct = 0;
  for (size_t i = 0; i < queue_.size(); ++i) {
    tct += (queue_.size() - i) * queue_[i].getTime();
  }
  tct_ = tct;
}

int Machine::getIdLastTask() const {
  if (queue_.empty()) {
    return -1;
  }
  return queue_[queue_.size() - 1].id_;
}

int Machine::getIdPreviousTask(int position) const {
  if (position == 0) {
    return -1;
  }
  return queue_[position - 1].id_;
}

int Machine::getTime() const {
  return time_;
}

void Machine::add(Task task) {
  if (Data::getInstance().getTimes()[task.id_].second) {
    throw "La tarea " + std::to_string(task.id_) +
      " ya esta incluida en otra maquina\n";
  }
  Data::getInstance().MarkTaskAsReady(task.id_);
  tct_ += previousTctTask_ + task.time_;
  previousTctTask_ = previousTctTask_ + task.time_;
  time_ += task.time_;
  // Todo emplace_back
  queue_.push_back(task);
}

unsigned long Machine::peekTCT(Task tarea) const {
  return tct_ + previousTctTask_ + tarea.time_;
}

unsigned long Machine::getTCT() const {
  return tct_;
}

Task Machine::erase(int position) {
  // TODO should I return a pointer?
  if (position >= queue_.size() || position < 0) {
    std::cout << "position: " << position << '\n';
    std::cout << "queue_.size(): " << queue_.size() << '\n';
    throw "[machine | erase] Algo esta mal con position\n";
  }
  Task taskDeleted = queue_[position];
  Data::getInstance().MarkTaskAsNotReady(queue_[position].id_);
  queue_.erase(queue_.begin() + position);
  return taskDeleted;
}

void Machine::insert(Task& task, int position) {
  if (position > queue_.size() || position < 0) {
    std::cout << "position: " << position << '\n';
    throw "[machine | insert] Algo esta mal con position\n";
  }
  if (Data::getInstance().getTimes()[task.id_].second) {
    throw "La tarea " + std::to_string(task.id_) +
      " ya esta incluida en otra maquina\n";
  }
  Data::getInstance().MarkTaskAsReady(task.id_);
  queue_.insert(queue_.begin() + position, task);
}

const Task& Machine::operator[] (int index) const {
  return queue_[index];
}

std::vector<Task>::const_iterator Machine::begin() const{
  return queue_.begin();
}

std::vector<Task>::iterator Machine::begin(){
  return queue_.begin();
}

std::vector<Task>::const_iterator Machine::end() const{
  return queue_.end();
}

std::vector<Task>::iterator Machine::end(){
  return queue_.end();
}

size_t Machine::size() const{
  return queue_.size();
}

std::ostream& Machine::show(std::ostream& os) const {
  for (size_t i = 0; i < queue_.size(); ++i) {
    os << "{ ";
    queue_[i].show(os);
    os << "} ";
  }
  os << '\n';
  return os;
}

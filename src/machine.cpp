// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include "../include/machine.hpp"

Machine::Machine(int id) {
  time_ = 0;
  tct_ = 0;
  previousTctTask_ = 0;
  id_ = id;
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

void Machine::reCalculateTctFrom(int startPosition) {
  // unsigned long tct = 0;
  size_t i = startPosition;
  if (startPosition == 0){
    queue_[0].tct_ = queue_[0].time_;
    queue_[0].tctUntilNow_ = queue_[0].tct_;
    i = 1;
  }
  for (; i < queue_.size(); ++i) {
    queue_[i].tct_ = queue_[i - 1].tct_ + queue_[i].time_;
    queue_[i].tctUntilNow_ = queue_[i - 1].tctUntilNow_ + queue_[i].tct_;
  }
  tct_ = queue_[queue_.size() - 1].tctUntilNow_;
}

int Machine::getIdLastTask() const {
  if (queue_.empty()) {
    return -1;
  }
  return queue_[queue_.size() - 1].id_;
}

int Machine::getId() const {
  return id_;
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
  if (Data::getInstance().isTaskTaken(task.id_)) {
    throw "La tarea " + std::to_string(task.id_) +
      " ya esta incluida en otra maquina\n";
  }
  Data::getInstance().markTaskAsTaken(task.id_);
  tct_ += previousTctTask_ + task.time_;
  task.setTct(previousTctTask_ + task.time_);
  task.setTctUntilNow(tct_);
  previousTctTask_ = previousTctTask_ + task.time_;
  time_ += task.time_;
  queue_.emplace_back(task);
}

unsigned long Machine::peekTCT(const Task& incomingTask) const {
  return tct_ + previousTctTask_ + incomingTask.time_;
}

unsigned long Machine::getTCT() const {
  return tct_;
}

Task Machine::erase(int position) {
  if ((size_t)position >= queue_.size() || position < 0) {
    std::cout << "position: " << position << '\n';
    std::cout << "queue_.size(): " << queue_.size() << '\n';
    throw "[machine | erase] Algo esta mal con position\n";
  }
  Task taskDeleted = queue_[position];
  Data::getInstance().markTaskAsNotTaken(queue_[position].id_);
  queue_.erase(queue_.begin() + position);
  return taskDeleted;
}

void Machine::insert(const Task& task, int position) {
  if ((size_t)position > queue_.size() || position < 0) {
    std::cout << "position: " << position << '\n';
    throw "[machine | insert] Algo esta mal con position\n";
  }
  if (Data::getInstance().isTaskTaken(task.id_)) {
    throw "La tarea " + std::to_string(task.id_) +
      " ya esta incluida en otra maquina\n";
  }
  Data::getInstance().markTaskAsTaken(task.id_);
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

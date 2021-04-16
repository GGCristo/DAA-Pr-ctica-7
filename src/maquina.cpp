// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include "../include/maquina.hpp"

Maquina::Maquina() {
  time_ = 0;
  tct_ = 0;
  previousTctTask_ = 0;
}

void Maquina::reCalculateTimeFrom(int startPosition) {
  for (int i = startPosition; i < queue_.size(); ++i) {
    queue_[i].time_ = Datos::getInstance().getTimes()[i].first +
      Datos::getInstance().getSetups()[getIdPreviousTask(i) + 1][i + 1];
  }
}

void Maquina::reCalculateTct() {
  unsigned long tct = 0;
  for (size_t i = 0; i < queue_.size(); ++i) {
    tct += (queue_.size() - i) * queue_[i].getTime();
  }
  tct = tct_;
}

int Maquina::getIdLastTask() const {
  if (queue_.empty()) {
    return -1;
  }
  return queue_[queue_.size() - 1].id_;
}

int Maquina::getIdPreviousTask(int position) const {
  if (position == 0) {
    return -1;
  }
  return queue_[position - 1].id_;
}

int Maquina::getTime() const {
  return time_;
}

void Maquina::add(Tarea task) {
  if (Datos::getInstance().getTimes()[task.id_].second) {
    int id = task.id_;
    throw "La tarea " + std::to_string(id) +
      " ya esta incluida en otra maquina\n";
  }
  Datos::getInstance().getTimes()[task.id_].second = true;
  tct_ += previousTctTask_ + task.time_;
  previousTctTask_ = previousTctTask_ + task.time_;
  time_ += task.time_;
  // Todo emplace_back
  queue_.push_back(task);
}

unsigned long Maquina::peekTCT(Tarea tarea) const {
  return tct_ + previousTctTask_ + tarea.time_;
}

unsigned long Maquina::getTCT() const {
  return tct_;
}

Tarea Maquina::erase(int position) {
  // TODO should I return a pointer?
  Tarea taskDeleted = queue_[position];
  queue_.erase(queue_.begin() + position);
  return taskDeleted;
}

void Maquina::insert(Tarea& task, int position) {
  if (Datos::getInstance().getTimes()[task.id_].second) {
    int id = task.id_;
    throw "La tarea " + std::to_string(id) +
      " ya esta incluida en otra maquina\n";
  }
  queue_.insert(queue_.begin() + position, task);
}

const Tarea& Maquina::operator[] (int index) const {
  return queue_[index];
}

std::vector<Tarea>::const_iterator Maquina::begin() const{
  return queue_.begin();
}

std::vector<Tarea>::iterator Maquina::begin(){
  return queue_.begin();
}

std::vector<Tarea>::const_iterator Maquina::end() const{
  return queue_.end();
}

std::vector<Tarea>::iterator Maquina::end(){
  return queue_.end();
}

size_t Maquina::size() const{
  return queue_.size();
}

std::ostream& Maquina::show(std::ostream& os) const {
  for (size_t i = 0; i < queue_.size(); ++i) {
    os << "{ ";
    queue_[i].show(os);
    os << "} ";
  }
  os << '\n';
  return os;
}

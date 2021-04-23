// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include "../include/data.hpp"

Data& Data::getInstance() {
  static Data instance;
  return instance;
}

Data::Data() {
  if (file_ == "") {
    throw "Especifíca el fichero\n";
  }
  std::fstream file;
  file.open(file_, std::ios::in);
  if (!file) {
    throw std::string("File could not be opened: ") + file_  + '\n';
  }
  std::string line;
  while(getline(file, line)) {
    switch(line[0]) {
      case 'n': {
                  std::string n;
                  std::stringstream linea_stream(line);
                  linea_stream >> n;
                  linea_stream >> n;
                  n_ = std::stoi(n);
                }
                break;
      case 'm': {
                  std::string m;
                  std::stringstream linea_stream(line);
                  linea_stream >> m;
                  linea_stream >> m;
                  m_ = std::stoi(m);
                }
                break;
      case 'P': {
                  times(line);
                }
                break;
      case 'S': {
                  setups(file);
                }
      default:
                break;
    }
  }
  file.close();
  tasksReady_ = 0;
}

int Data::getN() const {
  return n_;
}

int Data::getM() const {
  return m_;
}

bool Data::areAllTaskReady() const {
  if (tasksReady_ < 0 || tasksReady_ > n_) {
    throw "Take a look at tasksReady_ and n_ variable\n";
  }
  if (tasksReady_ == n_) return true;
  return false;
}

void Data::markTaskAsReady(int id) {
  tasksReady_++;
  if (tasksReady_ > n_) {
    throw std::string("[Data::checkTaskAsReady] tasksReady_ cannot be greater") +
        " than the number of tasks";
  }
  times_[id].second = true;
}

void Data::markTaskAsNotReady(int id) {
  tasksReady_--;
  if (tasksReady_ < -1) {
    throw std::string("[Data::checkTaskAsReady] tasksReady_ is less than - 1") +
        " maybe you forgot to add a task after deleting it";
  }
  times_[id].second = false;
}

void Data::times(const std::string& linea) {
  std::vector<std::pair<int, bool>> times;
  std::string numero;
  std::stringstream linea_stream(linea);
  while (linea_stream >> numero) {
    if(numero[numero.size() - 1] == ']') {
      break;
    }
    continue;
  }
  while(linea_stream >> numero) {
    times.emplace_back(std::stoi(numero), false);
  }
  times_ = times;
}

const std::vector<std::pair<int, bool>>& Data::getTimes() const {
  return times_;
}

void Data::setups(std::fstream& fichero) {
  std::string linea;
  std::string number;
  while(getline(fichero ,linea)) {
    std::vector<int> row;
    row.reserve(n_ + 1);
    std::stringstream linea_stream_inner(linea);
    while(linea_stream_inner >> number) {
      row.push_back(std::stoi(number));
    }
    setups_.push_back(row);
  }
}


void Data::reset() {
  for (size_t i = 0; i < times_.size(); ++i) {
    times_[i].second = false;
  }
  tasksReady_ = 0;
}

const std::vector<std::vector<int>>& Data::getSetups() const {
  return setups_;
}

void Data::showTimes() const {
  for (size_t i = 0; i < times_.size(); ++i){
    std::cout << times_[i].first << ' ';
  }
  std::cout << '\n';
}

void Data::showSetups() const {
  for (size_t i = 0; i < setups_.size(); ++i) {
    for (size_t j = 0; j < setups_[i].size(); ++j) {
      std::cout << setups_[i][j] << ' ';
    }
    std::cout << '\n';
  }
}

#pragma once

#include <iostream>

class Tarea {
  public:
    Tarea(int, int);
    int getTime();
    std::ostream& show(std::ostream& os = std::cout);
  private:
    // int setupTime_;
    // int time_;
    unsigned long tct_;
    int id_;
    int time_;
    friend class Maquina;
};

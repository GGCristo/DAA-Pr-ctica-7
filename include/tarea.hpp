#pragma once

#include <iostream>

class Tarea {
  public:
    Tarea(int id = -1, int = 0);
    int getTime();
    std::ostream& show(std::ostream& os = std::cout);
  private:
    // int setupTime_;
    // int time_;
    int id_;
    int time_;
    friend class Maquina;
};

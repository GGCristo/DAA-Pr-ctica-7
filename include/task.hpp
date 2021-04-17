#pragma once

#include <iostream>

class Task {
  public:
    Task(int, int);
    int getId() const;
    int getTime() const;
    std::ostream& show(std::ostream& os = std::cout) const;
  private:
    // int setupTime_;
    // int time_;
    int id_;
    int time_;
    friend class Machine;
};

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

#include "../include/datos.hpp"

std::vector<int> times(const std::string&);
std::vector<int> setups(std::fstream&, std::string&);

// TODO Hacer la lectura de líneas más robusta, asegurarte de cuando parar de
// leer Pi y pasar a Sij y demás
int main() {
  Datos datos;
  // datos.showTimes();
  // datos.showSetups();
  return 0;
}

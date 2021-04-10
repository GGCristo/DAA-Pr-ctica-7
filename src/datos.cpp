#include "../include/datos.hpp"

Datos::Datos() {
  std::fstream fichero;
  fichero.open("I40j_2m_S1_1.txt", std::ios::in);
  if (!fichero)
  {
    throw "No se ha podido cargar el programa";
  }
  std::string linea;
  while(getline(fichero, linea)) {
    // std::cout << "Linea: " << linea << '\n';
    // std::cin.get();
    switch(linea[0]) {
      case 'n': {
                  std::string n;
                  std::stringstream linea_stream(linea);
                  linea_stream >> n;
                  linea_stream >> n;
                  std::cout << "n: " << n << '\n';
                }
                break;
      case 'm': {
                  std::string m;
                  std::stringstream linea_stream(linea);
                  linea_stream >> m;
                  linea_stream >> m;
                  std::cout << "m: " << m << '\n';

                }
                break;
      case 'P': {
                  std::vector<int> tiempos = times(linea);
                  // std::cout << "Voy a mostrar los tiempos\n" << '\n';
                  // for (size_t i = 0; i < tiempos.size(); ++i) {
                  // std::cout << tiempos[i] << '\n';
                  // }
                }
                break;
      case 'S': {
                  std::vector<int> setup = setups(fichero, linea);
                  // std::cout << "Voy a mostrar los setups\n" << '\n';
                  // for (size_t i = 0; i < setup.size(); ++i) {
                  // std::cout << setup[i] << '\n';
                  // }
                }

      default:
                break;
    }
  }
  fichero.close();
  return 0;
}

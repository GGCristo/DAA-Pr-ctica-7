#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <utility>
#include <vector>
#include <memory>
#include "parallelInterface.hpp"

// TODO Make everything const
/**
 * @brief Clase que contiene todos los datos leídos del fichero, solo puede
 * haber una instancia de este clase (Singleton)
 */
class Datos {
  public:
    /**
     * @brief Create o return the instance of this class (Singleton)
     *
     */
    static Datos& getInstance();
    /**
     * @brief No permitas hacer copias de la clase (Singleton)
     * @param Objeto de la misma clase
     */
    Datos(const Datos&) = delete;
    /**
     * @brief No permitas hacer copias de la clase (Singleton)
     */
    Datos& operator =(const Datos&) = delete;
    /**
     * @brief Devuelve el número de tareas
     * @return Número de tareas totales
     */
    int getN();
    /**
     * @brief Devuelve el número de maquinas
     * @return Número de maquinas totales
     */
    int getM();
    /**
     * @brief Devuelve los tiempos de las tareas, cada indice representa su
     * respectiva tarea, cada celda tiene un booleano para saber si la tarea
     * ya esta asignada a una tarea o no
     * @return Vector de lo que serán las tareas, representadas con un
     * par de enteros y pares
     */
    std::vector<std::pair<int, bool>>& getTimes();
    /**
     * @brief Devuelve los setups que necesita cada tarea antes de empezar a
     * ejecutarse, la fila corresponde a la anterior tarea (limpieza) y la
     * columna a la tarea actual (preparación)
     * @return vector de vectores de enteros con los tiempos de setup
     *
     */
    const std::vector<std::vector<int>>& getSetups();
    /**
     * @brief Muestra el vector de pares de enteros y booleanos con los tiempos
     * de las tareas
     *
     */
    [[maybe_unused]] void showTimes();
    /**
     * @brief Muestra el vector de vectores de enteros con los setups de las
     * tareas dependientes de la tarea anterior
     *
     */
    [[maybe_unused]] void showSetups();
    /**
     * @brief Pone a false todos los booleanos del vector times_
     *
     */
    void reset();
    /**
     * @fichero_ Fichero desde donde se va a leer los datos
     * Forma de uso: Datos::fichero_ = "Nombre-del-fichero";
     */
    static inline std::string fichero_ = "";
  private:
    /**
     * @brief Lee y carga todos los datos del fichero
     *
     */
    Datos();
    /**
     * @brief Carga los tiempos desde el fichero en times_
     * @param {linea} Linea que contiene los tiempos de las tareas
     */
    void times(const std::string&);
    /**
     * @brief Carga los setups desde el fichero en setups_
     *
     * @param {fichero} Fichero desde donde se va a continuar leyendo
     */
    void setups(std::fstream&);

    /**
     * @m_ Número de maquinas
     */
    int m_;
    /**
     * @n_ Número de tareas
     */
    int n_;
    // TODO Return optimization doesn't work
    /**
     * @times_ Devuelve los tiempos de las tareas, cada indice representa su
     * respectiva tarea, cada celda tiene un booleano para saber si la tarea
     * ya esta asignada a una tarea o no
     */
    std::vector<std::pair<int, bool>> times_;
    /**
     * @setups_ Devuelve los setups que necesita cada tarea antes de empezar a
     * ejecutarse, la fila corresponde a la anterior tarea (limpieza) y la
     * columna a la tarea actual (preparación)
     */
    std::vector<std::vector<int>> setups_;
};

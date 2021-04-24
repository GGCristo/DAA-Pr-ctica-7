#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <utility>
#include <vector>

// TODO Make everything const
/**
 * @brief Clase que contiene todos los datos leídos del fichero, solo puede
 * haber una instancia de este clase (Singleton)
 */
class Data {
  public:
    /**
     * @brief Create o return the instance of this class (Singleton)
     *
     */
    static Data& getInstance();

    /**
     * @brief No permitas hacer copias de la clase (Singleton)
     * @param Objeto de la misma clase
     */
    Data(const Data&) = delete;

    /**
     * @brief No permitas hacer copias de la clase (Singleton)
     */
    Data& operator =(const Data&) = delete;

    /**
     * @brief Devuelve el número de tareas
     * @return Número de tareas totales
     */
    int getN() const;

    /**
     * @brief Devuelve el número de maquinas
     * @return Número de maquinas totales
     */
    int getM() const;

    /**
     * @brief Check if all Task are in a machine
     *
     * @return True if all Task are in a machine, false otherwise
     */
    bool areAllTaskTaken() const;

    /**
     * @brief Check if the Task is already in a machine
     *
     * @param {id} ID of the Task
     * @return True if the task is already in a machine, false otherwise
     */
    bool isTaskTaken(int) const;

    /**
     * @brief Mark a task as taken
     *
     * @param {id} Id or position in times_ vector
     */
    void markTaskAsTaken(int);

    /**
     * @brief Mark a task as not taken
     *
     * @param {id} ID or position in times_ vector
     */
    void markTaskAsNotTaken(int);

    /**
     * @brief Devuelve los tiempos de las tareas, cada indice representa su
     * respectiva tarea, cada celda tiene un booleano para saber si la tarea
     * ya esta asignada a una tarea o no
     * @return Vector de lo que serán las tareas, representadas con un
     * par de enteros y pares
     */
    const std::vector<std::pair<int, bool>>& getTimes() const;

    /**
     * @brief Devuelve los setups que necesita cada tarea antes de empezar a
     * ejecutarse, la fila corresponde a la anterior tarea (limpieza) y la
     * columna a la tarea actual (preparación)
     * @return vector de vectores de enteros con los tiempos de setup
     *
     */
    const std::vector<std::vector<int>>& getSetups() const;

    /**
     * @brief Muestra el vector de pares de enteros y booleanos con los tiempos
     * de las tareas
     *
     */
    [[maybe_unused]] void showTimes() const;
    /**
     * @brief Muestra el vector de vectores de enteros con los setups de las
     * tareas dependientes de la tarea anterior
     *
     */
    [[maybe_unused]] void showSetups() const;
    /**
     * @brief Pone a false todos los booleanos del vector times_
     *
     */
    void reset();

    /**
     * @fichero_ Fichero desde donde se va a leer los datos
     * Forma de uso: Datos::fichero_ = "Nombre-del-fichero";
     */
    static inline std::string file_ = "";

  private:
    /**
     * @brief Lee y carga todos los datos del fichero
     *
     */
    Data();

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

    /**
     * @tasksReady_ Number of tasks that are already in a machine
     */
    int tasksTaken_;

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

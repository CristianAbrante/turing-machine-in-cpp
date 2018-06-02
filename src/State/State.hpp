
// Prática 8: Computabilidad y algoritmia.

#pragma once

// Cabecera de inclusión de otras clases.
#include "../Transition/Transition.hpp"  // Inclusión de la clase Transition.

// Inclusión de las diversas librerias necesarias.
#include <cstdio>
#include <iostream>
#include <set>
#include <tuple>

using namespace std;

/**
    \author     Cristian Abrante Dorta (alu0100945850@ull.edu.es)
    \date       Noviembre de 2016
    
    \details    Clase que representa a un estado de una máquina de Turing. 
*/

class State
{
    
    // ATRIBUTOS PÚBLICOS.
    
    public:
        
        /** Variable que almacena el número del estado dentro del DFA. */
        int             identifier_;
        
        /** Conjunto de transciones de dicho estado. */
        set<Transition> transitions_;
        
    // MÉTODOS PÚBLICOS.
    
    public:
        
        /**	
            \author     Cristian Abrante Dorta (alu0100945850@ull.edu.es)
            \date       octubre de 2016
            
            \details    Constructor por defecto.
            
        */
        
        State(void);
        
        /**	
            \author     Cristian Abrante Dorta (alu0100945850@ull.edu.es)
            \date       octubre de 2016
            
            \details    Constructor al que se le pasa el ID del estado.
            
            * @param    stateID (int): identificador del estado.
            
        */
        
        State(int identifier);
        
        /**	
            \author     Cristian Abrante Dorta (alu0100945850@ull.edu.es)
            \date       octubre de 2016
            
            \details    Constructor de copia.
            
        */
        
        State(const State& new_state);
        
        /**	
            \author     Cristian Abrante Dorta (alu0100945850@ull.edu.es)
            \date       octubre de 2016
            
            \details    Destructor de la clase.
            
        */
        
        ~State(void);
        
        /**	
            \author     Cristian Abrante Dorta (alu0100945850@ull.edu.es)
            \date       octubre de 2016
            
            \details    Método que limpia el estado.
            
        */
        
        void clear(void);
        
        /**	
            \author     Cristian Abrante Dorta (alu0100945850@ull.edu.es)
            \date       octubre de 2016
            
            \details    Sobrecarga del operador que permite escribir el estado en un flujo.
            
        */
        
        friend ostream& operator<<(ostream& os, const State& rhs_state);
        
        /**	
            \author     Cristian Abrante Dorta (alu0100945850@ull.edu.es)
            \date       octubre de 2016
            
            \details    Sobrecarga del operador =. Iguala dos estados.
            
        */
        
        State& operator=(const State& rhs);
        
        /**	
            \author     Cristian Abrante Dorta (alu0100945850@ull.edu.es)
            \date       octubre de 2016
            
            \details    Sobrecarga del operador ==. Compara si dos estados son iguales.
            
        */
        
        bool operator==(const State& rhs) const;
        
        /**	
            \author     Cristian Abrante Dorta (alu0100945850@ull.edu.es)
            \date       octubre de 2016
            
            \details    Sobrecarga del operador <. Compara si el identificador del estado es menor que otro.
            
        */
        
        bool operator<(const State& rhs) const;
        
        /**	
            \author     Cristian Abrante Dorta (alu0100945850@ull.edu.es)
            \date       octubre de 2016
            
            \details    Método que establece la transición de un estado con el siguiente dependiendo de un símbolo.
            
            * @param    nextStateID Índice del siguiente estado al que se transitará mediante la transición.
            * @param    symbol Carácter con el que está etiquetada la transición.
            
        */
        
        void SetNextTransition(const char& current_symbol, const char& tape_symbol, 
                               const char& movement,       const int& next_state_id);
        
        /**	
            \author     Cristian Abrante Dorta (alu0100945850@ull.edu.es)
            \date       octubre de 2016
            
            \details    Método que devuelve el conjunto de identificadores del siguiente estado dado un símbolo.
            
            * @param    symbol Carácter con el que está etiquetada la transición.
            * @return   Conjunto de estados siguientes.
            
        */
        
        tuple<char, char, int> GetNextTransition(const char& symbol) const;
        
        /**	
            \author     Cristian Abrante Dorta (alu0100945850@ull.edu.es)
            \date       octubre de 2016
            
            \details    Método que devuelve si un símbolo es usado por el estado
            
            * @param    symbol Símbolo que queremos comporbar si ha sido usado.
            * @return   true si el símbolo es usado y false en otro caso.
            
        */
        
        bool symbol_is_used(const char& symbol) const;
        
        /**	
            \author     Cristian Abrante Dorta (alu0100945850@ull.edu.es)
            \date       octubre de 2016
            
            \details    Método que devuelve el número de transiciones del estado.
            
            * @return   Número de transiciones del estado.
            
        */
        
        int number_of_transitions(void) const;
        
};
// Prática 8: Computabilidad y algoritmia

#pragma once

#include "../Alphabet/Alphabet.hpp"
#include "../State/State.hpp"
#include "../Transition/Transition.hpp"  // Inclusión de la clase Transition.
#include "../Tape/Tape.hpp"

// Inclusión de las diversas librerias necesarias.

#include <cstdio>
#include <iostream>
#include <fstream>
#include <cassert>
#include <set>
#include <vector>
#include <tuple>

#define EPS_INFINITE 100

using namespace std;
    
/**	
    \author     Cristian Abrante Dorta (alu0100945850@ull.edu.es)
    \date       Noviembre de 2016
    
    \details    Clase que simula una máquina de Turing.
    
*/

class TuringMachine
{
    
    // ATRIBUTOS PRIVADOS.
    private:
        
        /** Atributo que representa el conjunto de estados de la máquina de Turing. */
        set<State>  set_of_states_;
        
        /** Atributo que representa el alfabeto de la cinta. */
        Alphabet    tape_alphabet_;
        
        /** Atributo que representa el alfabeto de entrada. */
        Alphabet    input_alphabet_;
        
        /** Atributo que representa el estado inicial de la máquina de Turing. */
        State       initial_state_;
        
        /** Atributo que representa el conjunto de estado de aceptación. */
        set<State>  accepted_states_;
        
        /** Atributo que representa el símbolo blanco. */
        char        blank_symbol;
        
    // MÉTODOS PÚBLICOS.
    public:
        
        /**	
            \author     Cristian Abrante Dorta (alu0100945850@ull.edu.es)
            \date       Noviembre de 2016
            
            \details   Constructor por defecto de la clase.
            
        */
        
        TuringMachine(void);
        
        /**	
            \author     Cristian Abrante Dorta (alu0100945850@ull.edu.es)
            \date       Noviembre de 2016
            
            \details   Destructor de la clase.
            
        */
        
        ~TuringMachine(void);
        
        /**	
            \author     Cristian Abrante Dorta (alu0100945850@ull.edu.es)
            \date       Noviembre de 2016
            
            \details   Constructor al que se le pasa una string.
            
            @param      tm_definition String que contiene el nombre del fichero que contiene la definción de la máquina de Turing.
            
        */
        
        TuringMachine(string tm_definition, bool& creating_fault);
        
        /**	
            \author     Cristian Abrante Dorta (alu0100945850@ull.edu.es)
            \date       Noviembre de 2016
            
            \details    Sobrecarga del operador << que muestra la máquina de Turing por un flujo de salida.
            
        */
        
        friend ostream& operator<<(ostream& os, const TuringMachine& rhs_tm);
        
        /**	
            \author     Cristian Abrante Dorta (alu0100945850@ull.edu.es)
            \date       Noviembre de 2016
            
            \details    Sobrecarga del operador >> que lee la máquina de Turing desde un flujo de entrada.
            
        */
        
        friend istream& operator>>(istream& is, TuringMachine& rhs_tm);
        
        /**	
            \author     Cristian Abrante Dorta (alu0100945850@ull.edu.es)
            \date       Noviembre de 2016
            
            \details    Función que determina si una cadena pertenece al lenguage que genera la máquina de Turing.
            
        */
        
        bool EvaluateTape(Tape& tape_string, ostream& os, bool print_path) const;
        
        /**	
            \author     Cristian Abrante Dorta (alu0100945850@ull.edu.es)
            \date       Noviembre de 2016
            
            \details    Método que limpia la máquina de Turing.
            
        */
        
        void clear(void);
        
    private:
        
        State GetState (int identifier) const;
        
        bool IsAnAcceptedState(const State& new_state) const;
};
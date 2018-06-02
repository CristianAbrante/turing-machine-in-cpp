
// Prática 8: Computabilidad y algoritmia.

#pragma once

// Inclusión de las diversas librerias necesarias.
#include <cstdio>
#include <iostream>
#include <tuple>
#include <set>

using namespace std;

/**
    \author   	Cristian Abrante Dorta (alu0100945850@ull.edu.es)
    \date 		Noviembre de 2016
    
    \details 	Clase que representa las transiciones de una máquina de Turing. 
*/

class Transition
{
    
    // ATRIBUTOS PÚBLICOS.
    
    public: 
        
        /** Atributo que especifica la transción para dicho símbolo. */
        char                    symbol_;
        
        /** Método que especifica la tupla que retorna la transición (Estado siguiente, 
        símbolo que se escribe en la cinta, y movimiento que hace el cabezal). */
        tuple<char,char,int>  transition_tuple_;
        
    
    // MÉTODOS PÚBLICOS.
    
    public:
        
        /**
            \author   	Cristian Abrante Dorta (alu0100945850@ull.edu.es)
            \date 		octubre de 2016
            
            \details 	Constructor por defecto de la clase. 
        */
        
        Transition(void);
        
        /**
            \author   	Cristian Abrante Dorta (alu0100945850@ull.edu.es)
            \date 		octubre de 2016
            
            \details 	Constructor al que se le pasa como parámetro el ID del siguiente estado, y el símbolo.
            
            * @param nextState      Le pasamos identificador del siguiente estado de la trnasición.
            * @param userSymbol     Le pasamos el símbolo con el que estará etiquetada la transición.
        */
        
        Transition(const char& symbol, const char& tape_symbol, 
                   const char& movement, const int& next_state_id);
        
        /**
            \author   	Cristian Abrante Dorta (alu0100945850@ull.edu.es)
            \date 		octubre de 2016
            
            \details 	Constructor de copia al que se le pasa la nueva transición.
            
            * @param newTransition     Transición de copia.
        */
        
        Transition(const Transition& new_transition);
        
        /**
            \author   	Cristian Abrante Dorta (alu0100945850@ull.edu.es)
            \date 		octubre de 2016
            
            \details 	Destructor de la clase.
            
        */
        
        ~Transition(void);
        
        friend ostream& operator<<(ostream& os, const Transition& rhs);
        
        /**
            \author   	Cristian Abrante Dorta (alu0100945850@ull.edu.es)
            \date 		octubre de 2016
            
            \details 	Sobrecarga del operador =. Iguala dos transiciones.
            
        */
        
        Transition& operator=(const Transition& rhs);
        
        /**
            \author   	Cristian Abrante Dorta (alu0100945850@ull.edu.es)
            \date 		octubre de 2016
            
            \details 	Sobrecarga del operador ==. Compara si dos transiciones son iguales.
            
        */
        
        bool operator==(const Transition& rhs) const;
        
        /**
            \author   	Cristian Abrante Dorta (alu0100945850@ull.edu.es)
            \date 		octubre de 2016
            
            \details 	Sobrecarga del operador <. Compara si una transición es menor a otra, la comparación se hace mediante el símbolo.
            
        */
        
        bool operator<(const Transition& rhs) const;
};
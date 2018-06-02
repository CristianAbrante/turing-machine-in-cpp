// Prática 8: Computabilidad y algoritmia

#pragma once

// Inclusión de las diversas librerias necesarias.

#include <cstdio>
#include <iostream>
#include <fstream>
#include <cassert>
#include <list>

using namespace std;
    
/**	
    \author     Cristian Abrante Dorta (alu0100945850@ull.edu.es)
    \date       Noviembre de 2016
    
    \details    Clase que simula la cinta de una máquina de Turing.
    
*/

class Tape
{
    // ATRIBUTOS PRIVADOS.
    private:
        
        /** Atributo que guarda en la lista los símbolos de la cinta. */
        list<char>      tape_symbols_;
        
    // MÉTODOS PÚBLICOS.
    public:
        
        /**	
            \author     Cristian Abrante Dorta (alu0100945850@ull.edu.es)
            \date       Noviembre de 2016
            
            \details   Constructor por defecto de la clase.
            
        */
        
        Tape(void);
        
        /**	
            \author     Cristian Abrante Dorta (alu0100945850@ull.edu.es)
            \date       Noviembre de 2016
            
            \details   Destructor de la clase.
            
        */
        
        ~Tape(void);
        
        /**	
            \author     Cristian Abrante Dorta (alu0100945850@ull.edu.es)
            \date       Noviembre de 2016
            
            \details   Constructor al que se le pasa una string.
            
            @param      tm_definition String que contiene el nombre del fichero que contiene la definción de la cinta.
            @param      opening_faul  TRUE si ha habido error de apertura FALSE en otro caso.
            
        */
        
        Tape(string tape_definition, bool& opening_fault);
        
        /**	
            \author     Cristian Abrante Dorta (alu0100945850@ull.edu.es)
            \date       Noviembre de 2016
            
            \details    Sobrecarga del operador << que muestra la cinta por un flujo de salida.
            
        */
        
        friend ostream& operator<<(ostream& os, Tape& rhs);
        
        /**	
            \author     Cristian Abrante Dorta (alu0100945850@ull.edu.es)
            \date       Noviembre de 2016
            
            \details    Sobrecarga del operador >> que lee la cinta desde un flujo de entrada.
            
        */
        
        friend istream& operator>>(istream& is, Tape& rhs);
        
        /**	
            \author     Cristian Abrante Dorta (alu0100945850@ull.edu.es)
            \date       Noviembre de 2016
            
            \details    Sobrecarga del operador [] que devulve el elemento en una posición determinada.
            
            @param      pos Posición del símbolo que se quiere comprobar.
            @return     Caracter del alfabeto que se encuentra en dicha posición.
            
        */
        
        char& operator[](const int& pos);
        
        /**	
            \author     Cristian Abrante Dorta (alu0100945850@ull.edu.es)
            \date       Noviembre de 2016
            
            \details    Método que limpia la cinta.
            
        */
        
        void clear(void);
        
        /**	
            \author     Cristian Abrante Dorta (alu0100945850@ull.edu.es)
            \date       Noviembre de 2016
            
            \details   Método que devuelve el número de elementos del alfabeto.
            
            @return     Número de elementos de la cinta.
            
        */
        
        int size(void);
        
        
        void insert_front(void);
        
};
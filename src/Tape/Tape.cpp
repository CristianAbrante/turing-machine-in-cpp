
    // Prática 8: Computabilidad y algoritmia
    // Curso: Segundo
    // Alumno: Cristian Abrante Dorta

    // Definición de la clase Alphabet

#include "Tape.hpp"
    
    // MÉTODOS PÚBLICOS.
    
    Tape::Tape(void)
     : tape_symbols_() {}
    
    
    Tape::~Tape(void) {
        clear();
    }
    
    
    Tape::Tape(string tape_definition, bool& opening_fault) {
        
        ifstream tape_file;
        tape_file.open(tape_definition);
        
        if (tape_file.is_open()) {
            
            opening_fault = false;
            
            tape_file >> *this;
            
        } else {
            opening_fault = true;
        }
        
    }
    
    
    ostream& operator<<(ostream& os, Tape& rhs) {
        
        os << "... $ $ ";
        
        for (int i = 0; i < rhs.size(); i++) {
            
            os << rhs[i] << " ";
            
        }
        
        os << "$ $ ...";
        
        return os;
        
    }
    
    
    istream& operator>>(istream& is, Tape& rhs) {
        
        string tape;
        
        getline(is, tape);
        
        for (int i = 0; i < tape.size(); i++) {
            
            rhs.tape_symbols_.push_back(tape[i]);
            
        }
        
        return is;
        
    }
    
    
    char& Tape::operator[](const int& pos) {
        
        if (pos >= size()) {
            
            tape_symbols_.push_back('$');
            
            return (*this)[pos];
            
        }
        
        int index = 0;
        bool found = false;
        
        list<char>::iterator it = tape_symbols_.begin();
        
        while ((it != tape_symbols_.end()) && !found) {
            
            if (index == pos) {
                found = true;
            } else {
                it++;
                index++;
            }
            
        }
        
        return (*it);
        
    }
    
    
    void Tape::clear(void) {
        tape_symbols_.clear();
    }
    
    
    int Tape::size(void) {
        return tape_symbols_.size();
    }
    
    void Tape::insert_front(void) {
        
        tape_symbols_.push_front('$');
        
    }
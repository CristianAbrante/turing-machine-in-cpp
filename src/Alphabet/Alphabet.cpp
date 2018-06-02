
    // Prática 8: Computabilidad y algoritmia
    // Curso: Segundo
    // Alumno: Cristian Abrante Dorta

    // Definición de la clase Alphabet

#include "Alphabet.hpp"
    
    // MÉTODOS PÚBLICOS.
    
    Alphabet::Alphabet(void) : symbols_(){}
    
    
    Alphabet::~Alphabet(void) {
        clear();
    }
    
    
    Alphabet::Alphabet(string user_alphabet, bool& creating_fault) {
        
        creating_fault = false;
        int i = 0;
        
        while ((i < user_alphabet.size()) && !creating_fault) {
            
            if (legal(user_alphabet[i])) { 
                symbols_.insert(user_alphabet[i]);
                i++;
            } else {
                creating_fault = true;
            } 
            
        }
        
    }
    
    
    Alphabet::Alphabet(const Alphabet& new_alphabet) {
        symbols_ = new_alphabet.symbols_;
    }
    
    
    ostream& operator<<(ostream& os, const Alphabet& rhs) {
        
        os << "𝝨 = {";
        
        for (int i = 0; i < rhs.size(); i++) {
            
            if (rhs[i] != '~')  os << rhs[i];
            if (i != (rhs.size()-1))  os << ", ";
            
        }
        
        os << "}";
        
        return os;
        
    }
    
    
    bool Alphabet:: operator== (const Alphabet& rhs) const {
        
        if (size() == rhs.size()) {
            
            bool equal = true; 
            int  i = 0;
            
            while ((i<size()) && equal) {
                
                if((*this)[i] != rhs[i]) {
                    equal = false;
                } else {
                    i++;
                }
                
            }
            
            return equal;
            
        } else {
            return false;
        }
        
    }
    
    
    char Alphabet::operator[](const int& pos) const {
        
        if (pos < size()) {
            
            int     i = 0; 
            char    result;
            bool    found = false;
            
            set<char>::iterator it = symbols_.begin();
            
            while ((it!=symbols_.end()) && !found) {
                
                if (pos == i) {
                    result = *it; 
                    found = true;
                } else {
                    it++;
                    i++; 
                }
                
            }
            
            return result;
            
        } else {
            return -1;
        }
        
    }
    
    
    int Alphabet::size(void) const {
        return symbols_.size();
    }
    
    
    void Alphabet::clear(void) {
        symbols_.clear();
    }
    
    
    void Alphabet::insert(const char& token) {
        if (legal(token)) symbols_.insert(token);
    }
    
    
    bool Alphabet::StringIsCorrect(const string& language_string) const {
        
        if (language_string == "~") return true;
        
        bool correct = true; 
        int  i = 0;
        
        while ((i < language_string.size()) && correct) {
            
            if (!BelongsToTheAlphabet(language_string[i])) {
                correct = false;
            } else {
                i++;
            }
            
        }
        
        return correct;
        
    }
    
    
    bool Alphabet::BelongsToTheAlphabet(const char& token) const {
        
        bool found = false; 
        int  i = 0;
        
        while ((i < size()) && !found) {
            
            if ((*this)[i] == token) {
                found = true;
            } else {
                i++;
            }
            
        }
        
        return found;
        
    }
    
    // MÉTODOS PRIVADOS.
    
    bool Alphabet::legal(const char& token) const {
        return ((token != '~') &&
                (token != '{') &&
                (token != '}') &&
                (token != ' ') &&
                (token != ','));
    }
    

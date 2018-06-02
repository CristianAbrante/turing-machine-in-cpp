
    // Prática 8: Computabilidad y algoritmia
    // Curso: Segundo
    // Alumno: Cristian Abrante Dorta

    // Implementación de la clase Transition.
    
#include "Transition.hpp"
    
    Transition::Transition(void)
     : symbol_(),
       transition_tuple_('~', '-', -1) {}
    
    Transition::Transition(const char& symbol, const char& tape_symbol, 
                           const char& movement, const int& next_state_id)
     : symbol_(symbol),
       transition_tuple_(tape_symbol, movement, next_state_id) {}
    
    
    Transition::Transition(const Transition& new_transition) {
        symbol_ = new_transition.symbol_;
        transition_tuple_ = new_transition.transition_tuple_;
    }
    
    
    Transition::~Transition (void) {
        symbol_ = '0';
    }
    
    
    ostream& operator<<(ostream& os, const Transition& rhs) {
        
        os << rhs.symbol_ << " ";
        os << get<0>(rhs.transition_tuple_) << " ";
        os << get<1>(rhs.transition_tuple_) << " ";
        os << get<2>(rhs.transition_tuple_) << " ";
        
        return os;
        
    }
    
    
    Transition& Transition::operator=(const Transition& rhs) {
        
        this->symbol_ = rhs.symbol_;
        this->transition_tuple_ = rhs.transition_tuple_;
        
    }
    
    
    bool Transition::operator==(const Transition& rhs) const {
        
        if (this->symbol_ == rhs.symbol_) {
            
            bool equal = true;
            
            if (get<0>(transition_tuple_) != get<0>(rhs.transition_tuple_)) {
                    equal = false;
            }
            
            if (get<1>(transition_tuple_) != get<1>(rhs.transition_tuple_)) {
                    equal = false;
            }
            
            if (get<2>(transition_tuple_) != get<2>(rhs.transition_tuple_)) {
                    equal = false;
            }
            
            return equal;
            
        } else {
            return false;
        }
        
    }
    
    
    bool Transition::operator<(const Transition& rhs) const {
        
        if (this->symbol_ <= rhs.symbol_) return true;
        
        return false;
    }


    // Prática 8: Computabilidad y algoritmia
    // Curso: Segundo
    // Alumno: Cristian Abrante Dorta

    // Implementación de la clase State
    
#include "State.hpp"
    
    State::State(void)
     : transitions_(),
       identifier_(-1) {}
    
    
    State::State(int identifier)
     : transitions_(),
       identifier_(identifier) {}
    
    
    State::State(const State& new_state) {
        
        transitions_ = new_state.transitions_;
        identifier_ = new_state.identifier_;
        
    }
    
    
    State::~State(void) {
        clear();
    }
    
    
    void State::clear(void) {
        
        transitions_.clear();
        identifier_ = -1;
        
    }
    
    
    ostream& operator<<(ostream& os, const State& rhs_state) {
        
        set<Transition>::iterator it = rhs_state.transitions_.begin();
        
        for (; it != rhs_state.transitions_.end(); it++) {
            
            os << rhs_state.identifier_ << " ";
            
            os << *(it) << endl;
        }
        
        return os;
    }
    
    
    State& State::operator=(const State& rhs) {
        
        this->transitions_ = rhs.transitions_;
        this->identifier_ = rhs.identifier_;
        
        return *this;
    }
    
    
    bool State::operator==(const State& rhs) const {
        
        if ((this->identifier_ == rhs.identifier_) && 
           ((this->transitions_).size() == rhs.transitions_.size())) {
            
            return true;
            
        } else {
            
            return false;
            
        }
        
    }
    
    
    bool State::operator<(const State& rhs) const {
        if (this->identifier_ < rhs.identifier_) return true;
        return false;
    }
    
    
    void State::SetNextTransition(const char& current_symbol, const char& tape_symbol, 
                                  const char& movement,       const int& next_state_id) {
        
        Transition new_transition(current_symbol, tape_symbol, movement, next_state_id);
        
        transitions_.insert(new_transition);
        
    }
    
    
    tuple<char, char, int> State::GetNextTransition(const char& symbol) const {
        
        bool found = false;
        tuple<char, char, int> result('~', '-', -1);
        
        set<Transition>::iterator it = transitions_.begin();
        
        while ((it != transitions_.end()) && !found) {
            
            if ((*it).symbol_ == symbol) {
                
                found = true;
                result = (*it).transition_tuple_;
                
            } else {
                it++;
            }
            
        }
        
        return result;
    }
    
    
    bool State::symbol_is_used(const char& symbol) const {
        
        bool found = false;
        set<Transition>::iterator it = transitions_.begin();
        
        while ((it != transitions_.end()) && !found) {
            
            if ((*it).symbol_ == symbol) { 
                found = true;
            } else {
                it++;
            }
            
        }
        
        return found;
        
    }
    
    
    int State::number_of_transitions(void) const {
        return transitions_.size();
    }
    
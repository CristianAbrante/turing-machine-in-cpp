
    // Prática 8: Computabilidad y algoritmia
    // Curso: Segundo
    // Alumno: Cristian Abrante Dorta

    // Implementación de la clase TuringMachine
    
#include "TuringMachine.hpp"
    
    TuringMachine::TuringMachine(void)
     : set_of_states_(),
       tape_alphabet_(),
       input_alphabet_(),
       initial_state_(-1),
       accepted_states_(),
       blank_symbol('$') {}
    
    
    TuringMachine::~TuringMachine(void) {
        clear();
    }
    
    
    TuringMachine::TuringMachine(string tm_definition, bool& creating_fault)
     : set_of_states_(),
       tape_alphabet_(),
       input_alphabet_(),
       initial_state_(-1),
       accepted_states_(),
       blank_symbol('$') {
            
            ifstream tm_stream;
            tm_stream.open(tm_definition);
            
            if (tm_stream.is_open()) {
                
                creating_fault = false;
                
                tm_stream >> *this;
                
            } else {
                creating_fault = true;
            }
        
       }
      
    
    istream& operator>>(istream& is, TuringMachine& rhs_tm) {
        
        int number_of_states;
        is >> number_of_states;
        
        vector<State>   tmp_states;
        
        for (int i = 0; i < number_of_states; i++) {
            
            State tmp(i);
            tmp_states.push_back(tmp);
            
        }
        
        int initial_state_id;
        is >> initial_state_id;
        
        is.ignore(1);
        
        string      accepted_states_string;
        vector<int> accepted_states_id_vector;
        
        getline(is, accepted_states_string);
        
        if (!accepted_states_string.empty()) {
            
            for (int i = 0; i < accepted_states_string.size(); i++) {
                
                string tmp_id_string = "";
                
                tmp_id_string += accepted_states_string[i];
                
                while (accepted_states_string[i+1] != ' ') {
                    
                    i++;
                    tmp_id_string += accepted_states_string[i];
                    
                }
                
                int id = stoi(tmp_id_string);
                accepted_states_id_vector.push_back(id);
            }
            
        }
        
        int number_of_tuples;
        is >> number_of_tuples;
        
        int     current_state_id;
        char    input_symbol, tape_symbol, movement;
        int     next_state_id;
        
        for (int i = 0; i < number_of_tuples; i++) {
            
            is >> current_state_id;
            is >> input_symbol;
            is >> tape_symbol;
            rhs_tm.tape_alphabet_.insert(tape_symbol);
            is >> movement;
            assert((movement == 'R') || (movement == 'L') || (movement == 'S'));
            is >> next_state_id;
            
            tmp_states[current_state_id].SetNextTransition(input_symbol,
                                                                tape_symbol,
                                                                movement,
                                                                next_state_id);
            
        }
        
        for (int i=0; i < tmp_states.size(); i++) {
            
            rhs_tm.set_of_states_.insert(tmp_states[i]);
            
        }
        
        rhs_tm.initial_state_ = rhs_tm.GetState(initial_state_id);
        
        for (int i = 0; i < accepted_states_id_vector.size(); i++) {
            
            int id = accepted_states_id_vector[i];
            
            rhs_tm.accepted_states_.insert(rhs_tm.GetState(id));
            
        }
        
        return is;
        
    }
    
    
    ostream& operator<<(ostream& os, const TuringMachine& rhs_tm) {
        
        os << rhs_tm.set_of_states_.size() << endl;
        
        os << rhs_tm.initial_state_.identifier_ << endl;
        
        set<State>::iterator it = rhs_tm.accepted_states_.begin();
        
        for (; it != rhs_tm.accepted_states_.end(); it++) {
            
            os << (*it).identifier_ << " ";
            
        }
        
        os << endl;
        
        int number_of_transitions = 0;
        
        for(it = rhs_tm.set_of_states_.begin(); it != rhs_tm.set_of_states_.end(); it++) {
            
            number_of_transitions += (*it).number_of_transitions();
        }
        
        os << number_of_transitions << endl;
        
        it = rhs_tm.set_of_states_.begin();
        
        for (; it != rhs_tm.set_of_states_.end(); it++) {
            
            os << (*it);
        }
        
        return os;
        
    }
    
    
    void TuringMachine::clear(void) {
        
        set_of_states_.clear();
        tape_alphabet_.clear();
        input_alphabet_.clear();
        initial_state_.clear();
        accepted_states_.clear();
        blank_symbol = '$';
        
    }
    
    
    bool TuringMachine::EvaluateTape(Tape& tape_string, ostream& os, bool print_path) const {
        
        int head = 0;
        int iterations = 0;
        int user_iterations = 100;
        
        State current_state = initial_state_;
        char tape_symbol = tape_string[head];
        
        do {
        
            while (current_state.symbol_is_used(tape_symbol) && (iterations < EPS_INFINITE) && (iterations < user_iterations)) {
                
                if (print_path) {
                    os << "... $$";
                    for (int i = 0; i < tape_string.size(); i++) {
                        
                        if (i == head) {
                            os << " q" << current_state.identifier_ << " ";
                            os << tape_string[i] << " ";
                        } else {
                            os << tape_string[i];
                        }
                    }
                    os << "$$..." << endl;
                    
                }
                
                tuple<char, char, int> next_transition = current_state.GetNextTransition(tape_symbol);
                
                tape_string[head] = get<0>(next_transition);
                
                switch (get<1>(next_transition)) {
                    
                    case 'R': head++; break;
                    case 'L': {
                        head--;
                        if (head < 0) {
                            head = 0;
                            tape_string.insert_front();
                        }
                    }
                }
                
                int id = get<2>(next_transition);
                
                current_state.clear();
                current_state = GetState(id);
                
                tape_symbol = tape_string[head];
                
                iterations++;
            }
            
            if ((iterations >= EPS_INFINITE) || (iterations >= user_iterations)){
                
                if (print_path) {
                    os << "..." << endl;
                    os << "La máquina continuaría su ejecución hasta el infinito." << endl;
                    
                    os << "Introduzca el número de pasos que quiere continuar la ejecución (menos de 100 iteraciones) > ";
                    cin >> user_iterations;
                    iterations = 0;
                }
                
            }
            
        } while ((user_iterations != 100) && (iterations < user_iterations));
        
        if (print_path && !current_state.symbol_is_used(tape_symbol)) {
            os << "... $$";
            for (int i = 0; i < tape_string.size(); i++) {
                if (i == head) {
                    os << " q" << current_state.identifier_ << " ";
                    os << tape_string[i] << " ";
                } else {
                        os << tape_string[i];
                }
            }
            os << "$$..." << endl;
        }
        
        if (IsAnAcceptedState(current_state)) {
            return true;
        } else {
            return false;
        }
        
    }
    
    
    State TuringMachine::GetState (int identifier) const {
        
        assert(identifier < set_of_states_.size());
        
        State result_state;
        bool found = false;
        
        set<State>::iterator it = set_of_states_.begin();
        
        while ((it != set_of_states_.end()) && !found) {
            
            if ((*it).identifier_ == identifier) {
                found = true;
                result_state = (*it);
            } else {
                it++;
            }
            
        }
        
        return result_state;
        
    }
    
    
    bool TuringMachine::IsAnAcceptedState(const State& new_state) const {
        
        bool found = false;
        
        set<State>::iterator it = accepted_states_.begin();
        
        while ((it != accepted_states_.end()) && !found) {
            
            if ((*it) == new_state) {
                found = true;
            } else {
                it++;
            }
            
        }
        
        return found;
        
    }
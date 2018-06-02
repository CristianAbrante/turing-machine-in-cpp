
// Práctica 8: Computabilidad y algoritmia.
// Cristian Abrante Dorta.

#include "./TuringMachine/TuringMachine.hpp"                // Inclusión de la clase Turing Machine.
#include "./Tape/Tape.hpp"                                  // Inclusión de la clase Tape.

#include <cstdio>
#include <cstdlib>

int main(int argc, char* argv[]) {
    
    system ("clear");
    cout << "-------------------------------------------------------------------" << endl;
    cout << "\tPráctica 8 : Simulación de máquinas de Turing." << endl;
    cout << "-------------------------------------------------------------------" << endl;
    
    if (argc == 3) {
        
        string str(argv[1]);
        bool opening_fault = false;
        
        TuringMachine myTuringMachine(str, opening_fault);
        
        if (!opening_fault)
        {
            cout << "Cargando máquina de Turing desde el fichero " << str << endl;
            cout << myTuringMachine << endl;
            
            str = argv[2];
            bool opening_fault_tape;
            Tape myTape(str, opening_fault_tape);
            
            if (!opening_fault_tape) {
                
                cout << "Cargando cinta desde el fichero " << str << endl;
                cout << myTape << endl;
                cout << endl;
                
                cout << "Computaremos la cinta a través de la máquina de Turing." << endl;
                cout << endl;
                
                if (myTuringMachine.EvaluateTape(myTape, cout, 1)) {
                    cout << endl;
                    cout << "La cadena está aceptada." << endl;
                } else {
                    cout << endl;
                    cout << "La cadena no está aceptada." << endl;
                }
                
            } else {
                cerr << "ERROR DE APERTURA EN LA CINTA." << endl;
                exit(1);
            }
            
        } else {
            cerr << "ERROR DE APERTURA EN LA MÁQUINA DE TURING." << endl;
            exit(1);
        }
    } else {
        cerr << "NÚMERO INCORRECTO DE ARGUMENTOS." << endl;
        exit(1);
    }
    
    cout << "\nHecho por: Cristian Abrante Dorta." << endl;
    cout << endl;
    
}
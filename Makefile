# Makefile para compilar la práctica 7 de C&A.
# Cristian Abrante Dorta.

CC = g++
CXXFLAGS= --std=c++11 -g
OBJECTS= ./src/TuringMachine/TuringMachine.o ./src/State/State.o ./src/Transition/Transition.o ./src/Alphabet/Alphabet.o  ./src/Tape/Tape.o ./src/main.o 

Practica7: ${OBJECTS}
	${CC} ${CXXFLAGS} -o turing-machine.out ${OBJECTS}

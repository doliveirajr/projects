#----------- VARIABLES -----------

ECHO = echo -e

PROG = ./*/PROG
F_PROG = $(PROG)/*.cpp
UNITTEST = ./*/UNITTEST
F_UNITTEST = $(UNITTEST)/*.cpp
INCLUDE = ./*/INCLUDE
F_INCLUDE = $(INCLUDE)/*.hpp
FILES_O = $(OBJ)/cgpa.o $(OBJ)/rPsGame.o $(OBJ)/Inventory.o $(OBJ)/CassinoGame.o $(OBJ)/Payroll.o
OBJ = ./obj
LIB = ./lib

#----------- FLAGS -----------

LIBS = -lcompile -L $(LIB)
FLAGS = -O3 -Wall -std=c++17 -lsqlite3

#----------- CODE -----------

all: compile test

compile: dir $(FILES_O) build
	$(ECHO) Compiled

build: $(FILES_O)
	ar -rcs $(LIB)/libcompile.a $(OBJ)/*.o

test: 
	$(ECHO) Testing...
	g++ $(F_UNITTEST) $(F_PROG) -lgtest -lgmock -lgtest_main -pthread -lsqlite3
	./a.out

tree:
	$(ECHO) Showing Tree
	tree .

clean:
	rm -rf ./obj ./lib *.db *.out

dir:
	rm -rf obj
	rm -rf lib
	mkdir obj lib

#----------- TEMPLATE -----------

$(OBJ)/%.o: $(PROG)/%.cpp $(INCLUDE)/%.hpp
	g++ $(FLAGS) -c $< $(LIBS) -I $(INCLUDE) -o $@

$(OBJ)/%.o: $(INCLUDE)/%.hpp
	g++ $(FLAGS) -c $< $(LIBS) -o $@
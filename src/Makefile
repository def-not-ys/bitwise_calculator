CC = g++
CFLAG = -g -std=c++11 -Wall

C_DIR = arithematics/
CPP_DIR = calculator_cpp/
OBJ_DIR = obj/
AST_DIR = $(CPP_DIR)_util/
INCLUDES = -I$(CPP_DIR) -I$(AST_DIR)

HEADER = $(CPP_DIR)Calculator.h $(AST_DIR)Parser.h $(AST_DIR)Evaluator.h $(AST_DIR)AST.h
TARGET = calculator

C_OBJ = arithematics.o
CPP_OBJ = parser.o evaluator.o AST.o

all: $(CPP_OBJ) calculator.o $(C_OBJ)
	$(CC) $(CFLAG) $(CPP_OBJ) calculator.o $(C_OBJ) $(HEADER) source.cpp -o $(TARGET)

test_arithematics: $(C_OBJ)
	$(CC) $(CFLAG) test/arithematics_test.cpp arithematics.o -o test_arithematics

test_calculator: calculator.o $(CPP_OBJ) $(C_OBJ)
	$(CC) $(CFLAG) test/calculator_test.cpp $(CPP_OBJ) $(C_OBJ) calculator.o -o test_calculator

calculator.o: $(CPP_OBJ) $(CPP_DIR)Calculator.h
	$(CC) $(CFLAG) -c $(CPP_DIR)Calculator.cpp

parser.o: $(AST_DIR)Parser.h $(AST_DIR)AST.h
	$(CC) $(CFLAG) -c $(AST_DIR)AST.cpp $(AST_DIR)Parser.cpp

evaluator.o: $(AST_DIR)Evaluator.h $(AST_DIR)AST.h $(C_DIR)arithematics.h
	$(CC) $(CFLAG) -c $(AST_DIR)AST.cpp $(AST_DIR)Evaluator.cpp $(C_DIR)arithematics.c

arithematics.o: $(C_DIR)arithematics.h
	$(CC) $(CFLAG) -c $(C_DIR)arithematics.c

run:
	calculator

clean:
	rm -f calculator 0 *.o *~ test_arithematics test_calculator
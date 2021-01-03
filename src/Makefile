CC = g++
CFLAG = -g -o0 -std=c++11 -Wall 

C_DIR = arithematics/
CPP_DIR = calculator_cpp/
AST_DIR = $(CPP_DIR)_util/
INCLUDES = -I$(CPP_DIR) -I$(AST_DIR)

HEADER = $(CPP_DIR)Calculator.h $(AST_DIR)AST.h
TARGET = calculator

C_OBJ = $(C_DIR)arithematics.o
CPP_OBJ = $(CPP_DIR)calculator.o $(AST_DIR)AST.o

all: $(CPP_OBJ)
	$(CC) $(CFLAG) $(INCLUDES) $(CPP_OBJ) $(HEADER) source.cpp -o $(TARGET)

arithematics_test: $(C_OBJ)
	$(CC) $(CFLAG) test/arithematics_test.cpp $(C_DIR)arithematics.o -o arithematics_test

calculator_test: $(CPP_DIR)calculator.o
	$(CC) $(CFLAG) test/calculator_test.cpp $(CPP_DIR)calculator.o -o calculator_test

AST.o: $(AST_DIR)AST.h arithematics.o
	$(CC) $(CFLAG) -c $(AST_DIR)AST.cpp $(AST_DIR)Parser.cpp $(AST_DIR)Evaluator.cpp arithematics.o

arithematics.o: $(C_DIR)arithematics.h
	$(CC) $(CFLAG) -c $(C_DIR)arithematics.c

calculator.o: $(CPP_DIR)Calculator.h
	$(CC) $(CFLAG) -c $(CPP_DIR)Calculator.cpp

run:
	calculator

clean:
	rm -f calculator 0 *.o *~ $(C_DIR)*.o $(C_DIR)*~ $(CPP_DIR)*.o $(CPP_DIR)*~ $(AST_DIR)*.o $(AST_DIR)*~ arithematics_test calculator_test
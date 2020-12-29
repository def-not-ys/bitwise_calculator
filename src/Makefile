CC = g++
CFLAG = -g -o0 -std=c++14 -Wall 

C_DIR = arithematics/
CPP_DIR = calculator/
INCLUDES = -I$(C_DIR) -I$(CPP_DIR)

HEADER = $(C_DIR)arithematics.h $(CPP_DIR)Calculator.h
TARGET = calculator_silly

C_OBJ = $(C_DIR)arithematics.o
CPP_OBJ = $(CPP_DIR)calculator.o

all: $(C_OBJ) $(CPP_OBJ)
	$(CC) $(CFLAG) $(INCLUDES) $(C_OBJ) $(CPP_OBJ) $(HEADER) source.cpp -o $(TARGET)

arithematics_test: $(C_DIR)arithematics.o
	$(CC) $(CFLAG) test/arithematics_test.cpp $(C_DIR)arithematics.o -o arithematics_test

calculator_test: $(CPP_DIR)calculator.o
	$(CC) $(CFLAG) test/calculator_test.cpp $(CPP_DIR)calculator.o -o calculator_test

arithematics.o: $(C_DIR)arithematics.h
	$(CC) $(CFLAG) -c $(C_DIR)arithematics.c

calculator.o: $(CPP_DIR)Calculator.h
	$(CC) $(CFLAG) -c $(CPP_DIR)Calculator.cpp

run:
	calculator_silly

clean:
	rm -f calculator_silly 0 *.o *~ $(C_DIR)*.o $(C_DIR)*~ $(CPP_DIR)*.o $(CPP_DIR)*~ arithematics_test calculator_test
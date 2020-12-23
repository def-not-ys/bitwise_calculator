
CC = g++
CFLAG = -g -o0 -Wall

C_DIR = arithematics/
CPP_DIR = ui/
INCLUDES = -I$(C_DIR) -I$(CPP_DIR)

HEADER = $(C_DIR)arithematics.h $(CPP_DIR)ui.h
TARGET = calculator

C_OBJ = $(C_DIR)arithematics.o
CPP_OBJ = $(CPP_DIR)ui.o

all: $(C_OBJ) $(CPP_OBJ)
	$(CC) $(CFLAG) $(INCLUDES) $(C_OBJ) $(CPP_OBJ) $(HEADER) source.cpp -o $(TARGET)

arithematics.o: $(C_DIR)arithematics.h $(C_DIR)arithematics.c
	cd $(C_DIR)
	$(CC) $(CFLAG) $(INCLUDES) -c arithematics.c

ui.o: $(CPP_DIR)ui.cpp $(CPP_DIR)ui.h
	cd $(CPP_DIR)
	$(CC) $(CFLAG) -c ui.cpp

run:
	calculator

clean:
	rm -f calculator *.o *~ $(C_DIR)*.o $(C_DIR)*~ $(CPP_DIR)*.o $(CPP_DIR)*~
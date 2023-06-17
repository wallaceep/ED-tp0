CC = gcc
CFLAGS = -pg -Wall -c -I$(INC)
#CXXFLAGS = -std=c++11 -O3 -Wall

# folders
INCLUDE_FOLDER = ./include/
BIN_FOLDER = ./bin/
OBJ_FOLDER = ./obj/
SRC_FOLDER = ./src/
MEM_FOLDER = ./analisamem/bin/analisamem

LOG_FILE = log.out
S_FILE = saida

# all sources, objs, and header files
MAIN = Main
TARGET = run.out
SRC = $(wildcard $(SRC_FOLDER)*.c)
OBJ = $(patsubst $(SRC_FOLDER)%.c, $(OBJ_FOLDER)%.o, $(SRC))

IMG_FILE = bolao

$(OBJ_FOLDER)%.o: $(SRC_FOLDER)%.c
	$(CC) $(CXXFLAGS) -c $< -o $@ -I$(INCLUDE_FOLDER)

all: $(OBJ)
	$(CC) $(CXXFLAGS) -o $(BIN_FOLDER)$(TARGET) $(OBJ)

log:
	$(MEM_FOLDER) -i $(BIN_FOLDER)$(LOG_FILE) -p $(BIN_FOLDER)$(S_FILE)
	@gnuplot $(BIN_FOLDER)*.gp
	@rm -rf $(OBJ_FOLDER)* $(BIN_FOLDER)*.gpdat $(BIN_FOLDER)*.gp
	

clean:
	@rm -rf $(OBJ_FOLDER)* $(BIN_FOLDER)*.out $(BIN_FOLDER)*.png $(BIN_FOLDER)*.pgm
	
	
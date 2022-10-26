CC = g++
LIBS = -lm
SRC = src
OBJ = obj
OUT = saidas/*
INC = include
BIN = bin
OBJS = $(OBJ)/tp3.o $(OBJ)/Email.o $(OBJ)/Servidor.o $(OBJ)/Usuario.o
HDRS = $(INC)/Email.h $(INC)/Servidor.h $(INC)/Usuario.h
CFLAGS = -pg -Wall -c -I$(INC)
# ANALISAMEM = ../analisamem/bin/analisamem

EXE = $(BIN)/tp3

# run: $(EXE)
# 	rm -rf output
# 	mkdir output
# 	$(EXE)	-i input/entrada_1.txt -o output/saida_1.txt
# 	$(EXE)	-i input/entrada_2.txt -o output/saida_2.txt
# 	$(EXE)	-i input/entrada_3.txt -o output/saida_3.txt
# 	$(EXE)	-i input/entrada_4.txt -o output/saida_4.txt



all:$(EXE)

$(BIN)/tp3: $(OBJS)
	$(CC) -pg -o $(BIN)/tp3 $(OBJS) $(LIBS)

$(OBJ)/tp3.o: $(HDRS) $(SRC)/tp3.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/tp3.o $(SRC)/tp3.cpp 	

$(OBJ)/Usuario.o: $(HDRS) $(SRC)/Usuario.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/Usuario.o $(SRC)/Usuario.cpp 

$(OBJ)/Servidor.o: $(HDRS) $(SRC)/Servidor.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/Servidor.o $(SRC)/Servidor.cpp 

$(OBJ)/Email.o: $(HDRS) $(SRC)/Email.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/Email.o $(SRC)/Email.cpp 
	
	
clean:
	rm -f  gmon.out $(BIN)/tp3 $(OBJS) $(OUT) 
	rm -rf output

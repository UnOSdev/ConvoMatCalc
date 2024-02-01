PROJECT = convolutionMatrix

CC = gcc
CFLAGS = -Wall -g -std=c99
LFLAGS = -lm 

SOURCES = main.c matrix.c

build:
	$(CC) $(CFLAGS) $(SOURCES) -o $(PROJECT) $(LFLAGS)

run: build 
	./$(PROJECT)

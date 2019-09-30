# SUBTRA makefile
# 2019 Matthias Scherba @szczm_

CC = g++
LIBS = -lSDL2 -lGL
FLAGS = -Iinclude

OBJ = \
	Mesh.o \
	Exception.o \
	Window.o \
	Engine.o

%.o : src/%.cpp
	$(CC) $(FLAGS) -c $< $(LIBS) -o $@

all : src/main.cpp $(OBJ)
	$(CC) $(FLAGS) $(OBJ) src/main.cpp $(LIBS) -o subtra

clean :
	rm subtra $(OBJ)

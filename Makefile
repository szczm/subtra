# SUBTRA makefile
# 2019 Matthias Scherba @szczm_

CC=g++
LIBS=-lSDL2

all : src/main.cpp
	$(CC) src/main.cpp -o subtra $(LIBS)

clean :
	rm subtra *.o

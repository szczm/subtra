# SUBTRA makefile
# 2019 Matthias Scherba @szczm_

CC=g++
LIBS=-lSDL2

all : main.cpp
	$(CC) main.cpp -o subtra $(LIBS)

clean :
	rm subtra *.o

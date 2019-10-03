# SUBTRA makefile
# 2019 Matthias Scherba @szczm_

CC = g++
LIBS = -ldl -lSDL2 -lGL
FLAGS = -Iinclude -Ilibs/glad/include -Ilibs/imgui \
	-std=c++1z

OBJ = \
	glad.o \
	imgui.o imgui_demo.o imgui_draw.o imgui_widgets.o imgui_impl_sdl.o imgui_impl_opengl3.o \
	Exception.o Mesh.o Shader.o Window.o InputManager.o WindowManager.o Engine.o


all : src/main.cpp $(OBJ)
	$(CC) $(FLAGS) $(OBJ) src/main.cpp $(LIBS) -o subtra

debug : src/main.cpp $(OBJ)
	$(CC) $(FLAGS) $(OBJ) src/main.cpp $(LIBS) -g -o subtra

%.o : src/%.cpp
	$(CC) $(FLAGS) -c $< $(LIBS) -o $@

glad.o : libs/glad/src/glad.c
	$(CC) $(FLAGS) -c $< $(LIBS) -o $@

imgui%.o : libs/imgui/imgui%.cpp
	$(CC) $(FLAGS) -c $< $(LIBS) -o $@

imgui.o : libs/imgui/imgui.cpp
	$(CC) $(FLAGS) -c $< $(LIBS) -o $@

clean :
	rm subtra $(OBJ)

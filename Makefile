# SUBTRA makefile
# 2019 Matthias Scherba @szczm_


# The configurable part

CC = g++
MKDIR = mkdir
RM = rm -r

LIBS = -ldl -lSDL2 -lGL -lstdc++fs
FLAGS = -Iinclude -Ilibs/glad/include -Ilibs/imgui \
	-std=c++17

SOURCE_DIR = src
BUILD_DIR = build

MAIN = main.cpp
OUTPUT = subtra


# The technical part

SOURCES = $(shell find $(SOURCE_DIR) -name "*.cpp")
EXT_OBJS = glad.o imgui.o imgui_demo.o imgui_draw.o imgui_widgets.o imgui_impl_sdl.o imgui_impl_opengl3.o

OBJS := $(EXT_OBJS:%.o=$(BUILD_DIR)/%.o) $(SOURCES:$(SOURCE_DIR)/%.cpp=$(BUILD_DIR)/%.o)


# The part that rules (get it? rules?)

all : $(MAIN) $(OBJS)
	$(CC) $(FLAGS) $(OBJS) $(MAIN) $(LIBS) -o $(OUTPUT)

debug : $(MAIN) $(OBJS)
	$(CC) $(FLAGS) $(OBJS) $(MAIN) $(LIBS) -g -o $(OUTPUT)

clean :
	$(RM) $(OUTPUT) $(BUILD_DIR)


$(BUILD_DIR)/%.o : $(SOURCE_DIR)/%.cpp $(BUILD_DIR)
	$(CC) $(FLAGS) -c $< $(LIBS) -o $@

$(BUILD_DIR)/glad.o : libs/glad/src/glad.c $(BUILD_DIR)
	$(CC) $(FLAGS) -c $< $(LIBS) -o $@

$(BUILD_DIR)/imgui%.o : libs/imgui/imgui%.cpp $(BUILD_DIR)
	$(CC) $(FLAGS) -c $< $(LIBS) -o $@

$(BUILD_DIR)/imgui.o : libs/imgui/imgui.cpp $(BUILD_DIR)
	$(CC) $(FLAGS) -c $< $(LIBS) -o $@

$(BUILD_DIR) :
	$(MKDIR) $(BUILD_DIR)


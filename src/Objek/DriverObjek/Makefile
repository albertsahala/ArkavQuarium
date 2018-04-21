# Masukkan semua file cpp Anda
OBJS = DriverObjek.cpp Akuarium.cpp Interface.cpp Objek.cpp Koin.cpp MakananIkan.cpp  oop.cpp

CC = g++
COMPILER_FLAGS = -g -std=c++11 -Wall -O2
LINKER_FLAGS = -lSDL2 -lSDL2_image -lSDL2_ttf
OBJ_NAME = oopquarium
all : $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)

# Masukkan semua file cpp Anda
OBJS = main.cpp src/oop.cpp src/Akuarium.cpp src/Ikan/Ikan.cpp src/Interface.cpp src/Ikan/Guppy/Guppy.cpp src/Ikan/Piranha/Piranha.cpp src/Objek/Objek.cpp src/Objek/Koin/Koin.cpp src/Objek/MakananIkan/MakananIkan.cpp src/Siput/Siput.cpp

CC = g++
COMPILER_FLAGS = -g -std=c++11 -Wall -O2
LINKER_FLAGS = -lSDL2 -lSDL2_image -lSDL2_ttf
OBJ_NAME = oopquarium
all : $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)

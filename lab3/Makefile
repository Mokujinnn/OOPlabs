LIBS = -lsfml-graphics -lsfml-window -lsfml-system

all: main.o
	clang++ main.o -o app $(LIBS)

%.o: %.cpp
	clang++ -c $< -o $@
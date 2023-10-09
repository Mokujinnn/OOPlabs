LIBS = -L"../SFML-2.6.0/lib" -lsfml-system-s -lsfml-window -lsfml-graphics
SRC = main.cpp tPoint.cpp
OBJ = $(SRC:.cpp=.o)

all: $(OBJ)
	g++ $(OBJ) -o app $(LIBS)

%.o: %.cpp
	g++ -I../SFML-2.6.0/include -c -Wall $< -o $@ 

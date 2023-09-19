LIBS = -L"../SFML-2.6.0/lib" -lsfml-graphics -lsfml-window -lsfml-system
SRC = main.cpp tPoint.cpp
OBJ = $(SRC:.cpp=.o)

all: $(OBJ)
	g++ $(OBJ) -o app $(LIBS)

%.o: %.cpp
	g++ -c -Wall $< -o $@ -I../SFML-2.6.0/include

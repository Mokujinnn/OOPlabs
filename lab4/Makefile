LIBS = -lsfml-graphics -lsfml-window -lsfml-system
SRC = main.cpp tPoint.cpp
OBJ = $(SRC:.cpp=.o)
EXECUTABLE = app

all: $(SRC) $(EXECUTABLE)

$(EXECUTABLE): $(OBJ)
	clang++ $(LIBS) $(OBJ) -o (EXECUTABLE)

%.o: %.cpp
	clang++ -c -Wall $< -o $@
CC = g++ -std=c++11 -Wall
LIB = -lsfml-graphics -lsfml-window -lsfml-system
CPP = main.cpp App.cpp Common.cpp Window.cpp State.cpp StateMachine.cpp IntroState.cpp PlayState.cpp
OBJ = $(CPP:.cpp=.o)
EXE = fooGame

default: $(EXE)
	./$(EXE)

$(EXE): $(OBJ)
	$(CC) -o $(EXE) $(OBJ) $(LIB)

main.o: main.cpp App.hpp
	$(CC) -c main.cpp

Window.o: Window.cpp Window.hpp
	$(CC) -c Window.cpp

Common.o: Common.cpp Common.hpp
	$(CC) -c Common.cpp

App.o: App.cpp App.hpp StateMachine.hpp Common.hpp State.hpp  IntroState.hpp PlayState.hpp Window.hpp
	$(CC) -c App.cpp

State.o: State.cpp State.hpp Window.hpp StateMachine.hpp
	$(CC) -c State.cpp

StateMachine.o: StateMachine.cpp StateMachine.hpp State.hpp IntroState.hpp PlayState.hpp Window.hpp
	$(CC) -c StateMachine.cpp

IntroState.o: IntroState.cpp IntroState.hpp State.hpp Window.hpp StateMachine.hpp Common.hpp
	$(CC) -c IntroState.cpp

PlayState.o: PlayState.cpp PlayState.hpp State.hpp Window.hpp StateMachine.hpp
		$(CC) -c PlayState.cpp

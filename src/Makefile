PROJECT = mikmik
CXX = g++
CXXFLAGS = -std=c++17 -I../include -I../tests -Werror -Wpedantic -Wall
LGTESTFLAGS = -pthread -lgtest -lgtest_main

DEPS = $(wildcard *.hpp)

OBJ = Animatronic.o Cam.o Door.o Energy.o Fox.o Fredd.o Game.o Phone.o Player.o Random.o Picture.o Menu.o MiniPlayer.o MiniEnemy.o MiniAbility.o Minigame.o MiniBattleSystem.o MiniWarrior.o MiniMage.o MiniRogue.o MiniGoblin.o MiniEffect.o

TEST_SRC = ../tests/tests.cpp
TEST_OBJ = tests.o
TEST_PROJECT = testik

.PHONY: default
default: all

%.o: %.cpp $(DEPS)
	$(CXX) $(CXXFLAGS) -c $<

$(PROJECT): main.o $(OBJ)
	$(CXX) -o $@ main.o $(OBJ)
	
$(TEST_PROJECT): $(TEST_SRC) $(OBJ)
	$(CXX) $(CXXFLAGS) -c $(TEST_SRC) -o $(TEST_OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $(TEST_OBJ) $(OBJ) $(LGTESTFLAGS)

all: $(PROJECT)

test: $(TEST_PROJECT)

.PHONY: clean cleanall

clean:
	rm -f *.o

cleanall: clean
	rm -f $(PROJECT)
	rm -f testik

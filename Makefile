CC=g++
FLAGS=-Wall -pedantic -std=c++11
SFML_FLAGS=-lsfml-graphics -lsfml-window -lsfml-system

HEADERS_DIR=include
SOURCE_DIR=src
TARGET_DIR=bin

HEADERS= $(wildcard $(HEADERS_DIR)/*.hpp)
SOURCES= $(wildcard $(SOURCE_DIR)/*.cpp)
OBJECTS= $(subst src,bin,$(SOURCES:.cpp=.o))

$(TARGET_DIR)/%.o : $(SOURCE_DIR)/%.cpp $(HEADERS_DIR)/%.hpp
	$(CC) -c -o $@ $< $(FLAGS) 

$(TARGET_DIR)/%.o : $(SOURCE_DIR)/%.cpp 
	$(CC) -c -o $@ $< $(FLAGS) 

debug: FLAGS += -g -DDEBUG
debug: OBJECTS := $(filter-out bin/unitTests.o, $(OBJECTS))
debug: $(HEADERS) $(SOURCES) $(OBJECTS)
	$(CC) -o game $(OBJECTS) $(FLAGS) $(SFML_FLAGS)

test: FLAGS += -g -DDEBUG
test: OBJECTS := $(filter-out bin/main.o, $(OBJECTS))
test: $(HEADERS) $(SOURCES) $(OBJECTS)
	$(CC) -o utest $(OBJECTS) $(FLAGS) $(SFML_FLAGS)

release: $(HEADERS) $(SOURCES) $(OBJECTS)
	$(CC) -o game $(OBJECTS) $(FLAGS) $(SFML_FLAGS)

.PHONY: clean

clean:
	rm -f $(TARGET_DIR)/*.o game 
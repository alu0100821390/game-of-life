# Macros

MAIN = main/
MAIN_FILE = $(MAIN)main.cpp
SRC = src/
SRC_FILES = $(SRC)cell_t.cpp $(SRC)board_t.cpp
OUT = bin/
OUT_FILE = $(OUT)juego-vida
IN = input/
IN_FILE = $(IN)default.txt


# Reglas explícitas

default:
	g++ $(MAIN_FILE) $(SRC_FILES) -o $(OUT_FILE)

manual:
	$(OUT_FILE)

file:
	$(OUT_FILE) $(IN_FILE)

run: default manual

run-file: default file

CC=gcc # -std=c99
INC = /Include
CFLAGS=-g -Wall -Werror
LINK=-lm
_SRC=src
SRC=$(wildcard $(_SRC)/*.c)
_OBJ=src/obj
OBJ=$(patsubst $(_SRC)/%.c, $(_OBJ)/%.o, $(SRC))
# _INPUT=images
# IMGS=$(wildcard $(_INPUT)/*.bmp)
OUT=delta

all: $(OUT)

$(OUT): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(OUT) $(LINK)

$(_OBJ)/%.o: $(_SRC)/%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(LINK)

clean:
	rm $(OBJ)*
	rm $(OUT)


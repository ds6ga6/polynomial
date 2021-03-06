# Project: polynomial
# This is for Linux

CC       = gcc
TMPDIR   = obj/
OBJ      = obj/PolynomialADT.o obj/polynomialMain.o
INCS     = -I "./lib/"
BIN      = polynomial
FLAGS    = $(INCS)
RM       = rm -f

.PHONY: all clean

all: $(TMPDIR) $(BIN)

clean:
	${RM} $(OBJ) $(BIN)
	${RM} -r $(TMPDIR)

$(BIN): $(OBJ)
	$(CC) $(OBJ) -o $(BIN)

obj/:
	mkdir obj/

obj/polynomialMain.o : polynomialMain.c
	$(CC) -c polynomialMain.c -o obj/polynomialMain.o $(FLAGS)

obj/PolynomialADT.o : lib/PolynomialADT.c lib/PolynomialADT.h
	$(CC) -c lib/PolynomialADT.c -o obj/PolynomialADT.o $(FLAGS)
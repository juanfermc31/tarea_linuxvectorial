// =========================
// Archivo: Makefile
// =========================
CC=gcc
CFLAGS=-Iinclude -Wall -O2


all: triple_integral


triple_integral: src/main.o src/integracion.o src/densidades.o
$(CC) src/main.o src/integracion.o src/densidades.o -o triple_integral -lm


src/main.o: src/main.c include/integracion.h include/densidades.h
$(CC) $(CFLAGS) -c src/main.c -o src/main.o


src/integracion.o: src/integracion.c include/integracion.h
$(CC) $(CFLAGS) -c src/integracion.c -o src/integracion.o


src/densidades.o: src/densidades.c include/densidades.h
$(CC) $(CFLAGS) -c src/densidades.c -o src/densidades.o


clean:
rm -f src/*.o triple_integral
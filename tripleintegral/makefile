CC = gcc
CFLAGS = -Wall -Iinclude
LIBS = -lm

# Archivos fuente y objeto
SRC = src/main.c src/densidades.c src/integracion.c
OBJ = $(SRC:.c=.o)
EXEC = programa_vectorial

# Regla principal: compilar todo
all: $(EXEC)

# Enlazar los objetos para crear el ejecutable
$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $(EXEC) $(LIBS)

# Compilar archivos .c a .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Limpiar archivos generados
clean:
	rm -f src/*.o $(EXEC)
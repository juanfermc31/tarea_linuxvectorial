# Compilador
CC = gcc

# Flags de compilación
CFLAGS = -Wall -O2 -Iinclude
LIBS = -lm

# Directorios
SRC_DIR = src
OBJ_DIR = obj
BIN = programa_vectorial

# Archivos .c y sus .o correspondientes
SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

# =========================
# Regla principal
# =========================
all: $(BIN)

# Enlace final
$(BIN): $(OBJ)
	$(CC) $(OBJ) -o $(BIN) $(LIBS)
	@echo "✔ Ejecutable generado: $(BIN)"

# =========================
# Regla genérica para compilar .c → .o
# =========================
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# =========================
# Limpieza
# =========================
clean:
	rm -rf $(OBJ_DIR) $(BIN)
	@echo "✔ Limpieza completa"

# =========================
# Ejecutar programa
# =========================
run: all
	./$(BIN)

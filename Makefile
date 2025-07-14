# Define el compilador por defecto para Linux
CXX_LINUX = g++
# Define el compilador por defecto para Windows (usando clang++ para compatibilidad con MSYS2/WSL)
CXX_WINDOWS = clang++

# Define las banderas de compilación comunes
CXXFLAGS = -Wall -Wextra -std=c++17

# Rutas a los directorios
BIN_DIR = bin
OBJ_DIR = obj
SRC_DIR = Meride-o-roulette/src
CLASSES_DIR = Meride-o-roulette/Clases
INCLUDE_DIR = Meride-o-roulette/include

# Archivos fuente
MAIN_SRC = $(SRC_DIR)/main.cpp
CLASSES_SRC = $(CLASSES_DIR)/class.cpp
FUNCTIONS_SRC = $(INCLUDE_DIR)/Funciones.cpp

# Archivos objeto
MAIN_OBJ = $(OBJ_DIR)/main.o
CLASSES_OBJ = $(OBJ_DIR)/class.o
FUNCTIONS_OBJ = $(OBJ_DIR)/Funciones.o

# Nombre del ejecutable
TARGET_LINUX = $(BIN_DIR)/programa_linux
TARGET_WINDOWS = $(BIN_DIR)/programa_windows.exe

# Todos los archivos objeto
OBJS = $(MAIN_OBJ) $(CLASSES_OBJ) $(FUNCTIONS_OBJ)

.PHONY: all linux windows clean

all: linux windows

# Regla para compilar para Linux
linux: $(BIN_DIR) $(OBJ_DIR) $(TARGET_LINUX)

$(TARGET_LINUX): $(OBJS)
	@echo "Compilando para Linux..."
	$(CXX_LINUX) $(OBJS) -o $@

# Regla para compilar para Windows
windows: $(BIN_DIR) $(OBJ_DIR) $(TARGET_WINDOWS)

$(TARGET_WINDOWS): $(OBJS)
	@echo "Compilando para Windows..."
	$(CXX_WINDOWS) $(OBJS) -o $@

# Reglas para compilar los archivos .cpp a .o
$(MAIN_OBJ): $(MAIN_SRC) $(CLASSES_DIR)/class.hh $(INCLUDE_DIR)/Funciones.hh
	@echo "Compilando $< a objeto..."
	$(CXX_LINUX) $(CXXFLAGS) -c $< -o $@ -I$(CLASSES_DIR) -I$(INCLUDE_DIR)

$(CLASSES_OBJ): $(CLASSES_SRC) $(CLASSES_DIR)/class.hh
	@echo "Compilando $< a objeto..."
	$(CXX_LINUX) $(CXXFLAGS) -c $< -o $@ -I$(CLASSES_DIR) -I$(INCLUDE_DIR)

$(FUNCTIONS_OBJ): $(FUNCTIONS_SRC) $(INCLUDE_DIR)/Funciones.hh
	@echo "Compilando $< a objeto..."
	$(CXX_LINUX) $(CXXFLAGS) -c $< -o $@ -I$(CLASSES_DIR) -I$(INCLUDE_DIR)

# Reglas para crear los directorios bin y obj si no existen
$(BIN_DIR):
	@mkdir -p $(BIN_DIR)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# Regla para limpiar los archivos compilados
clean:
	@echo "Limpiando archivos compilados..."
	@rm -f $(OBJS) $(TARGET_LINUX) $(TARGET_WINDOWS)
	@rmdir $(BIN_DIR) 2>/dev/null || true
	@rmdir $(OBJ_DIR) 2>/dev/null || true


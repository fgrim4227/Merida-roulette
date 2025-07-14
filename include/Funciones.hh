#ifndef INCLUDE_FUNCIONES_HH // Unique guard for Funciones.hh
#define INCLUDE_FUNCIONES_HH
#include<iostream>
#include "class.hh"
using namespace std;
// Definiciones de colores ANSI para mayor legibilidad
const std::string RESET = "\033[0m";
const std::string GRAY_TEXT = "\033[90m";   // Texto gris claro para la mesa
const std::string WHITE_TEXT = "\033[97m";  // Texto blanco para el contorno de la mesa
const std::string RED_PLAYER_COLOR = "\033[31m"; // Cian para la persona
const std::string GREEN_PLAYER_COLOR = "\033[32m";
const std::string CLEAR_SCREEN = "\033[2J";
const std::string GOTO_TOP_LEFT = "\033[H";

void mesa_vacia();
void mesa_full(Bala*,int);
void start_mesa(Bala*, int);
void destruir_mesa(Bala*, int);
int status_mesa(Bala[],int);
void limpiar_pantalla();
#endif // INCLUDE_FUNCIONES_HH

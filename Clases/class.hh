#ifndef CLASES_CLASS_HH // 1. If this macro is NOT defined...
#define CLASES_CLASS_HH // 2. ...then define it.
#include<iostream>
#include<vector>
#include<string>
#include <cstring>
#include <cstdlib>  // Para rand(), srand(), RAND_MAX
#include <ctime>
class Persona {
public:
    std::string nombre; // <-- ¡Cambiar a std::string!
    int n_vidas;
    char estado; // Asumo que es 'char' para estados como '0', '1'

    Persona(const std::string& Nombre, int N_vidas, char Estado); // Adaptar el constructor
    ~Persona();
};
class Bala{
    private:
    char estado;   
    public:
    Bala();
    void determinar();
    char get_estado();
    void desactivar_bala();
    ~Bala();
};
class Jugador : public Persona{
    public:
    Jugador(std::string&,int,char);
    void bajar_vida();
    void elegir_ronda(Bala,Bala*,int);
    void elegir_objeto();
    ~Jugador();
};
class Bot : public Jugador{
    public:
    Bot(std::string&,int,char);
    int determinar_choice(int,Bala*);
    ~Bot();
};
#endif // 3. ... End of the conditional block
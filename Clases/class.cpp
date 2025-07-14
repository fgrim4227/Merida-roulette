#include "class.hh"
#include "Funciones.hh"
Persona::Persona(const std::string& Nombre, int N_vidas, char Estado){
    this->nombre = Nombre; // Asignación simple, std::string se encarga de todo
    this->n_vidas = N_vidas;
    this->estado = Estado;
}

Persona::~Persona(){

}

void Bala::determinar(){
    int det = rand() % 2;
    if(det == 0)
    {
        estado = '0';
    }
    else if(det == 1)
    {
        estado = '1';
    }
    else
    {
        std::cout<<"Se ha producido un error"<<std::endl;
        estado = '0';
    }
}
Bala::Bala(){
    determinar();
}
void Bala::desactivar_bala(){
    //estado == '3'; fran conchaLE CONTIGO == ES comparacionnnnnnnnnnNN NO ASIGNACIONNNNNNN
    estado = '3';
}
char Bala::get_estado(){
    return estado;
}
Bala::~Bala(){

}
Jugador::Jugador(std::string& Nombre,int Vidas,char Estado) : Persona( Nombre,Vidas,Estado){

}
Jugador::~Jugador(){
   
}
void Jugador::bajar_vida(){
    n_vidas--;
}
void Jugador::elegir_ronda(Bala Bala_choice, Bala* Mesa, int indice){
    if(Bala_choice.get_estado() == '0')
    {
        std::cout<<"Click... Nada paso"<<std::endl;
        std::cout<<"Presiona enter para seguir";
        cin.get();

    }
    else if(Bala_choice.get_estado() == '1')
    {
        std::cout<<"Pumm..."<<std::endl;
        std::cout<<"Esa fue una bala... presiona enter para reanimar";
        cin.get();
        bajar_vida();
    }
    else
    {
        std::cout<<"Algo paso que escogio una bala vacia";
        cin.get();
    }
    Mesa[indice-1].desactivar_bala();
}
Bot::Bot(std::string& Nombre,int vidas,char Estado) : Jugador(Nombre,vidas,Estado){

}
int Bot::determinar_choice(int size_mesa,Bala* Mesa)
{
    int choice;
    while(true)
    {
        choice = rand() % (size_mesa + 1);
        if((Mesa[choice].get_estado() == '0') || (Mesa[choice].get_estado() == '1'))
        {
            break;
        }
        else
        {
            continue;
        }
    }
    return choice;

}
Bot::~Bot(){

}
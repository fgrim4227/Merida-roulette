#include "Funciones.hh"

void mesa_vacia(){
    // Primera parte: La persona al otro lado de la mesa
    std::cout << "        " << RED_PLAYER_COLOR << " ( ) " << RESET << std::endl; // Cabeza
    std::cout << "        " << RED_PLAYER_COLOR << "/ | \\" << RESET << std::endl; // Brazos y cuerpo
    std::cout << "        " << RED_PLAYER_COLOR << " / \\ " << RESET << std::endl; // Piernas

    // Separador para la persona y la mesa
    std::cout << std::endl; // Espacio entre la persona y la mesa

    // Segunda parte: La mesa
    // Línea superior de la mesa
    std::cout << WHITE_TEXT << "  +-------------------+" << RESET << std::endl;
    // Superficie de la mesa (con relleno gris)
    for (int i = 0; i < 3; ++i) { // Tres líneas para la profundidad de la mesa
        std::cout << WHITE_TEXT << "  |" << GRAY_TEXT << "                   " << WHITE_TEXT << "|" << RESET << std::endl;
    }
    // Línea inferior de la mesa (opcional, para darle más cuerpo)
    std::cout << WHITE_TEXT << "  +-------------------+" << RESET << std::endl;
    std::cout << "        " << GREEN_PLAYER_COLOR << " ( ) " << RESET << std::endl; // Cabeza
    std::cout << "        " << GREEN_PLAYER_COLOR << "/ | \\" << RESET << std::endl; // Brazos y cuerpo
    std::cout << "        " << GREEN_PLAYER_COLOR << " / \\ " << RESET << std::endl; // Piernas

}
void limpiar_pantalla(){
    cout<<CLEAR_SCREEN;
    cout<<GOTO_TOP_LEFT;
}
void mesa_full(Bala* Mesa,int n_balas){
    // Primera parte: La persona al otro lado de la mesa
    std::cout << "        " << RED_PLAYER_COLOR << " ( ) " << RESET << std::endl; // Cabeza
    std::cout << "        " << RED_PLAYER_COLOR << "/ | \\" << RESET << std::endl; // Brazos y cuerpo
    std::cout << "        " << RED_PLAYER_COLOR << " / \\ " << RESET << std::endl; // Piernas

    // Separador para la persona y la mesa
    std::cout << std::endl; // Espacio entre la persona y la mesa
    // Segunda parte: La mesa
    // Línea superior de la mesa
    std::cout << WHITE_TEXT << "  +-------------------+" << RESET << std::endl;
    // Superficie de la mesa (con relleno gris)
    int multiplicador = 1;
    int probar_mesa = 0;
    for (int i = 0; i < 3; ++i) { // Tres líneas para la profundidad de la mesa
        if(i == 1)
        {
            std::cout << WHITE_TEXT << "  |"<<WHITE_TEXT ;
            for(int k = 0; k <= 18; k++)
            {
                if((i != 0) && (i != 18))
                {
                    if((k == (18/(n_balas + 1)*multiplicador)) && ((Mesa[probar_mesa].get_estado() == '0') || ((Mesa[probar_mesa].get_estado() == '1'))))
                    {
                        /*if(Mesa[probar_mesa].get_estado() == '0')
                        {
                            cout<<WHITE_TEXT <<"*"<<WHITE_TEXT ;
                        }
                        else
                        {
                            cout<<RED_PLAYER_COLOR <<"*"<<RED_PLAYER_COLOR ;
                        }
                        multiplicador++;*/
                        probar_mesa++;
                        cout<<WHITE_TEXT <<(probar_mesa)<<WHITE_TEXT ;
                        multiplicador++;
                    }
                    else if((Mesa[probar_mesa].get_estado() == '3'))
                    {
                        probar_mesa++;
                        cout<<WHITE_TEXT <<" "<<WHITE_TEXT ;
                    }
                    else
                    {
                        cout<<WHITE_TEXT <<" "<<WHITE_TEXT ;
                    }
                }
                else
                {
                    cout<<WHITE_TEXT <<" "<<WHITE_TEXT ;
                }
            }
            std::cout<<WHITE_TEXT <<"|"<< WHITE_TEXT << endl;
        }
        else
        {
             std::cout << WHITE_TEXT << "  |" << GRAY_TEXT <<"                   " << WHITE_TEXT << "|" << RESET << std::endl;
        }
    }
    // Línea inferior de la mesa (opcional, para darle más cuerpo)
    std::cout << WHITE_TEXT << "  +-------------------+" << RESET << std::endl;
    std::cout << "        " << GREEN_PLAYER_COLOR << " ( ) " << RESET << std::endl; // Cabeza
    std::cout << "        " << GREEN_PLAYER_COLOR << "/ | \\" << RESET << std::endl; // Brazos y cuerpo
    std::cout << "        " << GREEN_PLAYER_COLOR << " / \\ " << RESET << std::endl; // Piernas

}
void start_mesa(Bala* Mesa,int size_mesa){
    for (size_t i = 0; i < size_mesa; i++)
    {
        Mesa[i] = Bala();
    }
    
}
void destruir_mesa(Bala* Mesa,int size_mesa){
    for (size_t i = 0; i < size_mesa; i++)
    {
        Mesa[i].~Bala();
    }
    
}
int status_mesa(Bala Mesa[],int size_mesa){
    int chequeo = 1; //Si retorna 1 es que la mesa esta vacia y termina la ronda
    for (int i = 0; i < size_mesa; i++)
    {
        if((Mesa[i].get_estado() == '0') || (Mesa[i].get_estado() == '1'))
        {
            chequeo = 0;
            break;
        }
    }
    return chequeo;
    
}
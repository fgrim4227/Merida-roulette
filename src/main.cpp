#include "class.hh"
#include "Funciones.hh"
#include <limits>
int main(){
    limpiar_pantalla();
    srand(time(0));
    mesa_vacia();
    std::cout << "\nBienvenido, cual es tu nombre?" << std::endl;
    string player;
    std::cin>>player;
    Bala* Mesa = nullptr;
    string rob_name = "Rob";
    Jugador p1(player,5,'3');
    Bot rob(rob_name,6,1);
    int rob_choice;
    char opcion = 1;
    int n_balas;
    int opcion_bala;
    int status_table = 1;
    char seguro_opcion_salida;
    do
    {
        if(Mesa != nullptr)
        {
            delete[] Mesa;
            Mesa = nullptr;
        }
        cout<<"Con cuantas balas quieres comenzar? "<<endl;
        std::cin>>n_balas;
        if (n_balas <= 0) {
            std::cout << "El numero de balas debe ser positivo. Intenta de nuevo." << std::endl;
            // Podrías añadir un continue para volver al inicio del bucle
            continue;
        }
        // 2. ASIGNAR MEMORIA DINÁMICAMENTE para el arreglo de Balas
        // Se crea un arreglo de 'n_balas' objetos Bala.
        // Los constructores por defecto de Bala se llaman automáticamente para cada uno.
        Bala* Mesa = new Bala[(n_balas-1)]; // <--- ¡AQUÍ ESTÁ LA ASIGNACIÓN!

        // Tu función start_mesa probablemente espera el tamaño completo (n_balas)
        // No (n_balas-1), a menos que tu lógica sea para usar n_balas como índice máximo.
        // Lo común es pasar el tamaño total del arreglo.
        start_mesa(Mesa, n_balas); // Pasa el arreglo y su tamaño total
        do
        {
            limpiar_pantalla();
            mesa_full(Mesa,(n_balas-1)); // Pasa el arreglo y su tamaño total
            // Bucle para seguir pidiendo entrada hasta que sea válida
            while (true) 
            {
                cout<<"Selecciona cual bala quieres probar, comienza en uno y de ahi vas contando: "<<endl;
                std::cin >> opcion_bala;
        
                // 1. Verificar si la lectura fue exitosa (no hay error de tipo)
                if (std::cin.fail()) {
                    std::cout << "Entrada invalida. Eso no es un numero entero. ";
                    // 2. Limpiar el flag de error del flujo (sin esto, cin seguirá fallando)
                    std::cin.clear();
                    // 3. Ignorar/descartar los caracteres restantes en el buffer de entrada
                    // (hasta el final de la línea o un número máximo de caracteres)
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Por favor, intenta de nuevo." << std::endl;
                }
                // Opcional: Añadir validaciones de rango si el número debe estar entre min y max
                else if (opcion_bala < 1 || opcion_bala > n_balas) { // Ejemplo: número entre 1 y 100
                    std::cout << "El numero debe estar entre 1 y el numero de balas. Por favor, intenta de nuevo." << std::endl;
                    // No se necesita clear/ignore aquí, ya que la lectura del entero fue exitosa.
                }
                else {
                    // La entrada es un entero válido y está dentro del rango (si se aplica)
                    break; // Salir del bucle porque la entrada es buena
                }
            }
            p1.elegir_ronda(Mesa[(opcion_bala-1)],Mesa,opcion_bala);
            cin.get();
            limpiar_pantalla();
            status_table = status_mesa(Mesa,(n_balas-1));
            if(status_table == 1)
            {
                break;
            }
            mesa_full(Mesa,n_balas);
            cout<<"Turno de robert... ";
            cin.get();
            rob_choice = rob.determinar_choice((n_balas-1),Mesa);
            rob.elegir_ronda(Mesa[rob_choice],Mesa,(rob_choice + 1));
            limpiar_pantalla();
            mesa_full(Mesa,n_balas);
            status_table = status_mesa(Mesa,(n_balas-1));
        } while (status_table != 1);   
        std::cout<<"Se acabaron las balas, quieres darle otra ronda? "<<std::endl;
        std::cout<<"1 para si, 2 para irte "<<std::endl;
        cin>>seguro_opcion_salida;
        if(seguro_opcion_salida == '1')
        {
            opcion = 1;
        }
        else if(seguro_opcion_salida == '2')
        {
            opcion = 2;
        }
        else
        {
            std::cout<<"opcion invalida, termina el juego"<<endl;
            opcion = 2;
        }
    } while (opcion != 2);
    if(Mesa != nullptr)
    {
        delete[] Mesa;
        Mesa = nullptr;
    }
    return 0;
}
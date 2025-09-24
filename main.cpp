#include <iostream>
#include <string>

void menu();

int main() {
    // Tamaño de los vectores predefinido en variable
    int tam = 6;
    int accion;
    bool entrada_valida;

    int codigo[tam] = {101, 102, 103, 104, 105, 106};
    std::string nombre[tam] = {
        "Torinillos para madera",
        "Cinta de color negro",
        "Destornillador plano",
        "taladro eléctrico gris",
        "Martillo de carpintero",
        "Bombilla ahorradora"
    };
    int stock[tam] = {100, 20, 10, 5, 15, 30};
    float precio[tam] = {4.0f, 35.0f, 40.0f, 499.9f, 45.0f, 49.9f};

    std::cout<<"\tBienvenido a Ferretería el Martillo"<<std::endl;

    do{menu();
        std::cin>>accion;

        // Validación si falló la lectura
        if(std::cin.fail()){
            std::cout<<"Error: Valor invalido, no entero. Favor de ingresar numero entero"<<std::endl;
            
            // Limpia los marcadoresde error
            std::cin.clear();
            
            // Descarta la entrada incorrecta del buffer
            std::cin.ignore(1024, '\n');

            /*
                1024 -> Son los carácteres maximos que va (y puede) a descartar el ignore()
                \n   -> Es una delimitacion, detentra el descarte cuando vea un salto de linea
                        independientemente de ya fueron los 1024 carácteres
            */

            continue;
        }

        switch(accion){
            case 1: // consulta
                int cod_entrada;

                // Ciclo de Validación del codigo ingresado
                do{
                    std::cout<<"\nIngrese codigo de producto: ";
                    std::cin>>cod_entrada;

                    // Validación de fallo de lectura
                    if(std::cin.fail()){
                        std::cout<<"Error: Valor invalido, no entero. Favor de ingresar numero entero"<<std::endl;
                        std::cin.clear();
                        std::cin.ignore(1024, '\n');

                        entrada_valida = false;
                    } else { // Lectura correcta
                        entrada_valida = true;
                    }
                } while(!entrada_valida);

                // Busqueda del codigo y muestreo de datos
                bool cod_encontrado;
                for(int i = 0; i < tam; i++){
                    if(cod_entrada == codigo[i]){
                        std::cout<<"\nInformación del producto - - - -"<<std::endl;
                        std::cout<<"Código: "<<codigo[i]<<std::endl;
                        std::cout<<"Nombre: "<<nombre[i]<<std::endl;
                        std::cout<<"Cantidad en stock: "<<stock[i]<<std::endl;
                        std::cout<<"Precio Unitario: $"<<precio[i]<<std::endl;

                        cod_encontrado = true;
                        break; // Cerramos ciclo para no gastar recurso
                    } else {
                        cod_encontrado = false;
                    }
                }

                if (!cod_encontrado){
                    std::cout<<"\nError: No hay un producto con el codigo "<<cod_entrada<<std::endl;
                }
            break;
            case 2:
            break;
            case 3:
            break;
            case 4:
            break;
            case 5:
            break;
            default:
                std::cout<<"Error: La opción no esta en el menú"<<std::endl;
            break;
        }

        // Limpialos el cin cada que iteramos para evitar errores
        std::cin.clear();
        std::cin.ignore(1024, '\n');

    } while(accion != 5);



    
    return 0;
}

void menu(){
    std::cout<<"\n- - - M e n ú - - -"<<std::endl<<std::endl;
    std::cout<<"1. Consultar un producto"<<std::endl;
    std::cout<<"2. Actualizar inventario"<<std::endl;
    std::cout<<"3. Generar reporte completo"<<std::endl;
    std::cout<<"4. Encontrar el producto más caro"<<std::endl;
    std::cout<<"5. Salir"<<std::endl;

    std::cout<<"\nOpción seleccionada: ";
}
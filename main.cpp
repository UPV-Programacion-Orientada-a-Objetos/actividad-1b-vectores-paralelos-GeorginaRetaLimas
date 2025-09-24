#include <iostream>
#include <string>

void menu();
int validarEntradaEnteros(std::string texto);
int buscarIndiceCodigo(int cod_entrada, int* codigo, int tam);

int main() {
    // Tamaño de los vectores predefinido en variable
    int tam = 6;
    int accion, cod_entrada, index;
    bool valor_valido;

    int codigo[tam] = {101, 102, 103, 104, 105, 106};
    std::string nombre[tam] = {
        "Torinillos de metal",
        "Cinta de color negro",
        "Destornillador plano",
        "Taladro eléctrico",
        "Martillo carpintero",
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

            //1024 -> Son los carácteres maximos que va (y puede) a descartar el ignore()
            //\n   -> Es una delimitacion, detentra el descarte cuando vea un salto de linea
            //            independientemente de ya fueron los 1024 carácteres

            continue;
        }

        switch(accion){
            case 1: // consulta

                // Validamos que el codigo de entrada sea valido
                cod_entrada = validarEntradaEnteros("Ingrese el código del producto");

                // Buscamos el indice del producto del codigo, si no lo encuentra retorna tam
                index = buscarIndiceCodigo(cod_entrada, codigo, tam);

                // Si retorno tam es porque no encontro el codigo
                if(index == tam){
                   std::cout<<"\nError: No hay un producto con el codigo "<<cod_entrada<<std::endl; 
                } else { // Lo encontro
                    std::cout<<"\nInformación del producto - - - -"<<std::endl;
                    std::cout<<"Código: "<<codigo[index]<<std::endl;
                    std::cout<<"Nombre: "<<nombre[index]<<std::endl;
                    std::cout<<"Cantidad en stock: "<<stock[index]<<std::endl;
                    std::cout<<"Precio Unitario: $"<<precio[index]<<std::endl;
                }
            break;
            case 2: // Actualizar inventario
                cod_entrada = validarEntradaEnteros("Ingrese el código del producto");
                index = buscarIndiceCodigo(cod_entrada, codigo, tam);

                if(index == tam){
                   std::cout<<"\nError: No hay un producto con el codigo "<<cod_entrada<<std::endl; 
                } else {
                    std::cout<<"\nInformación del producto - - - -"<<std::endl;
                    std::cout<<"Nombre: "<<nombre[index]<<std::endl;
                    std::cout<<"Cantidad actual en stock: "<<stock[index]<<std::endl;

                    // Ciclo para validar que no se ingrese un stock negativo
                    do{
                        int cambio = validarEntradaEnteros("Ingrese la cantidad de cambio");
                        int nuevo_stock = stock[index] + cambio;

                        if(nuevo_stock < 0){
                            std::cout<<"Error: No se puede tener un stock negativo"<<std::endl;
                            valor_valido = false;
                        } else {
                            // En caso que no sea menor a 0 se actualiza
                            stock[index] = nuevo_stock;
                            valor_valido = true;
                        }

                    } while(!valor_valido);

                    std::cout<<"Stock actualizado correctamente..."<<std::endl;
                }
            break;
            case 3: // Generación de reportes
                std::cout<<"\n-- R E P O R T E  D E  T O D O  P R O D U C T O --"<<std::endl;
                std::cout<<"+-------+-----------------------+-------+-------+"<<std::endl;
                for(int i = 0; i < tam; i++){
                    //codigo nombre stock precio
                    std::cout<<"| "<<codigo[i]<<"\t| "<< nombre[i] <<"\t| "<<stock[i]<<"\t| "<< precio[i] <<"\t|"<<std::endl;
                }
                std::cout<<"+-------+-----------------------+-------+-------+"<<std::endl;
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

int validarEntradaEnteros(std::string texto){
    int cod_entrada;
    bool entrada_valida;

    // Ciclo de Validación del codigo ingresado
    do{
        std::cout<<"\n"<<texto<<": ";
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

    return cod_entrada;
}

int buscarIndiceCodigo(int cod_entrada, int* codigo, int tam){
    int index;
    
    bool cod_encontrado = false;

    // Usamos un for para buscar una coincidencia en la entrada y codigo
    for(int i = 0; i < tam; i++){
        if(cod_entrada == codigo[i]){
            cod_encontrado = true;
            index = i; // Pasamos el index
            break; // Cerramos el ciclo
        } else {
            cod_encontrado = false;
        }
    }

    // Si no encuentra nada asignamos el valor del tamaño
    if (!cod_encontrado){
        index = tam;
    }

    return index;
}
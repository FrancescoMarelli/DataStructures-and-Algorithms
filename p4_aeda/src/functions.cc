#include <iostream>

#include "../include/hashTable.h"

//how to create a namespace with all the functions
namespace functions {
unsigned selectTableSize(unsigned tableSize) {
    std::cout << "Crea una tabla hash, generalmente un numero primo o con pocos divisores" << std::endl;
    std::cout << "Introduzca el tamaño de la tabla: " ;
    if(std::cin >> tableSize) {
        return tableSize;
    } else {
        throw std::invalid_argument("El tamaño de la tabla debe ser un número");
        return 0;
    }
    std::cout << std::endl;
}

template <class Key>
DispersionFunction<Key>* selectDispersionFunction(DispersionFunction<Key>* fd, unsigned tableSize) {
    std::cout << "Ahora seleccione la función de dispersión que desea usar: " << std::endl;
    std::cout << "1. FdModule" << std::endl;
    std::cout << "2. FdPseudoRandom" << std::endl;
    std::cout << "3. FdSum" << std::endl;
    std::cout << "Si no escoges entre las tres opciones por defecto se usará la FdModule" << std::endl;
    int command = 0;
    if(!(std::cin >> command))
        throw std::invalid_argument("Tienes que escoger un numero entre 1 y 3"); 

        switch (command) {
            case 1: 
                fd = new FdModule<long>(tableSize);
                break;
            case 2:
                fd = new FdPseudo<long>(tableSize);
                break;
            case 3:
                fd = new FdSum<long>(tableSize);
                break;
            default:
                fd = new FdModule<long>(tableSize);
                break;
        }
        std::cout << std::endl;
    return fd;
}

int selectDispersionType(){
    bool quit = false;
    int disp_op = 1;
    while(!quit) {
        std::cout << "Con que tipo de Dispersión vas a trabajar? " << std::endl;
        std::cout << "1. Abierta" << std::endl;
        std::cout << "2. Cerrada" << std::endl;
        
        if(!(std::cin >> disp_op))
            throw std::invalid_argument("Puedes elegir entre 1 y 2");
        
            if (disp_op == 1) {
                std::cout << "Elegiste la dispersión abierta" << std::endl;
                quit = true;
            } else if (disp_op == 2){
                std::cout << "Elegiste la Dispersión cerrada" << std::endl;
                quit = true;
            } else {
                std::cout << "Opción no válida, Vuelve a elegir: " << std::endl;
                std::cin >> disp_op;
                if(disp_op == 1 || disp_op == 2)
                    quit = true;
            }
        }
        return disp_op;
}

template <class Key>
ExplorationFunction<Key>* selectExplorationFunction(ExplorationFunction<Key>* fe, DispersionFunction<Key>* fd) {

    std::cout << "Ahora seleccione la función de exploración que desea usar: " << std::endl;
    std::cout << "1. Lineal" << std::endl;
    std::cout << "2. Cuadrática" << std::endl;
    std::cout << "3. Doble" << std::endl;
    std::cout << "4. Redispersión" << std::endl;
    std::cout << "Si no escoges entre las tres opciones por defecto se usará la Lineal" << std::endl;
    int command = 0;
    if(!(std::cin >> command))
        throw std::invalid_argument("Tienes que escoger un numero entre 1 y 3"); 

        switch (command) {
            case 1: 
                fe = new FeLineal<Key>();
                break;
            case 2:
                fe = new FeSquared<Key>();
                break;
            case 3:
                fe = new FeDoubleDispersion<Key>(fd);
                break;
            case 4:
                fe = new FeRedispersion<Key>(fd);
                break;
            default:
                fe = new FeLineal<Key>();
                break;
        }
        std::cout << std::endl;
    return fe;
}

unsigned selectBlock(unsigned blockSize) {
    std::cout << "Con una Dispersión cerrada hace falta más información: " << std::endl;
    std::cout << "Especificar el tamaño de los bloques con los que se quiere trabajar: " << std::endl;
    if(!(std::cin >> blockSize))
        throw std::invalid_argument("El tamaño de los bloques debe ser un número");
    return blockSize;
}

template <class Key>
void Menu(HashTable<Key>& hashTable) {

    
    
    bool quit = false;
    while (!quit) {
        int option = 0;
        long key = 0;

        std::cout << "¿Qué deseas realizar en la tabla hash?" << std::endl;
        std::cout << "1. Insertar un elemento" << std::endl;
        std::cout << "2. Buscar un elemento" << std::endl;
        std::cout << "3. Mostrar la tabla" << std::endl;
        std::cout << "4. Salir" << std::endl;
        std::cout << "Introduzca una opción: " << std::endl;
       
        if(!(std::cin >> option)) {
            throw std::invalid_argument("La opción debe ser un número");
        } 
        if(option != 1 && option != 2 && option != 3 && option != 4) {
            std::cout << "La opción debe ser un número entre 1 y 4" << std::endl;
            std::cin >> option;
        }

        switch (option) {
        case 1: {
            int dig = 0;
            std::cout << "Especificar la clave de 7 digitos a insertar : " << std::endl;
            if(!(std::cin >> key))  {
                std::cout << "La clave debe ser un número" << std::endl; 
                std::cin >> key;
            }
            //chequeando que la clave sea de 5 dígitos
                std::string aux_key =std::to_string(key);
                for(auto& i : aux_key) 
                    dig++;

            if(dig == 7) {
                if(hashTable.insert(key)) {
                    std::cout << "La clave insertó correctamente"<< std::endl;
                    std::cout << std::endl;

                    std::ofstream file;
                    file.open("tabla.txt");
                    if(file.is_open()) 
                        file << hashTable;
                     file.close();

                     
                } else {
                    
                    std::cout << "La clave no se pudo insertar en la tabla, el bloque está completo" << std::endl;
                    std::cout << std::endl;
                }
            } else {
                std::cout << "La clave debe ser de 7 dígitos" << std::endl;
                std::cout << std::endl;
            }
            
            
        }
                break;
        case 2:
            std::cout << "Que clave quieres buscar: " << std::endl;
            if(!(std::cin >> key)) {
                std::cout << "La clave debe ser un número" << std::endl;
                std::cin >> key;
            }
            if(hashTable.search(key)) {
                std::cout << "la clave " << key << " se encontró " <<std::endl;
                std::cout << std::endl;
            } else {
                std::cout << "No se encontró la clave" << std::endl;
                std::cout << std::endl;
            }
            break;
        case 3: {
            std::cout << "Mostrando la tabla" << std::endl;
            hashTable.print();
            std::ofstream file;
            file.open("tabla.txt");
            if(file.is_open()) {
                file << hashTable;
            }
            file.close();
        }
            break;

        case 4:
            std::cout << "Saliendo..." << std::endl;
            quit = true;
            break;
    
        default:
            std::cout << "Error en teclear la opción" << std::endl;
            quit = true;
            break;
        }
    } //end while
    } //end function
}// end namespace

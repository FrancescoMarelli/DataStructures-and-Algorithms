#include <iostream>
#include <fstream>

#include "../include/AB.h"

/**
 * @brief 
  *
  * @details program gestiona los arboles creados, las inserciones etc
  * 
**/
void program() {
  int option = 0;  
  long value = 0;
  bool quit = false; 
  AB<long> *arbol = nullptr;

  quit = false;
  while (!quit) {

    std::cout << std::endl; 
    std::cout << "Qué te gustaría hacer: " << std::endl;
    std::cout << "[1] Usar árbol binario de búsqueda (ABB)" << std::endl;
    std::cout << "[2] Usar árbol AVL" << std::endl;
    std::cout << "→ ";

    if(!(std::cin >> option)) {
      std::cout << "Opción no válida" << std::endl;
      std::cin.clear();
      std::cin.ignore(10000, '\n');
      continue;
    }

    switch (option) {
      case 1: 
        arbol = new ABB<long>;
        quit = true;
        break;
      case 2:
        arbol = new AVL<long>;
        quit = true;
        break;
      default:
        break;
    }
  }

  // Menú
  quit = false;
  while (!quit) {
    std::cout << std::endl; 
    std::cout << "Qué te gustaría hacer: " << std::endl;
    std::cout << "[0] Salir" << std::endl;
    std::cout << "[1] Insertar clave" << std::endl;
    std::cout << "[2] Buscar clave" << std::endl;
    std::cout << "[3] Mostrar árbol en inorden" << std::endl;
    std::cout << "[4] Mostrar árbol en preorden" << std::endl;
    std::cout << "[5] Mostrar árbol en postorden" << std::endl;
    std::cout << "[6] Borra el arbol anterior y crea un arbol nuevo" << std::endl;
    std::cout << "→ ";
    while(!(std::cin >> option)) {
      std::cout << "Opción no válida" << std::endl;
      std::cin.clear();
      std::cin.ignore(10000, '\n');
      std::cout << "→ ";
    }

    switch (option) {
      case 0:
        quit = true;        
        break;   
      case 1:
        std::cout << "¿Que clave quieres insertar?" << std::endl;
        std::cout << "→  ";
        std::cin >> value;
        if (arbol->insertar(value)) {
          std::cout << "La clave se pudo insertar" << std::endl;
          arbol->operator>>(std::cout); 
        } else {
          std::cout << "La clave no se pudo insertar" << std::endl; 
        }
        std::cout << std::endl;
        break;
      case 2:
        std::cout << "¿Que clave quieres buscar?" << std::endl;
        std::cout << "→  ";
        std::cin >> value;
        if (arbol->buscar(value)) {
          std::cout << "La clave se encuentra en el arbol binario" << std::endl; 
        } else {
          std::cout << "La clave no se encuentra en el arbol binario" << std::endl; 
        }
        std::cout << std::endl;
        break;
      case 3:
        arbol->inorden();
        std::cout << std::endl;
        break;      
      case 4:
        arbol->preorden();
        std::cout << std::endl;
        break;
      case 5:
        arbol->postorden();
        std::cout << std::endl;
        break;
      case 6:
        quit = true;
        arbol->podarArbol();
        std::cout << std::endl;
        program();
        break;
      default:
        break;        
    }
  }  
  
  delete arbol;
}


/**
 * @brief Programa principal
 * @return int
 * 
 * @details Llamada a función program que se ocupa de gestionar el programa
 */
int main() {  

  program();

  std::cout << std::endl;
  std::cout << "Programa Finalizado" << std::endl;

  return 0;
}



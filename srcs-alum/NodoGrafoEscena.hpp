#ifndef NODOGRAFOESCENA_H
#define NODOGRAFOESCENA_H

#include <vector>
#include "aux.hpp"
#include "Objeto3D.hpp"
#include "matrices-tr.hpp"
#include "Material.hpp"

// Entradas del nodo de grafo de escena. Puede ser un objeto 3D o una
// transformación representada por el puntero a una matriz.
struct EntradaNGE {
  // Tipo de la entrada
  //  0 - objeto,
  //  1 - transformación,
  //  2 - material.
  unsigned char tipoE;

  union {
    Objeto3D* objeto; 
    Matriz4f* matriz;
    Material* material;
  };

  // Constructores de los dos tipos distintos
  EntradaNGE(Objeto3D* pObjeto) : tipoE(0), objeto(pObjeto) {};
  EntradaNGE(const Matriz4f& pMatriz) : tipoE(1) {
    matriz = new Matriz4f(pMatriz);
  };
  EntradaNGE(Material* pmaterial) : tipoE(2), material(pmaterial) {};
};

// Nodos de grafo de escena.
class NodoGrafoEscena : public Objeto3D {
protected:
  std::vector<EntradaNGE> entradas;
  
public:
  // Visualizar el nodo usando OpenGL, se dibujará recursivamente la
  // estructura compuesta del nodo raíz.
  virtual void visualizarGL(ContextoVis& cv);

  // Añade una entrada al final del nodo, directamente o
  // construyéndola desde un objeto o una matriz.
  void agregar(EntradaNGE* entrada);
  void agregar(Objeto3D* pObjeto);
  void agregar(const Matriz4f& pMatriz);
  void agregar(Material* material);
};

#endif

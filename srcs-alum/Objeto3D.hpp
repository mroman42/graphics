#ifndef OBJETO_3D_HPP
#define OBJETO_3D_HPP

#include <string>
#include "practicas.hpp"
#include "aux.hpp"
#include "matrices-tr.hpp"

// Un objeto 3D es cualquier cosa que pueda ser visualizada
// dentro de OpenGL.
class Objeto3D {
protected:
  // Nombre interno del objeto. Puede usarse para depurar.
  // Debe accederse para lectura desde "nombre()".
  std::string nombre_objeto;

public:
  Objeto3D() : identificador(0), centro_oc(Tupla3f(0,0,0)) {}

  // Identificador del objeto. Se usa un valor 0 para los nodos que no
  // pueden ser seleccionados y se usa un valor -1 para los objetos de
  // tipo nodo cuyo identificador es exactamente el identificador del padre.
  int identificador;
  
  // Punto central del objeto en coordenadas de objeto
  Tupla3f centro_oc; 
  
  // Devuelve el nombre interno del objeto.
  std::string nombre();

  // Visualiza un objeto con el modo de visualización dado.
  virtual void visualizarGL(ContextoVis& cv) = 0;

  // Busca un nodo dado un identificador. Devuelve true si el objeto
  // se ha encontrado y false en otro caso. Los parámetros son
  //
  //  - ident: identificador del objeto buscado, se devuelve un error si es 0 o negativo;
  //  - mmodelado: matriz de modelado del padre, es la identidad en la raíz;
  //  - objeto: parámetro de salida apuntando al objeto encontrado;
  //  - centro_wc: parámetro de salida conteniendo la posición en coordenadas del mundo.
  virtual bool buscarObjeto(const int ident, const Matriz4f& mmodelado, Objeto3D** objeto, Tupla3f& centro_wc);
};

#endif

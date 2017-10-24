#ifndef MALLAIND_H
#define MALLAIND_H

#include "Objeto3D.hpp"
#include "tuplasg.hpp"
#include "aux.hpp"
#include <vector>

// Una malla es un objeto 3D, por lo que hereda de él y
// consta de un método "visualizar" que la dibuja.
class MallaInd : public Objeto3D {
protected:
  // Los objetos derivados de una malla 3D deberían poder modificar
  // los vértices y las caras de la malla.
  std::vector<Tupla3f> vertices;
  std::vector<Tupla3i> caras;

  // Variable lógica que indica si se han creado los VBOs y datos que
  // se añaden para identificar los VBOs y su tamaño.
  bool vbos_creados; // Indica si se han creado los VBOs.
  GLuint id_vbo_ver; // Identifica el VBO con la tabla de vértices.
  GLuint id_vbo_tri; // Identifica el VBO con la tabla de triángulos.
  unsigned tam_ver; // Tamaño de la tabla de vértices.
  unsigned tam_tri; // Tamaño de la tabla de triángulos.
  unsigned num_ver; // Número de vértices
  unsigned num_tri; // Número de triángulos
  
public:
  // Función de visualización de la malla, implementando el método
  // abstracto de un objeto3D.
  void visualizarGL(ContextoVis& cv) override;

  // Creación y visualización de los VBOs
  void crearVBOs();
  void visualizarVBOs();
  
  // Constructor de una malla indexada
  MallaInd(){
    vbos_creados = false; // por defecto, no están creados
  }
};

GLuint VBO_Crear(GLuint tipo, GLuint tamanio, GLvoid* puntero) {
  assert(tipo == GL_ARRAY_BUFFER or tipo == GL_ELEMENT_ARRAY_BUFFER);
  
  GLuint id_vbo; // identificador de VBO
  glGenBuffers(1, &id_vbo); // crea nuevo VBO asociado a identificador
  glBindBuffer(tipo, id_vbo); // activa el nuevo VBO
  glBufferData(tipo, tamanio, puntero, GL_STATIC_DRAW); // transfiere RAM->CPU
  glBindBuffer(tipo, 0); // desactiva el VBO

  return id_vbo;
}

#endif

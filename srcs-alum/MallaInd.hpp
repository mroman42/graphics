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
  std::vector<Tupla3f> vertices; // Tabla de vértices
  std::vector<Tupla3i> caras;    // Tabla de caras
  std::vector<Tupla3f> nor_ver;  // Tabla de normales de vértices
  std::vector<Tupla3f> nor_tri;  // Tabla de normales de triángulos
  std::vector<Tupla3f> col_ver;  // Tabla de colores de vértices
  std::vector<Tupla3f> col_tri;  // Tabla de colores de triángulos
  std::vector<Tupla2f> cctt; // Coordenadas de textura

  // Variable lógica que indica si se han creado los VBOs y datos que
  // se añaden para identificar los VBOs y su tamaño.
  bool vbos_creados; // Indica si se han creado los VBOs.
  GLuint id_vbo_ver; // Identifica el VBO con la tabla de vértices.
  GLuint id_vbo_tri; // Identifica el VBO con la tabla de triángulos.
  GLuint id_vbo_col_ver; // Identifica el VBO con los colores de vértices.
  GLuint id_vbo_nor_ver; // Identifica el VBO con las normales de vértices.
  GLuint id_vbo_cctt; // Identifica el VBO con las coordenadas de textura.
  unsigned tam_ver; // Tamaño de la tabla de vértices.
  unsigned tam_tri; // Tamaño de la tabla de triángulos.
  unsigned num_ver; // Número de vértices
  unsigned num_tri; // Número de triángulos

  float color_r = 0.0; // color en rojo
  float color_g = 0.0; // color en verde
  float color_b = 0.0; // color en azul

  // Visualiza con normales y coordenadas de textura
  void visualizarGL_Textura(ContextoVis& cv);
  void visualizarGL_Textura_VBOs(ContextoVis& cv);
  // Visualiza en modo selección
  void visualizarGL_Seleccion(ContextoVis& cv);
  
public:
  // Función de visualización de la malla, implementando el método
  // abstracto de un objeto3D.
  void visualizarGL(ContextoVis& cv) override;

  // Cálculo de normales
  void calcularNormales();

  // Creación y visualización de los VBOs
  void crearVBOs();
  void visualizarVBOs();
  void visualizarVBOsAtrVer();
  void darColor(float r, float g, float b);
  GLuint VBO_Crear(GLuint tipo, GLuint tamanio, GLvoid* puntero);
  
  // Constructor de una malla indexada
  MallaInd() : color_r(0), color_g(0), color_b(0) {
    vbos_creados = false; // por defecto, no están creados
    color_r = 0.0;
    color_g = 0.0;
    color_b = 0.0;
  }
};

#endif

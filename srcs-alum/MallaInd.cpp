#include "MallaInd.hpp"
#include <vector>

void MallaInd::visualizarGL(ContextoVis& cv) {
  // Implementa los modos distintos del modo ajedrez,
  // que son similares en implementación.
  if (cv.modoVisu == modoPuntos or
      cv.modoVisu == modoAlambre or
      cv.modoVisu == modoSolido) {
    
    // Prepara el array de vértices e indica sobre él la
    // posición inicial y el sentido que llevará.
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, vertices[0]);

    // Escoge el modo de visualización dentro de los tres modos posibles
    // desde este punto. La variable se usará en "glPolygonMode".
    auto polygonmode = GL_POINT;
    switch (cv.modoVisu) {
    case modoPuntos:  polygonmode = GL_POINT; break;
    case modoAlambre: polygonmode = GL_LINE;  break;
    case modoSolido:  polygonmode = GL_FILL;  break;
    default: break;
    }
    glPolygonMode(GL_FRONT_AND_BACK, polygonmode);

    // Dibuja el array de vértices indicando los índices de los
    // triángulos que se dibujarán. Esto es más eficiente que repetir
    // varias veces un mismo punto (glDrawArrays) y que realizar una
    // llamada por vértice (glVertex).
    glDrawElements(GL_TRIANGLES, caras.size()*3, GL_UNSIGNED_INT, caras[0]);

    // Deja de usar el array de vértices.
    glDisableClientState(GL_VERTEX_ARRAY);
  }

  // Modo ajedrez
  else if (cv.modoVisu == modoAjedrez) {
    // Prepara el array de vértices e indica sobre él la
    // posición inicial y el sentido que llevará.
    // Señala además la forma de dibujarlo.
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, vertices[0]);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    // Separa en caras pares e impares
    std::vector<Tupla3i> caras_pares, caras_impares;
    for (unsigned int i=0; i<caras.size(); i++)
      ((i%2 == 0)? caras_pares : caras_impares).push_back(caras[i]);

    // Fija dos colores distintos para dibujar las caras según sean caras
    // o caras impares. Necesita dos llamadas a glDrawElements.
    glColor3f(0.2, 0.2, 0.2);
    glDrawElements(GL_TRIANGLES, caras_pares.size()*3, GL_UNSIGNED_INT, caras_pares[0]);
    glColor3f(0.8, 0.8, 0.8);
    glDrawElements(GL_TRIANGLES, caras_impares.size()*3, GL_UNSIGNED_INT, caras_impares[0]);
    
    // Deja de usar el array de vértices.
    glDisableClientState(GL_VERTEX_ARRAY);
  }
}

void MallaInd::crearVBOs() {
  // Calcula el tamaño de la tabla de vértices y la tabla de
  // triángulos
  num_ver = vertices.size();
  num_tri = caras.size();
  tam_ver = sizeof(float) * 3L * num_ver;
  tam_tri = sizeof(unsigned) * 3L * num_tri;
  
  // Crea un VBO conteniendo una tabla de vértices
  id_vbo_ver = VBO_Crear(GL_ARRAY_BUFFER, tam_ver, vertices.data());

  // Crea un VBO con la tabla de triángulos
  id_vbo_tri = VBO_Crear(GL_ELEMENT_ARRAY_BUFFER, tam_tri, caras.data());
}

void MallaInd::visualizarVBOs() {
  // Especifica el formato de los vértices en su VBO
  glBindBuffer(GL_ARRAY_BUFFER, id_vbo_ver); // indica VBO que se usaa
  glVertexPointer(3,GL_FLOAT,0,0); // indica formato y offset
  glBindBuffer(GL_ARRAY_BUFFER, 0); // desactiva buffer
  glEnableClientState(GL_VERTEX_ARRAY);

  // Visualización usando glDrawElements
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id_vbo_tri); // indica buffer triángulos
  glDrawElements(GL_TRIANGLES, 3L*num_tri, GL_UNSIGNED_INT, NULL); // visualiza
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0); // desactiva buffer

  // Desactiva el uso de arrays de vértices
  glDisableClientState(GL_VERTEX_ARRAY);
}

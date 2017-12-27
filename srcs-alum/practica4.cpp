#include "practica4.hpp"

// Objeto de la práctica
static ObjetoPractica4* objeto_practica_4 = nullptr;
static int angulo_actual = 0;

void P4_Inicializar() {
  // Asigna al puntero el objeto de la práctica 4
  objeto_practica_4 = new ObjetoPractica4();
}

void P4_DibujarObjetos(ContextoVis& cv) {
  // Visualiza el único objeto de la práctica 4
  glEnable(GL_LIGHTING);
  objeto_practica_4 -> visualizarGL(cv);
  glDisable(GL_LIGHTING);
}

bool P4_FGE_PulsarTeclaNormal(unsigned char tecla) {
  if (tecla == 'g' or tecla == 'G') {
    // Conmutar entre ángulo alpha y ángulo beta
    if (angulo_actual == 0) angulo_actual = 1;
    if (angulo_actual == 1) angulo_actual = 0;
  }
  else if (tecla == '<') {
    // Aumentar valor de ángulo actual
    if (angulo_actual == 0) objeto_practica_4->aumentarAlpha();
    if (angulo_actual == 1) objeto_practica_4->aumentarBeta();
  }
  else if (tecla == '>') {
    // Disminuir valor de ángulo actual
    if (angulo_actual == 0) objeto_practica_4->disminuirAlpha();
    if (angulo_actual == 1) objeto_practica_4->disminuirBeta();
  }
  
  return false;
}

// Función de gestión del evento desocupado de la práctica 4. Debe
// devolver
//   - false: si queremos que desactive el evento
//   - true: si queremos que permanezca activado
bool P4_FGE_Desocupado() {
  // Si las animaciones están desactivadas, no es necesario hacer nada
  // y podemos desactivar el evento desocupado. Devolver false
  // desactivará en main el evento desocupado.
  if (not p4_animaciones)
    return false;

  // Modifica los parámetros de la animación según sus
  // velocidades actuales.
  objeto_practica_4 -> siguienteCuadro();

  // Fuerza un evento de redibujado para el siguiente cuadro.
  glutPostRedisplay();

  // Termina, manteniendo activado el evento desocupado. Devolver true
  // mantiene en main el evento desocupado.
  return true;
}

#include "practica5.hpp"

// El objeto jerárquico a visualizar se crea en memoria dinámica y se
// guarda en una variable de la práctica.
static ObjetoPractica4* objeto_practica_5 = nullptr;
static int angulo_actual = 0;

void P5_Inicializar() {
  // Asigna al puntero el objeto de la práctica 5
  objeto_practica_5 = new ObjetoPractica4();
}

void P5_DibujarObjetos(ContextoVis& cv) {
  // Visualiza el único objeto de la práctica 5
  glEnable(GL_LIGHTING);
  objeto_practica_5 -> visualizarGL(cv);
  glDisable(GL_LIGHTING);
}

bool P5_FGE_PulsarTeclaNormal(unsigned char tecla) {
  if (tecla == 'g' or tecla == 'G') {
    // Conmutar entre ángulo alpha y ángulo beta
    if (angulo_actual == 0) {
      std::cout << "Ángulo actual: beta" << std::endl;
      angulo_actual = 1;
      return true;
    }
    else if (angulo_actual == 1) {
      std::cout << "Ángulo actual: alpha" << std::endl;
      angulo_actual = 0;
      return true;
    }
  }
  else if (tecla == '<') {
    // Aumentar valor de ángulo actual
    std::cout << "Aumenta ángulo" << std::endl;
    if (angulo_actual == 0) objeto_practica_5->aumentarAlpha();
    if (angulo_actual == 1) objeto_practica_5->aumentarBeta();
    return true;
  }
  else if (tecla == '>') {
    // Disminuir valor de ángulo actual
    std::cout << "Disminuye ángulo" << std::endl;
    if (angulo_actual == 0) objeto_practica_5->disminuirAlpha();
    if (angulo_actual == 1) objeto_practica_5->disminuirBeta();
    return true;
  }
  
  return false;
}

// Función de gestión del evento desocupado de la práctica 5. Debe
// devolver
//   - false: si queremos que desactive el evento
//   - true: si queremos que permanezca activado
bool P5_FGE_Desocupado() {
  // Si las animaciones están desactivadas, no es necesario hacer nada
  // y podemos desactivar el evento desocupado. Devolver false
  // desactivará en main el evento desocupado.
  if (not p5_animaciones)
    return false;

  // Modifica los parámetros de la animación según sus
  // velocidades actuales.
  objeto_practica_5 -> siguienteCuadro();

  // Fuerza un evento de redibujado para el siguiente cuadro.
  glutPostRedisplay();

  // Termina, manteniendo activado el evento desocupado. Devolver true
  // mantiene en main el evento desocupado.
  return true;
}

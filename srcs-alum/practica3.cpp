#include "practica3.hpp"

// Objeto de la práctica
static ObjetoPractica3* objeto_practica_3 = nullptr;

void P3_Inicializar() {
  // Asigna al puntero el objeto de la práctica 3
  objeto_practica_3 = new ObjetoPractica3();
}

void P3_DibujarObjetos(ContextoVis& cv) {
  // Visualiza el único objeto de la práctica 3
  objeto_practica_3 -> visualizarGL(cv);
}

bool P3_FGE_PulsarTeclaNormal(unsigned char tecla) {
  if (tecla == 'o' or tecla == 'O') {
    return true;
  }
  else if (tecla == 'a' or tecla == 'A') {
    if (p3_animaciones) {
      std::cout << "Desactiva animaciones" << std::endl;
      p3_animaciones = false;
    }
    else {
      std::cout << "Activa animaciones" << std::endl;
      p3_animaciones = true;
    }
    FGE_Desocupado();
    return true;
  }
  else if (tecla == 'g' or tecla == 'G') {
    return true;
  }
  else if (tecla == 'r' or tecla == 'R') {
    return true;
  }
  else if (tecla == '<') {
    // Con las animaciones activadas, aumenta o disminuye la velocidad
    // del grado de libertad actual.
    if (p3_animaciones) {
      
    }
    // Con las animaciones desactivadas, incrementa o disminuye el
    // grado de libertad actual.
    else {
    }
    return true;
  }
  else if (tecla == '>') {
    return true;
  }
  
  return false;
}

// Función de gestión del evento desocupado de la práctica 3. Debe
// devolver
//   - false: si queremos que desactive el evento
//   - true: si queremos que permanezca activado
bool P3_FGE_Desocupado() {
  // Si las animaciones están desactivadas, no es necesario hacer nada
  // y podemos desactivar el evento desocupado. Devolver false
  // desactivará en main el evento desocupado.
  if (not p3_animaciones)
    return false;

  // Modifica los parámetros de la animación según sus
  // velocidades actuales.
  objeto_practica_3 -> siguienteCuadro();

  // Fuerza un evento de redibujado para el siguiente cuadro.
  glutPostRedisplay();

  // Termina, manteniendo activado el evento desocupado. Devolver true
  // mantiene en main el evento desocupado.
  return true;
}

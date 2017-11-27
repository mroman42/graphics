#include "practica3.hpp"

// Objeto de la práctica
static ObjetoPractica3* objeto_practica_3 = nullptr;
static int grado_libertad_actual = 0;
static int grados_libertad = 0;


void P3_Inicializar() {
  // Asigna al puntero el objeto de la práctica 3
  objeto_practica_3 = new ObjetoPractica3();

  // Calcula grados de libertad
  grados_libertad = objeto_practica_3->numParametros();
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
      glutIdleFunc(FGE_Desocupado);
    }

    return true;
  }
  else if (tecla == 'g' or tecla == 'G') {
    // Activa el grado de libertad siguiente al actual
    grado_libertad_actual++;
    grado_libertad_actual = grado_libertad_actual % grados_libertad;

    std::cout << "Grado de libertad " << grado_libertad_actual << ": ";
    std::cout << objeto_practica_3->leerPtrParametro(grado_libertad_actual) -> leer_descripcion();
    std::cout << std::endl;
    return true;
  }
  else if (tecla == 'r' or tecla == 'R') {
    // Desactiva animaciones
    std::cout << "Desactiva animaciones" << std::endl;
    p3_animaciones = false;

    // Resetea todos los parámetros del modelo
    std::cout << "Resetea los parámetros del modelo" << std::endl;
    for (Parametro& p : objeto_practica_3->parametros) {
      p.reset();
    }
    
    return true;
  }
  else if (tecla == '<') {
    // Con las animaciones activadas, aumenta la velocidad del grado
    // de libertad actual.
    if (p3_animaciones) {
      objeto_practica_3->leerPtrParametro(grado_libertad_actual)->acelerar();
      std::cerr << "Velocidad actual: "
		<< objeto_practica_3->leerPtrParametro(grado_libertad_actual)->leer_velocidad_actual()
                << std::endl;
    }
    // Con las animaciones desactivadas, incrementa el grado de
    // libertad actual.
    else {
      objeto_practica_3->leerPtrParametro(grado_libertad_actual)->incrementar();
      std::cerr << "Valor actual: "
		<< objeto_practica_3->leerPtrParametro(grado_libertad_actual)->leer_valor_actual()
	        << std::endl;
    }
    return true;
  }
  else if (tecla == '>') {
    // Con las animaciones activadas, disminuye la velocidad del grado
    // de libertad actual.
    if (p3_animaciones) {
      objeto_practica_3->leerPtrParametro(grado_libertad_actual)->decelerar();
      std::cerr << "Velocidad actual: "
		<< objeto_practica_3->leerPtrParametro(grado_libertad_actual)->leer_velocidad_actual()
                << std::endl;
    }
    // Con las animaciones desactivadas, decrementa el grado de
    // libertad actual.
    else {
      objeto_practica_3->leerPtrParametro(grado_libertad_actual)->decrementar();
      std::cerr << "Valor actual: "
		<< objeto_practica_3->leerPtrParametro(grado_libertad_actual)->leer_valor_actual()
	        << std::endl;
    }
    
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

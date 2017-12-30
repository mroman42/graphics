#include "practica5.hpp"

#include "jpg_readwrite.hpp"

// El objeto jerárquico a visualizar se crea en memoria dinámica y se
// guarda en una variable de la práctica.
static ObjetoPractica4* objeto_practica_5 = nullptr;
static int angulo_actual = 0;

// Posición anterior del ratón
static int xant = 0;
static int yant = 0;

// Cámaras activas actualmente
static std::vector<CamaraInteractiva> camaras;
static int camaraActiva = 0;

// Viewport actual
static Viewport viewport;

// Buffer de selección
//static BufferSeleccion buffer;

static bool modoArrastrar = false;


void P5_Inicializar(int tamx, int tamy) {
  // Asigna al puntero el objeto de la práctica 5, que es el mismo de
  // la práctica 4.
  objeto_practica_5 = new ObjetoPractica4();

  // Debería usar este ratio ???
  float ratio = ((float) tamy) / ((float) tamx);

  // Inicializa la práctica 5 sobre una ventana

  // Crea las cámaras
  // Primera persona
  camaras.push_back(CamaraInteractiva(false, true, ratio, 0, 0, Tupla3f(0,0,0), 40));
  // 2. Alzado: examinar, ortográfica, ratio 2, longlat, atención al origen, distancia
  camaras.push_back(CamaraInteractiva(true, false, ratio, 90, 0, Tupla3f(0,0,0)));
  // 1. Frente: examinar, perspectiva, ratio 1, longlat, atención al origen
  camaras.push_back(CamaraInteractiva(true, true, ratio, 0, 0, Tupla3f(0,0,0), 40));
  // 3. Perfil: examinar, perspectiva, ratio 1, longlat, atención al origen
  camaras.push_back(CamaraInteractiva(true, true, ratio, 0, 90, Tupla3f(0,0,0), 40));

  // Crea el viewport con los parámetros que ha recibido desde main
  viewport = Viewport(0,0,tamx,tamy);
}

void P5_DibujarObjetos(ContextoVis& cv) {
  // Visualiza el único objeto de la práctica 5
  glEnable(GL_LIGHTING);
  objeto_practica_5 -> visualizarGL(cv);
  glDisable(GL_LIGHTING);
}

bool P5_FGE_PulsarTeclaNormal(unsigned char tecla) {
  if (tecla == 'c' or tecla == 'C') {
    // Cambia la cámara activa
    camaraActiva++;
    camaraActiva %= camaras.size();
    std::cout << "Cámara activa: " << camaraActiva << std::endl;
    return true;
  }
  else if (tecla == 'w' or tecla == 'W' or tecla == 'v' or tecla == 'V') {
    // Cambia entre modo examinar y modo primera persona
    if (camaras[camaraActiva].examinar) {
      camaras[camaraActiva].modoPrimeraPersona();
      std::cout << "Cámara activa: " << camaraActiva << " en modo Primera Persona." << std::endl;
    }
    else {
      camaras[camaraActiva].modoExaminar();
      std::cout << "Cámara activa: " << camaraActiva << " en modo Examinar." << std::endl;
    }

    return true;
  }
  else if (tecla == '+' or tecla == '(') {
    // Acerca
    std::cout << "Acerca la cámara" << std::endl;
    camaras[camaraActiva].desplaZ(1);
    return true;
  }
  else if (tecla == '-' or tecla == ')') {
    // Aleja
    std::cout << "Aleja la cámara" << std::endl;
    camaras[camaraActiva].desplaZ(-1);
    return true;
  }
  
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

bool P5_FGE_PulsarTeclaEspecial(unsigned char tecla) {
  bool redibujar = false;
  
  if (tecla == GLUT_KEY_LEFT or tecla == 'j') {
    std::cout << "Movimiento a izquierda" << std::endl;
    camaras[camaraActiva].moverHV(-1,0);
    redibujar = true;
  }
  else if (tecla == GLUT_KEY_RIGHT or tecla == 'l') {
    std::cout << "Movimiento a derecha" << std::endl;
    camaras[camaraActiva].moverHV(1,0);
    redibujar = true;
  }
  else if (tecla == GLUT_KEY_DOWN or tecla == 'k') {
    std::cout << "Movimiento abajo" << std::endl;
    camaras[camaraActiva].moverHV(0,-1);
    redibujar = true;
  }
  else if (tecla == GLUT_KEY_UP or tecla == 'i') {
    std::cout << "Movimiento arriba" << std::endl;
    camaras[camaraActiva].moverHV(0,1);
    redibujar = true;
  }

  return redibujar;
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

// Procesa el click del ratón, determinando el botón que se ha pulsado.
bool P5_FGE_ClickRaton(int button, int state, int x, int y) {
  if (button == GLUT_LEFT_BUTTON and state == GLUT_DOWN)
    return P5_ClickIzquierdo(x,y);
  else if (button == GLUT_RIGHT_BUTTON and state == GLUT_DOWN)
    P5_InicioModoArrastrar(x,y);
  else if (button == GLUT_RIGHT_BUTTON and state == GLUT_UP)
    modoArrastrar = false;

  return true;
}

// Calcula el objeto sobre el que se ha hecho el click. Si hay alguno
// seleccionado pone la cámara activa mirando a dicho objeto en modo
// examinar y devuelve true, en otro caso devuelve false
bool P5_ClickIzquierdo(int x, int y) {
  // ???
  std::cout << "Click izquierdo en: (" << x << ", " << y << ")" << std::endl;

  // Implementación con BufferSeleccion
  // // Calcular el objeto sobre el que se ha hecho click ???
  // // NodoGrafoEscena* obj = objeto_practica_5 -> buscarNodo();
  // // buffer.inicioModoSel();
  // // glutPostRedisplay();
  // // buffer.finModoSel();
  // // std::cout << "Nombre seleccionado: ";
  // // for (int i=0; i<buffer.longNombreMin; i++)
  // //   std::cout << buffer.nombreMin[i];
  // // Poner la cámara mirando al objeto en modo examinar

  // Implementamos la selección usando el frame-buffer trasero.
  // 1. Fijamos el color del fondo de pantalla a (0,0,0)
  

  // 2. Activamos el modo selección y visualizamos la escena.

  // Visualiza la escena en modo selección sobre el buffer GL_BACK,
  // desactivando todo lo que pueda ser conflictivo con los colores
  // puros y limpiando previamente el buffer.
  glBindFramebuffer(GL_FRAMEBUFFER, GL_BACK);
  glDisable(GL_LIGHTING);
  glDisable(GL_TEXTURE_2D);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  
  ContextoVis cvsel;
  cvsel.modoVisu = modoSeleccion;
  objeto_practica_5 -> visualizarGL(cvsel);
  glutPostRedisplay();

  // Lee en la visualización en modo selección el pixel dado.
  unsigned ident = LeerIdentEnPixel(x,glutGet(GLUT_WINDOW_HEIGHT) - y);
  glBindFramebuffer(GL_FRAMEBUFFER, 0);
  
  std::cerr << "Identificador de pixel: " << ident << std::endl;

  
  
  // GLint drawFboId = 0, readFboId = 0;
  // glGetIntegerv(GL_DRAW_FRAMEBUFFER_BINDING, &drawFboId);
  // glGetIntegerv(GL_READ_FRAMEBUFFER_BINDING, &readFboId);
  // std::cout << "Current draw: " << drawFboId << std::endl;
  // std::cout << "Current read: " << readFboId << std::endl;
  

  // // DEBUG: Exporta en una imagen
  // unsigned char pixels[200*200*3] = {0};
  // glReadPixels(x, y, 200, 200, GL_RGB, GL_UNSIGNED_BYTE, pixels);
  // std::string nombrearchivo = "./frame-test.jpg";
  // jpg::JpegFile::RGBToJpegFile(nombrearchivo.c_str(), pixels,200,200,1,100);

  // Devuelve el framebuffer

  // glDeleteFramebuffers(1, fbo);


  // 3. Determinamos si se ha seleccionado algún objeto comprobando si
  // el color del pixel sobre el que se hace click es 0.

  
  // 4. Caso de que no se haya encontrado objeto.

  // 5. Buscar por el identificador del objeto.

  // 6. Pasa la cámara al modo examinar en el objeto seleccionado.
  
  return false;
}

// Entra en modo arrastrar, registra donde se ha iniciado el movimiento
void P5_InicioModoArrastrar(int x, int y) {
  modoArrastrar = true;
  
  // Registra la posición de inicio del arrastre
  xant = x;
  yant = y;
}

bool P5_FGE_RatonMovidoPulsado(int x, int y) {
  // Verifica si el botón pulsado es el botón derecho y en ese caso
  // invoca la función de arrastre
  
  // ??? Cómo lo va a verificar
  if (modoArrastrar)
    P5_RatonArrastradoHasta(x,y);

  return true;
}

void P5_RatonArrastradoHasta(int x, int y) {
  // Calcula la diferencia de distancias
  int dx = x - xant;
  int dy = y - yant;
  xant = x;
  yant = y;
  
  // Coloca la cámara según esa misma diferencia
  camaras[camaraActiva].moverHV(dx,dy);
}

void P5_FijarMVPOpenGL(int vpx, int vpy) {
  // Actualiza el Viewport y cambia el ratio del viewfrustum de la
  // cámara; con esto, fija matrices en OpenGL.
  viewport = Viewport(0,0,vpx,vpy);
  viewport.fijarViewport(); // ??? tiene sentido usar el viewport así?
  camaras[camaraActiva].ratio_yx_vp = ((float) vpy) / ((float) vpx);
  camaras[camaraActiva].calcularViewfrustum();
  camaras[camaraActiva].fijarMVPogl();
}

void FijarColorIdent(const int ident) {
  // Asigna un color sacado exactamente del identificador del objeto.
  if (ident != -1) {
    const unsigned char byteR = (ident           ) % 0x100U; // rojo,  byte menos significativo
    const unsigned char byteG = (ident /   0x100U) % 0x100U; // verde, byte intermedio
    const unsigned char byteB = (ident / 0x10000U) % 0x100U; // azul,  byte más significativo
    glColor3ub(byteR, byteG, byteB);
  }
}

unsigned LeerIdentEnPixel(int xpix, int ypix) {
  // Reconstruye un identificador a través de un color.
  unsigned char bytes[3];
  glReadPixels(xpix, ypix, 1, 1, GL_RGB, GL_UNSIGNED_BYTE, (void*) bytes);
  return bytes[0] + (0x100U * bytes[1]) + (0x10000U * bytes[2]);
}

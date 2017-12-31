#ifndef CAMARAINTERACTIVA_HPP
#define CAMARAINTERACTIVA_HPP

#include "Camara.hpp"

class CamaraInteractiva : public Camara {
private:
  // Signo que mide si hay que dar la vuelta a la cámara una vez hemos
  // dado media vuelta con la latitud.
  int upcoeff;
  
public:
  // Parámetros de la cámara
  bool examinar; // True si se está en modo examinar, False en primera persona
  bool perspectiva; // True en proyección perspectiva, False en proyección ortográfica
  float ratio_yx_vp; // Aspect ratio del viewport
  float longi; // Ángulo de longitud, en torno al eje Y
  float lati; // Ángulo de latitud, en torno al eje X

  // Gestión del punto de atención
  Tupla3f aten; // Punto de atención de la cámara, inicialmente será el origen
  float dist; // Distancia desde el punto de atención al observador

  // Constructor de cámaras
  CamaraInteractiva(bool pexaminar, bool pperspectiva, int pratio,
		    float plongi, float plati, const Tupla3f& paten,
		    float pdist = 4, std::string nombre = "");

  // Calcula el view-frustum
  void calcularViewfrustum();

  // Calcula el marco de referencia de la cámara
  void calcularMarcoCamara();

  // Desplazamiento de la cámara
  void moverHV(int nh, int nv); // Desplazamientos y rotaciones horizontales/verticales
  void desplaZ(int nz);         // Desplazamiento en el eje Z

  // Modo de cámara
  void modoExaminar(const Tupla3f& paten); // Examina un punto dado
  void modoExaminar();                     // Pasa a modo examinar
  void modoPrimeraPersona();               // Pasa a modo primera persona

  // Fija matriz de modelview y matriz de proyección de OpenGL
  void activar();
};

#endif

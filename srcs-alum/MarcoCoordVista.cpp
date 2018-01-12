#include "MarcoCoordVista.hpp"

MarcoCoordVista::MarcoCoordVista() {
  // Mirando a Z-
  eje[0] = Tupla3f(1,0,0);
  eje[1] = Tupla3f(0,1,0);
  eje[2] = Tupla3f(0,0,1);

  // Matrices de cambio de coordenadas identidad
  matrizML = MAT_Ident();
}

MarcoCoordVista::MarcoCoordVista(const Tupla3f& pfoco, const Tupla3f& paten, const Tupla3f& pvup)
  : MarcoCoordVista()
{
  // Constructor con parámetros iguales a gluLookAt
  // pfoco: posición del ojo
  // paten: posición del punto de referencia, al que se atiende
  // pvup:  posición dirección
  recalcular(pfoco, paten, pvup);
}

void MarcoCoordVista::recalcular (const Tupla3f& pfoco, const Tupla3f& paten, const Tupla3f& pvup) {
  // Calcular el marco es necesario para poder moverse luego.  Lo
  // calculará usando perpendiculares (Tema 3).
  Tupla3f u = pvup;
  Tupla3f n = pfoco - paten;          // n = o - a
  Tupla3f ncu = n.cross(u);

  // Evita recalcular en el caso en el que existan vectores nulos
  if (n.lengthSq() != 0 and ncu.lengthSq() != 0) {
    eje[0] = ncu.normalized();          // x = (n × u) / ‖n × u‖
    eje[2] = n.normalized();            // z = n / ‖n‖
    eje[1] = eje[2].cross(eje[0]);      // y = x × z
  
    // La librería nos da la matriz para la transformación de vista
    matrizML = MAT_LookAt(pfoco, paten, pvup);
  }
  else {
    std::cerr << "Evita recalcular" << std::endl;
  }
}

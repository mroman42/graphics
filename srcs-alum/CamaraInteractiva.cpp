#include "CamaraInteractiva.hpp"

// Unidad de desplazamiento. Una constante real positiva que podrá
// ajustarse para que el uso de la cámara sea cómodo.
static const float udesp = 1;
// Unidad de rotación. Un real en radianes positivo que podrá
// ajustarse para que el uso de la cámara sea cómodo.
static const float urot = 1;
// Porcentaje de exceso de distancia. Puede ajustarse para que sea más
// cómoda la navegación.
static const float porc = 1;
// Distancia mínima a un objeto
static const float dmin = 1;

CamaraInteractiva::CamaraInteractiva(bool pexaminar, bool pperspectiva, int pratio,
		    float plongi, float plati, const Tupla3f& paten)
  : examinar(pexaminar), perspectiva(pperspectiva), ratio_yx_vp(pratio),
    longi(plongi), lati(plati), aten(paten)
{
  // Inicializa la distancia al observador
  dist = sqrt((mcv.org - aten).lengthSq());
}


void CamaraInteractiva::calcularViewfrustum() {
  // Lee perspectiva, dist, ratio_yx_vp
  
  // Crea view-frustum perspectiva  
  if (perspectiva) {
    // ???
    vf = ViewFrustum(dist, ratio_yx_vp, 0, 1);
  }
  
  // Crea view-frustum ortográfico
  else {
    vf = ViewFrustum();
  }
}

void CamaraInteractiva::calcularMarcoCamara() {
  // Lee longi, lati, dist, aten
  // ???
  // Pasar pfoco, paten, pvup

  // Parámetros de gluLookAt
  // Cálculo del marco de vista
  //  A = Tra[aten] * Rot_y[long] * Rot_x[-lati] * Tra[0,0,r]
  Matriz4f A =
    MAT_Traslacion(aten[0], aten[1], aten[2]) *
    MAT_Rotacion(longi, 0, 1, 0) *
    MAT_Rotacion(-lati, 1, 0, 0) *
    MAT_Traslacion(0, 0, dist);
  Tupla3f o = Tupla3f(A(3,0), A(3,1), A(3,2));
  
  mcv = MarcoCoordVista(o, aten, Tupla3f(0,1,0));
}

void CamaraInteractiva::moverHV(int nh, int nv) {
  // Modo en primera persona
  if (not examinar) {
    // Calcula el desplazamiento en los ejes del marco y lo aplica al
    // origen y a la matriz
    Tupla3f despl = mcv.eje[0] * nh * udesp + mcv.eje[1] * nv * udesp;
    mcv.org = mcv.org + despl;
    mcv.matrizML = mcv.matrizML * MAT_Traslacion(despl[0], despl[1], despl[2]);
  }

  // Modo examinar
  else {
    // Aumenta latitud y longitud
    longi += nh * urot;
    lati  += nv * urot;

    // Recalcula el marco de coordenadas de la cámara
    // ???
    // mcv = MarcoCoordVista(mcv.org, aten, )
  }
}

void CamaraInteractiva::desplaZ(int nz) {
  // Modo en primera persona
  if (not examinar) {
    // Calcula el desplazamiento en los ejes del marco y lo aplica al
    // origen y a la matriz
    Tupla3f despl = mcv.eje[2] * nz * udesp;
    mcv.org = mcv.org + despl;
    mcv.matrizML = mcv.matrizML * MAT_Traslacion(despl[0], despl[1], despl[2]);
  }

  // Modo examinar
  else {
    // Actualiza la distancia siguiendo la fórmula de la práctica;
    // tras modificar la distancia, se debe volver a llamar al
    // frustum.
    dist = dmin + (dist-dmin) * (1.0 - nz * porc / 100.0);
    calcularViewfrustum();
  }
}

void CamaraInteractiva::modoExaminar(const Tupla3f& paten) {
  aten = paten;
}

void CamaraInteractiva::modoExaminar() {
  examinar = true;
}

void CamaraInteractiva::modoPrimeraPersona() {
  examinar = false;
}

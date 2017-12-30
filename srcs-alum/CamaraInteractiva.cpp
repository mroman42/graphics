#include "CamaraInteractiva.hpp"

// Unidad de desplazamiento. Una constante real positiva que podrá
// ajustarse para que el uso de la cámara sea cómodo.
static const float udesp = 0.1;
static const float udespv = 0.2;
// Unidad de rotación. Un real en radianes positivo que podrá
// ajustarse para que el uso de la cámara sea cómodo.
static const float urot = 3;
// Porcentaje de exceso de distancia. Puede ajustarse para que sea más
// cómoda la navegación.
static const float porc = 4;
// Distancia mínima a un objeto
static const float dmin = 0.5;

CamaraInteractiva::CamaraInteractiva(bool pexaminar, bool pperspectiva, int pratio,
				     float plongi, float plati, const Tupla3f& paten,
				     float pdist, std::string pnombre)
  : examinar(pexaminar), perspectiva(pperspectiva), ratio_yx_vp(pratio),
    longi(plongi), lati(plati), aten(paten), dist(pdist)
{
  nombre = pnombre;
  
  // Distancia inicial para todas las cámaras
  calcularMarcoCamara();
  calcularViewfrustum();
}


void CamaraInteractiva::calcularViewfrustum() {
  // Lee perspectiva, dist, ratio_yx_vp

  // Qué plano de recorte elegir ???
  // Puede jugarse con el plano de recorte para solucionar el ratio ???  
  const float hfovy = 45;
  const float near = 0.01;
  const float far  = 200;
  
  // Crea view-frustum perspectiva  
  if (perspectiva) {
    vf = ViewFrustum(hfovy, ratio_yx_vp, near, far);
  }
  
  // Crea view-frustum ortográfico
  else {
    vf = ViewFrustum(dist, near, far);
  }
}

void CamaraInteractiva::calcularMarcoCamara() {
  // Lee longi, lati, dist, aten
  // ???
  // Pasar pfoco, paten, pvup

  // Parámetros de gluLookAt
  // Cálculo del marco de vista
  //  A = Tra[aten] * Rot_y[long] * Rot_x[-lati] * Tra[0,0,dist]
  Matriz4f A =
    MAT_Traslacion(aten[0], aten[1], aten[2]) *
    MAT_Rotacion(longi, 0, 1, 0) *
    MAT_Rotacion(-lati, 1, 0, 0) *
    MAT_Traslacion(0, 0, dist);
  Tupla3f orig = Tupla3f(A(0,3), A(1,3), A(2,3));
  
  mcv = MarcoCoordVista(orig, aten, Tupla3f(0,1,0));
}

void CamaraInteractiva::moverHV(int nh, int nv) {
  if (examinar) {
    // En el modo examinar, cambia la latitud y longitud desde la que
    // se mira
    longi += nh * urot;
    lati  += nv * urot;
  }
  else {
    // En primera persona desplaza la atención sobre los ejes del marco
    Tupla3f despl = mcv.eje[0] * nh * udesp + mcv.eje[1] * nv * udesp;
    aten = aten - despl;
  }

  // Recalcula el marco de coordenadas de la cámara
  calcularMarcoCamara();
  calcularViewfrustum();
}

void CamaraInteractiva::desplaZ(int nz) {
  if (examinar) {
    // Actualiza la distancia siguiendo la fórmula de la práctica;
    // tras modificar la distancia, se debe volver a llamar al
    // frustum.
    dist = dmin + (dist-dmin) * (1.0 - nz * porc / 100.0);
  }
  else {
    // En primera persona, desplaza la atención sobre el eje Z
    Tupla3f despl = mcv.eje[2] * nz * udespv;
    aten = aten - despl;
  }

  // Recalcula marcos
  calcularViewfrustum();
  calcularMarcoCamara();
}

void CamaraInteractiva::modoExaminar(const Tupla3f& paten) {
  examinar = true;
  aten = paten;
  calcularViewfrustum();
  calcularMarcoCamara();
}

void CamaraInteractiva::modoExaminar() {
  examinar = true;
  calcularViewfrustum();
  calcularMarcoCamara();
}

void CamaraInteractiva::modoPrimeraPersona() {
  examinar = false;
  calcularViewfrustum();
  calcularMarcoCamara();
}

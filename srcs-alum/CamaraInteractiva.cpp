#include "CamaraInteractiva.hpp"

// Unidad de desplazamiento. Una constante real positiva que podrá
// ajustarse para que el uso de la cámara sea cómodo.
static const float udesp = 0.1;
static const float udespv = 0.2;
// Unidad de rotación. Un real en radianes positivo que podrá
// ajustarse para que el uso de la cámara sea cómodo.
static const float urot = 10;
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
  // Inicialización de marco y frustum
  nombre = pnombre;
  calcularMarcoCamara();
  calcularViewfrustum();
  upcoeff = 1;
}


void CamaraInteractiva::calcularViewfrustum() {
  // Lee perspectiva, dist, ratio_yx_vp

  // Qué plano de recorte elegir ???
  // Puede jugarse con el plano de recorte para solucionar el ratio ???  
  const float near = 0.01;
  const float far  = 200;
  
  // Crea view-frustum perspectivo u ortográfico
  if (perspectiva) {
    const float hfovy = 45;
    // Hay que invertir aquí el ratio_yx_vp (?)
    vf.perspectivo(hfovy, 1/ratio_yx_vp, near, far);
  }
  else
    vf.ortografico(dist, 1/ratio_yx_vp, near, far);
}

void CamaraInteractiva::calcularMarcoCamara() {
  // Lee longi, lati, dist, aten y devuelve foco, aten, up.
  // El cálculo del marco de vista:
  //  A = Tra[aten] * Rot_y[long] * Rot_x[-lati] * Tra[0,0,dist]
  Matriz4f A =
    MAT_Traslacion(aten[0], aten[1], aten[2]) *
    MAT_Rotacion(longi, 0, 1, 0) *
    MAT_Rotacion(lati, 1, 0, 0) *
    MAT_Traslacion(0, 0, dist);
  Tupla3f orig = Tupla3f(A(0,3), A(1,3), A(2,3));

  // Signo que mide si hay que dar la vuelta a la cámara una vez hemos
  // dado media vuelta con la latitud.
  if (cos(lati / 180.0 * M_PI) > 0) upcoeff = 1;
  if (cos(lati / 180.0 * M_PI) < 0) upcoeff = -1;
  
  mcv = MarcoCoordVista(orig, aten, Tupla3f(0,upcoeff,0));
}

void CamaraInteractiva::moverHV(int nh, int nv) {
  if (examinar) {
    // En el modo examinar, cambia la latitud y longitud desde la que
    // se mira
    longi += nh * urot;
    lati  += nv * urot;
    std::cerr << "Long,Lat: (" << longi << "," << lati << ")" << std::endl;
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

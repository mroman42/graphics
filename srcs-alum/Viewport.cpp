#include "Viewport.hpp"
#include "aux.hpp"

Viewport::Viewport() : Viewport(0,0,512,512) {}

Viewport::Viewport(int p_org_x, int p_org_y, int p_ancho, int p_alto)
  : org_x(p_org_x), org_y(p_org_y), ancho(p_ancho), alto(p_alto)
{
  // Calcula la relación de aspecto alto/ancho
  ratio_yx = ((float) alto) / ((float) ancho);

  // Determina la matriz de viewport, siguiendo la descripción en el
  // tema 3 de teoría, donde se ve que es una composición
  //   D = Tra[orgx,orgy,0] . Esc[ancho,alto,1] . Esc[1/2] . Tra[1,1,1]
  // si asumimos el rango de valores de salida en Z como [0,1].
  matrizVp =
    MAT_Traslacion(org_x,org_y,0) *
    MAT_Escalado(ancho,alto,1) *
    MAT_Escalado(0.5,0.5,0.5) *
    MAT_Traslacion(1,1,1);
  
  // Matriz de viewport inversa.
  matrizVpInv =
    MAT_Traslacion(-1,-1,-1) *
    MAT_Escalado(2,2,2) *
    MAT_Escalado(1/((float) ancho), 1/((float) alto), 1) *
    MAT_Traslacion(-org_x,-org_y,0);
}

void Viewport::fijarViewport() {
  glViewport(org_x, org_y, ancho, alto);
}

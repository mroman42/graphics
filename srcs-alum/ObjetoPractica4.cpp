#include "ObjetoPractica4.hpp"

ObjetoPractica4::ObjetoPractica4() {}

void ObjetoPractica4::aumentarAlpha() {}
void ObjetoPractica4::aumentarBeta() {}
void ObjetoPractica4::disminuirAlpha() {}
void ObjetoPractica4::disminuirBeta() {}

MaterialPeonMadera::MaterialPeonMadera() {
  Textura texturaPeonMadera;
  texturaPeonMadera.idText = 0;
  texturaPeonMadera.img = new jpg::Imagen("../imgs/text-madera.jpg");
  texturaPeonMadera.mgct = 0;
  texturaPeonMadera.cs = Tupla4f(0,0,0,0);
  texturaPeonMadera.ct = Tupla4f(0,0,0,0);
}

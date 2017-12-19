#include "FuenteLuz.hpp"
#include <vector>

void ColeccionFL::activar() {
  for (FuenteLuz* f : fuentes)
    f -> activar();
}

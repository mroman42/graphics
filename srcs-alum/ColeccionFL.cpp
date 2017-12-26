#include "ColeccionFL.hpp"
#include "FuenteLuz.hpp"
#include <vector>

void ColeccionFL::activar() {
  for (FuenteLuz* f : fuentes)
    f -> activar(0); // 0 ??
}

#include "PilaMateriales.hpp"

PilaMateriales::PilaMateriales() : actual(nullptr) {}

void PilaMateriales::push() {
  pila.push_back(actual);
}

void PilaMateriales::pop() {
  actual = pila.back();
  pila.pop_back();
}

void PilaMateriales::activarMaterial(Material* material) {
  actual = material;
  actual->activar();
}

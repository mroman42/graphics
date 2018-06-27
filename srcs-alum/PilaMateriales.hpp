#ifndef PILAMATERIALES_HPP
#define PILAMATERIALES_HPP

#include <vector>
#include "Material.hpp"

class PilaMateriales {
private:
  Material* actual; // Material actualmente activado
  std::vector<Material*> pila; // Pila de materiales

public:
  PilaMateriales(); // Inicializa la pila vacía
  void push(); // Añade el material actual a la pila
  void pop(); // Saca el tope de pila al actual
  void activarMaterial(Material* material); // Activa material
};

#endif

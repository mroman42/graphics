#ifndef MALLAREVOL_H
#define MALLAREVOL_H

#include "MallaInd.hpp"
#include "file_ply_stl.hpp"
#include <string>

class MallaRevol : public MallaInd {
public:
  // Constructor que crea una malla de revolución dados el nombre del
  // archivo inicial del que se extrae el perfil, el número de perfiles
  // a obtener, y dos indicaciones de si se quieren creaar las tapas y
  // cerrar la malla.
  MallaRevol(const std::string& nombre_arch,
	     const unsigned nperfiles,
	     const bool crear_tapas,
	     const bool cerrar_malla);
};

#endif

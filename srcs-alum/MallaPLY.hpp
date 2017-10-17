#ifndef MALLAPLY_H
#define MALLAPLY_H

#include "MallaInd.hpp"
#include "file_ply_stl.hpp"
#include <string>

class MallaPLY : public MallaInd {
public:
  // Constructor que genera una malla a partir del nombre de archivo
  // dado, leyendo desde él.
  MallaPLY(const std::string& nombre_archivo);
};

#endif

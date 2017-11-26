#include "MallaPLY.hpp"

MallaPLY::MallaPLY(const std::string& nombre_archivo) : MallaInd() {
  // Extrae los puntos para generar los vértices y las caras
  // desde el archivo PLY pasado como argumento.
  std::vector<float> plyv; // Puntos, leídos como flotantes
  std::vector<int> plyc;   // Caras, leídas como enteros
  ply::read(nombre_archivo.c_str(), plyv, plyc);
  darColor(0.0,0.0,0.0);
  
  std::cerr << "Creado con: " << color_r << " " << color_b  << " " << color_g << std::endl;

  // Genera la malla organizando los puntos leídos en tuplas.
  // Organiza los vértices, cada tres flotantes forman una tupla
  // que determina un vértice.
  for (unsigned i=0; i<plyv.size()/3; i++) {
    Tupla3f vertice = Tupla3f(plyv[i*3],plyv[i*3+1],plyv[i*3+2]);
    vertices.push_back(vertice);
  }

  // Organiza las caras, por cada tres índices de vértice, tenemos
  // definida una cara.
  for (unsigned i=0; i<plyc.size()/3; i++) {
    Tupla3i cara = Tupla3i(plyc[i*3],plyc[i*3+1],plyc[i*3+2]);
    caras.push_back(cara);
  }
}

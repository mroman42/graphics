#include "ObjetoPractica3.hpp"

ObjetoPractica3::ObjetoPractica3() {
  // Nombra el objeto
  nombre_objeto = "Escena de la práctica 3";

  // Agrega objetos al grafo de escena
  // agregar(Matriz4f(MAT_Rotacion(60.0, 1.0, 0.0, 0.0)));

  // Objeto3D* cilindro = new MallaRevol("cilindro.ply", 6, true, true);
  // agregar(cilindro);

  // Matriz4f* ptr_matriz_rotacion_base = entradas[0].matriz;
  // Parametro rotacion_base("rotación de la base",
  // 			  ptr_matriz_rotacion_base,
  // 			  [=](float v) {return MAT_Rotacion(v, 1.0, 0.0, 0.0);},
  // 			  true, 30.0, 30.0, 0.005);
  // parametros.push_back(rotacion_base);

  Objeto3D* caballo = new Caballo();
  agregar(caballo);

  agregar(Matriz4f(MAT_Rotacion(0.0, 1.0, 0.0, 0.0)));
  Matriz4f* ptr_matriz_rotacion_base = entradas[1].matriz;
  Parametro rotacion_base("rotación de la base",
  			  ptr_matriz_rotacion_base,
  			  [=](float v) {return MAT_Rotacion(v, 0.0, 1.0, 0.0);},
  			  false, 0.0, 0.5, 1);
  parametros.push_back(rotacion_base);
  
  Objeto3D* rotor = new Rotor();
  //agregar(Matriaz4f(MAT_Traslacion(0,-0.2,0)));

  // Rotor
  agregar(rotor);
}

Rotor::Rotor() {
  nombre_objeto = "Rotor";
  Objeto3D* base = new Base();
  Objeto3D* columnas = new Columnas();
  
  // Base inferior
  agregar(base);
  // Columnas
  agregar(columnas);
  // Base superior
  agregar(Matriz4f(MAT_Traslacion(0,0.7,0)));
  agregar(base);
  
}

Base::Base() {
  nombre_objeto = "Base";
  Objeto3D* base = new MallaRevol("cilindro.ply", 12, true, true);
  agregar(Matriz4f(MAT_Escalado(1,0.05,1)));
  agregar(base);
}

Columnas::Columnas() {
  nombre_objeto = "Estructura de columnas";
  Objeto3D* columna_central = new Columna(0,0);
  Objeto3D* columna_1 = new Columna(0,0.4);
  Objeto3D* columna_2 = new Columna(0,-0.4);
  Objeto3D* columna_3 = new Columna(0.34641016151377546,0.2);
  Objeto3D* columna_4 = new Columna(0.34641016151377546,-0.2);
  Objeto3D* columna_5 = new Columna(-0.34641016151377546,0.2);
  Objeto3D* columna_6 = new Columna(-0.34641016151377546,-0.2);

  agregar(columna_central);
  agregar(columna_1);
  agregar(columna_2);
  agregar(columna_3);
  agregar(columna_4);
  agregar(columna_5);
  agregar(columna_6);
}

Columna::Columna(float x, float z) {
  nombre_objeto = "Columna";
  Objeto3D* cilindro = new MallaRevol("cilindro.ply", 24, true, true);
  agregar(Matriz4f(MAT_Traslacion(x,0,z)));
  agregar(Matriz4f(MAT_Traslacion(0,0.35,0)));
  agregar(Matriz4f(MAT_Escalado(0.03,0.7,0.03)));
  agregar(cilindro);
}

Cilindro::Cilindro() {
  nombre_objeto = "Cilindro";
  Objeto3D* cilindro = new MallaRevol("cilindro.ply", 24, true, true);
  agregar(cilindro);
}

Caballo::Caballo() {
  nombre_objeto = "Caballito";
  Objeto3D* caballito = new MallaPLY("cow.ply");
  agregar(caballito);
}

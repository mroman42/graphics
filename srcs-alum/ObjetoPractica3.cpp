#include "ObjetoPractica3.hpp"

ObjetoPractica3::ObjetoPractica3() {
  // Nombra el objeto
  nombre_objeto = "Escena de la práctica 3";

  // Parámetro principal de rotación
  agregar(Matriz4f(MAT_Rotacion(0.0, 0.0, 1.0, 0.0)));
  Matriz4f* ptr_matriz_rotacion_base = entradas[0].matriz;
  Parametro rotacion_base("rotación de la base",
  			  ptr_matriz_rotacion_base,
  			  [=](float v) {return MAT_Rotacion(v, 0.0, 1.0, 0.0);},
  			  false, 0.0, 0.5, 1);
  parametros.push_back(rotacion_base);

  // Rotor
  Objeto3D* rotor = new Rotor();
  agregar(rotor);
  
  // // Parámetro de traslación del caballito sobre el poste
  // Matriz4f* ptr_matriz_traslacion_caballito = entradas[2].matriz;
  // Parametro vertical_caballito("movimiento vertical del caballito",
  // 			  ptr_matriz_traslacion_caballito,
  // 			  [=](float v) {return MAT_Traslacion(0.0, v, 0.0);},
  // 			  true, 0.15, 0.15, 1);
  // parametros.push_back(vertical_caballito);
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
  Objeto3D* columna_central = new Columna();
  Objeto3D* poste_1 = new Poste(0,0.4,0);
  Objeto3D* poste_2 = new Poste(0,-0.4,180);
  Objeto3D* poste_3 = new Poste(0.34641016151377546,0.2,60);
  Objeto3D* poste_4 = new Poste(0.34641016151377546,-0.2,120);
  Objeto3D* poste_5 = new Poste(-0.34641016151377546,0.2,300);
  Objeto3D* poste_6 = new Poste(-0.34641016151377546,-0.2,240);

  agregar(columna_central);
  agregar(poste_1);
  agregar(poste_2);
  agregar(poste_3);
  agregar(poste_4);
  agregar(poste_5);
  agregar(poste_6);
}

Poste::Poste(float x,float z, float angle) {
  nombre_objeto = "Poste";  
  
  Objeto3D* columna = new Columna();
  agregar(Matriz4f(MAT_Traslacion(x,0,z)));
  agregar(columna);

  Objeto3D* caballito = new Caballito();
  agregar(Matriz4f(MAT_Traslacion(0,0.15,0)));
  agregar(Matriz4f(MAT_Escalado(0.08,0.08,0.08)));
  agregar(Matriz4f(MAT_Rotacion(angle,0,1,0)));
  agregar(caballito);
}

Columna::Columna() {
  nombre_objeto = "Columna";
  Objeto3D* cilindro = new MallaRevol("cilindro.ply", 24, true, true);
  agregar(Matriz4f(MAT_Traslacion(0,0.35,0)));
  agregar(Matriz4f(MAT_Escalado(0.03,0.7,0.03)));
  agregar(cilindro);
}

Cilindro::Cilindro() {
  nombre_objeto = "Cilindro";
  Objeto3D* cilindro = new MallaRevol("cilindro.ply", 24, true, true);
  agregar(cilindro);
}

Caballito::Caballito() {
  nombre_objeto = "Caballito";
  Objeto3D* caballito = new MallaPLY("cow.ply");
  agregar(caballito);
}

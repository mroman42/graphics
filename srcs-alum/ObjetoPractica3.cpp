#include "ObjetoPractica3.hpp"

ObjetoPractica3::ObjetoPractica3() {
  // Nombra el objeto
  nombre_objeto = "Escena de la práctica 3";

  // Estructura exterior del tiovivo
  NodoGrafoEscenaParam* estructura = new Estructura();
  agregar(estructura);
  
  // Rotor principal
  agregar(Matriz4f(MAT_Rotacion(0.0, 0.0, 1.0, 0.0)));
  NodoGrafoEscenaParam* rotor = new Rotor();
  agregar(rotor);
  
  
  // Parámetro de rotación general
  Matriz4f* ptr_matriz_rotacion_base = entradas[1].matriz;
  Parametro rotacion_base("rotación de la base",
  			  ptr_matriz_rotacion_base,
  			  [=](float v) {return MAT_Rotacion(v, 0.0, 1.0, 0.0);},
  			  false, 0.0, 0.5, 1, 0);
  parametros.push_back(rotacion_base);

  // Parámetros de nodos hijo
  std::cout << "Añadidos " << rotor->parametros.size() << " parametros" << std::endl;
  for (Parametro p : rotor->parametros) parametros.push_back(p);
}

Estructura::Estructura() {
  nombre_objeto = "Estructura del tiovivo";
  MallaInd* suelo = new MallaRevol("cilindro.ply", 6, true, true);
  MallaInd* carpa = new MallaRevol("cono.ply",12,true,true);
  suelo->darColor(0.9,0.3,0.3);
  carpa->darColor(0.9,0.3,0.3);

  agregar(MAT_Traslacion(0,-0.05,0));
  agregar(MAT_Escalado(1.2,0.1,1.2));
  agregar(suelo);
  agregar(MAT_Escalado(1,2.2,1));
  agregar(MAT_Traslacion(0,4,0));
  agregar(carpa);
};

Rotor::Rotor() {
  nombre_objeto = "Rotor";
  Objeto3D* base = new Base();
  NodoGrafoEscenaParam* columnas = new Columnas();
  
  // Base inferior
  agregar(base);
  // Columnas
  agregar(columnas);
  // Base superior
  agregar(Matriz4f(MAT_Traslacion(0,0.7,0)));
  agregar(base);

  // Parámetros de nodos hijo
  for (Parametro p : columnas->parametros) parametros.push_back(p);
}

Base::Base() {
  nombre_objeto = "Base";
  MallaInd* base = new MallaRevol("cilindro.ply", 12, true, true);
  base -> darColor(0.8,0.4,0.4);
  agregar(Matriz4f(MAT_Escalado(1,0.05,1)));
  agregar(base);
}

Columnas::Columnas() {
  nombre_objeto = "Estructura de columnas";
  NodoGrafoEscenaParam* columna_central = new Columna();
  NodoGrafoEscenaParam* poste_1 = new Poste(0,0.4,0,1);
  NodoGrafoEscenaParam* poste_2 = new Poste(0,-0.4,180,-1);
  NodoGrafoEscenaParam* poste_3 = new Poste(0.34641016151377546,0.2,60,0);
  NodoGrafoEscenaParam* poste_4 = new Poste(0.34641016151377546,-0.2,120,1);
  NodoGrafoEscenaParam* poste_5 = new Poste(-0.34641016151377546,0.2,300,-1);
  NodoGrafoEscenaParam* poste_6 = new Poste(-0.34641016151377546,-0.2,240,0);

  agregar(columna_central);
  agregar(poste_1);
  agregar(poste_2);
  agregar(poste_3);
  agregar(poste_4);
  agregar(poste_5);
  agregar(poste_6);

  // Parámetros de nodos hijo
  for (Parametro p : poste_1->parametros) parametros.push_back(p);
  for (Parametro p : poste_2->parametros) parametros.push_back(p);
  for (Parametro p : poste_3->parametros) parametros.push_back(p);
  for (Parametro p : poste_4->parametros) parametros.push_back(p);
  for (Parametro p : poste_5->parametros) parametros.push_back(p);
  for (Parametro p : poste_6->parametros) parametros.push_back(p);
}

Poste::Poste(float x,float z, float angle, int inicialmente) {
  nombre_objeto = "Poste";  
  
  NodoGrafoEscenaParam* columna = new Columna();
  agregar(Matriz4f(MAT_Traslacion(x,0,z)));
  agregar(columna);

  NodoGrafoEscenaParam* caballito = new Caballito();
  agregar(Matriz4f(MAT_Traslacion(0,0.15 + inicialmente*0.15,0)));
  agregar(Matriz4f(MAT_Escalado(0.08,0.08,0.08)));
  agregar(Matriz4f(MAT_Rotacion(angle,0,1,0)));
  agregar(caballito);

  // Parámetro de traslación del caballito sobre el poste
  Matriz4f* ptr_matriz_traslacion_caballito = entradas[2].matriz;
  Parametro vertical_caballito("movimiento vertical del caballito",
			       ptr_matriz_traslacion_caballito,
			       [=](float v) {return MAT_Traslacion(0.0, v, 0.0);},
			       true, 0.15, 0.13, 0.006, inicialmente*M_PI/2);
  parametros.push_back(vertical_caballito);

  // Parámetro de cabeceo del caballito sobre el poste
  Matriz4f* ptr_matriz_cabeceo_caballito = entradas[4].matriz;
  Parametro cabeceo_caballito("movimiento de cabeceo del caballio",
			      ptr_matriz_cabeceo_caballito,
			      [=](float v) {return MAT_Rotacion(v,0,1,0);},
			      true, angle, 30, 0.002, 0);
  parametros.push_back(cabeceo_caballito);
}

Columna::Columna() {
  nombre_objeto = "Columna";
  MallaInd* cilindro = new MallaRevol("cilindro.ply", 24, true, true);
  agregar(Matriz4f(MAT_Traslacion(0,0.35,0)));
  agregar(Matriz4f(MAT_Escalado(0.03,0.7,0.03)));
  cilindro -> darColor(0.4,0.4,0.4);
  agregar(cilindro);
}

Cilindro::Cilindro() {
  nombre_objeto = "Cilindro";
  MallaInd* cilindro = new MallaRevol("cilindro.ply", 24, true, true);
  agregar(cilindro);
}

Caballito::Caballito() {
  nombre_objeto = "Caballito";
  MallaInd* caballito = new MallaPLY("cow.ply");
  caballito->darColor(0.8,0.8,0.8);
  agregar(caballito);
}

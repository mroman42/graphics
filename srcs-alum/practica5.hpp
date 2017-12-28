#ifndef IG_PRACTICA5_HPP
#define IG_PRACTICA5_HPP

#include "practicas.hpp"
#include "Objeto3D.hpp"
#include "CamaraInteractiva.hpp"
#include "ObjetoPractica4.hpp"
#include "aux.hpp"
#include <string>

// Gestiona cuál es el grado de libertad activo en cada momento
static int p5_grado_libertad_activo;

// Animaciones activadas
static bool p5_animaciones;

// Funciones de gestión de la práctica 5
void P5_Inicializar(int tamx, int tamy);
void P5_DibujarObjetos(ContextoVis& cv);
bool P5_FGE_PulsarTeclaNormal(unsigned char tecla);
bool P5_FGE_PulsarTeclaEspecial(unsigned char tecla);
bool P5_FGE_ClickRaton(int button, int state, int x, int y);
bool P5_FGE_RatonMovidoPulsado(int x, int y);
bool P5_FGE_Desocupado();
bool P5_ClickIzquierdo(int x, int y);
void P5_InicioModoArrastrar(int x, int y);
void P5_RatonArrastradoHasta(int x, int y);
void P5_FijarMVPOpenGL(int vpx, int vpy);


// Declara la función gestora del evento desocupado
void FGE_Desocupado();

#endif

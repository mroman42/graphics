#ifndef IG_PRACTICA4_HPP
#define IG_PRACTICA4_HPP

#include "practicas.hpp"
#include "Objeto3D.hpp"
#include "ObjetoPractica4.hpp"
#include "aux.hpp"
#include <string>

// El objeto jerárquico a visualizar se crea en memoria dinámica y se
// guarda en una variable de la práctica.
static ObjetoPractica4* objeto_practica4 = nullptr;

// Gestiona cuál es el grado de libertad activo en cada momento
static int p4_grado_libertad_activo;

// Animaciones activadas
static bool p4_animaciones;

// Funciones de gestión de la práctica 4
void P4_Inicializar();
void P4_DibujarObjetos(ContextoVis& cv);
bool P4_FGE_PulsarTeclaNormal(unsigned char tecla);
bool P4_FGE_PulsarTeclaEspecial(unsigned char tecla);
bool P4_FGE_Desocupado();

// Declara la función gestora del evento desocupado
void FGE_Desocupado();

#endif

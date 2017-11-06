#ifndef IG_PRACTICA3_HPP
#define IG_PRACTICA3_HPP

#include "practicas.hpp"
#include "Objeto3D.hpp"
#include "ObjetoPractica3.hpp"
#include "aux.hpp"

// El objeto jerárquico a visualizar se crea en memoria dinámica y se
// guarda en una variable de la práctica.
static ObjetoPractica3* objeto_practica3 = nullptr;

// Gestiona cuál es el grado de libertad activo en cada momento
static int p3_grado_libertad_activo;

// Animaciones activadas
static bool p3_animaciones;

// Funciones de gestión de la práctica 3
void P3_Inicializar();
void P3_DibujarObjetos(ContextoVis& cv);
bool P3_FGE_PulsarTeclaNormal(unsigned char tecla);
bool P3_FGE_Desocupado();

// Declara la función gestora del evento desocupado
void FGE_Desocupado();

#endif

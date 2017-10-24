// *********************************************************************
// **
// ** Informática Gráfica, curso 2016-17
// ** Declaraciones públicas auxiliares, comunes a todas las prácticas
// **
// *********************************************************************

#ifndef IG_PRACTICAS_HPP
#define IG_PRACTICAS_HPP

// ---------------------------------------------------------------------
// tipo de datos enumerado para los modos de visualización:

typedef enum
{
   modoPuntos,
   modoAlambre,
   modoSolido,
   modoAjedrez
}
   ModosVisu;

const int numModosVisu = 4 ; // numero de modos distintos

// --------------------------------------------------------------------

class ContextoVis
{
   public:
      ModosVisu modoVisu ; // modo de visualización actual
      ContextoVis() { modoVisu = modoAlambre ; } // poner alambre por defecto
};

#endif

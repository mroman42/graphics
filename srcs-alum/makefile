## *********************************************************************
##
## prácticas IG GIM (17-18) - makefile para las prácticas
## (Septiembre de 2017)
##

## ---------------------------------------------------------------------
## nombre del binario ejecutable y archivos a enlazar en 'srcs-alu'
target_name := prac

# nota: se debe añadir a 'units_loc' los nombres de las unidades de compilación
# que se quieran enlazar para crear el ejecutable 'prac'. Por ejemplo:
# Objeto3D, MallaInd, practica2, MallaRevol, MallaPLY, practica3, etc......
# (para cada nombre habrá un archivo .cpp en 'srcs-alum')
units_loc := 
units_alu := main practica1 practica2 practica3 practica4 practica5 MallaInd MallaPLY MallaRevol Objeto3D Parametro NodoGrafoEscena NodoGrafoEscenaParam ObjetoPractica3 ObjetoPractica4 Material MaterialEstandar Textura FuenteLuz FuenteDireccional FuentePosicional ColeccionFL ColeccionFuentesP4 PilaMateriales Camara CamaraInteractiva MarcoCoordVista Viewport ViewFrustum ParTransf

## ---------------------------------------------------------------------
## aspectos configurables

opt_dbg_flag   := -g  # seleccionar depuración (-g) u optimización (-O3)
exit_first     := -Wfatal-errors # sirve para abortar después de primer error
warn_all       := -Wall    # sirve para ver todos los warnings
compatibilidad := -std=c++11   # versión del estandar C++ admitida

## ---------------------------------------------------------------------
## invocar las definiciones y targets en el archivo 'include.make'

include ../include/include.make

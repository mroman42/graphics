#ifndef PARAMETRO_H
#define PARAMETRO_H

#include <string>
#include "matrizg.hpp"

class Parametro {
private:
  // Descripción de un parámetro.
  const std::string descripcion;

  // Si está acotado, el valor oscilará entre dos valores; cuando no
  // lo esté crecerá indefinidamente.
  const bool acotado;

  // Función para producir una nueva matriz a través de un valor
  // flotante.
  const TFuncionCMF fun_calculo_matriz;

  // Variables del parámetro.
  const float c; // valor inicial del parámetro
  const float s; // semiamplitud o factor de escala
  const float f; // frecuencia

  // Puntero a una matriz dentro del modelo.
  Matriz4f* const ptr_mat;

  float valor_norm; // Valor actual normalizado no acotado.
  float velocidad;  // Velocidad actual.

public:
  // Crea un grado de libertad desde sus datos.
  Parametro(const std::string& descripcion, Matriz4f* p_ptr_mat,
	    TFuncionCMF p_fcm, bool p_acotado,
	    float p_c, float p_s, float p_f);

  void siguiente_cuadro();
  void reset();
  void incrementar();
  void decrementar();
  void acelerar();
  void decelerar();
  float leer_valor_actual();
  float leer_velocidad_actual();
  std::string leer_descripcion();
};

#endif

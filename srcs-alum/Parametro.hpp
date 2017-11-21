#ifndef PARAMETRO_H
#define PARAMETRO_H

#include <string>
#include <functional>
#include "matrizg.hpp"

typedef std::function<Matriz4f(float)> TFuncionCMF;




class Parametro {
private:
  // Constantes globales para todos los parámetros
  // Constante de aceleración
  static constexpr const float a = 1;
  // Constante de incremento
  static constexpr const float delta = 1;
  // Constante de velocidad inicial
  static constexpr const float velocidadinicial = 1;

  
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
  const float shift; // desplazamiento respecto a lo inicial

  // Puntero a una matriz dentro del modelo.
  Matriz4f* const ptr_mat;

  float valor_norm; // Valor actual normalizado no acotado.
  float velocidad;  // Velocidad actual.

public:
  // Crea un grado de libertad desde sus datos.
  Parametro(const std::string& descripcion, Matriz4f* p_ptr_mat,
	    TFuncionCMF p_fcm, bool p_acotado,
	    float p_c, float p_s, float p_f, float p_shift) :
    descripcion(descripcion),
    acotado(p_acotado),
    fun_calculo_matriz(p_fcm),
    c(p_c),
    s(p_s),
    f(p_f),
    shift(p_shift),
    ptr_mat(p_ptr_mat)
  {
    reset();
  }

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

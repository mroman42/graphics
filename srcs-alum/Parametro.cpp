#include "Parametro.hpp"

void Parametro::siguiente_cuadro() {
  valor_norm = valor_norm + velocidad;
  *ptr_mat = fun_calculo_matriz(leer_valor_actual());
}

void Parametro::reset() {
  valor_norm = 0;
  velocidad = velocidadinicial;
}

std::string Parametro::leer_descripcion() {
  return descripcion;
}

float Parametro::leer_valor_actual() {
  if (not acotado)
    return c + s * valor_norm;
  else
    return c + s * sin(f * 2 * M_PI * valor_norm);
}

float Parametro::leer_velocidad_actual() {
  return velocidad;
}

void Parametro::acelerar() {
  velocidad = velocidad + a;
}

void Parametro::decelerar() {
  velocidad = velocidad - a;
}

void Parametro::incrementar() {
  valor_norm = valor_norm + delta;
}

void Parametro::decrementar() {
  valor_norm = valor_norm - delta;
}

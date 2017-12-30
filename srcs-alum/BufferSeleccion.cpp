// #include "BufferSeleccion.hpp"

// BufferSeleccion::BufferSeleccion()
//   : numNombres(0), nombreMin(nullptr), longNombreMin(0)
// {}

// void BufferSeleccion::inicioModoSel() {
//   // Indica el buffer del modo selección y entra en modo selección,
//   // inicializando la pila de nombres.
//   glSelectBuffer(tamB, vec[0]);
//   glRenderMode(GL_SELECT);
//   glInitNames();
// }

// void BufferSeleccion::finModoSel() {
//   int* bloque = vec;
//   numNombres = glRenderMode(GL_RENDER);

//   for (i=0; i < numNombres; i++) {
//     if (i == 0 or bloque[1] < profZmin) {
//       profZmin = bloque[1]; // Guarda una nueva profundidad mínima
//       longNombreMin = bloque[0]; // Registra la longitud del nombre
//       nombreMin = &(bloque[3]); // Registra el puntero al nombre mínimo
//     }

//     // Avanza el puntero a la base del bloque siguiente
//     bloque += bloque[0] + 3;
//   }
// }



#version 130

void main() {
  // El objetivo es escribir estas variables:
  //  - gl_Position, posición del vértice en pantalla,
  //  - gl_FrontColor, color asociado al vértice.
  //
  // Se pueden leer (entre otras) las variables:
  //  - gl_ModelViewProjection, matriz actual de transformación
  //  - gl_Vertex, coordenadas del punto
  //  - gl_Color, color actual especificado

  gl_FrontColor = gl_Color;
  gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;
}

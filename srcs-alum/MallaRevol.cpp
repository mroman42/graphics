#include "MallaRevol.hpp"

MallaRevol::MallaRevol(const std::string& nombre_arch,
		       const unsigned nperfiles,
		       const bool crear_tapas,
		       const bool cerrar_malla) {
  // Extrae los puntos que generarán los vértices.
  std::vector<float> plyv;
  ply::read_vertices(nombre_arch.c_str(), plyv);
  int vnum = plyv.size()/3;

  // La figura de revolución se extrae generando un número determinado
  // de perfiles, cada uno de ellos a distinto ángulo. Estos perfiles
  // serán unidos por caras que se añadirán uniendo cada perfil con el
  // siguiente.
  for (unsigned j=0; j < nperfiles or (j == nperfiles and not cerrar_malla); j++) {
    // Genera el ángulo al que va a colocar el perfil
    const double angulo = j*2*M_PI/nperfiles;
    const double cosp = cos(angulo);
    const double senp = sin(angulo);

    // Añade cada vértice del perfil colocado en el nuevo ángulo.
    for (int i=0; i<vnum; i++) {
      // Calcula la posición del nuevo vértice aplicando una rotación.
      const float px = plyv[i*3];
      const float py = plyv[i*3+1];
      const float pz = plyv[i*3+2];
      const float nx = cosp*px - senp*pz;
      const float ny = py;
      const float nz = cosp*pz + senp*px;
      vertices.push_back(Tupla3f(nx,ny,nz));

      // Une el perfil con el anterior mediante dos triángulos
      // que se unen formando una cara con el siguiente vértice.
      // Esta operación no es necesaria para el primer vértice ni
      // para la última cara, que cuando se cierra malla es una menos.
      if (i!=0 and j!=nperfiles and (j!=(nperfiles-1) or !cerrar_malla)) {
	// Primer triángulo
	int ua = j*vnum+i;
	int ub = ua+vnum;
	int uc = ua-1;
	caras.push_back(Tupla3i(ua,ub,uc));
	
	// Segundo triángulo
	int va = uc;
	int vb = ub;
	int vc = ub-1;
	caras.push_back(Tupla3i(va,vb,vc));
      }
    }
  }
  
  // Si se va a cerrar malla y no se va a crear la última copia, se
  // deben crear las caras que unen las últimas copias.
  if (cerrar_malla) {
    for (int i=1; i<vnum; i++) {
      // Primer triángulo
      int ua = (nperfiles-1)*vnum + i;
      int ub = i;
      int uc = ua-1;
      caras.push_back(Tupla3i(ua,ub,uc));
      
      // Segundo triángulo
      int va = uc;
      int vb = i;
      int vc = i-1;
      caras.push_back(Tupla3i(va,vb,vc));
    }
  }

  // Cuando se le añaden tapas, lo que se haace es crear un punto más
  // en el centro del eje de revolución y conectarlo por caras con
  // todos los puntos iniciales y finales del prefil de revolución.
  if (crear_tapas) {
    // Puntos en el centro de los ejes de revolución.
    vertices.push_back(Tupla3f(0,plyv[0*3+1],   0)); // Centro inferior
    vertices.push_back(Tupla3f(0,plyv[vnum*3-2],0)); // Centro superior

    // Caras formando las tapas superior e inferior contando hasta la
    // penúltima cara y teniendo en cuenta cuándo se está cerrando la
    // malla.
    for (unsigned k=0; k<nperfiles and (k<(nperfiles-1) or not cerrar_malla); k++) {
      // Cara superior
      int supa = (k+1)*vnum - 1;
      int supb = vertices.size() - 1;
      int supc = supa + vnum;
      caras.push_back(Tupla3i(supa,supb,supc));

      // Cara inferior
      int infa = k*vnum;
      int infb = vertices.size()-2;
      int infc = infa + vnum;
      caras.push_back(Tupla3i(infa,infb,infc));
    }

    // En el caso de que se cierre la malla, se deben crear las tapas
    // que faltan conectadas con las iniciales.
    if (cerrar_malla) {
      // Cara superior
      int supa = (nperfiles-1)*vnum + vnum - 1;
      int supb = vertices.size()-1;
      int supc = vnum - 1;
      caras.push_back(Tupla3i(supa,supb,supc));

      // Cara inferior
      int infa = (nperfiles-1)*vnum + 0;
      int infb = vertices.size()-2;
      int infc = 0;
      caras.push_back(Tupla3i(infa,infb,infc));
    }
  }
}

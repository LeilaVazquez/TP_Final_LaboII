#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

///PROTOTIPOS///

bool arroba(char correo[]);

void cargarCadena(char *pal, int tam);

void cargarCUIT(char *pal, int tam);

bool setteoContador();

void subirVentana();

void mostrarCategoria(int numero);

void escribirEnRenglones(const char*cadena, int ancho, int tam, int x, int y);

void aumentarID(int pos);

int mostrarID(int pos);

int buscarIDCliente(int ID);

int buscarIDReparacion(int ID);

int buscarIDTecnico(int ID);

int buscarIDRepuesto(int ID);

int seleccionarRepuesto(int c, int cat, int x, int y, int idReparacion);

float calcularPresupuestoRepuesto(int idR);

float calcularPresupuestoTecnico(int ID, float horas);


/// FILTROS REPARACION

void filtrarRepaPresup();

void filtrarRepaTiempo();

void filtrarRepaEstado();

void filtrarRepaCliente();

void filtrarRepaTecnico();

void filtrarRepaCat();


///FILTROS REPUESTOS

void filtrarRepuPorMarca();

void filtrarRepuPorCat();

void filtrarRepuPorPrecio();

void filtrarRepuPorNombre();


/// FILTROS TECNICO

char pasarAmayusc(char &cat);

void filtrarTecnicoCat();

void filtrarTecnicoEstado();

void filtrarTecnicoNombre();

void filtrarTecnicoLocalidad();


/// FILTROS CLIENTE

void filtrarClienteNombre();

void filtrarClienteLocalidad();

void filtrarClienteCUIT();

///INFORMES

float cantHoras(int id);

void horasPorTecnico();

int tecnicoConMasClientes();

void nombreYApellido(int id);

void nombreYApellidoTecnico(int id);

void listarPre();

int clienteConMayorPresupuesto();

int localidadMasRepa();

int repuestoMasUsado();

///CONFIGURACIÓN

bool copiaSeguridadClientes();

bool copiaSeguridadTecnicos();

bool copiaSeguridadReparaciones();

bool copiaSeguridadRepuestos();

bool copiaSeguridadPresupuestos();

bool restaurarArchivoClientes();

bool restaurarArchivoTecnicos();

bool restaurarArchivoReparaciones();

bool restaurarArchivoRepuestos();

bool restaurarArchivoPresupuestos();

bool restaurarDatosInicio();





#endif // FUNCIONES_H_INCLUDED

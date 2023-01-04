

#include "Tecnico.h"
#include "funciones.h"


/*void Tecnico::cargarCadena(char *pal, int tam){
    int i;
    fflush(stdin);
    for(i=0;i<tam;i++){
        pal[i]=cin.get();
        if(pal[i]=='\n') break;
        }
    pal[i]='\0';
    fflush(stdin);
}*/

void Tecnico::cargarEspecialidades(CategoriaTecnico aux){
    int c;
    if(aux.getTipo()=='A')c=4;
    if(aux.getTipo()=='B')c=3;
    if(aux.getTipo()=='C')c=2;
    if(aux.getTipo()=='D')c=1;
    for(int i=0; i<c;i++){
    cout<<"Ingrese la especialidad: "<<endl;
    fflush(stdin);
    cin.getline(especialidad[i],15);
    }
}

void Tecnico::mostrarEspecialidades(CategoriaTecnico aux){
    int c;
    if(aux.getTipo()=='A')c=4;
    if(aux.getTipo()=='B')c=3;
    if(aux.getTipo()=='C')c=2;
    if(aux.getTipo()=='D')c=1;
    cout<<"ESPECIALIDADES: "<<endl;
    for(int i=0; i<c;i++){
    cout<<"  ";
        for(int j=0; j<15;j++){
            if(especialidad[i][j]=='\0')break;
            cout<<especialidad[i][j];
        }
    cout<<endl;
    }
}

bool Tecnico::cargar(){

    char nombre[40];
    Direccion auxDir;
    Contacto auxCon;
    CategoriaTecnico cat;
    cout<<"Ingrese el nombre del técnico: ";
    cargarCadena(nombre, 39);
    setNombre(nombre);
    cout<<"Ingrese el apellido del técnico: ";
    cargarCadena(nombre, 39);
    setApellido(nombre);
    system("cls");
    cout<<"Ingrese el domicilio del técnico: "<<endl;
    auxDir.cargar();
    setDireccion(auxDir);
    system("cls");
    cout<<"Ingrese información de contacto del técnico: "<<endl;
    if(!auxCon.cargar()){
        cout<<"Error en la carga del contacto."<<endl;
        return false;
    }
    setContacto(auxCon);
    system("cls");
    cout<<"INFORMACIÓN TÉCNICA"<<endl;
    //setId(mostrarID(0));
    cout<<"ID del técnico: "<<getId()<<endl;
    cout<<"A - 4 especialidades"<<endl;
    cout<<"B - 3 especialidades"<<endl;
    cout<<"C - 2 especialidades"<<endl;
    cout<<"D - 1 especialidad"<<endl;
    cat.cargar();
    setCategoria(cat);
    if(cat.getTipo()=='0'){
        cout<<"Error en la carga de categoría."<<endl;
        return false;
    }
    cargarEspecialidades(cat);
    setContratado(true);
    //aumentarID(0);
    return true;

}

void Tecnico::mostrar(){

    cout<<"ID: "<<getId()<<endl;
    cout<<"Nombre: "<<getNomrbre()<<endl;
    cout<<"Apellido: "<<getApellido()<<endl;
    cout<<"Categoria: "<<getCategoria().getTipo()<<endl;
    mostrarEspecialidades(getCategoria());
    cout<<"DOMICILIO"<<endl;
    getDireccion().mostrar();
    cout<<"CONTACTO"<<endl;
    getContacto().mostrar();
}

bool Tecnico::grabar(){
    FILE *arc=fopen("Tecnicos.dat", "ab");
    if(arc==NULL){
        cout<<"Falló en la carga de archivos."<<endl;
        return false;
    }
    fwrite(this, sizeof(*this), 1, arc);
    fclose(arc);
    return true;
}

int Tecnico::leer(int pos){
    FILE *arc=fopen("Tecnicos.dat", "rb");
    if(arc==NULL){
        cout<<"Falló en la carga de archivos."<<endl;
        return -1;
    }
    fseek(arc, sizeof *this*pos,0);
    int leyo=fread(this, sizeof *this,1, arc);
    fclose(arc);
    return leyo;
}

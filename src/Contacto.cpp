#include "Contacto.h"

bool Contacto::arroba(char correo[]){

    for(int i=0;i<15;i++){
        cout<<correo[i]<<endl;
        if(correo[i]==(char)64){
            cout<<"Hasta ac� bien"<<endl;
            return true;
        }

    }
    return false;

}

bool Contacto::cargar(){

    char correo[15];
    long num;
    cout<<"Ingrese el n�mero de telefono: ";
    cin>>num;
    if(!setTelefono(num)){return false;}
    cout<<"Ingrese el correo electr�nico: ";
    cin>>correo;
    if(!arroba(correo)){
        return false;
    }
    setMail(correo);
    return true;
}

void Contacto::mostrar(){

    cout<<"Telefono: "<<getTelefono()<<endl;
    cout<<"Correo Electr�nico: "<<getMail()<<endl;

}

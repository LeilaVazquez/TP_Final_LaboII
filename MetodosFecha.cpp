#include <iostream>
#include <ctime>
#include <windows.h>

using namespace std;

#include "Fecha.h"

void Fecha::mostrar(){
  cout<<dia<<"/"<<mes<<"/"<<anio;
}

void Fecha::anioBiciesto(){
  int anioVal=getAnio();
  if((anioVal%4 == 0 && anioVal%100 != 0) || anioVal%400 == 0){setBiciesto(true);}
  else {setBiciesto(false);}
}

bool Fecha::validacion(){

  time_t tiempo;
  struct tm *tmPtr;

  tiempo = time(NULL);
  tmPtr = localtime(&tiempo);

  if (mes==4 || mes==6 || mes==9 || mes==11){
    if (dia>30){return false;}
  }
  else if (mes==2){
    if (getBiciesto()){
        if (dia>29){return false;}
    }
    else if (dia>28){return false;}
  }
//Fecha actual
  if(anio==(tmPtr->tm_year+1900)){
    if(mes==(tmPtr->tm_mon+1)){
        if(dia<=(tmPtr->tm_mday)){return true;}
    }
    else if(mes<(tmPtr->tm_mon+1)){return true;}
  }
  else if(anio<(tmPtr->tm_year+1900)){return true;}
  return false;
}

void Fecha::cargar(){
    while(true){
      int fechas;
      cout<<"Ingrese el día: ";
      cin>>fechas;
      if(setDia(fechas)){
        cout<<"Ingrese el mes: ";
        cin>>fechas;
        if(setMes(fechas)){
          cout<<"Ingrese el año: ";
          cin>>fechas;
          if(setAnio(fechas)){
            setAnio(fechas);
            anioBiciesto();
            if(!validacion()){
              cout<<"Se ingresó una fecha inválida"<<endl;
              cout<<endl<<endl;;
            }
            else {break;}
          }
          else{
              cout<<"Se ingresó una fecha inválida"<<endl;
              cout<<endl<<endl;}
        }
        else {
              cout<<"Se ingresó una fecha inválida"<<endl;
              cout<<endl<<endl;}
      }
      else {
              cout<<"Se ingresó una fecha inválida"<<endl;
              cout<<endl<<endl;}

    }

}

#ifndef FECHA_H
#define FECHA_H

class Fecha{

private:
        int dia;
        int mes;
        int anio;
        bool biciesto;
    public:
        ///Sets:
        bool setDia(int _dia){
          if((_dia<=31)&&(_dia>=1)){
            dia=_dia;
            return true;
          }
          return false;
        }
        bool setMes(int _mes){
          if((_mes<=12)&&(_mes>=1)){
            mes=_mes;
            return true;
          }
          return false;
        }
        bool setAnio(int _anio){
          if(_anio>1900){
            anio=_anio;
            return true;
          }
          return false;
        }
        void setBiciesto(bool estado){biciesto=estado;}
        ///Gets:
        int getDia(){return dia;}
        int getMes(){return mes;}
        int getAnio(){return anio;}
        bool getBiciesto(){return biciesto;}
        ///metodos
        void mostrar();
        void cargar();
        void anioBiciesto();
        bool validacion();

///SOBRECARGA DE OPERADORES

    bool operator>(Fecha aux){
        if(anio>aux.getAnio())return true;
        else if(mes>aux.getMes())return true;
        else if(dia>aux.getDia())return true;
        return false;
    }

    bool operator>=(Fecha aux){
        if(anio>=aux.getAnio())return true;
        else if(mes>=aux.getMes())return true;
        else if(dia>=aux.getDia())return true;
        return false;
    }

    bool operator<(Fecha aux){
        if(anio<aux.getAnio())return true;
        else if(mes<aux.getMes())return true;
        else if(dia<aux.getDia())return true;
        return false;
    }

    bool operator<=(Fecha aux){
        if(anio<=aux.getAnio())return true;
        else if(mes<=aux.getMes())return true;
        else if(dia<=aux.getDia())return true;
        return false;
    }

    bool operator==(Fecha aux){
    if(anio==aux.getAnio()){
        if(mes==aux.getMes()){
            if(dia==aux.getDia())return true;
        }
    }
    return false;
}

};



#endif // FECHA_H

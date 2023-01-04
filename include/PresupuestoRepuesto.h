#ifndef PRESUPUESTOREPUESTO_H
#define PRESUPUESTOREPUESTO_H


class PresupuestoRepuesto{

private:
    int idReparacion;
    int idRep;
    int catRepuesto;
    float precio;
    int unidades;

public:
    ///sets
    void setIdRep(int id){idRep=id;}
    void setIdReparacion(int id){idReparacion=id;}
    bool setCatRepuesto(int cr){
        if(cr>0&&cr<4){
           catRepuesto=cr;
           return true;
        }
        return false;
    }

    bool setPrecio(float s){
        if(s>0){
            precio=s;
            return true;
        }
        return false;
    }
    void setUnidades(int u){unidades=u;}

    ///gets
    int getIdRe(){return idRep;}
    int getIdReparacion(){return idReparacion;}
    int getCatRepuesto(){return catRepuesto;}
    float getPrecio(){return precio;}
    int getUnidades(){return unidades;}

    bool grabar();
    int leer(int pos);
    void mostrar();

};

#endif // PRESUPUESTOREPUESTO_H

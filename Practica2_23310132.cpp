#include <iostream>
#include <string>

using namespace std;

class Usuario{
    protected:
     string nombre;
     string telefono;
     string psw;
     int edad;
    public:
     Usuario(string _nombre, string _telefono, string _psw, int _edad){
       nombre = _nombre;
       telefono = _telefono;
       psw = _psw;
       edad = _edad;
     }
     
    bool login(string nombre_usuario, string psw_usuario) {
    if (nombre_usuario == nombre && psw_usuario == psw) {
        cout << "\nInicio de sesion para " << nombre_usuario<<"."<< endl;
        return true;
    } else {
        cout << "Nombre de usuario o contrasena incorrectos." << endl;
        return false;
    }
    }

     void logout(){
        cout<<"Sesion cerrada para "<<nombre<<"."<<endl;
     }
    void cambiar_psw(string actual_psw, string nueva_psw){
        if(psw == actual_psw){
            psw = nueva_psw;
            cout<<"Contrasena actualizada."<<endl;
        } else{ cout<<"Las contrasenas no coinciden."<<endl;}
    }
};

class Cliente : public Usuario{
    public:
    Cliente(string _nombre, string _telefono, string _psw, int _edad):Usuario( _nombre, _telefono, _psw,  _edad){
     }
    void comprar(){
         cout<< nombre << " ha realizado su compra correctamente."<<endl;
    }
    void reclamar(){
         cout<< nombre << " procedio con una reclamacion."<<endl;
    }
    void devolucion(){
         cout<< nombre << " ha realizado una devolucion."<<endl; 
    }
};

class Vendedor : public Usuario{
    public:
    Vendedor(string _nombre, string _telefono, string _psw, int _edad):Usuario( _nombre, _telefono, _psw,  _edad){
     }
    void vender(){
         cout<< nombre << " ha realizado una venta."<<endl; 
    }
    void actualizarInv(){
         cout<< nombre << " ha actualizado inventario."<<endl;
    }
};

int main(){
    Cliente c1("Lucia","3323310132","Asap", 19);
    c1.login("Lucia", "Asap");
    c1.cambiar_psw("Asap", "Rocky");
    c1.comprar();
    c1.reclamar();
    c1.devolucion();
    c1.logout();

    Vendedor v1("Manu", "3340412378","Demons", 24);
    v1.login("Manu","Demons");
    v1.vender();
    v1.actualizarInv();
    v1.logout();
    return 0;
}
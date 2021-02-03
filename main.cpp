#include <iostream>
#include <fstream>

using namespace std;

void escribirArchivo();
void leerArchivo();
int menu();

int main(){
  int opc;
  do{
    opc=menu();
    cin.ignore();
    cout << endl;
    if(opc==1){
      escribirArchivo();
    }
    if(opc==2){
      leerArchivo();
    }
  }while(opc!=3);
  cout << "Hasta pronto..." << endl;
}

int menu(){
  int op;
  do{
    cout << " Opciones " << endl;
    cout << "1. Ingresar datos" << endl;
    cout << "2. Mostrar datos" << endl;
    cout << "3. Salir" << endl;
    cout << "Ingrese opcion: ";
    cin >> op;
  }while(op<1||op>3);
  return op;
}

void escribirArchivo(){
  string nombre;
  string apellido;
  string carrera;
  int edad;
  char r;
  ofstream archivoprueba;
  string nombrearchivo;
  
  nombrearchivo="contactos.txt";
  archivoprueba.open(nombrearchivo.c_str(),ios::out);
  cout << endl;

  cout<<"Ingrese el nombre del archivo: ";
  //while(getchar()!='\n');  
  getline(cin,nombrearchivo);

  do{
    cout << "Ingrese el nombre   : ";
    getline(cin,nombre);
    cout << "Ingrese el apellido : ";
    getline(cin,apellido);
    cout << "Ingrese la carrera  : ";
    getline(cin,carrera);
    cout << "Ingrese la edad     : ";
    cin >> edad;
    archivoprueba << nombre << " " << apellido << " " << carrera << " " << edad <<endl;
    cout << "\nDesea ingresar otro contacto (s/n): ";
    cin>>r;
    cin.ignore();
    cout << endl;
  }while(r=='s'||r=='S');
  archivoprueba.close();
}

void leerArchivo(){
  string nombre;
  string apellido;
  string carrera;
  int edad;
  
  ifstream archivolectura("contactos.txt");
  string texto;
  cout << endl;
  while(!archivolectura.eof()){
    archivolectura >> nombre >> apellido >> carrera >> edad;
    if(!archivolectura.eof()){
      cout << "Nombre   : " << nombre << endl;
      cout << "Apellido : " << apellido << endl;
      cout << "Carrera  : " << carrera << endl;
      cout << "Edad     : " << edad << endl;
      cout << endl;
    }
  }
  archivolectura.close();
}

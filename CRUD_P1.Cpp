#include <iostream>
using namespace std;

const char * nombre_archivo= "datos.dat"; // Nombre del archivo de entrada
struct Estudiante
{
    /* data */
int codigo;
char nombres[50];
char apellidos[50];
int telefono;
};

void leer();
void crear();

main(){
    leer();
//    crear();
    system("pause");
}

void leer(){
    system("cls");
    FILE* archivo = fopen(nombre_archivo, "rb");
    if(!archivo) {
        archivo = fopen(nombre_archivo,"w+b");
        cout << "No se pudo abrir el archivo"<<endl;
        
    }
    Estudiante estudiante;
    int id=0; //indice o pocision del registro dentro del archivo.
    fread(&estudiante,sizeof(Estudiante),1,archivo);
    cout<<"_____________________________________________-"<<endl;
    cout<<"ID"<<"|"<<"Codigo"<<"|"<<"Nombres"<<"|"<<"Apellidos"<<"|"<<"Telefono"<<endl;
    do
    {
    cout<<id<<"|"<<estudiante.codigo<<"|"<<estudiante.nombres<<"|"<<estudiante.apellidos<<"|"<<estudiante.telefono<<endl;
        id+=1;
    } while (feof(archivo)==0);
    fclose(archivo);



}

void crear(){
    FILE * archivo=fopen(nombre_archivo,"a+b");//abrir el archivo en modo binario para escritura y lectura
	char res;
    Estudiante estudiante;
	do{
        fflush(stdin);
    cout << "\n\tIngrese el Codigo: ";
    cin >> estudiante.codigo;
    cin.ignore();

    cout <<"ingrese Nombre: ";
    cin.getline(estudiante.nombres,50);
    cout<<"ingrese Apellido: ";
    cin.getline(estudiante.apellidos,50);

    cout << "\n\tIngrese Telefono: ";
    cin >> estudiante.telefono;

    fwrite(&estudiante,sizeof(Estudiante),1,archivo); //llamada a la función de guardado de datos

		cout<<"Desea Ingresar otro estudiante(s/n): ";
        cin>>res;        
	}while(res=='s'|| res=='S');
	
	
	fclose(archivo);
}

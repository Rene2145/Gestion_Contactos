#include <iostream>
#include <string>

using namespace std;

struct contactoEmail {
    string nombres, sexo, email, nacionalidad, telefono;
    int edad;

};


int main() {
    int opcion;
    do {
	    cout << "\nMENU DE CONTACTOS - EMAIL:\n";
	    cout << "--------------------------\n\n";
	    cout << "1) Agregar un nuevo contacto\n";
	    cout << "2) Eliminar un contacto existente\n";
	    cout << "3) Mostrar todos los contactos\n";
	    cout << "4) Listar contactos por correo\n";
	    cout << "5) Finalizar programa\n";
	    cout << "Escoge una opcion: ";	
        cin >> opcion;
        cin.ignore();
        switch(opcion) {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                cout << "\nCerrando el programa.\n";
                break;
            default:
                cout << "\nError: no se reconoce esta opcion.\n";
        }
    } while(opcion != 5);
    return 0;
}


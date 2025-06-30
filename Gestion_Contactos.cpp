#include <iostream>
#include <string>
using namespace std;

struct contactoEmail {
  	string nombres, sexo, email, nacionalidad, telefono;
    int edad;
};

contactoEmail contactos[60];
int total = 0;

void agregar();              
void eliminar();            
void mostrar();              
void ordenarPorDominio();    
int main() {
    char opcion;
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

        switch (opcion) {
            case 1: agregar(); break;
            case 2: eliminar(); break;
            case 3: mostrar(); break;
            case 4: ordenarPorDominio(); break;
            case 5: cout << "\nCerrando el programa.\n"; break;
            default: cout << "\nError: no se reconoce esta opcion.\n";
        }

    } while (opcion != 5);

    return 0;
}

void agregar() {
    if (total < 60) {
        cin.ignore();
        cout << "nombres completos: "; getline(cin, contactos[total].nombres);
        cout << "Sexo: "; getline(cin, contactos[total].sexo);
        cout << "Edad: "; cin >> contactos[total].edad; cin.ignore();
        cout << "Telefono: "; getline(cin, contactos[total].telefono);
        cout << "Email: "; getline(cin, contactos[total].email);
        cout << "Nacionalidad: "; getline(cin, contactos[total].nacionalidad);
        total++;
        cout << "El contacto fue añadido\n";
    } else {
        cout << "No peudes añadir mas contactos.\n";
    }
}
void eliminar() {
    string nombreBorrar;
    cin.ignore();
    cout << "Introduce el nombre del contacto que deseas eliminar: ";
    getline(cin, nombreBorrar);

    bool encontrado = false;
    for (int i = 0; i < total; i++) {
        if (contactos[i].nombres == nombreBorrar) {
            for (int j = i; j < total - 1; j++) {
                contactos[j] = contactos[j + 1];
            }
            total--;
            cout << "Se elimino el contacto.\n";
            encontrado = true;
            break;
        }
    }
    if (!encontrado) {
        cout << "No existe este contacto.\n";
    }
}
void mostrar() {
    if (total == 0) {
        cout << "Aun no cuentas con contactos guardados.\n";
        return;
    }

    for (int i = 0; i < total; i++) {
        cout << "\nContacto #" << (i + 1) << "\n";
        cout << "nombres: " << contactos[i].nombres << "\n";
        cout << "Sexo: " << contactos[i].sexo << "\n";
        cout << "Edad: " << contactos[i].edad << "\n";
        cout << "Teléfono: " << contactos[i].telefono << "\n";
        cout << "Email: " << contactos[i].email << "\n";
        cout << "Nacionalidad: " << contactos[i].nacionalidad << "\n";
    }
}
string dominio(string email) {
    size_t pos = email.find('@');
    return (pos != string::npos) ? email.substr(pos + 1) : "";
}

void ordenarPorDominio() {
    for (int i = 0; i < total - 1; i++) {
        for (int j = i + 1; j < total; j++) {
            if (dominio(contactos[i].email) > dominio(contactos[j].email)) {
                swap(contactos[i], contactos[j]);
            }
        }
    }

    cout << "\nContactos ordenados alfabeticamente por el dominio de su correo:\n";
    mostrar(); 
}


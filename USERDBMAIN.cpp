#include "USERDBHEADER.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

Usuario::Usuario(int id, const string& nombreUsuario, const string& nombreLegal, int edad)
    : ID(id), NombreUsuario(nombreUsuario), NombreLegal(nombreLegal), edad(edad) {}

ostream& operator<<(ostream& os, const Usuario& p) {
    return os << "("
              << p.ID << ", "
              << p.edad << ": "
              << p.NombreUsuario << ", "
              << p.NombreLegal
              << ")";
}

void displayUser(const Usuario& user) {
    cout << "ID: " << user.ID << endl;
    cout << "Nombre: " << user.NombreUsuario << endl;
    cout << "Nombre legal: " << user.NombreLegal << endl;
    cout << "Edad: " << user.edad << endl;
}

vector<Grupo> CrearGrupos() {
    vector<Grupo> grupos;

    Grupo grupo1 = {1, "Grupo A", {
        Usuario(1234, "Juan", "Juan Perez", 18),
        Usuario(5678, "Maria", "Maria Gonzales", 22),
        Usuario(2345, "Carlos", "Carlos Lopez", 24),
        Usuario(3456, "Lucia", "Lucia Sanchez", 27),
        Usuario(4567, "Miguel", "Miguel Torres", 30),
        Usuario(5678, "Ana", "Ana Romero", 21),
        Usuario(6789, "Ricardo", "Ricardo Perez", 26),
        Usuario(7890, "Valeria", "Valeria Castro", 23)
    }};

    Grupo grupo2 = {2, "Grupo B", {
        Usuario(2213, "Copernico", "Nicolas Copernico", 34),
        Usuario(2324, "Juan Pablo", "Juan Pablo Ruiz", 28),
        Usuario(3435, "Paola", "Paola Garcia", 22),
        Usuario(4546, "Eduardo", "Eduardo Lopez", 26),
        Usuario(5657, "Mariana", "Mariana Hernandez", 33),
        Usuario(6768, "Jose", "Jose Martinez", 25),
        Usuario(7879, "Elena", "Elena Sanchez", 31),
        Usuario(8980, "Fernando", "Fernando Torres", 29)
    }};


    Grupo grupo3 = {3, "Grupo C", {
        Usuario(3334, "Carlos", "Carlos Mendoza", 25),
        Usuario(4567, "Luis", "Luis Ramirez", 30),
        Usuario(5679, "Ana", "Ana Torres", 28),
        Usuario(6780, "Jose", "Jose Luis Rodriguez", 33),
        Usuario(7891, "Isabella", "Isabella Martinez", 24),
        Usuario(8902, "Eduardo", "Eduardo Sanchez", 26),
        Usuario(9013, "Sofia", "Sofia Diaz", 22),
        Usuario(1014, "Gabriel", "Gabriel Garcia", 29),
        Usuario(1125, "Lucia", "Lucia Perez", 27),
        Usuario(1236, "Ricardo", "Ricardo Gomez", 31),
        Usuario(1347, "Valeria", "Valeria Lopez", 23),
        Usuario(1458, "Pedro", "Pedro Gonzalez", 35),
        Usuario(1569, "Paola", "Paola Romero", 21),
        Usuario(1670, "Antonio", "Antonio Ruiz", 32),
        Usuario(1781, "Elena", "Elena Herrera", 26)
    }};

    Grupo grupo4 = {4, "Grupo D", {
        Usuario(1882, "Felipe", "Felipe Soto", 25),
        Usuario(1993, "Camila", "Camila Castillo", 23),
        Usuario(2104, "Adrian", "Adrian Perez", 29),
        Usuario(2215, "Teresa", "Teresa Sanchez", 24),
        Usuario(2326, "Manuel", "Manuel Garcia", 28),
        Usuario(2437, "Claudia", "Claudia Gonzalez", 22),
        Usuario(2548, "Ricardo", "Ricardo Fernandez", 30),
        Usuario(2659, "Maria", "Maria Lopez", 21),
        Usuario(2770, "Fernando", "Fernando Martinez", 31),
        Usuario(2881, "Alba", "Alba Ramirez", 26),
        Usuario(2992, "Hector", "Hector Diaz", 32),
        Usuario(3103, "Mercedes", "Mercedes Torres", 33),
        Usuario(3214, "Javier", "Javier Ruiz", 35),
        Usuario(3325, "Patricia", "Patricia Romero", 24),
        Usuario(3436, "Juan Carlos", "Juan Carlos Perez", 27)
    }};

    Grupo grupo5 = {5, "Grupo E", {
        Usuario(3547, "Francisco", "Francisco Soto", 26),
        Usuario(3658, "Carla", "Carla Jimenez", 22),
        Usuario(3769, "Manuel", "Manuel Ruiz", 30),
        Usuario(3870, "Valentina", "Valentina Martinez", 24),
        Usuario(3981, "Julio", "Julio Fernandez", 27),
        Usuario(4092, "Marta", "Marta Lopez", 28),
        Usuario(4203, "Alvaro", "Alvaro Perez", 31),
        Usuario(4314, "Teresa", "Teresa Rodriguez", 25),
        Usuario(4425, "David", "David Sanchez", 29),
        Usuario(4536, "Gabriela", "Gabriela Garcia", 21),
        Usuario(4647, "Ricardo", "Ricardo Jimenez", 33),
        Usuario(4758, "Vera", "Vera Gomez", 30),
        Usuario(4869, "Oscar", "Oscar Hernandez", 24),
        Usuario(4970, "Lina", "Lina Torres", 26),
        Usuario(5081, "Raul", "Raul Castro", 28)
    }};

    grupos.push_back(grupo1);
    grupos.push_back(grupo2);
    grupos.push_back(grupo3);
    grupos.push_back(grupo4);
    grupos.push_back(grupo5);

    return grupos;
}

bool login() {
    const string CorrUsuario = "admin";
    const string corrClave = "admin123";
    string UsuarioLogin, Clave;

    cout << "Ingrese su usuario: \n";
    cin >> UsuarioLogin;
    cout << "Ingrese su clave: \n";
    cin >> Clave;

    return (UsuarioLogin == CorrUsuario && Clave == corrClave);
}

void case1(const vector<Grupo>& grupos) {
    int grupoID, BusqID;
    cout << "Elija el grupo por ID: ";
    cin >> grupoID;

    bool grupoEncontrado = false;
    for (const auto& grupo : grupos) {
        if (grupo.id == grupoID) {
            grupoEncontrado = true;
            cout << "Busque un ID en el grupo " << grupo.nombre << ": ";
            cin >> BusqID;

            bool encontrado = false;
            for (const auto& user : grupo.usuarios) {
                if (BusqID == user.ID) {
                    displayUser(user);
                    encontrado = true;
                    break;
                }
            }
            if (!encontrado) {
                cout << "Usuario con ID " << BusqID << " no encontrado en el grupo." << endl;
            }
            break;
        }
    }
    if (!grupoEncontrado) {
        cout << "Grupo con ID " << grupoID << " no encontrado." << endl;
    }
}

void case2(vector<Grupo>& grupos) {
    int grupoID, BusqID2;

    while(true) {
        cout << "Elija el grupo por ID: ";
        cin >> grupoID;

        bool grupoEncontrado = false;

        for (auto& grupo : grupos) {
            if (grupo.id == grupoID) {
                grupoEncontrado = true;
                cout << "Elija el usuario por ID para editar en el grupo " << grupo.nombre << ": ";

                bool encontrado = false;

                while(true) {
                    cin >> BusqID2;

                    for (auto& user : grupo.usuarios) {
                        if (BusqID2 == user.ID) {
                            displayUser(user);

                            cout << "Ingrese el nuevo nombre de usuario: ";
                            cin.ignore();
                            getline(cin, user.NombreUsuario);

                            cout << "Usuario actualizado" << endl;
                            displayUser(user);

                            encontrado = true;
                        }
                    }

                    if (encontrado) {
                        break;
                    } else {
                        cout << "Usuario con ID " << BusqID2 << " no encontrado en el grupo. Intente de nuevo: \n";
                    }
                }

                break;
            }
        }

        if (!grupoEncontrado) {
            cout << "Grupo con ID " << grupoID << " no encontrado. Intente de nuevo: \n";
        } else {
            break;
        }
    }
}

void case3(const vector<Grupo>& grupos) {
    int grupoID;
    cout << "Elija el grupo por ID para ver todos los usuarios: ";
    cin >> grupoID;

    bool grupoEncontrado = false;
    for (const auto& grupo : grupos) {
        if (grupo.id == grupoID) {
            grupoEncontrado = true;
            for (const auto& user : grupo.usuarios) {
                displayUser(user);
            }
        }
    }
    if (!grupoEncontrado) {
        cout << "Grupo con ID " << grupoID << " no encontrado." << endl;
    }
}

bool SwitchReset() {
    char choice;
    cout << "\nDesea volver al menu principal? (Y/n): ";
    cin >> choice;
    return (choice == 'Y' || choice == 'y');
}

int main() {
    bool loggedIn = false;

    while (!loggedIn) {
        loggedIn = login();
        if (!loggedIn) {
            cout << "Acceso denegado. Intente de nuevo." << endl;
        }
    }

    vector<Grupo> grupos = CrearGrupos();

    int opcion;
    bool opc = false;
    int IterationCounter = 0;

    do {
        cout << "\nElija una opcion:" << endl;
        cout << "1) Buscar por ID en grupo" << endl;
        cout << "2) Editar usuario por ID en grupo" << endl;
        cout << "3) Ver todos los usuarios en un grupo" << endl;
        cout << "4) Salir" << endl;
        cin >> opcion;

        switch(opcion) {
            case 1:
                case1(grupos);
                break;

            case 2:
                case2(grupos);
                break;

            case 3:
                case3(grupos);
                break;

            case 4:
                cout << "Saliendo del sistema" << endl;
                return 0;

            default:
                cout << "Opcion no valida" << endl;
                cin.clear();
                cin.ignore();
                break;
        }

        opc = SwitchReset();

        IterationCounter++;

        if (IterationCounter > 5) {
            cout << "Exceso de intentos fallidos" << endl;
            break;
        }

    } while (opc);

    return 0;
}
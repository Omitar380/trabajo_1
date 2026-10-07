#include <iostream>
#include <cctype>
using namespace std;

struct Nodo {
    char letra;
    Nodo *sig;
};

void insertarAlFinal(Nodo *&cab, char letra);
void mostrarLista(Nodo *cab);
bool esVocal(char c);
bool empiezaConsonanteYTerminaDosVocalesIguales(Nodo *cab);
void liberarLista(Nodo *&cab);

int main() {
    Nodo *cab = nullptr;
    int n;
    char letra;

    cout << "Cuantas letras tiene la palabra? (minimo 3): ";
    cin >> n;

    if (n < 3) {
        cout << "Error: la lista debe tener minimo 3 nodos." << endl;
        return 0;
    }

    cout << "Ingrese las letras en MAYUSCULA (una por una):" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Letra " << i + 1 << ": ";
        cin >> letra;
        letra = toupper(static_cast<unsigned char>(letra));
        insertarAlFinal(cab, letra);
    }

    cout << "\nLista ingresada: ";
    mostrarLista(cab);

    bool resultado = empiezaConsonanteYTerminaDosVocalesIguales(cab);

    if (resultado) {
        cout << "\nResultado: TRUE - La palabra empieza en consonante y termina en dos vocales iguales." << endl;
    } else {
        cout << "\nResultado: FALSE - La palabra NO cumple la condicion." << endl;
    }

    liberarLista(cab);
    return 0;
}

void insertarAlFinal(Nodo *&cab, char letra) {
    Nodo *nuevo = new Nodo;
    nuevo->letra = letra;
    nuevo->sig = nullptr;

    if (cab == nullptr) {
        cab = nuevo;
    } else {
        Nodo *aux = cab;
        while (aux->sig != nullptr) {
            aux = aux->sig;
        }
        aux->sig = nuevo;
    }
}

void mostrarLista(Nodo *cab) {
    Nodo *aux = cab;
    while (aux != nullptr) {
        cout << aux->letra << " ";
        aux = aux->sig;
    }
    cout << endl;
}

bool esVocal(char c) {
    c = toupper(static_cast<unsigned char>(c));
    return (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}

bool empiezaConsonanteYTerminaDosVocalesIguales(Nodo *cab) {
    if (cab == nullptr || cab->sig == nullptr || cab->sig->sig == nullptr) {
        return false;
    }

    if (esVocal(cab->letra)) {
        return false;
    }

    Nodo *aux = cab;
    while (aux->sig != nullptr && aux->sig->sig != nullptr) {
        aux = aux->sig;
    }

    char penultima = aux->letra;
    char ultima = aux->sig->letra;

    return esVocal(penultima) && esVocal(ultima) &&
           toupper(static_cast<unsigned char>(penultima)) == toupper(static_cast<unsigned char>(ultima));
}

void liberarLista(Nodo *&cab) {
    Nodo *aux;
    while (cab != nullptr) {
        aux = cab;
        cab = cab->sig;
        delete aux;
    }
}
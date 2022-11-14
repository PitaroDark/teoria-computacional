#include <iostream>
#include <string>
#define comando "cls"

using namespace std;

struct zigma {
    string palabra;
    int posicion;
    struct zigma *siguiente;
};

bool includesTwins(string );
void showZigmas(struct zigma *);
void showZigmasFinal(struct zigma *, int);
struct zigma *newZigma(string , int );
struct zigma *searchZigma(struct zigma *, int );
void pause();

int main() {
    struct zigma *ptrZigma = NULL, *ptrCorredor, *ptrCorredorN;
    string palabra;
    bool bandera = false;
    int exponente;
    do{
        system(comando);
        cout<<"La cadena se separa por caracter, es decir, ab = { a, b }"<<endl;
        cout<<"L = ";
        cin>>palabra;
    }while(palabra.size() <= 0 || palabra.size() >= 9 || includesTwins(palabra));
    do{
        system(comando);
        cout<<"Ingrese su exponente dentro del rango 0 al 6"<<endl;
        cout<<"Exp = ";
        cin>>exponente;
    }while(exponente < 0 || exponente >= 7);
    //PROCESO DE EXPONENCIACION
    for(int i = 0; i < exponente; i++){
        for (int j = 0; j < palabra.size(); j++){
            if(i != 0){
                ptrCorredorN = searchZigma(ptrZigma, i-1);
                while (i-1 == ptrCorredorN->posicion){
                    ptrCorredor->siguiente=newZigma((palabra[j] + ptrCorredorN->palabra) ,i);
                    ptrCorredor = ptrCorredor->siguiente;
                    ptrCorredorN = ptrCorredorN->siguiente;
                }   
            }
            else{
                string aux(1, palabra[j]);
                if(ptrZigma != NULL){
                    ptrCorredor->siguiente = newZigma(aux, 0);
                    ptrCorredor = ptrCorredor->siguiente;
                }
                else{
                    ptrZigma = newZigma(aux, 0);
                    ptrCorredor = ptrZigma;
                    ptrCorredorN = ptrZigma;
                }
            }
        }
    }
    //MOSTRAR EN PANTALLA
    pause();
    system(comando);
    cout<<"Cadena -> "<<palabra<<endl<<"Exp -> "<<exponente<<endl;
    showZigmasFinal(ptrZigma, 1);//L base
    cout<<endl;
    //showZigmas(ptrZigma);
    showZigmasFinal(ptrZigma, exponente);
    return 1;
}

struct zigma *newZigma(string palabra, int posicion){
    struct zigma *newZigma = new struct zigma();
    newZigma->palabra = palabra;
    newZigma->posicion = posicion;
    newZigma->siguiente = NULL;
    return newZigma;    
}

struct zigma *searchZigma(struct zigma *ZIGMA, int posicion){
    struct zigma *aux = ZIGMA;
    while (aux != NULL && aux->posicion != posicion){
        aux = aux->siguiente;
    }
    return aux;
}

void showZigmas(struct zigma *ZIGMA){
    struct zigma *aux = ZIGMA;
    int posicion = 0;
    cout<<"\"Cadena Vacia\""<<endl;
    while (aux != NULL){
        cout<<aux->palabra;
        if (aux->siguiente != NULL && posicion == aux->siguiente->posicion ) cout<<" - "; else cout<<endl;
        aux = aux->siguiente;
        posicion = aux->posicion;
    }
}

void showZigmasFinal(struct zigma *ZIGMA, int exp){
    struct zigma *aux = ZIGMA;
    cout<<"L^"<<exp<<" = { ";
    while (aux != NULL){
        if(aux->posicion == exp-1){
            cout<<aux->palabra;
            if(aux->siguiente != NULL && aux->posicion == aux->siguiente->posicion )
                cout<<", ";
        }
        aux = aux->siguiente;
    }
    cout<<" }"<<endl;
}

bool includesTwins(string palabra) {
    for(int i = 0; i < palabra.size(); i++)
        for (int j = i; j < palabra.size(); j++)
            if(palabra[i] == palabra[j] && i != j)
                return true;
    return false;
}

void pause(){
    fflush(stdin);
    cout<<"Presiona enter para continuar...";
    cin.get();
}
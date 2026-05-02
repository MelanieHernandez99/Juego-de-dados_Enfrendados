#include <iostream>
#include "rlutil.h"
#include "funciones.h"
#include <vector>
#include <cstdlib>
using namespace std;

void jugar ()
{
system ("cls");


string  jugadores1, jugadores2;
bool turnoJugador1=false;
NombreJugadores(jugadores1, jugadores2);

string jugadores[2] = {jugadores1, jugadores2};
primeraRondaEmpieza(jugadores,turnoJugador1);
jugadorganador(jugadores,turnoJugador1);


system ("pause");

}


void NombreJugadores(string &jugadores1,string &jugadores2){

 for(int i=0;i<2;i++){
    if(i==0){
    cout<< "JUGADOR Nro 1 INGRESE SU NOMBRE:" ;
    cin>> jugadores1;
    }else{
    cout<< "JUGADOR Nro 2 INGRESE SU NOMBRE:";
    cin>> jugadores2
    ;
    }
 }
}


void dibujarDados(int dados[],int cant){


    for (int i = 0; i < cant; i++) {
        cout << " ____  ";
    }
    cout << endl;

    for (int i = 0; i < cant; i++) {
        cout << "|    | ";
    }
    cout << endl;


    for (int i = 0; i < cant; i++) {
        if (dados[i] > 9)
            cout << "| " << dados[i] << " | ";
        else
            cout << "| " << dados[i] << "  | ";
    }
    cout << endl;

    for (int i = 0; i < cant; i++) {
        cout << "|____| ";
    }
    cout << endl;



}





void dibujarDadosObjetivos(int dados[], string jugadores[], int cant) {

    for (int i = 0; i < cant; i++) {
        cout << jugadores[i] << "     ";
    }
    cout << endl;


    for (int i = 0; i < cant; i++) {
        cout << " ____  ";
    }
    cout << endl;

    for (int i = 0; i < cant; i++) {
        cout << "|    | ";
    }
    cout << endl;


    for (int i = 0; i < cant; i++) {
        if (dados[i] > 9)
            cout << "| " << dados[i] << " | ";
        else
            cout << "| " << dados[i] << "  | ";
    }
    cout << endl;

    for (int i = 0; i < cant; i++) {
        cout << "|____| ";
    }
    cout << endl;
}






void jugadorganador(string jugadores [], bool turnojugador1)
{
string jugadorActual[2];
string nombre1 = jugadores [0];
string nombre2 = jugadores [1];
int dados1[12], dados2[12];
int cantidadDados1 = 6, cantidadDados2 = 6;
int puntos1 = 0, puntos2 = 0;
int dadoobjetivo={};


bool fin=false;


 for (int ronda = 1; ronda <= 3; ronda++) {

        if (turnojugador1==true) {

            fin=turnoJugador(jugadores,true, dados1, cantidadDados1, dados2, cantidadDados2, puntos1, ronda);
             system("pause");
             system("cls");
            if (fin==true) {
                    break;
            }

            fin = turnoJugador(jugadores,false, dados2, cantidadDados2, dados1, cantidadDados1, puntos2, ronda);
            system("pause");
            system("cls");
            if (fin==true) {
                    break;
            }

        }
         else {
            fin = turnoJugador(jugadores,false, dados2, cantidadDados2, dados1, cantidadDados1, puntos2, ronda);
           system("pause");
           system("cls");
            if (fin==true) {
                    break;
            }
          fin = turnoJugador(jugadores,true, dados1, cantidadDados1, dados2, cantidadDados2, puntos1, ronda);
           system("pause");
             system("cls");
            if (fin==true){
                    break;
            }
        }

    }
  cout << endl;
   cout<< "puntaje acumulado:" << nombre1 <<":"<<  puntos1  << endl;
   cout<< "puntaje acumulado:" << nombre2 <<":"<<  puntos2  << endl;
    cout << "=========================================================================" << endl;


    if(puntos1==puntos2){
    cout<<"felicidades obtuvieron el mismo puntaje empataron!"<< endl;

}






    if (puntos1 >= dadoobjetivo && puntos1>puntos2) {
        cout<< nombre1 <<" ganaste tuviste mas puntos acumulados :"<< puntos1<< endl;
        cout<< nombre1 <<"  Se alcanzo el dado objetivo."                    <<  endl;
        cout << "=========================================================================" << endl;

        estadistica(nombre1,puntos1,false);

    system ("pause");
    }


    if(puntos2>=dadoobjetivo && puntos2>puntos1){
          cout<< nombre2<<" ganaste tuviste mas puntos acumulados :"  << puntos2         << endl;
          cout<<nombre2 <<" se alcanzo el dado objetivo. "                               << endl;
          cout << "=========================================================================" << endl;

         estadistica(nombre2,puntos2, false);
            system ("pause");
    }



    if(puntos1<dadoobjetivo && puntos2<dadoobjetivo){
        cout<<"no se alcanzo el objetivo"<< dadoobjetivo<< endl;
        cout<<"puntaje final de"<<nombre1<<puntos1<< endl;
        cout<<"puntaje final de"<<nombre2<<puntos2<< endl;
        cout << "=========================================================================" << endl;

        }
        system("cls");

    }


void estadistica(const string &nombre, int puntaje, bool mostrar) {
    static string rankingNombres[5] = {"", "", "", "", ""};
    static int rankingPuntajes[5] = {0, 0, 0, 0, 0};


    for (int i = 0; i < 5; i++){
        if (puntaje > rankingPuntajes[i]) {
            for (int j = 4; j > i; j--) {
                rankingPuntajes[j] = rankingPuntajes[j - 1];
                rankingNombres[j] = rankingNombres[j - 1];
            }

            rankingPuntajes[i] = puntaje;
            rankingNombres[i] = nombre;
            break;
        }
    }

if(mostrar==true) {
        cout << "------ RANKING ACTUAL ------" << endl;
        for (int i = 0; i < 5; i++) {
            if (rankingNombres[i] != "") {
                cout << i + 1 << "|. " << rankingNombres[i]<< " - " << rankingPuntajes[i] << " puntos" << endl;
            } else {
                cout << i + 1 << "|. ---" << endl;
            }
        }
    }



}




void primeraRondaEmpieza(string jugadores [],bool &turnoJugador1){



int dados[2]={};

do{



 dados[0]=TirarDado12Caras();
 dados[1]=TirarDado12Caras();

dibujarDadosObjetivos(dados,jugadores,2);

if(dados[0]==dados[1]){
    cout<<"el dado es el mismo, se repite la tirada"<< endl;
}
}while(dados[0]==dados[1]);


if(dados[0]>dados[1]){
cout << "=============================" << endl;
    cout << jugadores[0]<<" saco " <<dados[0]<< " puntos"<< endl;
    cout<<"empieza el jugador: "<< jugadores[0]<< " ya que saco "<< dados[0]<< " puntos" << endl;
turnoJugador1= true;
}else {
    cout << "=============================" << endl;
    cout << jugadores[1]<<" saco " <<dados[1]<< " puntos"<< endl;

cout<<"empieza el jugador "<< jugadores[1]<< " ya que saco "<< dados[1]<< " puntos" << endl;
turnoJugador1= false;
}

system("pause");
system("cls");
}

int TirarDado12Caras(){

int Dado=0;

return Dado=rand() % 12+1;

}

int TirarDado6Caras(){

int Dado=0;

return Dado=rand() % 6+1;

}

bool turnoJugador(string jugadores[],bool turnojugador1, int dadosStock[], int &cantidadDados, int dadosRival[], int &cantidadRival, int &puntaje, int &ronda) {
    cout<<endl<<endl;
    cout << " RONDA " << ronda << " :"<< endl;


    if (turnojugador1)
        {
                 cout << "Turno de jugador 1: " <<jugadores[0] << endl;
    }

     else
            {
                 cout << "Turno de jugador 2: " <<jugadores[1] << endl;
    }


    bool YaElegido[12]={};


    int dado[2]={};
    dado[0]=TirarDado12Caras();
    dado[1]=TirarDado12Caras();

    int objetivo = dado[0] + dado[1];

    cout << "Dados objetivos de 12 caras: " << dado[0] << " + " << dado[1] << " = OBJETIVO: " << objetivo << endl;


    for (int i = 0; i < cantidadDados; i++) {
        dadosStock[i] = TirarDado6Caras();


    }

dibujarDados(dadosStock,cantidadDados);
     cout << endl;


    cout <<"Que dados desea seleccionar?"<<endl<< "Tus dados stock:";

    for (int i = 0; i < cantidadDados; i++) {
        cout << "Dado " << i + 1 << ": " << dadosStock[i] << ".  ";

    }

    cout << endl;

    int suma = 0;
    int elegidos[12]={};
    int usados = 0;
    int dados;

    while (true) {
        cout << "Selecciona numero de dado (0 para rendirte): "<<"";
        cin >> dados;


        if (dados == 0) break;

        if (dados < 1 || dados > cantidadDados) {
            cout << "Numero invalido.";
            continue;
        }
        if(YaElegido[dados-1]){
            cout<<"ese dado ya fue elegido. Elije otro."<<endl;
            continue;

        }

        YaElegido[dados-1]=true;
        suma += dadosStock[dados - 1];
        elegidos[usados] = dados - 1;
        usados++;
       cout << " suma de los dados: " << suma << endl;


        if (suma == objetivo) {
            int puntos = objetivo * usados;
             cout << "en esta ronda sacaste: " << puntos << " puntos.";

            puntaje += puntos;
            cout<<endl;
            cout << "la combinacion total  es: " << suma << endl;
            cout <<"dados elegidos:("<< usados <<"dados)"<<endl;
            cout<<"puntos:"<<objetivo<<"x"<<usados<<"="<<puntos<<endl;
            cout<<"transferiste a tu rival: "<<usados<<" dados."<< endl;
            cout << "tirada exitosa! acumulaste " << puntaje << " puntos.";


            for (int i = 0; i < usados; i++) {
                dadosRival[cantidadRival] = 1;
                cantidadRival++;

            }


            for (int i = 0; i < usados; i++) {
                int pos = elegidos[i];
                dadosStock[pos] = dadosStock[cantidadDados - 1];
                cantidadDados--;
            }




            if (cantidadDados == 0) {
                puntaje += 10000;
                cout << " El jugador" << " se quedo sin dados y gana +10.000 puntos!";
                return true;
            }

            return false;
        }

        if (suma > objetivo) {
            cout << " Te pasaste del objetivo. Fallaste.";
            break;
        }
    }


    if (cantidadRival > 1) {
        dadosStock[cantidadDados] = 1;
        cantidadDados++;
        cantidadRival--;
        cout << " recibis 1 dado de penalidad.";
    } else {
        cout << "El rival no tiene dados suficientes para castigar.";
    }

    return false;
}


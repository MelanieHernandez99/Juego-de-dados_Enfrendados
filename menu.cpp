#include <iostream>
#include "rlutil.h"
#include <ctime>
#include "menu.h"
#include "funciones.h"
using namespace std;


int menu (){

bool respuesta=true;
int opcion;

do{
rlutil::setBackgroundColor(rlutil::LIGHTMAGENTA);
rlutil::cls();
rlutil::setColor(rlutil:: WHITE);




rlutil::locate(1050,1055);
  cout<<endl<<endl<<endl;
  cout<<"                 _______   _____________________   _____   ___ 	  ____  ____   _____        "<<endl;
  cout<<"                / ____/ | / / ____/ __  / ____/ | / / __ )/   |  / __ )/ __  /|  ___)        "<<endl;
  cout<<"               / __/ /  |/ / /_  / /_/ / __/ /  |/ / / / / /| | / / / / / / / |___  |       "<<endl;
  cout<<"              / /___/ /|  / __/ / _, _/ /___/ /|  / /_/ / ___ |/ /_/ / /_/ /   ___| |         "<<endl;
  cout<<"             /_____/_/ |_/_/   /_/ |_/_____/_/ |_/_____/_/  |_/_____/(____ /   |_____|          "<<endl;

rlutil::locate(3,24);
cout << "ELEGIR OPCION."<< endl ;
rlutil::locate(3,25);
cout << endl << endl;
rlutil::locate(3,26);
cout << "1- JUGAR " << endl;
rlutil::locate(3,27);
cout << "2- ESTADISTICAS " << endl;
rlutil::locate(3,28);
cout << "3- CREDITOS "<< endl;
rlutil::locate(3,29);
cout <<" ------------------------ "<<  endl;
rlutil::locate(3,30);
cout << "0- SALIR " <<endl;


cout<<"elegir opcion:";
  cin >> opcion;

  if(opcion==0){

     respuesta = salir();}

}while(respuesta==false);

return opcion;
}


void Ejecutar_menu(int opcion){

  switch (opcion){

   case 1 :
         jugar();
   break;

   case 2 :
         system ("cls");
         estadistica("",0,true);
         system ("pause");


   break;

   case 3 :
         MostrarCreditos();
   break;

   case 0 :
       system ("cls");
      cout << "Saliendo del juego..." << endl;
      cout<<"muchas gracias por jugar:)"<<endl;

       break;

    default:
          rlutil::setColor(rlutil::RED);
          cout << "opcion incorrecta. " << endl;

   break;

   }
  }










bool salir(){

string respuesta;
bool opcion;
cout<<"esta seguro que desea salir del juego? (si/no):";
cin>>respuesta;

if(respuesta=="si"){
    return opcion=true;

}
else{
    return opcion=false;
}
}


void MostrarCreditos(){
system("cls");
rlutil::locate(40,10);
cout<<"-----------------------------------------"<<endl;
rlutil::locate(40,11);
cout<<"|                                         |"<<endl;
rlutil::locate(40,12);
cout<<"|           CREDITOS                      |"<<endl;
rlutil::locate(40,13);
cout<<"-----------------------------------------"<<endl;
rlutil::locate(40,14);
cout<<"|    Nombre del equipo:                   |"<<endl;
rlutil::locate(40,15);
cout<<"|                                         |"<<endl;
rlutil::locate(40,16);
cout<<"|    Integrantes del grupo:               |"<<endl;
rlutil::locate(40,17);
cout<<"|                                         |"<<endl;

rlutil::locate(40,18);

cout<<"|    melanie hernandez ,                  |"<<endl;

rlutil::locate(40,19);
cout<<"|                                         |"<<endl;
rlutil::locate(40,20);
cout<<"|    Creador de rlutil:                   |"<<endl;
rlutil::locate(40,21);
cout<<"|      Tapio Vierros                      |"<<endl;
rlutil::locate(40,22);
cout<<" -----------------------------------------"<<endl<< endl;



system("pause");

}



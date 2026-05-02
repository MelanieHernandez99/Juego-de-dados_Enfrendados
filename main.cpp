#include "menu.h"
#include<iostream>
#include <ctime>
#include "rlutil.h"


using namespace std;



int main(){

srand (time(0));
int opcion;


  do{

     opcion=menu();
     Ejecutar_menu(opcion);

    }while(opcion!=0);




 return 0;
}

//NUMERO ESPEJO POR FUNCION RECURSIVA
//30/05/23
//MIGUEL FLORES
//ESTE PORGRAMA IMPRIME EL NUMERO ESPEJO UTILIZANDO FUNCION RECURSIVA

#include <stdio.h>

//PROTOTIPO DE LA FUNCION
 void espejo(int n);

int main(){
    //DECLARACION DE VARIABLES
    int n;
    //PETICION DE DATOS
    printf("Ingrese el numero que desea convertir a espejo: ");
    scanf("%d",&n);
    //INVOCACION
    espejo(n);
}

//FUNCION
  void espejo(int n){
    if(n==0){
        return;
    }
    else{
        printf("%d",n%10);
        espejo(n/10);
    }

 }

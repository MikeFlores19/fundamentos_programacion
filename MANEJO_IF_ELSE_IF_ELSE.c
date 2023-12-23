//SET DE TENNIS
//11/03/23
//MIGUEL ALEJANDRO FLORES SOTELO
//Este programa muesta como es el uso de condicionales

//Bibliotecas
#include <stdio.h>
//Funcion principal
int main (){
//Declarar variables
int resultjuga;
int resultjugb;

//Mensaje de inicio
printf("Este programa muestra quien gano lo sets del partido");

//Peticion de datos
printf("\n\nIngrese cuantos sets ha ganado el jugador a: ");
scanf("%d",&resultjuga);
printf("Ingrese cuantos sets ha ganado el jugador b: ");
scanf("%d",&resultjugb);

//Realizar operaciones y resultados
if ((resultjuga>=0 && resultjugb>=0) && (resultjuga<=7 && resultjugb<=7)){
    if (resultjuga<=5 && resultjugb<=5){
        printf("El juego aun no ha terminado ");
    }
    else if(resultjuga==6 && resultjugb==5){
        printf("El juego aun no ha terminado");
    }
    else if(resultjugb==6 && resultjuga==5){
        printf("El juego aun no ha terminado"); 
    }
    else if(resultjuga==6 && resultjugb==6){
        printf("El juego aun no ha terminado, el primero que llegue a 7 sets gana");
    }
    else if (resultjuga==7 && resultjugb<5){
        printf("Datos invalidos");
    }
    else if (resultjugb==7 && resultjuga<5){
        printf("Datos invalidos");
    }
     else if (resultjuga==7 && resultjugb==7){
        printf("Datos invalidos");
    }
    else if(resultjuga==6 && resultjugb<=4){
        printf("El jugador A ha ganado");
    }
    else if(resultjugb==6 && resultjuga<=4){
        printf("El jugador B ha ganado");
    }
    else if (resultjuga==7 && resultjugb==5){
        printf("El jugador A ha ganado");
    }
    else if(resultjugb==7 && resultjuga==5 ){
        printf("El jugador B ha ganado");
    }
}
else{
    printf("No se aceptan valores mayores a 7 y menores a 0");
}
return 0;
}

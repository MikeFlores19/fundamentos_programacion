//Longitud de alambre
//01/03/2023
//Miguel Alejandro Flores Sotelo
//Este programa muestra como manejar los operadores aritmeticos y uso de variables



//Bibliotecas
#include <stdio.h>
#include <math.h>

//Funcion principal
int main(){

//Declarar variables
float longitud;
float x;
float acuadrado;
float acircunferencia;
float areatotal;

const float pi=3.1416;
//Mensaje de inicio
printf("Este programa calcula en donde debe cortarse el alambre para obtener un area minima para las dos figuras");

//Peticion de datos
printf("\n\nIntroduce la longitud del alambre en metros: ");
scanf("%f",&longitud);

//Realizar operaciones
x=(8*longitud/(2*pi+8));
acuadrado=pow(x,2)/16;
acircunferencia=pow(longitud-x,2)/(4*pi);
areatotal=acuadrado+acircunferencia;

//Resultado
printf("\nEl alambre debe cortarse en: %0.2f m",x);
printf("\nEl area minima total de las dos figuras es: %0.2f m^2",areatotal);
printf("\nEl area del cuadrado es: %0.2f m^2",acuadrado);
printf("\nEl area de la circunferencia es: %0.2f m^2",acircunferencia);

return 0;
}


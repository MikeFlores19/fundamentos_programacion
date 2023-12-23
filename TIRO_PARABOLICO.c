//Miguel Flores
//Este programa muestra por medio del tiro parabolico los resultados de la velocidad inicial y el angulo de inclinacion en grados por medio de datos que ingresa el usuario
//Permite mostrar y leer datos de entrada

#include <stdio.h> 
#include <math.h>

//Funcion principal
int main ()
{
	//Declarar variables
	float distancia;
	float tiempo;
	float velocidadix;
	float velocidadiy;
	float gravedad=9.82;
    float velocidadixy;
    float angulo;
	
	printf("Introduce la distancia en metros recorrida por el proyectil: ");
	scanf("%f",&distancia);
	
	printf("Introduce el tiempo de vuelo en segundos del proyectil: ");
	scanf("%f",&tiempo);
	
	//Realizar operaciones
	velocidadix=distancia/tiempo;
	velocidadiy=(gravedad*tiempo)/2;
    velocidadixy=sqrt(pow(velocidadix,2)+pow(velocidadiy,2));
    angulo= atan(velocidadiy/velocidadix);

	//Resultados
	printf("La velocidad en el eje x es: %.2f m/s \n",velocidadix);
    printf("La velocidad en el eje y es: %.2f m/s \n",velocidadiy);
	printf("La velocidad inicial del proyectil es: %.2f m/s \n",velocidadixy);
    printf("El angulo de inclinacion es: %.2f grados ",angulo*180/3.1416);
	return 0;
}
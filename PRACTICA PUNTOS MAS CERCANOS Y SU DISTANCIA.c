//27/03/23
//Miguel Alejandro Flores Sotelo
//Este programa muestra el uso de las estructuras de control

//BIBLIOTECAS
 #include <stdio.h>
 #include <math.h>
 
 //FUNCION PRINCIPAL
 int main (){
 	//DECLARACION DE VARIABLES
 	system("color 02");
 	int n,i,j;
 	float array_x[200], array_y[200];
	float distancia,distancia_minima=999999;
	float x1,y1,x2,y2;
 	//MENSAJE INICIAL
 	printf("Este programa muestra cuales son los puntos mas cercanos y calcula su distancia\n");
 	//SOLICITA EL NUMERO DE PUNTOS AL USUARIO
 	printf("Ingrese el numero de puntos que desea utilizar: ");
 	scanf("%d",&n);
 	
 	//CONDICION PAR QUE SE EJECUTE EL CODIGO
 	if (n>=3){
	
	//SOLICITA LAS COORDENADAS DE LOS PUNTOS Y LAS ALMACENA EN LOS ARREGLOS
 	for (i=0;i<n;i++){
 		printf("Ingrese en el formato x%d,y%d: ",i+1,i+1);
 		scanf("%f,%f",&array_x[i],&array_y[i]);
	}
	//IMPRIME LOS PUNTOS ALMACENADOS EN LOS ARREGLOS (X,Y)
	for (i=0;i<n;i++){
		printf("Las coordenada %d es (%.0f,%.0f)\n",i+1,array_x[i],array_y[i]);
	}
	//BUSCA EL PAR DE PUNTOS MAS CERCANOS Y CALCULA LA DISTANCIA ENTRE ELLOS
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			distancia=sqrt(pow(array_x[j]-array_x[i],2)+pow(array_y[j]-array_y[i],2));
			if (distancia<distancia_minima){
				distancia_minima=distancia;
				x1=array_x[i];
				y1=array_y[i];
				x2=array_x[j];
				y2=array_y[j];
			}
		}
	}
	//MUESTRA LOS RESULTADOS (COORDENADAS DE LOS PUNTOS MAS CERCANOS Y LA DISTANCIA)
	printf("Los puntos mas cercanos son (%.0f,%.0f) y (%.0f,%.0f) y la distancia es %.4f",x1,y1,x2,y2,distancia_minima);
    }
    //POR SI LA PRIMERA CONDICION IF NO SE CUMPLE 
    else{
    	printf("Para medir los puntos mas cercanos debe ingresar mas de 2 puntos");
	}
	 return 0;	
 }

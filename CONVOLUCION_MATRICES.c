//Convolución de matrices
///04/23
//Miguel Alejandro Flores Sotelo
//Este programa muestra la convolución de matrices 
#include <stdio.h>
int main(){
	printf("Programa que muestra el resultado de la convolucion de mtrices\n\n");
	
	

	//DECLARACION DE VARIABLES
	int f[7][7]={0};
	int g[3][3]={{1,2,1},{2,4,2},{1,2,1}};
	int h[5][5]={0};
	int i,j,k,l,m,n;
	
	printf("Inserte los valores la matriz f:\n");
	//PETICION DE LA MATRIZ F
	for (i=2;i<5;i++){
		for(j=2;j<5;j++){
			scanf("%d",&f[i][j]);
		}
	}
	
	printf("\n");
	//IMPRESION DE LA MATRIZ F
	printf("La matriz f es:\n");
	for (i=0;i<7;i++){
		for(j=0;j<7;j++){
			printf("%d ",f[i][j]);
		}
	printf("\n");
	}
	printf("\n");
	//IMPRESION DE LA MATRIZ G
	printf("La matriz g es:\n");
	for(k=0;k<3;k++){
		for(l=0;l<3;l++){
			printf("%d ",g[k][l]);
		}
	printf("\n");
	}
	
	printf("\n");
	//CONVOLUCION DE LAS MATRICES
	for(i=2;i<7;i++){
		for(j=2;j<7;j++){
			for(k=0;k<3;k++){
				for(l=0;l<3;l++){
					h[i-2][j-2]+=g[k][l]*f[i-k][j-l];
				}
			}
		}
	}
	
	//IMPRESION DE LA MATRIZ RESULTANTE
	printf("La matriz resultante de la convolucion es: \n");
	for (m=0;m<5;m++){
		for(n=0;n<5;n++){
			printf("%d ",h[m][n]);
		}
	printf("\n");
	}
	
	
	
	
	
	
	
	
	
	
	return 0;
}

//PI POR METODO DE MONTECARLO
//28/05/23
//MIGUEL FLORES
//PROGRAMA QUE UTILIZA EL METODO DE MONTECARLO PARA APROXIMAR EL NUMERO PI

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// PROTOTIPO DE FUNCIONES
void distancia(double[], double[], long int, double[]);
void dentro_circulo(double[],long int,int*,int*);
void imprimir(double [20][20], double [], long int, double [], double[]);
void calcular_pi(int *,int *,float *,float*);



int main() {
    // DECLARACION DE VARIABLES
    double x[10000], y[10000],d[10000],matriz [20][20];
    long int n;
    int cont_circ_punt,cont_cuadr_punt;
    float aproxpi,margen_error;

    srand(time(NULL));

    // MENSAJE DE INICIO
    printf("ESTE PROGRAMA CALCULA LA APROXIMACION DE PI POR EL METODO DE MONTECARLO (LIMITE DE GOTAS ES DE 9999)\n");

    // PETICION DE VARIABLES
    printf("Ingresa el numero de gotas de lluvia: ");
    scanf("%ld", &n);

    for (int i = 0; i < n; i++) {
        x[i] = 1 - 2 * (double)rand() / RAND_MAX;//RAND_MAX ES LA CONSTANTE DEL MAXIMO NUMERO DE rand()
        y [i]= 1 - 2 * (double)rand() / RAND_MAX;
        printf("El punto %ld es (%lf,%lf)\n", i + 1, x[i],y[i]);

    }

    // INVOCACION DE FUNCIONES
    printf("\n");
    distancia(x,y,n,d);
    for (int i = 0; i < n; i++) {
        printf("La distancia del punto %d (%lf,%lf) respecto al origen es %lf\n", i + 1, x[i], y[i], d[i]);
    }
    printf("\n");
    dentro_circulo(d,n,&cont_circ_punt,&cont_cuadr_punt);
    printf("Hay %d puntos dentro del circulo\n",cont_circ_punt);
    printf("Hay %d puntos fuera del circulo pero dentro del cuadrado\n",cont_cuadr_punt);

    imprimir(matriz,d,n,x, y);
    calcular_pi(&cont_circ_punt,&cont_cuadr_punt,&aproxpi,&margen_error);
    printf("La aproximacion de PI es %f\n",aproxpi);
    printf("El margen de error es %f\n",margen_error);





    return 0;
}

// FUNCIONES
void distancia(double x[], double y[], long int n, double d[]) {
        for(int i=0;i<n;i++){
        d[i] = pow(x[i], 2) + pow(y[i], 2);
        }
}

void dentro_circulo(double d[],long int n,int *cont_circ_punt,int *cont_cuadr_punt){
    *cont_circ_punt=0;
    *cont_cuadr_punt=0;
    for(int i=0;i<n;i++){
        if(d[i]<1){
            (*cont_circ_punt)++;
            printf("La distancia %lf=1\n",d[i]);
        }
        else{
            printf("La distancia %lf=0\n",d[i]);
            (*cont_cuadr_punt)++;
        }
    }
    printf("\n");
}



void imprimir(double matriz[20][20], double d[], long int n,double x[],double y[]){
    for (int i = 0; i < n; i++) {
        if (d[i] <= 1) {
            int coord_mtz_x = (x[i]+1)*10;//DE UN RANGO DE [-1,1] AL SUMARLE 1 PASA A [0,2] Y AL MULTIPLICARLO PASA A UN RANGO DE [1,20]
            int coord_mtz_y = (y[i]+1)*10;//DE UN RANGO DE [-1,1] AL SUMARLE 1 PASA A [0,2] Y AL MULTIPLICARLO PASA A UN RANGO DE [1,20]
            matriz[coord_mtz_x][coord_mtz_y]++;//SE VA INCREMENTANDO EL VALOR DE 1 EN 1 EN LAS COORDENAS CORRESPONDIENTES
        }
        system ("cls");
        for(int i=0;i<20;i++){//FILAS DE LA MATRIZ
            for(int j=0;j<20;j++){//COLUMNAS DE LA MATRIZ
                if(matriz[i][j]>0){//SE UTILIZA LA CONDICION MAYOR A CERO PARA QUE SOLO SE IMPRIMAN LAS COORDENAS EN DONDE TENGAN VALOR DE LO CONTRARIO SE IMPRIMIRA UN ESPACIO EN BLANCO
                    if(matriz[i][j]<=4){
                        printf("%c",176);
                    }
                    else if(matriz[i][j]<=8){
                        printf("%c",177);
                    }
                    else if(matriz[i][j]<=12){
                        printf("%c",178);
                    }
                    else{
                        printf("%c",219);
                    }

                }
                else{
                    printf(" ");//INDICA QUE ESA POSICION NO TIENE NINGUN VALOR POR LO TANTO ESTA VACIA Y NO SE IMPRIMRIA NADA
                }
            }
            printf("\n");//SALTO DE LINEA CADA QUE TERMINE UNA FILA
        }
    }
}

void calcular_pi(int *cont_circ_punt,int *cont_cuadr_punt,float *aproxpi,float *margen_error){

    *aproxpi=4*((float)*cont_circ_punt)/((float)*cont_circ_punt+((float)*cont_cuadr_punt));
    *margen_error=(*aproxpi)-M_PI;
}














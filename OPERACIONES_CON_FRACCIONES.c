
//FRACCIONES CON FUNCIONES
//24/03/23
//MIGUEL FLORES
//PROGRAMA QUE UTILIZA EL MANEJO DE FUNCIONES CON LAS FRACCIONES

#include <stdio.h>


// PROTOTIPO DE FUNCIONES
void mostrarmenu(void);
void leerfraccion(int, int[], int[]);
void escribirfraccion(int, int[], int[]);
void suma(int [],int[],int ,int *,int *);
void restar(int [],int [],int,int*,int*);
void multiplicar(int[],int[],int,int*,int*);
void dividir(int[],int[],int,int*,int*);
void conversion(int[],int[],int);
void simplificar(int*,int*);
int MCD(int, int);

int main() {
    // DECLARACION DE VARIABLES
    int n, i, opc;
    int numerador[100] = {0};
    int denominador[100] = {0};
    int resultadonum,resultadodenom;
    float result;

    // MENSAJE DE INICIO
    printf("ESTE PROGRAMA MUESTRA EL MANEJO DE FUNCIONES CON FRACCIONES\n");

    // PETICION DEL NUMERO DE FRACCIONES
    printf("Cuantas fracciones desea utilizar: ");
    scanf("%d", &n);
    //INVOCACION DE FUNCIONES
    if(n>=1){
        leerfraccion(n, numerador, denominador);  // FUNCION LEER FRACCION
        printf("\n");
        escribirfraccion(n, numerador, denominador);  // FUNCION ESCRIBIR FRACCION
        printf("\n");
        mostrarmenu();  // FUNCION MOSTRAR MENU
        scanf("%d", &opc);

        //REPETICION DEL MENU E INVOCACION DE FUNCIONES
        while (opc != 6) {
            if (opc == 1) {
                suma(numerador,denominador,n,&resultadonum,&resultadodenom);
                printf("La suma es: %d/%d\n",resultadonum,resultadodenom);
                simplificar(&resultadonum, &resultadodenom);
                printf("La suma simplificada es: %d/%d\n",resultadonum,resultadodenom);
            } else if (opc == 2) {
                restar(numerador,denominador,n,&resultadonum,&resultadodenom);
                printf("La resta es: %d/%d\n",resultadonum,resultadodenom);
                simplificar(&resultadonum,&resultadodenom);
                printf("La resta simplificada es: %d/%d\n",resultadonum,resultadodenom);
            } else if (opc == 3) {
                multiplicar(numerador,denominador,n,&resultadonum,&resultadodenom);
                printf("La multiplicacion es: %d/%d\n ",resultadonum,resultadodenom);
                simplificar(&resultadonum,&resultadodenom);
                printf("La multiplicacion simplificada es: %d/%d\n",resultadonum,resultadodenom);
            } else if (opc == 4) {
                dividir(numerador,denominador,n,&resultadonum,&resultadodenom);
                printf("La division es: %d/%d\n ",resultadonum,resultadodenom);
                simplificar(&resultadonum,&resultadodenom);
                printf("La division simplificada es: %d/%d\n",resultadonum,resultadodenom);
            } else if (opc == 5) {
                conversion(numerador,denominador,n);
            } else {
                printf("Opcion no valida");
            }
            printf("\n");
            mostrarmenu();
            scanf("%d", &opc);
        }
        printf("HASTA PRONTO!");
    }
    else{
        printf("Se debe ingresar mas de una fraccion");
    }
}

// FUNCIONES
void mostrarmenu(void) {
    printf("\n\n");
    printf("MENU\n");
    printf("1.-Sumar fracciones\n");
    printf("2.-Restar fracciones\n");
    printf("3.-Multiplicar fracciones\n");
    printf("4.-Dividir fracciones\n");
    printf("5.-Conversion de fracciones a decimales\n");
    printf("6.-Salir\n");

    printf("Introduce la opcion que deseas realizar: ");
}

void leerfraccion(int n, int numerador[], int denominador[]) {
        for (int i = 0; i < n; i++) {
            printf("Ingrese el numerador %d: ", i + 1);
            scanf("%d", &numerador[i]);
            do{
            printf("Infrese el denominador %d: ", i + 1);
            scanf("%d", &denominador[i]);
            } while(denominador[i]==0);
        }
    }

void escribirfraccion(int n, int numerador[], int denominador[]) {
    for (int i = 0; i < n; i++) {
        if (denominador[i] != 1) {
            printf("La fraccion %d es: %d/%d\n",i+1, numerador[i], denominador[i]);
        } else {
            printf("La fraccion %d es: %d\n", i+1,numerador[i]);
        }
    }
}

void suma(int numerador[],int denominador[],int n,int *resultadonum,int *resultadodenom){
    *resultadonum=numerador[0];
    *resultadodenom=denominador[0];

    for(int i=1;i<n;i++){
        *resultadonum=(*resultadonum*denominador[i])+(numerador[i]*(*resultadodenom));
        *resultadodenom=*resultadodenom*denominador[i];
    }
}

void restar(int numerador[],int denominador[],int n,int *resultadonum,int *resultadodenom){
    *resultadonum=numerador[0];
    *resultadodenom=denominador[0];
    for(int i=1;i<n;i++){
        *resultadonum=(*resultadonum*denominador[i])-(numerador[i]*(*resultadodenom));
        *resultadodenom=*resultadodenom*denominador[i];
    }
}

void multiplicar(int numerador[],int denominador[],int n,int *resultadonum,int *resultadodenom){
    *resultadonum=numerador[0];
    *resultadodenom=denominador[0];
    for (int i=1;i<n;i++){
        *resultadonum=*resultadonum*numerador[i];
        *resultadodenom=*resultadodenom*denominador[i];
    }
}

void dividir(int numerador[],int denominador[],int n,int *resultadonum,int *resultadodenom){
    *resultadonum=numerador[0];
    *resultadodenom=denominador[0];
    for (int i=1;i<n;i++){
        *resultadonum=*resultadonum*denominador[i];
        *resultadodenom=*resultadodenom*numerador[i];
    }
}

void conversion(int numerador[],int denominador[],int n){
    printf("La conversion a decimales son:\n");
    for(int i=0;i<n;i++){
        float result=0;
        result=(float)numerador[i]/(float)denominador[i];
        printf("Fraccion %d es: %.2f\n",i+1,result);
    }
    printf("\n");
    printf("La conversion a mixtas de las fracciones impropias son:\n ");
     for(int i=0;i<n;i++){
        if(numerador[i]>denominador[i]){
               int parteentera=0;
               int partenum=0;
               int partedenom=0;

                parteentera=numerador[i]/denominador[i];
                partenum=numerador[i]%denominador[i];
                partedenom=denominador[i];
                printf("La fraccion %d es: %d %d/%d\n",i+1,parteentera,partenum,partedenom);
        }
        else{
            printf("La fraccion %d no es una fraccion impropia\n",i+1);
        }
    }
}

void simplificar(int *resultadonum, int *resultadodenom) {
    int mcd;
        mcd = MCD(*resultadonum, *resultadodenom);
        *resultadonum = *resultadonum/ mcd;
        *resultadodenom = *resultadodenom / mcd;
}

int MCD(int a, int b) {
    while (b != 0) {
        int c = b;
        b = a % b;
        a = c;
    }
    return a;
}









	//APROXIMCACION DE FUNCIONES TRIGONOMETRICAS
//MIGUEL ALEJANDRO FLORES SOTELO
//22/03/23
//ESTE PROGRAMA MUESTRA EL USO DE ESTRUCTURAS DE CONTROL 

//BIBLIOTECAS
#include <stdio.h>
#include <math.h>

//FUNCION PRINCIPAL
int main() {
//DELCARACION DE VARIBALES
    int opc, aprox;
    float x, seno = 0, coseno = 0;
    long long int factorial;
//MENSAJE DE INICIO
    printf("Este programa calcula la aproximacion de senos o cosenos\n\n");
//MENU 
    printf("ELIGE UNA OPCION:\n\n1.-Calcular aproximacion de senos\n2.-Calcular aproximacion de cosenos\n\n");
    printf("Dame una opcion: ");
    scanf("%d", &opc);
//CASOS A ELEGEIR Y OPERACIONES
    switch (opc) {
    	//CALCULAR SENO
        case 1:
            printf("Ingresa el valor de angulos en grados: ");
            scanf("%f", &x);
            x = (x * 6.28) / 360.0;
            printf("Ingresa el numero de terminos de aproximacion: ");
            scanf("%d", &aprox);
            seno = x;
            for (int i = 2; i <= aprox; i++) {
                factorial = 1;
                for (int j = 1; j <= (2 * i - 1); j++) {
                    factorial *= j;
                }
                seno += (pow(-1, (i - 1)) * pow(x, 2 * i - 1)) / factorial;
            }
            //RESULTADO DE SENO
            printf("El resultado es: %f", seno);
            break;
        //CALCULAR COSENO
        case 2:
        	
            printf("Ingresa el valor de x en grados: ");
            scanf("%f", &x);
            x = (x * 6.28) / 360.0;
            printf("Ingresa el numero de terminos de aproximacion: ");
            scanf("%d", &aprox);
            coseno = 1;
            for (int i = 1; i <= aprox; i++) {
                factorial = 1;
                for (int j = 1; j <= 2 * i; j++) {
                    factorial *= j;
                }
                coseno += (pow(-1, i) * pow(x, 2 * i)) / factorial;
            }
            //RESULTADO DE COSENO
            printf("El resultado es: %f", coseno);
            break;

        default:
            printf("Opcion invalida");
            break;
    }

    return 0;
}

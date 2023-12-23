//KNN
//JUAN FLORES, MIGUEL FLORES, OSCAR AYALA
//03/06/26
//ESTE PORGRAMA MUESTA EL APRENDIZAJE MAQUINA POR MEDIO DEL KNN
void numeros_rand(float [],float [],float []);
void impresion_centroides(float [],float [],float []);
float distance(float [][4], float [], int );
#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
//PROTOTIPO DE FUNCIONES


int main (){
    //MENSAJE DE INICIO
    printf("Este porgrama muestra el algortimo de agrupación.\n");

    //INICIALIZACION DE VARIABLES
    int i=0,j=0,k=0,l=0;
    float datos[150][4];
    float c1[4],c2[4],c3[4];
    char *token;
    char titulos[100],linea[100];
    srand(time(NULL));

    //ABRIR EL DOCUMNETO
    FILE *valores;
    valores=fopen("IRIS.csv","r");
    if(valores==NULL){
        printf("\nEl archivo no se pudo abrir");
    }
    else{
       fgets(titulos,100,valores);//QUITA EL TITOULO DE CADA COLUMNA

        while(feof(valores)==0 && i<150){
            fgets(linea,100,valores);
            token=strtok(linea,",");//TROZEA LOS CAMPOS DE LA FILA POR CADA UNA
            j=0;
            while(token!=NULL){
                if(j<4){
                    datos[i][j]=atof(token);//GUARDA LOS NUMEROS
                    token=strtok(NULL,",");//AVANZA AL SIGUIENTE ELEMENTO
                    j++;
                }
                else{
                    strcpy(titulos,token);//CUANDO LLEGA AL NOMBRE DE ESPECIE,SIMPLEMENTE SE COPIA A OTRO LADO
                    token=strtok(NULL,",");
                }
            }
            token=strtok(NULL,",");//AVANZA A LA SIGUIENTE FILA
            i++;
        }
    }
    fclose(valores);

   //GENERAR CENTROIDES ALEATORIOS
    numeros_rand(c1,c2,c3);
    //COMPRIBACION DE GENERACION DE CENTROIDES
    printf("\nLos valores generados para los centroides son: \n");
    impresion_centroides(c1,c2,c3);

    //VERIFICA DISTANCIA DE LOS CENTROIDES A LOS DATOS DE LAS PLANTAS
    for(int l=0;l<250;l++){
        float nuevoc1[4] = {0};
        float nuevoc2[4] = {0};
        float nuevoc3[4] = {0};
        int cont_c1 = 0;
        int cont_c2 = 0;
        int cont_c3 = 0;
        for(int i=0;i<150;i++){//MANEJA LAS FILAS DE LOS DATOS
            float distancia_c1=0,distancia_c2=0,distancia_c3=0;
                //Saca la distancia entre el punto y los centroides
                distancia_c1=distance(datos,c1,i);
                distancia_c2=distance(datos,c2,i);
                distancia_c3=distance(datos,c3,i);


                //CLASIFICA QUE QUE DATOS DE LAS PLANTAS SON MAS CERCANOS A LOS CENTROIDES
                if(((distancia_c1<distancia_c2) && (distancia_c2<distancia_c3)) ||((distancia_c1<distancia_c3) && (distancia_c3<distancia_c2))){
                    for(int k=0;k<4;k++){
                        nuevoc1[k]+=datos[i][k];

                    }
                    cont_c1++; //Cuenta cada vez que el punto sí es el más cercano al centroide

                }
                else if(((distancia_c2<distancia_c1) && (distancia_c2<distancia_c3)) ||((distancia_c2<distancia_c3) && (distancia_c3<distancia_c1))) {
                    for(int k=0;k<4;k++){
                        nuevoc2[k]+=datos[i][k];
                    }
                    cont_c2++;

                }
                else if(((distancia_c3<distancia_c2) && (distancia_c2<distancia_c1))||((distancia_c3<distancia_c1) && (distancia_c1<distancia_c2))){
                    for(int k=0;k<4;k++){
                        nuevoc3[k]+=datos[i][k];
                    }
                    cont_c3++;

                }
        }

        //SACA EL PROMEDIO PARA LOS NUEVOS CENTROIDES


        for(int k=0;k<4;k++){//Esta parte evalua si el contador es 0, para que, si es el caso, simplemente vuelva a poner los valores iniciales de los centroides y no los pierda
            if(cont_c1!=0){
                nuevoc1[k]/=cont_c1;
            }else{
                nuevoc1[k]=c1[k];
            }
            if(cont_c2!=0){
                nuevoc2[k]/=cont_c2;
            }else{
                nuevoc2[k]=c2[k];
            }
            if(cont_c3!=0){
                nuevoc3[k]/=cont_c3;
            }else{
                nuevoc3[k]=c3[k];
            }
        }


        //ASIGNA LOS CENTROIDES NUEVOS AL ORIGINAL
        for(int k=0;k<4;k++){
            c1[k]=nuevoc1[k];
            c2[k]=nuevoc2[k];
            c3[k]=nuevoc3[k];

        }
        printf("Los valores de los centroides en la iteracion %d son:\n",l+1);
        impresion_centroides(c1,c2,c3);
        printf("\n");

    }
    printf("\nLos valores finales de los centroides son:\n");
    impresion_centroides(c1,c2,c3);

    i=0;

    valores=fopen("setosa.txt","w");
    if(valores==NULL){
        printf("\nNo se pudo abrir el archivo.");
    }else{
        while((feof(valores)==0)&&(i<50)&& (fprintf(valores,"%.2f %.2f %.2f %.2f\n",datos[i][0],datos[i][1],datos[i][2],datos[i][3])<=49))
            i++;
        }
    fclose(valores);

    valores=fopen("versicolor.txt","w");
    if(valores==NULL){
        printf("\nNo se pudo abrir el archivo.");
    }else{
        while((feof(valores)==0)&&(i<100)&& (fprintf(valores,"%.2f %.2f %.2f %.2f\n",datos[i][0],datos[i][1],datos[i][2],datos[i][3])<=99))
            i++;
        }
    fclose(valores);

    valores=fopen("virginica.txt","w");
    if(valores==NULL){
        printf("\nNo se pudo abrir el archivo.");
    }else{
        while((feof(valores)==0)&&(i<150)&& (fprintf(valores,"%.2f %.2f %.2f %.2f\n",datos[i][0],datos[i][1],datos[i][2],datos[i][3])<=149))
            i++;
        }
    fclose(valores);

    valores=fopen("centroidesfinales.txt","w");
    if(valores==NULL){
        printf("\nNo se pudo abrir el archivo.");
    }else{
        while((feof(valores)==0)&& (fprintf(valores,"%.2f %.2f %.2f %.2f\n",c1[0],c1[1],c1[2],c1[3])==4)){
        }
        while((feof(valores)==0)&& (fprintf(valores,"%.2f %.2f %.2f %.2f\n",c2[0],c2[1],c2[2],c2[3])==4)){
        }
        while((feof(valores)==0)&& (fprintf(valores,"%.2f %.2f %.2f %.2f\n",c3[0],c3[1],c3[2],c3[3])==4)){
        }
    }
    fclose(valores);
    return 0;
}

void numeros_rand(float c1[4],float c2[4],float c3[4]){
    for(int k=0;k<4;k++){
        c1[k]=((float)rand()/RAND_MAX)*5;
        c2[k]=((float)rand()/RAND_MAX)*5;
        c3[k]=((float)rand()/RAND_MAX)*5;
    }
    return;
}

void impresion_centroides(float c1[4],float c2[4],float c3[4]){
    for(int k=0;k<4;k++){
            printf("Los datos del centroide 1 son %.2f\n",c1[k]);
    }
    for(int k=0;k<4;k++){
        printf("Los datos del centroide 2 son %.2f\n",c2[k]);
    }
    for(int k=0;k<4;k++){
        printf("Los datos del centroide 3 son %.2f\n",c3[k]);
    }
        printf("\n");

    return;
}

float distance(float datos[][4], float c[], int i){
    float distancia;
    distancia=sqrt((pow((datos[i][0]-c[0]),2))+(pow((datos[i][1]-c[1]),2))+(pow((datos[i][2]-c[2]),2))+(pow((datos[i][3]-c[3]),2)));
    return distancia;
}




// Softwork
// 15/06/23
// Miguel Alejandro Flores Sotelo, Juan Carlos Flores Mora, Sergio de Jesus Castillo Molano y Oscar Ayala Elizalde
// SOFTWORK ES UN PROGRAMA QUE BRINDA APOYO AL GESTOR PARA TENER UN MANEJO DINAMICO Y EFICIENTE DE LOS EMPLEADOS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

//PROTOTIPOS DE FUNCIONES
struct empleado{
    char nombre[200];
    char area[200];
    int id;
    float sueldo;
    char num_cel[200];
    int hrs_sem_trbj;
};
void mostrarmenu();
int cargarempleados(struct empleado empleados[100],int producc,int finan,int rechum,int ingen,int geren,int limp,int transp,int *produccion,int *finanzas,int *rechumanos,int *ingenieria,int *gerencia,int *limpieza,int *transporte);//FUNCION QUE DEVUELVE EL NUMERO DE EMPLEADOS QUE EXISTIRAN EN EL FICHERO
void guardar_empleados(struct empleado empleados[100],int num_empleados);
void listar_empleados(struct empleado empleados [100],int num_empleados);//FUNCION QUE ENLISTA A LOS EMPLEADOS EXISTENTES
int alta_de_empleado(struct empleado empleados[100],int num_empleados,int producc,int finan,int rechum,int ingen,int geren,int limp,int transp,int *produccion,int *finanzas,int *rechumanos,int *ingenieria,int *gerencia,int *limpieza,int *transporte);//FUNCION QUE DEVUELVE 1 SI SE PUDO DAR DE ALTA Y 0 SI NO SE PUDO
int baja_de_empleado(struct empleado empleados[100],int num_empleados,int producc,int finan,int rechum,int ingen,int geren,int limp,int transp,int *produccion,int *finanzas,int *rechumanos,int *ingenieria,int *gerencia,int *limpieza,int *transporte);//FUNCION QUE DA DE BAJA AL EMPLEADO Y MANDA 1 SI SE PUDO DAR DE BAJA EL EMPLEADO Y 0 SI NO
void consultar_empleado_gestor(struct empleado empleados[100],int num_empleados);//FUNCION QUE SIRVE PARA CONSULTAR LOS DATOS DE UN EMPLEADO EN ESPECIFICO PARA EL GESTOR
void consultar_empleado_empleado(struct empleado empleados[100],int num_empleados);//FUNCION QUE SIRVE PARA CONSULTAR LOS DATOS DEL EMPLEADO
void modificar_area(struct empleado empleados[100],int num_empleados,int producc,int finan,int rechum,int ingen,int geren,int limp,int transp,int *produccion,int *finanzas,int *rechumanos,int *ingenieria,int *gerencia,int *limpieza,int *transporte);//FUNCION QUE MODIFICA EL AREA DE TRABAJO DE LOS EMPLEADOS
void modificar_sueldo(struct empleado empleados [100],int num_empleados);//FUNCION QUE MODIFICA EL SUELDO DE LOS EMPLEADOS
void modificar_num_cel(struct empleado empleados[100],int num_empleados);//FUNCION QUE MODIFICA EL NUMERO DE CELULAR DE LOS EMPLEADOS
void modificar_hrs_sem_trbj(struct empleado empleados [100],int num_empleados);//FUNCION QUE MODIFICA LAS HORAS DE SEMANA DE TRABAJO
int comprobacion_existencia_empleado(struct empleado empleados[100], int num_empleados, int id);//FUNCION QUE NOS AYUDARA PARA SABER SI EXISTE UN EMPLEADO
int lecturaCredenciales(char *iniusuAdm, char *iniclaveAdm); // Funcion para leer las credenciales guardades en archivo txt
void inicioSesion(char *iniusuAdm, char *iniclaveAdm); // Funcion para inicio de sesion
void graficadora(int grafica[50][49],int produccion,int finanzas,int rechumanos,int ingenieria,int gerencia,int limpieza,int transporte);
int claveUsuario(void); // Funcion para registro de credenciales de gestor

int main(){
    //INICIALIZACION DE VARIABLES
    int elecc=0;//VARIABLE DE ELECCION PARA EL SWITCH
    int grafica[50][49]={0}; //Matriz para poder graficar
    int produccion=0,finanzas=0,rechumanos=0,ingenieria=0,gerencia=0,limpieza=0,transporte=0; //Contabiliza el numero de empleados por area
    int opc=0;//VARIABLE DE OPCION PARA EL MENU
    int num_empleados=0;//INCIALIZAS LA VARIABLE DE NUMERO DE EMPLEADOS A CERO PARA PSOTERIORMENTE IGUALARLO AL RESULTADO QUE DA LA FUNCION CARGAR EMPLEADOS
    struct empleado empleados[100];//ESTRUCTURA DONDE ESTARAN TODOS LOS EMPLEADOS, MAX 100
    num_empleados=cargarempleados(empleados,produccion,finanzas,rechumanos,ingenieria,gerencia,limpieza,transporte,&produccion,&finanzas,&rechumanos,&ingenieria,&gerencia,&limpieza,&transporte);//ANTES DE DAR LA BIENVENIDA, YA SE TENDRA EN EL ARRAY DE EMPLEADOS TODOS LOS EMPLEADOS CARGADOS Y EN NUM_EMPLEADOS ESTARA EL NUMERO DE EMPLEADOS QUE HAY EN EL SISTEMA
    int id_empleado;//VARIABLE QUE SE APLICA DENTRO DEL CASE 2 PARA QUE EL USUARIO PUEDA VER LOS DATOS CON SU ID
    int opc_modificacion_empleado=0;//VARIABLE QUE SE APLICA DENTRO DEL CASE 1 EN LA OPCION 5 PARA QUE ELIGA QUE DESEA MODIFICAR
    char cntclave, iniusuAdm[20], iniclaveAdm[20]; // Variables para funcion de lectura de credenciales
    FILE *sesion;
    //MENSAJE DE INICIO
    printf("     --SoftWork es un programa que brinda apoyo al gestor para tener un manejo dinamico y eficiente de los empleados--\n\n");
    printf("\n      ---------------------------------------------------");
    printf("\n      |Rol en la empresa\t\t\t\t|\n      |\t[1]-Gestor\t\t\t\t\t|\n      |\t[2]-Empleado\t\t\t\t\t|");
    printf("\n      ---------------------------------------------------");
    printf("\n\tPor favor, seleccione la opcion que desea realizar: ");
    scanf("%d",&elecc);
    system("cls");

    switch(elecc){
        case 1://CASO PARA EL GESTOR
        	// Inicio de sesi�n
            sesion = fopen("credenciales.txt", "r");
            if (sesion == NULL){
            	claveUsuario();
			}
			else {
				fclose(sesion);
				lecturaCredenciales(iniusuAdm, iniclaveAdm);
				inicioSesion(iniusuAdm, iniclaveAdm);
			}
            system("cls");
            //MENSAJE DE BIENVENIDA AL GESTOR
            printf("\tBienvenido a SoftWork!\n\n");
            mostrarmenu();
            scanf("%d",&opc);

            while(opc!=6){
                if(opc==1){
                    system("cls");
                    int creado=alta_de_empleado(empleados,num_empleados,produccion,finanzas,rechumanos,ingenieria,gerencia,limpieza,transporte,&produccion,&finanzas,&rechumanos,&ingenieria,&gerencia,&limpieza,&transporte);
                    if(creado==1){
                        num_empleados++;//SI CREADO ES IGUAL A 1 SE INCREMENTA EL NUMERO DE EMPLEADOS EXISTENTES EN EL SISTEMA
                    }
                }

                else if(opc==2){
                    system ("cls");
                    int eliminado=baja_de_empleado(empleados,num_empleados,produccion,finanzas,rechumanos,ingenieria,gerencia,limpieza,transporte,&produccion,&finanzas,&rechumanos,&ingenieria,&gerencia,&limpieza,&transporte);
                    if(eliminado==1){
                        num_empleados--;//SI ELIMINADO ES IGUAL A 1 SE HA ELIMINADO EL NUMERO DE EMPLEADOS EXISTENTES EN EL SITEMA
                    }
                }

                else if(opc==3){
                    system("cls");
                    listar_empleados(empleados,num_empleados);
                    graficadora(grafica,produccion,finanzas,rechumanos,ingenieria,gerencia,limpieza,transporte);
                }

                else if(opc==4){
                    system("cls");
                   consultar_empleado_gestor(empleados,num_empleados);
                }

                else if(opc==5){
                    system("cls");//NUEVO MENU PARA ELECCION DE MODIFICACION
                    printf("\n      ---------------------------------------------------\n");
                    printf("      |\t[1]-Area\t\t\t\t\t|\n      |\t[2]-Sueldo\t\t\t\t\t|\n      |\t[3]-Celular\t\t\t\t\t|\n      |\t[4]-Horas por semana\t\t\t\t|\n");
                    printf("      ---------------------------------------------------\n");
                    printf("\tIntroduce la opcion que desee realizar: ");
                    scanf("%d",&opc_modificacion_empleado);//SE LEE LA OPCION DESEADA
                    switch (opc_modificacion_empleado){//CON SWITCH MANDA A LLAMAR LAS FUNCIONES A ELEGIR
                        case 1:
                            modificar_area(empleados,num_empleados,produccion,finanzas,rechumanos,ingenieria,gerencia,limpieza,transporte,&produccion,&finanzas,&rechumanos,&ingenieria,&gerencia,&limpieza,&transporte);
                            break;
                        case 2:
                            modificar_sueldo(empleados,num_empleados);
                            break;
                        case 3:
                            modificar_num_cel(empleados,num_empleados);
                            break;
                        case 4:
                            modificar_hrs_sem_trbj(empleados,num_empleados);
                            break;
                        default:
                            printf("Opcion no valida.\n");
                    }
                }

                else{
                    printf("Opcion no valida.\n");
                }
                guardar_empleados(empleados,num_empleados);
                printf("\n");
                mostrarmenu();//VUELVE A MOSTRAR EL MENU
                scanf("%d",&opc);//SE VUELVE A GUARDAR LA NUEVA OPCION DEL MENU
            }
            system("cls");
            printf("\tSoftWork le desea un excelente dia. Hasta pronto!\n");//MENSAJE DE SALIDA
            break;

        case 2://CASO PARA EL EMPLEADO
            printf("Bienvenido a SoftWork!\n\n");
            consultar_empleado_empleado(empleados,num_empleados);
            break;

        default:
            printf("No existe la opcion ingresada\n");
            break;
      }
    return 0;
}
//FUNCIONES

void mostrarmenu(){
    printf("\n      ---------------------------------------------------");
    printf("\n      | Menu del administrador.\t\t\t\t|\n");
    printf("      |\t[1]-Alta empleado\t\t\t\t|\n      |\t[2]-Baja empleado\t\t\t\t|\n      |\t[3]-Listar empleados\t\t\t\t|\n      |\t[4]-Consultar datos de un empleado\t\t|\n      |\t[5]-Modificar datos del empleado\t\t|\n      |\t[6]-Salir\t\t\t\t\t|\n");
    printf("      ---------------------------------------------------\n");
    printf("\tIntroduce la opcion que desee realizar: ");//FUNCION PARA IMPRIMIR EL MENU
}
int cargarempleados(struct empleado empleados[100],int producc,int finan,int rechum,int ingen,int geren,int limp,int transp,int *produccion,int *finanzas,int *rechumanos,int *ingenieria,int *gerencia,int *limpieza,int *transporte){//FUNCION QUE DEVUELVE EL NUMERO DE EMPLEADOS QUE EXISTIRAN EN EL FICHERO
    int num_empleados=0;//NUMERO DE EMPLEADOS
    FILE *f;//VARIABLE DE TIPO FILE PARA LEER EL FICHERO
    f=fopen("empleados.txt","r");//ABRE EL FICHERO EN MODO "READING" QUE SIRVE PARA PASAR AL FICHERO LOS DATOS, EN ESTE CASO LOS EMPLEADOS
    char cadena[250];//CADENA  QUE ALMACENA CADA LINEA LEIDA DEL FICHERO
    char delimitador[]=";";//VARIABLE QUE DIVIDE EN TROZOS LAS LINEAS DEL FICHERO POR ; EN ESTE CASO

    while(feof(f)==0){//LA FUNCION FEOF MANDA DOS RESULTANTES, 1 o 0: 1 SIGNIFICA QUE YA TERMINO DE LEER EL FICHERO Y 0 QUE AUN NO HA  TERMINADO DE LEER EL FICHERO
    //POSTERIORMENTE SE PROCESA CADA LINEA, CADA LINEA REPRESENTA UN EMPLEADO, SEGUIDO DE SUS DATOS
        struct empleado e;//AQUI UTILIZAS LA ESTRUCTURA EMPLEADO PARA CARGAR LOS DATOS DEL EMPLEADO DE LA LINEA QUE SE ESTE LETYENDO
        fgets(cadena,250,f);// CON FGETS OBTIENES LA LINEA QUE SE GUARDA EN LA VARIABLE CADENA DE HASTA 200 CARACTERES, Y SI INGRESA EL FICHERO QUE SE LEE EN ESTE CASO ES f
        char *token= strtok(cadena,delimitador);//LA FUNCION STRTOK DIVIDE LA CADENA EN PARTES POR EL DELIMITADOR QUE ES ; Y DEVUELVE LOS DIFERENTES CAMPOS QUE ESTAN SEPARADOS POR EL DELIMITADOR POR LO TANTO SE ALMACENA EN UNA VARIABLE DE TIPO CADENA EN ESTE CASO LLAMADA TOKEN, SE VA LLAMANDO LA FUNCION STRTOK HASTA QUE LLEGUE AL FINAL DE LA CADENA Y TOKEN OBTENGA EL VALOR NULL

        if(token!=NULL){//POR LO TANTO SI TOKEN ES DISTINTO DE NULL, ESTA DENTRO DE LOS CAMPOS
            int campo=1;//VARIABLE QUE SIRVE PARA VER  EN QUE CAMPO TE ENCUENTRAS (SI ES EL NOMBRE, EL AREA, EL ID, ETC)
            while (token!=NULL){//MIENTRAS TOKEN SEA DIFERENTE DE NULL, OSEA QUE NO HAYALLEGADO HASTA EL FINAL
                if (campo==1){
                    strcpy(e.nombre,token);//SI VA EN EL CAMPO 1 SIGNIFICA QUE ES EL NOMBRE Y LO COPIA EN E.NOMBRE DE LA ESTRUCTURA
                }
                else if(campo==2){//SI VA EN EL CAMPO 2 SIGNIFICA QUE ES EL AREA Y LO COPIA EN E.AREA DE LA ESTRUCTURA
                    strcpy(e.area,token);
                    if(strcmp(e.area,"Produccion")==0){
                            producc++;
                        }
                        if(strcmp(e.area,"Finanzas")==0){
                            finan++;
                        }
                        if(strcmp(e.area,"Ingenieria")==0){
                            ingen++;
                        }
                        if(strcmp(e.area,"R. Humanos")==0){
                            rechum++;
                        }
                        if(strcmp(e.area,"Limpieza")==0){
                            limp++;
                        }
                        if(strcmp(e.area,"Gerencia")==0){
                            geren++;
                        }
                        if(strcmp(e.area,"Transporte")==0){
                            transp++;
                        }

                }
                else if(campo==3){//SI VA EN EL CAMPO 3 SIGNIFICA QUE ES EL ID Y LO COPIA EN E.ID DE LA ESTRUCTURA, DEBIDO A QUE SON CARACTERES LOS QUE SE LEEN Y ESTAS EN EL ID SE CONVIERTEN A ENTEROS CON LA FUNCION ATOI SEGUIDO DE LA VARIABLE QUE DESEAS CONVERTIR A ENTERO, BASICAMENTE ES PARA CONVERTIR DE CADENA A ENTERO
                    e.id=atoi(token);
                }
                else if(campo==4){//SI VA EN EL CAMPO 4 SIGNIFICA QUE ES EL SUELDO Y LO COPIA EN E.SUELDO DE LA ESTRUCTURA, DEBIDO A QUE SON CARACTERES LOS QUE SE LEEN Y ESTAS EN EL SUELDO SE CONVIERTEN A FLOTANTES CON LA FUNCION ATOF SEGUIDO DE LA VARIABLE QUE DESEAS CONVERTIR A FLOTANTE, BASICAMENTE ES PARA CONVERTIR DE CADENA A FLOTANTE
                    e.sueldo=atof(token);
                }
                else if(campo==5){
                    strcpy(e.num_cel,token);//SI VA EN EL CAMPO 5 SIGNIFICA QUE ES EL NUMERO DE CELULAR Y LO COPIA EN E.NUM_CEL DE LA ESTRUCTURA
                }
                else if(campo==6){
                    e.hrs_sem_trbj=atoi(token);//SI VA EN EL CAMPO 6 SIGNIFICA QUE SON LAS HORAS DE TRABAJO SEMANALES Y LO COPIA EN E.HRS_SEM_TRBJ DE LA ESTRUCTURA, DEBIDO A QUE SON CARACTERES LOS QUE SE LEEN, SE CONVIERTEN A ENTEROS CON LA FUNCION ATOI SEGUIDO DE LA VARIABLE QUE DESEAS CONVERTIR A ENTERO, BASICAMENTE ES PARA CONVERTIR DE CADENA A ENTERO
                }
                campo++;//AUMENTAS CAMPO DE 1 EN 1 PARA QUE SE VAYA RECORIENDO CADA ACAMPO
                token=strtok(NULL,delimitador);//CUANDO LLEGUE AL ULTIMO TOKEN SERA NULL Y SALE DEL WHILE
            }
            empleados[num_empleados]=e;//SE ALMACENA EN EL ARRAY DE EMPLEADOS EN LA POSICION QUE MARQUE NUM_EMPLEADOS EL EMPLEADO QUE SE ACABA DE CARGAR
            num_empleados++;//AUMENTAS EL NUMERO DE EMPLEADOS DE 1 EN 1
        }
    }
    fclose(f);//CUANDO ALLA LEIDO TODAS LAS LINEAS SE CIERRA EL FICHERO Y DVUELVES EL NUMERO DE EMPLEADOS QUE SE HAN CARGADO
    *produccion=producc;
   *finanzas=finan;
   *ingenieria=ingen;
   *rechumanos=rechum;
   *limpieza=limp;
   *gerencia=geren;
   *transporte=transp; //Devuelve el valor de los empleados registrados en el archivo
    return num_empleados;//RETORNA EL NUMERO DE EMPLEADOS
}

void guardar_empleados(struct empleado empleados[100],int num_empleados){
    FILE *f;
    f=fopen("empleados.txt","w");

    for(int i=0;i<num_empleados-1;i++){
        fprintf(f,"%s;%s;%d;%.2f;%s;%d\n",empleados[i].nombre,empleados[i].area,empleados[i].id,empleados[i].sueldo,empleados[i].num_cel,empleados[i].hrs_sem_trbj);
    }
    fprintf(f,"%s;%s;%d;%.2f;%s;%d",empleados[num_empleados-1].nombre,empleados[num_empleados-1].area,empleados[num_empleados-1].id,empleados[num_empleados-1].sueldo,empleados[num_empleados-1].num_cel,empleados[num_empleados-1].hrs_sem_trbj);
    fclose(f);
}


void listar_empleados(struct empleado empleados[100], int num_empleados){//FUNCIONES QUE ENLISTA LOS EMPLEADOS
	int i;
    printf("LISTANDO LOS DATOS DEL EMPLEADO\n\n");
    for(i = 0; i < num_empleados; i++){
        printf("-----------------------------------------------------------\n");
        printf("|Nombre del empleado\t | %s\n",empleados[i].nombre);
        printf("-----------------------------------------------------------\n");
        printf("|Area de trabajo\t | %s\n",empleados[i].area);
        printf("-----------------------------------------------------------\n");
        printf("|ID del empleado\t | %d\n",empleados[i].id);
        printf("-----------------------------------------------------------\n");
        printf("|Sueldo percibido\t | %.2f\n",empleados[i].sueldo);
        printf("-----------------------------------------------------------\n");
        printf("|Numero de telefono \t | %s\n",empleados[i].num_cel);
        printf("-----------------------------------------------------------\n");
        printf("|Horas por semana\t | %d\n",empleados[i].hrs_sem_trbj);
        printf("-----------------------------------------------------------\n");
        printf("\n");
    }
}

int alta_de_empleado(struct empleado empleados[100],int num_empleados,int producc,int finan,int rechum,int ingen,int geren,int limp,int transp,int *produccion,int *finanzas,int *rechumanos,int *ingenieria,int *gerencia,int *limpieza,int *transporte){//FUNCION QUE DA DE ALTA AL EMPLEADO Y MANDA 1 SI SE PUDO DAR DE ALTA EL EMPLEADO Y 0 SI NO
    int creado=0;//SE INICIALIZA LA VARIABLE EN  0 PARA INDICAR SI SE HA CREADO O NO
    struct empleado nuevoemp;//ESTRUCTURA EMPLEADO DONDE SE VAN A CARGAR LOS NUEVOS DATOS DEL EMPLEADO A CREAR
    fflush(stdin);//SE LIMPIA EL BUFFER PORQUE SE PEDIRAN COSAS
    printf("\tIntroduzca nombre y apellido del nuevo empleado: ");//SE GUARDA TODO DEL NUEVO EMPLEADO DESDE NOMBRE HASTA HORAS DE TRABAJO
    gets(nuevoemp.nombre);
    fflush(stdin);
    printf("\tIntroduzca el area del nuevo empleado: ");
    gets(nuevoemp.area);
    if(strcmp(nuevoemp.area,"Produccion")==0)
        producc++;
    else if (strcmp(nuevoemp.area,"Finanzas")==0)
        finan++;
    else if (strcmp(nuevoemp.area,"Ingenieria")==0)
        ingen++;
    else if (strcmp(nuevoemp.area,"R. Humanos")==0)
        rechum++;
    else if (strcmp(nuevoemp.area,"Limpieza")==0)
        limp++;
    else if (strcmp(nuevoemp.area,"Gerencia")==0)
        geren++;
    else if (strcmp(nuevoemp.area,"Transporte")==0)
        transp++;
    fflush(stdin);
    printf("\tIntroduzca el ID del nuevo empleado: ");
    scanf("%d",&nuevoemp.id);
    fflush(stdin);
    printf("\tIntroduzca el sueldo del nuevo empleado: ");
    scanf("%f",&nuevoemp.sueldo);
    fflush(stdin);
    printf("\tIntroduzca el telefono del nuevo empleado: ");
    gets(nuevoemp.num_cel);
    fflush(stdin);
    printf("\tIntroduzca las horas semanales a trabajar del empleado: ");
    scanf("%d",&nuevoemp.hrs_sem_trbj);

    int existe=comprobacion_existencia_empleado(empleados,num_empleados,nuevoemp.id);//SE COMPRUEBA SI EXISTE O NO EL ID DEL NUEVO EMPLEADO MANDANDO 1 SI EXISTE O MANDANDO 0 SI NO EXISTE, ASIGNANDOLA EN LA VARIABLE 'EXISTE'
    if(num_empleados<100){//SI EL NUMERO DE EMPLEADOS ES MENOR AL LIMITE PROSIGUE
        if(existe==0){//SI NO EXISTE SE CONTINUA
            empleados[num_empleados]=nuevoemp;//PROCEDE A GUARDAR EN EL ARREGLO DE EMPLEADOS EN LA POSICION NUM_EMPLEADOS SE GUARDA EL NUEVO EMPLEADO QUE SE ACABA DE CREAR
            creado=1;//CREADO SE CONVIERTE EN VERDADERO
            printf("Empleado registrado con exito.\n");//MENSAJE DE CONFIRAMCION
        }
        else{
           printf("No se puede crear el empleado. El ID ingresado ya existe.\n");//SI EXISTE NO SE PUED DUPLICAR PORQUE TIENE EL MISMO ID
        }
    }
    else{
        printf("No se puede dar de alta el empleado. Limite de registros alcanzado.\n");//SI NO NO SE PUEDE PORQUE YA SE ALCANZO EL CUPO
    }
    *produccion=producc;
    *finanzas=finan;
    *ingenieria=ingen;
    *rechumanos=rechum;
    *limpieza=limp;
    *gerencia=geren;
    *transporte=transp;
    return creado;
}

int baja_de_empleado(struct empleado empleados[100],int num_empleados,int producc,int finan,int rechum,int ingen,int geren,int limp,int transp,int *produccion,int *finanzas,int *rechumanos,int *ingenieria,int *gerencia,int *limpieza,int *transporte){//FUNCION QUE DA DE BAJA AL EMPLEADO Y MANDA 1 SI SE PUDO DAR DE BAJA EL EMPLEADO Y 0 SI NO
    int eliminado=0;//VARIABLE QUE NOS INDICA SI PUDIMOS ELIMINAR O NO AL EMPLEADO
    int id, i, j;
    int indice;
    printf("\tIntroduza el ID del empleado a dar de baja: ");
    scanf("%d",&id);
    int existe=comprobacion_existencia_empleado(empleados,num_empleados,id);
    if(existe==1){
        for(i=0;i<num_empleados;i++){
            if(empleados[i].id==id){
                 indice=i;//NO SE PUEDE QUEDAR UN ESPACIO EN BLANCO SI SE ELIMINA UN EMPLEADO QUE SE ENCUENTRE ENTRE OTROS ENTONCES UTILIZAMOS LA VARIABLE INDICE IGUALADA A LA POSICION I
            }
        }
        if(strcmp(empleados[indice].area,"Produccion")==0){
            producc--;
        }
        if(strcmp(empleados[indice].area,"Finanzas")==0){
            finan--;
        }
        if(strcmp(empleados[indice].area,"Ingenieria")==0){
            ingen--;
        }
        if(strcmp(empleados[indice].area,"R. Humanos")==0){
            rechum--;
        }
        if(strcmp(empleados[indice].area,"Limpieza")==0){
            limp--;
        }
        if(strcmp(empleados[indice].area,"Gerencia")==0){
            geren--;
        }
        if(strcmp(empleados[indice].area,"Transporte")==0){
            transp--;
        }
        *produccion=producc;
        *finanzas=finan;
        *ingenieria=ingen;
        *rechumanos=rechum;
        *limpieza=limp;
        *gerencia=geren;
        *transporte=transp;
        for(j=indice;j<num_empleados-1;j++){//CON ESTE CICLO SE EMPIEZA DESDE EL EMPLEADO QUE SE QUIERE ELIMINAR HACIA ADELANTE
            empleados[j]=empleados[j+1];//PARA CADA EMPLEADO QUE SE ACCEDA EN ESA POSICION J SE GUARDA EL EMPLEADO QUE SE ENCUENTRA EN LA POSICION SIGUIENTE
            struct empleado aux;//SE CREA UNA ESTRUCTURA EMPLEADO AUXILIAR
            empleados[j+1]=aux;//LA ESTRUCTURA INICIALIZADA SE METE EN LA POSICION J+1 PARA BORRAR LO QUE TUVIERA LA POSICION J+1 Y METER LA ESTRUCTURA QUE ESTA INICIALIZADA POR DEFECTO
        //CON ESTE FOR DESPLAZAMOS HACIA LA IZQUIERDA TODOS LOS EMPLEADOS
        }
        eliminado=1;
        printf("Empleado eliminado con exito.\n");

    }
    else{
        printf("No se puede dar de baja el  empleado. No existe el ID ingresado.\n");
    }
    return eliminado;
}

void consultar_empleado_gestor(struct empleado empleados[100],int num_empleados){//funcion que consulta los empleados que el gesto necesita en especifico
	int id;//variable del id a buscar
	int i;
	printf("Introduzca el ID del empleado a consultar porfavor: ");//se imprime en pantalla que ingrese el id del empleado que desea buscar
	scanf("%d",&id);//se guarda el id a buscar en la variable
	int existe=comprobacion_existencia_empleado(empleados,num_empleados,id);//compruebas si existe el empleado con la funcion comprobacion_existencia_empleado
	if(existe==1){//si existe continua
		for(i=0;i<num_empleados;i++){//con el ciclo for recorres a los empleados existentes
				if(empleados[i].id==id){//si de los empleados recorridos su id es igual al que se ingreso al incio
				printf("\nCargando los datos del empleado con ID %d\n\n",empleados[i].id);//entonces imprime los dtos del empleado solicitado
				printf("-----------------------------------------------------------\n");
                printf("|Nombre del empleado\t | %s\n",empleados[i].nombre);
                printf("-----------------------------------------------------------\n");
                printf("|Area de trabajo\t | %s\n",empleados[i].area);
                printf("-----------------------------------------------------------\n");
                printf("|ID del empleado\t | %d\n",empleados[i].id);
                printf("-----------------------------------------------------------\n");
                printf("|Sueldo percibido\t | %.2f\n",empleados[i].sueldo);
                printf("-----------------------------------------------------------\n");
                printf("|Numero de telefono \t | %s\n",empleados[i].num_cel);
                printf("-----------------------------------------------------------\n");
                printf("|Horas por semana\t | %d\n",empleados[i].hrs_sem_trbj);
                printf("-----------------------------------------------------------\n");
                printf("\n");
	}
        }
		    }

	else{
	    printf("ID no recnocido.EMPLEADO INEXISTENTE\n\n");//si no existe entonces se envia este mensaje
	}
}

void consultar_empleado_empleado(struct empleado empleados[100],int num_empleados){//funcion que consulta los empleados que el gesto necesita en especifico
	int id;//variable del id a buscar
	int i;
	printf("Dame tu ID de la empresa porfavor: ");//se imprime en pantalla que ingrese el id del empleado que desea buscar
	scanf("%d",&id);//se guarda el id a buscar en la variable
	int existe=comprobacion_existencia_empleado(empleados,num_empleados,id);//compruebas si existe el empleado con la funcion comprobacion_existencia_empleado
	if(existe==1){//si existe continua
		for(i=0;i<num_empleados;i++){//con el ciclo for recorres a los empleados existentes
				if(empleados[i].id==id){//si de los empleados recorridos su id es igual al que se ingreso al incio
				printf("\nCargando los datos del empleado con ID %d\n\n",empleados[i].id);//entonces imprime los dtos del empleado solicitado
				printf("-----------------------------------------------------------\n");
                printf("|Nombre del empleado\t | %s\n",empleados[i].nombre);
                printf("-----------------------------------------------------------\n");
                printf("|Area de trabajo\t | %s\n",empleados[i].area);
                printf("-----------------------------------------------------------\n");
                printf("|ID del empleado\t | %d\n",empleados[i].id);
                printf("-----------------------------------------------------------\n");
                printf("|Sueldo percibido\t | %.2f\n",empleados[i].sueldo);
                printf("-----------------------------------------------------------\n");
                printf("|Numero de telefono \t | %s\n",empleados[i].num_cel);
                printf("-----------------------------------------------------------\n");
                printf("|Horas por semana\t | %d\n",empleados[i].hrs_sem_trbj);
                printf("-----------------------------------------------------------\n");
                printf("\n");

	}
        }
		    }
	else{
	    printf("\nID no recnocido. Este empleado no esta registrado\n\n");//si no existe entonces se envia este mensaje
	}
	printf("Cualquier duda o aclaracion, favor de comunicarse con el administrador.\n");
}

void modificar_area(struct empleado empleados[100],int num_empleados,int producc,int finan,int rechum,int ingen,int geren,int limp,int transp,int *produccion,int *finanzas,int *rechumanos,int *ingenieria,int *gerencia,int *limpieza,int *transporte){//FUNCION QUE MODIFICA EL AREA DE TRABAJO DE LOS EMPLEADOS
    int id;
    int i;
    printf("\tIntroduzca el ID del empleado del cual quiere modificar su numero de celular: ");
    scanf("%d",&id);
    int existe=comprobacion_existencia_empleado(empleados,num_empleados,id);
    if(existe==1){
        char nueva_area[200];
        printf("\tIntroduzca la nueva area de trabajo del empleado: ");
        fflush(stdin);
        gets(nueva_area);
        for(i=0;i<num_empleados;i++){
            if(empleados[i].id==id){
                if(strcmp(empleados[i].area,"Produccion")==0){
                    producc--;
                }
                if(strcmp(empleados[i].area,"Finanzas")==0){
                    finan--;
                }
                if(strcmp(empleados[i].area,"Ingenieria")==0){
                    ingen--;
                }
                if(strcmp(empleados[i].area,"R. Humanos")==0){
                    rechum--;
                }
                if(strcmp(empleados[i].area,"Limpieza")==0){
                    limp--;
                }
                if(strcmp(empleados[i].area,"Gerencia")==0){
                    geren--;
                }
                if(strcmp(empleados[i].area,"Transporte")==0){
                    transp--;
                }

                strcpy(empleados[i].area,nueva_area);

                if(strcmp(empleados[i].area,"Produccion")==0){
                    producc++;
                }
                if(strcmp(empleados[i].area,"Finanzas")==0){
                    finan++;
                }
                if(strcmp(empleados[i].area,"Ingenieria")==0){
                    ingen++;
                }
                if(strcmp(empleados[i].area,"R. Humanos")==0){
                    rechum++;
                }
                if(strcmp(empleados[i].area,"Limpieza")==0){
                    limp++;
                }
                if(strcmp(empleados[i].area,"Gerencia")==0){
                    geren++;
                }
                if(strcmp(empleados[i].area,"Transporte")==0){
                    transp++;
                }
                printf("Area de trabajo actualizada.\n");

                *produccion=producc;
                *finanzas=finan;
                *ingenieria=ingen;
                *rechumanos=rechum;
                *limpieza=limp;
                *gerencia=geren;
                *transporte=transp;
            }
        }
    }
    else{
        printf("ID no reconocido.EMPLEADO INEXISTENTE\n\n");
    }
}

void modificar_sueldo(struct empleado empleados [100],int num_empleados){//FUNCION QUE MODIFICA EL SUELDO DE LOS EMPLEADOS
    int id;
    int i;
    printf("\tIntroduzca el ID del empleado del cual quiere modificar su sueldo: ");
    scanf("%d",&id);//SE INTRODUCE EL ID DEL EMPLEADO
    int existe=comprobacion_existencia_empleado(empleados,num_empleados,id);//SE UTILIZA LA FUNCION COMPROBACION EXISTENCIA DEL EPMPLEADO
    if(existe==1){//SI LA FUNCION ANTERIOR DA 1 SIGNIFICA QUE SI EXISTE POR LO TANTO SI SE PUEDE MODIFICAR
        float nuevo_sueldo;
        printf("\tIntroduzca el nuevo sueldo del empleado: ");
        scanf("%f",&nuevo_sueldo);//SE INTRODUCE EL NUEVO SUELDO
        for(i=0;i<num_empleados;i++){//SE RECORRE EL TOTAL DE EMPLEADOS
            if(empleados[i].id==id){//CUANDO ENCUENTRA EL MISMO ID
                empleados[i].sueldo=nuevo_sueldo;//A ESE EMPLEADO SE LE ASIGNA EL NUEVO SUELDO
                printf("Sueldo actualizado.\n");//IMPRESION DE COMPROBACION QUE SI SE MODIFICO EL SUELDO
            }
        }
    }
    else{
        printf("ID no reconocido.No se reconoce al empleado.\n\n");//DE LO CONTRARIO NO EXISTE ENTONCES NO SE PUEDE MODIFICAR
    }
}

void modificar_num_cel(struct empleado empleados[100],int num_empleados){//FUNCION QUE MODIFICA EL NUMERO DE CELULAR DE LOS EMPLEADOS
    int id;
    int i;
    printf("\tIntroduzca el ID del empleado del cual quiere modificar su numero de celular: ");
    scanf("%d",&id);
    int existe=comprobacion_existencia_empleado(empleados,num_empleados,id);
    if(existe==1){
        char nuevo_num_cel[200];
        printf("\tIntroduzca el nuevo numero de celular del empleado: ");
        fflush(stdin);
        gets(nuevo_num_cel);
        for(i=0;i<num_empleados;i++){
            if(empleados[i].id==id){
                strcpy(empleados[i].num_cel,nuevo_num_cel);
                printf("Numero de celular actualizado.\n");
            }
        }
    }
    else{
        printf("ID no reconocido.No se reconoce al empleado.\n\n");
    }
}

void modificar_hrs_sem_trbj(struct empleado empleados [100],int num_empleados){//FUNCION QUE MODIFICA LAS HORAS DE SEMANA DE TRABAJO
    int id;
    int i;
    printf("\tIntroduzca el ID del empleado del cual quiere modificar su sueldo: ");
    scanf("%d",&id);//SE INTRODUCE EL ID DEL EMPLEADO
    int existe=comprobacion_existencia_empleado(empleados,num_empleados,id);//SE UTILIZA LA FUNCION COMPROBACION EXISTENCIA DEL EPMPLEADO
    if(existe==1){//SI LA FUNCION ANTERIOR DA 1 SIGNIFICA QUE SI EXISTE POR LO TANTO SI SE PUEDE MODIFICAR
        int nuevo_hrs_sem_trbj;
        printf("\tIntroduzca las nuevas horas semanales de trabajo : ");
        scanf("%d",&nuevo_hrs_sem_trbj);//SE INTRODUCE EL NUEVO SUELDO
        for(i=0;i<num_empleados;i++){//SE RECORRE EL TOTAL DE EMPLEADOS
            if(empleados[i].id==id){//CUANDO ENCUENTRA EL MISMO ID
                empleados[i].hrs_sem_trbj=nuevo_hrs_sem_trbj;//A ESE EMPLEADO SE LE ASIGNA EL NUEVO SUELDO
                printf("Horas de trabajo actualizadas.\n");//IMPRESION DE COMPROBACION QUE SI SE MODIFICO EL SUELDO
            }
        }
    }
    else{
        printf("ID no reconocido. No se reconoce al empleado.\n\n");//DE LO CONTRARIO NO EXISTE ENTONCES NO SE PUEDE MODIFICAR
    }
}
// Funcion para confirmar existencia de empleado
int comprobacion_existencia_empleado(struct empleado empleados[100], int num_empleados, int id){//FUNCION QUE NOS AYUDARA PARA SABER SI EXISTE UN EMPLEADO
    int resultado=0;//SE DECLARA INICIALMENTE COMO SI NO HUBIERA
    int i;
    for(i=0;i<num_empleados;i++){//PASAS EL CICLO PARA RECORRER  LOS EMPLEADOS
        if(empleados[i].id==id){//SE COMPRUEBA SI  ES EL MISMO ID EN EL ARREGLO DE ALGUN EMPLEADO CON LO QUE SE INTRODUCE IGUALMENTE QUE SU NOMBRE
            resultado=1;//DE SER IGUAL RESULTADO ES IGUAL A 1
        }
    }
    return resultado;//REGRESA EL RESULTADO
}
// Funcion de registro de credenciales de gestor
int claveUsuario(void){
    // Variables de contrase�as
    char usuAdm[20], claveAdm[20], claveAdmconf[20], iniusuAdm[20], iniclaveAdm[20];
	char nombre[20];
    int n, i, j, cc=0, lenUsu=0, lenClave=0, flagadmsesion=0;

    // Registro de nuevos datos para administrador
    // Pedir nombre de usuario
    printf("\t***** Registro de datos del administrador ******\n\nIngrese su nombre de usuario, debe contener por lo menos 5 caracteres.");
    // Control de longitud de caracteres
	while (cc==0){
	printf("\n\tNombre de usuario: ");
    scanf("%s", usuAdm);
		if (strlen(usuAdm)<5){
			printf("\nNombre de usuario demasiado corto, debe ser de al menos 5 caracteres\n");
	        printf("\nNombre de usuario: ");
	        scanf("%s", usuAdm);
		} else{
			cc++;
		}
	}
    // Pedir contraseña y confirmar que sea correcta
    cc = 0;
    while (cc==0){
        printf("\n\tNueva contrasenia (Debe ser de 8 - 15 caracteres): ");
        scanf("%s", claveAdm);
        n = strlen(claveAdm);
        while (lenClave==0){
            if (n<8){
            	system("cls");
                printf("\nContrasenia demasiado corta, debe ser de 8 - 15 caracteres\n");
                printf("\tNueva contrasenia: ");
                scanf("%s", claveAdm);
                n = strlen(claveAdm);
            }
            else if (n>15){
            	system("cls");
                printf("\nContrasenia demasiado larga, debe ser de 8 - 15 caracteres");
                printf("\n\tNueva contrasenna: ");
                scanf("%s", claveAdm);
                n = strlen(claveAdm);
            }
            else if (n>=8 && n<=15){
                lenClave++;
            }
        }
        printf("\tConfirmar constrasenia: ");
        scanf("%s", claveAdmconf);
        for (i=0; i<n ;i++){
            if (claveAdm[i]!=claveAdmconf[i]){
            	system("cls");
                printf("\nxx Contrasenia no es la misma xx");
                lenClave=0;
                break;
            }
        }
        if (i==n){
            cc++;
        }
    }
	// Se abre archivo para escribir texto
    FILE *archivo = fopen("credenciales.txt", "w");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.");
        return 1;
    }
	// Codifica usuario
    for (i=0; usuAdm[i]!='\0'; i++){
        char caracterCodificado = usuAdm[i] + 5;
        fputc(caracterCodificado, archivo);
    }
    // Se agrega separaci�n por ';'
    fputc(';'+5, archivo);
    // Codifica clave
    for (i=0; claveAdm[i]!='\0'; i++){
        char caracterCodificado = claveAdm[i] + 5;
        fputc(caracterCodificado, archivo);
    }
    // Cerrar archivo
    fclose(archivo);
}
// Funci�n para registro de credenciales de gestor
int lecturaCredenciales(char *iniusuAdm, char *iniclaveAdm){
	// Declarar variables
	int caracterCodificado, i=0;
	char *token, cadena[100], caracterOriginal;
	// Lectura de archivo
    FILE *archivo = fopen("credenciales.txt", "r");
    if (archivo == NULL) {
        printf("Error al abrir archivo");
        return 0;
    }
    // Guardar informac�n en una cadena y decodificarlo
	while ((caracterCodificado = fgetc(archivo)) != EOF){
		caracterOriginal = caracterCodificado - 5;
		cadena[i++]=caracterOriginal;
	}
	// Separar informac�n en diferentes cadenas
	// Guarda usuario
	token = strtok(cadena, ";");
	if (token != NULL){
		strcpy(iniusuAdm, token);
		// Guarda clave
		token = strtok(NULL, ";");
		if (token != NULL){
			strcpy(iniclaveAdm, token);
		}
	}
	    // Se cierra el archivo
	    fclose(archivo);
	return 0;
}
// Funci�n para inicio de sesi�n
void inicioSesion(char *iniusuAdm, char *iniclaveAdm){
	// Declarar variables
	int i, j, flagadmsesion=0;
	char usuAdm[50], claveAdm[50];
	// Inicio de solicitar datos y comparar
	system("cls");
    while (flagadmsesion==0){
    	printf("\t--- Inicio de sesion ---\n");
		printf("\n\tNombre de usuario: ");
    	scanf("%s", usuAdm);
    	printf("\n\tConstrasenia: ");
		scanf("%s", claveAdm);
		for (j=0; j<strlen(usuAdm) ;j++){
	        if (iniusuAdm[j]!=usuAdm[j]){
	            break;
	        }
	    }
		for (i=0; i<strlen(claveAdm) ;i++){
			if (iniclaveAdm[i]!=claveAdm[i]){
				break;
	        }
	    }
		if (i!=strlen(claveAdm)||j!=strlen(usuAdm)){
			system("cls");
			printf("Error: Nombre de usuario o contrasenia incorrecto\n\n");
	    }
		else if (i==strlen(claveAdm) && j==strlen(usuAdm)){
		    flagadmsesion++;
	    }
    }
}

void graficadora(int grafica[][49],int produccion,int finanzas,int rechumanos,int ingenieria,int gerencia,int limpieza,int transporte){
    for(int i=0;i<50;i++)
        for(int j=0;j<49;j++)
            grafica[i][j]=0;
    for(int i=49;i>=0;i--){ //Inicia desde la fila de hasta abajo
            for(int j=1;j<49;j++){//Inicia en la primera columna
                if(j%7!=0){
                    if(j>0 && j<7 && produccion!=0 && ((49-i)<produccion)){ //Evalua para poder imprimir una barra, llenado las barras con 1
                       grafica[i][j]=1;
                    }else if (j>7 && j<14 && finanzas!=0 && ((49-i)<finanzas)){
                       grafica[i][j]=1;
                    }else if (j>14 && j<21 && rechumanos!=0 && ((49-i)<rechumanos)){
                       grafica[i][j]=1;
                    }else if (j>21 && j<28 && ingenieria!=0 && ((49-i)<ingenieria)){
                       grafica[i][j]=1;
                    }else if (j>28 && j<35 && gerencia!=0 && ((49-i)<gerencia)){
                       grafica[i][j]=1;
                    }else if (j>35 && j<42 && limpieza!=0 && ((49-i)<limpieza)){
                       grafica[i][j]=1;
                    }else if (j>42 && j<49 && transporte!=0 && ((49-i)<transporte)){
                       grafica[i][j]=1;
                    }
                }
            }
        }
        for(int i=0;i<50;i++){ //Impresion de la grafica
            if(50-i>=10)
                printf("\n\t %d|\t",50-i);
            else
                printf("\n\t  %d|\t",50-i);
            for(int j=0;j<49;j++){
                if(grafica[i][j]!=0) //Impresion de la barra
                    printf("%c",219);
                else
                    printf(" ");
            }
        }
    printf("\n\t    -------------------------------------------------------");
    printf("\n\t          Prod.  Fnzs. R.Hum.   Ing.  Grnc.  Limp.  Trans.\n");
    return;
}

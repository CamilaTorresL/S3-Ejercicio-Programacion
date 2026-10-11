/*
Nombre: Camila Torres
Fecha: 09/10/2016
Descripción:
Programa en C para la gestión de calificaciones de un grupo de 5 estudiantes en 3 asignaturas,
utilizando un vector para almacenar las notas de cada asignatura, validando estrictamente que cada 
ingreso se encuentre en el rango de 0 a 10 puntos. A partir de esta información, calcula y muestra:
- El promedio general por estudiante y por asignatura
- Las calificaciones máximas y mínimas obtenidas por estudiante y por asignatura
- La cantidad total de estudiantes aprobados (nota >= 6) y reprobados (nota < 6) por asignatura
*/

#include <stdio.h>
#include <windows.h>

int main (int argc, char *argv[]) {
    
    //Declaración de variables
    char nombres[5][20]={0};
    float programacion[5], calculo[5], fisica[5], promedioE[5];;
    int i, j,opc, respuesta, nombresIngresados = 0, notasIngresadas = 0;

    do{
        
        system("cls"); //Para una mejor interfaz al ejecutar el programa en el cmd
        
        //Menú principal
        printf("Escoja una opción:\n");
        printf("1. Ingresar el nombre de los estudiantes\n");
        printf("2. Ingresar las notas de los estudiantes\n");
        printf("3. Averiguar el promedio de calificaciones por estudiante y por asignatura\n");
        printf("4. Averiguar calificación más alta y baja por estudiante\n");
        printf("5. Averiguar calificación más alta y baja por asignatura\n");
        printf("6. Averiguar la cantidad de estudiantes aprobados y reprobados por asignatura\n");
        printf(">>");
        scanf(" %d", &opc);

        switch (opc)
        {
        case 1:
            //Nombres de los estudiantes
            for (i=0; i<5; i++){
                printf("Ingrese el nombre del estudiante número %d: \n",i+1);
                scanf(" %19s", &nombres[i]);
            }

            nombresIngresados = 1;

            break;

        case 2:
            //Notas de los estudiantes en cada asignatura
            for (i=0; i<5; i++){
                
                //Programación
                do{
                    printf("Ingrese la nota del estudiante %d en Programación: \n",i+1);
                    scanf(" %f", &programacion[i]);

                    if (programacion[i]<0 || programacion[i]>10){
                        printf("La nota ingresada no es válida\n");
                    }

                } while (programacion[i]<0 || programacion[i]>10);
                
                //Calculo
                do{
                    printf("Ingrese la nota del estudiante %d en Calculo: \n",i+1);
                    scanf(" %f", &calculo[i]);

                    if (calculo[i]<0 || calculo[i]>10){
                        printf("La nota ingresada no es válida\n");
                    }

                } while (calculo[i]<0 || calculo[i]>10);

                //Física
                do{
                    printf("Ingrese la nota del estudiante %d en Física: \n",i+1);
                    scanf(" %f", &fisica[i]);
                    if (fisica[i]<0 || fisica[i]>10){
                        printf("La nota ingresada no es válida\n");

                    }
                } while (fisica[i]<0 || fisica[i]>10);
        
            }
    
            notasIngresadas = 1;

            break; 

        case 3:

            if (nombresIngresados == 0 || notasIngresadas == 0){
                printf("Primero debe ingresar los nombres y las notas de los estudiantes\n");
                break;
            }

            //Promedio de calificaciones por estudiante
            for (i=0; i<5; i++){

                promedioE[i]=(programacion[i] + calculo[i] + fisica[i])/3;

            }

            //Promedio de calificaciones por asignatura
            //Programación
            float sum=0, promProgramacion;

            for (i=0; i<5; i++){

                sum+=programacion[i];
            }
            promProgramacion=sum/5;

            //Calculo
            float sum1=0, promCalculo;

            for (i=0; i<5; i++){

                sum1+=calculo[i];
            }
            promCalculo=sum1/5;

            //Física
            float sum2=0, promFisica;

            for (i=0; i<5; i++){

                sum2+=fisica[i];
            }
            promFisica=sum2/5;

            //•	El promedio de calificaciones por estudiante
            for (i=0; i<5; i++){

                printf("El promedio del estudiante %d es: %.2f\n", i+1, promedioE[i]);
            }
    
            //•	El promedio de calificaciones por asignatura.
            printf("El promedio de Programación es: %.2f\n", promProgramacion);
            printf("El promedio de Calculo es: %.2f\n", promCalculo);
            printf("El promedio de Física es: %.2f\n", promFisica);

            break;
        
        case 4:
            //calificación más alta y baja por estudiante

            if (nombresIngresados == 0 || notasIngresadas == 0){
                printf("Primero debe ingresar los nombres y las notas de los estudiantes\n");
                break;
            }

            for (i=0; i<5; i++){

                float nota=0, notaB=10;

                if (programacion[i] > nota){
                    nota = programacion [i];
                }

                if (programacion[i] < notaB){
                    notaB = programacion[i];
                }

                if (calculo[i] > nota){
                    nota = calculo[i];
                }

                if (calculo[i] < notaB){
                    notaB = calculo[i];
                }

                if (fisica[i] > nota){
                    nota = fisica[i];
                }

                if (fisica[i] < notaB){
                    notaB = fisica[i];
                }

                printf("La nota más alta del estudiante %d es: %.2f\n", i+1, nota);
                printf("La nota más baja del estudiante %d es: %.2f\n", i+1, notaB);
            }
            
            break;

        case 5:
            //calificación más alta y baja por asignatura

            if (nombresIngresados == 0 || notasIngresadas == 0){
                printf("Primero debe ingresar los nombres y las notas de los estudiantes\n");
                break;
            }

            float notaProgramacionAlta=0, notaProgramacionBaja=10;
            for (i=0; i<5; i++){

        

                if (programacion[i] > notaProgramacionAlta){

                    notaProgramacionAlta=programacion[i];

                }

                if (programacion[i] < notaProgramacionBaja){

                    notaProgramacionBaja=programacion[i];

                }
            }

            float notaCalculoAlta=0, notaCalculoBaja=10;
            for (i=0; i<5; i++){


                if (calculo[i] > notaCalculoAlta){

                    notaCalculoAlta=calculo[i];

                }

                if (calculo[i] < notaCalculoBaja){

                    notaCalculoBaja=calculo[i];

                }

            }
    
            float notaFisicaAlta=0, notaFisicaBaja=10;
            for (i=0; i<5; i++){

                if (fisica[i] > notaFisicaAlta){

                    notaFisicaAlta=fisica[i];

                }

                if (fisica[i] < notaFisicaBaja){

                    notaFisicaBaja=fisica[i];

                }
            }

            printf("La calificación más alta en Programación es: %.2f y la más baja es: %.2f\n", notaProgramacionAlta, notaProgramacionBaja);
            printf("La calificación más alta en Calculo es: %.2f y la más baja es: %.2f\n", notaCalculoAlta, notaCalculoBaja);
            printf("La calificación más alta en Física es: %.2f y la más baja es: %.2f\n", notaFisicaAlta, notaFisicaBaja);

            break; 

        case 6:
            //Estudiantes aprobados y reprobados por asignatura

            if (nombresIngresados == 0 || notasIngresadas == 0){
                printf("Primero debe ingresar los nombres y las notas de los estudiantes\n");
                break;
            }

            int aprobadosP=0, reprobadosP=0;
            for (i=0; i<5; i++){

                if (programacion[i] >= 6){
                    aprobadosP++;
                }
                else {
                    reprobadosP++;
                }
            }

            int aprobadosC=0, reprobadosC=0;
            for (i=0; i<5; i++){

                if (calculo[i] >= 6){
                    aprobadosC++;
                }
                else {
                    reprobadosC++;
                }
            }

            int aprobadosF=0, reprobadosF=0;
            for (i=0; i<5; i++){

                if (fisica[i] >= 6){
                    aprobadosF++;
                }
                else {
                    reprobadosF++;
                }
            }

            //•	El número de estudiantes aprobados y reprobados por asignatura.
            printf("Programación: \n %d estudiantes APROBADOS \n %d estudiantes REPROBADOS\n", aprobadosP, reprobadosP);
            printf("Calculo: \n %d estudiantes APROBADOS \n %d estudiantes REPROBADOS\n", aprobadosC, reprobadosC);
            printf("Física: \n %d estudiantes APROBADOS \n %d estudiantes REPROBADOS\n", aprobadosF, reprobadosF);

            break;

        default:
            printf("La opción ingresada no es válida\n"); 

            break;

        } 

        printf("¿Desea seleccionar otra opción?(1=si / 2=no)\n");
        scanf(" %d", &respuesta);

    } while (respuesta == 1);

}
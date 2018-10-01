#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FuncionesPersonales.h"
#define CANT 3

int main()
{
    Employee lista[CANT];

    char auxiliarNombre[51];
    char auxiliarApellido[51];
    char auxiliarChar[51];
    int empleadoIdEncontrado;
    int auxId;
    int auxSector;
    float auxSalario;
    int indiceLugarLibre;
    int eleccion = 0;
    int i,j;

    for (i=0;i<CANT;i++){
        lista[i].isEmpty = 0;
    }

    while (eleccion != 6){
        printf("------------Administracion de empleados------------\n");
        printf("1- Ingrese 1 para dar de alta a un empleado\n");
        printf("2- Ingrese 2 para dar de baja a un empleado\n");
        printf("3- Ingrese 3 para modificar los datos de un empleado\n");
        printf("4- Ingrese 4 para ordenarlos alfabeticamente\n");
        printf("5- Ingrese 5 para imprimir\n");
        printf("6- Ingrese 6 para salir del programa\n\n");
        getInt(&eleccion);
        system("cls");
        switch (eleccion){
        case 1:
            indiceLugarLibre = initEmployees(lista,CANT);
            if(indiceLugarLibre == -1){
                printf("No quedan lugares disponibles.\n");
                break;
            }
            printf("\nAlta de empleado");
            printf("\n\nIngrese el nombre: ");
            getSringLetras(auxiliarNombre);
            printf("\nIngrese el apellido: ");
            getSringLetras(auxiliarApellido);
            printf("\nIngrese el sector: ");
            getInt(&auxSector);
            printf("\nIngrese el salario: ");
            getFloat(&auxSalario);
            auxId = indiceLugarLibre;
            addEmployee(lista,CANT,auxId,auxiliarNombre,auxiliarApellido,auxSalario,auxSector);
            system("cls");
            break;
            case 2:
                printf("Ingrese el id del empleado al que desea borrar del registro");
                getInt(&auxId);
                empleadoIdEncontrado = findEmployeeById(lista,CANT,auxId);
                lista[empleadoIdEncontrado].isEmpty = 0;
                break;
            case 3:
                printf("Ingrese el id del empleado al que desea modificar el registro");
                getInt(&auxId);
                empleadoIdEncontrado = findEmployeeById(lista,CANT,auxId);
                if (empleadoIdEncontrado != -1){
                    printf("\n\nIngrese el nombre: ");
                    getSringLetras(auxiliarNombre);
                    printf("\nIngrese el apellido: ");
                    getSringLetras(auxiliarApellido);
                    printf("\nIngrese el sector: ");
                    getInt(&auxSector);
                    printf("\nIngrese el salario: ");
                    getFloat(&auxSalario);
                    strcpy(lista[empleadoIdEncontrado].name,auxiliarNombre);
                    strcpy(lista[empleadoIdEncontrado].lastName,auxiliarApellido);
                    lista[empleadoIdEncontrado].sector = auxSector;
                    lista[empleadoIdEncontrado].salary = auxSalario;
                }
                else {
                    printf("El id buscado no se encuentra en el registro");
                }
            break;
            case 4:
                for (i=0;CANT;i++){
                    if (lista[i].isEmpty!=0){
                    for (j=0;CANT;j++){
                        if (lista[j+1].isEmpty!=0)
                            if (strcmp(lista[i].lastName,lista[j+1].lastName)>=1){
                                strcpy(auxiliarChar,lista[i].lastName);
                                strcpy(lista[i].lastName,lista[j+1].lastName);
                                strcpy(lista[j+1].lastName,auxiliarChar);
                            }
                        }
                    }
                }
                break;
            case 5:
                for (i=0;i<CANT;i++){
                    if (lista[i].isEmpty == 1){
                        printf("\nNombre: %s",lista[i].name);
                        printf("\nApellido: %s",lista[i].lastName);
                        printf("\nSector: %d",lista[i].sector);
                        printf("\nSalario: %f",lista[i].salary);
                        printf("\nId: %d\n\n",lista[i].id);
                    }
                }
                break;
            case 6:
            printf("Ah salido del programa\n");
            break;

        }
    }
    return 0;
}

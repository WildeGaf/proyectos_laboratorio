#include <stdio.h>
#include <stdlib.h>
#define CANT 2

struct eEmpleado{
    int legajo;
    int isEmpty;
    char nombre[31];
    float salario;
};

int main(){
    struct eEmpleado emple[CANT];
    int i;
    for (i=0;i<CANT;i++){
        printf("\nLegajo:");
        scanf("%d", &emple[i].legajo);

        printf("\nNombre: ");
        fflush(stdin);
        scanf("%s", emple[i].nombre);

        printf("\nSalario: ");
        scanf("%f", &emple[i].salario);

        emple[i].isEmpty = 0;

        system("cls");


    }
    for (i=0;i<CANT;i++){
    printf("%d\t%s\t\t%.2f\n", emple[i].legajo, emple[i].nombre, emple[i].salario);
    }
return 0;
}

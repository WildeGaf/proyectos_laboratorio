#include <stdio.h>
#include <stdlib.h>
#define CANT 2

int menu(){
    int respuesta;
    printf("---------------Menu de la Agenda----------------");
    printf("\n1- Ingrese uno para dar de alta");
    printf("\n2- Ingrese dos para dar de baja");
    printf("\n3- Ingrese tres para modificar un valor");
    printf("\n4- Ingrese cuatro para imprimir los datos ordenados");
    printf("\n5- Ingrese cinco para salir");
    printf("\n\nDigite la opcion elegida: ");
    scanf("%d",&respuesta);
    return respuesta;
}

struct ePersonas{
    char nombre[31];
    char apellido[31];
    char dni[31];
    int dia,mes,anio,dataEmpty;
};

int espacioLibre(){
    struct ePersonas per[CANT];
    int i, retorno;
    for(i=0;i<CANT;i++){
        if (per[i].dataEmpty == 1){
            per[i].dataEmpty = 0;
            retorno = i;
            break;
        }else{
        retorno = -1;
        }
    }
    return retorno;

}

int main()
{
    struct ePersonas per[200];
    int i,bandera,eleccion,salida = 0;
    do{
        for (i=0;i<CANT;i++){
            per[i].dataEmpty = 1;
        }
        eleccion = menu();
        switch (eleccion){
            case 1:
                if (bandera=espacioLibre()==-1){
                    printf("No se encontro un espacio vacio");
                }
                else if(bandera == 0){
                    printf("Ingrese el nombre: ");
                    scanf("%s",per[bandera].nombre);
                    printf("Ingrese el apellido: ");
                    scanf("%s",per[bandera].apellido);
                    printf("Ingrese el dni: ");
                    scanf("%s",per[bandera].dni);
                    printf("Ingrese el dia de nacimiento: ");
                    scanf("%d",&per[bandera].dia);
                    printf("Ingrese el dia de mes: ");
                    scanf("%d",&per[bandera].mes);
                    printf("Ingrese el dia de anio: ");
                    scanf("%d",&per[bandera].anio);
                }
                break;
        }
    }while(salida != 1);
    return 0;
}

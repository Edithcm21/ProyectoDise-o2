#include <stdio.h>

int main(void) {
  int opcion1,opcion2;
   do
  {
    printf("\n");
    
    printf("[1] Explorar canciones\n");
    printf("[2] Buscar canciones a partir de una frase\n");
    printf("[3] salir\n");
    printf("\n Selecciona una opcion   ");
    scanf("%d", &opcion1);

    
    switch(opcion1)
    {
      case 1: 
        {
          do{
            printf("\nListas de canciones");
            printf("[1] Con paginacion de 10\n");
            printf("[2] Agrupadas por categoria\n");
            printf("[3] Top 5 canciones mas reproducidas\n");
            printf("[4] ordenadas por puntaje 1-5\n");
            printf("[5] Lista de numero de canciones que se pueden escuchar en un tiempo t\n");
            printf("[6] regresar al menú principal\n");
            printf("\n Selecciona una opcion   ");
            scanf("%d", &opcion2);

            switch(opcion2)
            {
            case 1:
              //metodo de paginacion 10
              break;
            case 2:
              //
              break;
            case 3:
              //metodo `para listar las 5 canciones mas reproducidas
              break;
            case 4:
              //ordenar por puntaje 1-5
              break;
            case 5:
              //lista de canciones que se pueden escuchar en un tiempo t
              break;
            default:
              opcion2=6;


            }


          }while(opcion2!=6);
          break;

        }
          
      case 2:   
         //
          break;
      
      case 3: printf("\n Saliendo...\n\n");
      break;
      default: opcion1=3;
    }
  }while(opcion1!=3);
  
  printf("Hello World\n");
  
  return 0;

}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>

#define max_nombre 100
#define max_canciones 20
// Definimos la estructura para las canciones
typedef struct Cancion {
  char nombre_cancion[200];
  char Categoria[30];
  int Puntuacion;
  int duracion;
  int num_reproducciones;
}Cancion;

void Imprimir_canciones(int pagina,int paginas, Cancion *arreglodin, int tamano);
void ingresarcanciones(Cancion cancion);
float leerarchivo(Cancion cancion);
Cancion * llenararray(Cancion cancion, int j, Cancion *arreglodin);

// Variable para llevar el control de la canción actual
int cancion_Actual = 0;

// Creamos una lista de canciones
Cancion lista[] = {{"Cancion 1", "Categoria 1", 5, 200},
                   {"Cancion 2", "Categoria 1", 4, 150},
                   {"Cancion 3", "Categoria 2", 3, 100},
                   {"Cancion 4", "Categoria 2", 4, 120},
                   {"Cancion 5", "Categoria 3", 5, 180},
                   {"Cancion 6", "Categoria 3", 4, 130},
                   {"Cancion 7", "Categoria 3", 3, 90},
                   {"Cancion 8", "Categoria 1", 4, 140},
                   {"Cancion 9", "Categoria 2", 5, 210},
                   {"Cancion 10", "Categoria 2", 4, 160},
                   {"Cancion 11", "Categoria 1", 3, 110},
                   {"Cancion 12", "Categoria 3", 4, 120},
                   {"Cancion 13", "Categoria 1", 5, 190},
                   {"Cancion 14", "Categoria 2", 4, 150},
                   {"Cancion 15", "Categoria 2", 3, 100},
                   {"Cancion 16", "Categoria 3", 4, 130},
                   {"Cancion 17", "Categoria 1", 5, 200},
                   {"Cancion 18", "Categoria 2", 4, 140},
                   {"Cancion 19", "Categoria 3", 3, 110},
                   {"Cancion 20", "Categoria 1", 4, 160}};

//Función para buscar una cancion a partir de una frase
void buscar_Frase(Cancion *arreglodin) {
	int i,j;
	char search [max_nombre];
	printf("Ingresa una frase para buscar en las canciones: ");
    //scanf("%[^\n]", search);
    scanf("%s", search);
    printf("Las canciones que coinciden con %s son : \n", search);
    for ( i = 0;i < max_canciones; i++) {
      if (strstr(arreglodin[i].nombre_cancion, search) != NULL) {
        printf("- %s\n", arreglodin[i]);
      }
    }
    printf("\n");
  }


// Función para imprimir la lista de canciones de 10 en 10
// Función para imprimir la lista de canciones de 10 en 10
void Imprimir_canciones(int pagina,int paginas, Cancion *arreglodin, int tamano) {
  int inicio_Indice = (pagina - 1) * 10;
  int final_Indice = inicio_Indice + 10;
  if(final_Indice>=tamano)
  	final_Indice=tamano;

int i;

printf (" ************************************************************************\n");
  
  for ( i = inicio_Indice; i < final_Indice; i++) {

    printf("\t valor del i= %d%  ,%s   nombre del artista \n",i,arreglodin[i].nombre_cancion);
   
    //printf("nombre del artista \n");
  }
   printf("\n \t \tPágina %d / %d:\n", pagina,paginas);
   printf (" ************************************************************************\n");
  

  printf("\n");
}

void agrupar_Categoria() {
	int i,j;
  // Creamos un diccionario para almacenar las canciones agrupadas por categoría
  char *categoria[] = {"Categoria 1", "Categoria 2", "Categoria 3"};
  for (i = 0; i < 3; i++) {
    printf("Categoria %d:\n", i + 1);
    for ( j = 0; j < max_canciones; j++) {
      if (strcmp(lista[j].Categoria, categoria[i]) == 0) {
        printf("%s\n", lista[j].nombre_cancion);
      }
    }
    printf("\n");
  }
}

// Función para obtener las 5 canciones más reproducidas
void top_Canciones() {
	int i,j;
  // Ordenamos las canciones por cantidad de reproducciones de mayor a menor
  for (i = 0; i < 5; i++) {
    for ( j = i + 1; j < max_canciones; j++) {
      if (lista[i].Puntuacion < lista[j].Puntuacion) {
        Cancion temp = lista[i];
        lista[i] = lista[j];
        lista[j] = temp;
      }
    }
  }

  // Imprimimos las 5 canciones más reproducidas
  printf("Top 5 canciones mas reproducidas:\n");
  for ( i = 0; i < 5; i++) {
    printf("%s\n", lista[i].nombre_cancion);
  }
  printf("\n");
}
// Función para obtener las canciones ordenadas por puntuación (1-5) de mayor a
// menor
void orden_puntuacion() {
	int i,j;
  // Ordenamos las canciones por puntuación de mayor a menor
  for ( i = 0; i < 5; i++) {
    for (j = i + 1; j < 5; j++) {
      if (lista[i].Puntuacion < lista[j].Puntuacion) {
        Cancion temp = lista[i];
        lista[i] = lista[j];
        lista[j] = temp;
      }
    }
  }

  // Imprimimos las canciones ordenadas por puntuación de mayor a menor
  printf("Canciones ordenadas por puntuacion (1-5) de mayor a menor:\n");
  for ( i = 0; i < 5; i++) {
    printf("%s\n", lista[i].nombre_cancion);
  }
  printf("\n");
}


// Función para ir a la canción siguiente
void siguiente_Cancion() {
  // Verificamos que no se encuentre en la última canción
  if (cancion_Actual == 4) {
    printf("Ya se encuentra en la última canción.\n\n");
    return;
  }

  // Incrementamos el índice de la canción en 1
  cancion_Actual++;

  // Imprimimos el título de la canción
  printf("Reproduciendo: %s\n\n", lista[cancion_Actual].nombre_cancion);
}

// Función para ir a la canción anterior
void cancion_Anterior() {
  // Verificamos que no se encuentre en la primera canción
  if (cancion_Actual == 0) {
    printf("Ya se encuentra en la primera canción.\n\n");
    return;
  }

  // Decrementamos el índice de la canción en 1
  cancion_Actual--;

  // Imprimimos el título de la canción
  printf("Reproduciendo: %s\n\n", lista[cancion_Actual].nombre_cancion);
}

int main(void) {
  int opcion1, opcion2, opc, i,j,y,numeropaginas;
  float x;
  float num_canciones;


  Cancion *arreglodin;
  Cancion cancion;
  
  ingresarcanciones(cancion);
  ingresarcanciones(cancion);
  ingresarcanciones(cancion);
  ingresarcanciones(cancion);
  ingresarcanciones(cancion);
  ingresarcanciones(cancion);
  ingresarcanciones(cancion);
  ingresarcanciones(cancion);
  ingresarcanciones(cancion);
  ingresarcanciones(cancion);
  ingresarcanciones(cancion);
  ingresarcanciones(cancion);
  num_canciones=leerarchivo(cancion);
  
  
if(num_canciones<=0)
		{
			printf("Aun no existen canciones");
		}
		else{
			x=ceil(num_canciones/10);
			numeropaginas=x;  // declaramos cuantas paginas tenemos en base al numero de canciones registradas
		
			arreglodin=(Cancion*)malloc(num_canciones*sizeof(Cancion));
		if(!arreglodin)				
			{
				printf("No se pudo alojar la memoria \n");
				return 0;	
			}


			llenararray(cancion,num_canciones,arreglodin);
		}
		

		
  
  do {
    printf("\n");
    printf("=========== SpotifyUv ===========\n");
    printf("[1] Explorar canciones\n");
    printf("[2] Buscar canciones a partir de una frase\n");
    printf("[3] salir\n");
    printf("\n Selecciona una opcion   ");
    scanf("%d", &opcion1);

    switch (opcion1) {
      
    case 1: {
      int pagina=1;
      do {
        printf("\n==========Selecciona las listas==========\n");
        printf("\nListas de canciones\n");
        printf("[1] Con paginacion de 10\n");
        printf("[2] Agrupadas por categoria\n");
        printf("[3] Top 5 canciones mas reproducidas\n");
        printf("[4] ordenadas por puntaje 1-5\n");
        printf("[5] Lista de numero de canciones que se pueden escuchar en un tiempo t\n");
        printf("[6] Siguiente cancion\n");
        printf("[7] Cancion anterior\n");
        printf("[8] Cancion actual\n");
        printf("[9] regresar al menú principal\n");
        printf("\n Selecciona una opcion   ");
        scanf("%d", &opcion2);

        switch (opcion2) {
        case 1:
          
        	do{
        		Imprimir_canciones(pagina,numeropaginas,arreglodin,num_canciones);
          printf("\t\t Opciones \n");
          if(pagina==1 && pagina!=numeropaginas){
          	printf("\t\t [ 2 ] pagina siguiente\n");
          }
          if(pagina==numeropaginas)
          {
          	printf("\t\t [ 1 ] pagina pagina anterior\n");

          }
          if(pagina>1 && pagina <numeropaginas)
          {

          	printf("\t\t [ 1 ] pagina anterior\n");
          	printf("\t\t [ 2 ] pagina siguiente \n");
          }

          printf("\t\t [ 3 ] regresar al menu principal\n");
          printf (" ************************************************************************\n");

          printf("\t\t digita la opcion ");
          scanf("%i",&opc);
          
          if(opc==1){
          	pagina--;
          	//Imprimir_canciones(pagina,numeropaginas,arreglodin,num_canciones);
          }
          if(opc==2){
          	pagina++;
          	//Imprimir_canciones(pagina,numeropaginas,arreglodin,num_canciones);
          }

          if(opc!=1 && opc!=2){
          	printf("Volviendo a el menu de listar canciones ...");
          	break;

          }


        	}while(opc==2 || opc ==1);
          // metodo de paginacion 10
          
          
          break;
        case 2:
          // Agrupamos las canciones por categoría
          agrupar_Categoria();
          break;
        case 3:
          // metodo `para listar las 5 canciones mas reproducidas
          top_Canciones();
          break;
        case 4:
          // obtenemos las canciones ordenadas por puntiacion de mayor a menor
          orden_puntuacion();
          break;
        case 5:
          // lista de canciones que se pueden escuchar en un tiempo t
          break;
        case 6:
          // Llamamos a la función para ir a la canción siguiente
          siguiente_Cancion();
          break;
        case 7:
          // Llamamos a la función para ir a la canción anterior
          cancion_Anterior();
          break;
        case 8:
          // Reproducimos la primera canción
          printf("Reproduciendo: %s\n\n", lista[cancion_Actual].nombre_cancion);
        default:
          
            opcion2 = 9;
          
        }

      } while (opcion2 != 9);
      break;
    }

    case 2:
      //Realizar busqueda a partir de una frase
      buscar_Frase(arreglodin);
      break;

    case 3:
      printf("\n Saliendo...\n\n");
      break;
    default:
      opcion1 = 3;
    }
  } while (opcion1 != 3);


  return 0;
}

void ingresarcanciones(Cancion cancion)
{
	FILE *file1;


	if(!(file1=fopen("canciones.bin", "a+b")))
	{
		printf("Se ha producido un error al intentar abrir el archivo.\n");
		return;
	}

	fflush(stdin);
		printf("Ingrese el nombre de la cancion: ");
		scanf(" %[^\n]", cancion.nombre_cancion);fflush(stdin);//fgets(cancion.nombre_cancion, 100, stdin);fflush(stdin);
		printf("ingresa la categoria : ");
		scanf(" %[^\n]", cancion.Categoria);fflush(stdin);//fgets(cancion.Categoria, 50, stdin);fflush(stdin);
		printf("ingresa la Puntuacion:  ");
		scanf(" %i",&cancion.Puntuacion);fflush(stdin);
		printf( "ingresa la duracion :  ");
		scanf(" %i",&cancion.duracion);fflush(stdin);
		printf("ingresa el numero de reproducciones:  ");
		scanf(" %i",&cancion.num_reproducciones);fflush(stdin);

		fwrite(&cancion, sizeof(Cancion), 1, file1);
		
		printf("\n");
	
	printf("\nLos datos han sido registrados.\n\n");
	fclose(file1);


}

float  leerarchivo(Cancion cancion)
{
	FILE *file2;
	
	if(!(file2=fopen("canciones.bin", "rb")))
	{
		printf("Se ha producido un error al intentar abrir el archivo.\n");
		return 0;
	}
	float i=0;
	fseek(file2,0,SEEK_SET);			//regreso el archivo a la posicion 0 
	fread(&cancion,sizeof(Cancion),1,file2);
		while(!feof(file2))
		{
			i=i+1;
			fread(&cancion,sizeof(Cancion),1,file2);
			
		}
		fclose(file2);
		printf("Termino de leer el archivo %f",i);
		return i;
	
}


//Hace el llenado del array desde el archivo

Cancion * llenararray(Cancion cancion,int j, Cancion *arreglodin){
	FILE *file3;
	
	
	if(!(file3=fopen("canciones.bin", "rb")))
	{
		printf("Se ha producido un error al intentar abrir el archivo.\n");
		return 0;
	}

		fseek(file3,0,SEEK_SET);			//regreso el archivo a la posicion 0 
		int x;
		for ( x = 0; x < j; x++)
		{
			fread(&cancion,sizeof(Cancion),1,file3);
			arreglodin[x]=cancion;
			
		}
		
		fclose(file3);
		return arreglodin;

}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define N 300
#define max_nombre 100
#define max_canciones 20

// Definimos la estructura para las canciones
typedef struct Cancion {
  char nombre_cancion[100];
  char artista[40];
  int id_categoria;
  int Puntuacion;
  int duracion;
  int num_reproducciones;
}Cancion;

void Imprimir_canciones(int pagina,int paginas, Cancion *arreglodin, int tamano);
void ingresarcanciones(Cancion cancion);
float leerarchivo(Cancion cancion);
Cancion * llenararray(Cancion cancion, int j, Cancion *arreglodin);
void quickSort(Cancion *v, int primero, int ultimo);
void Imprimir_Categoria(Cancion *array,int tam);
void mergeSort(int left, int right, Cancion *a,int tam);
void merge(int left, int centro, int right, Cancion *a, int tam);
void top5(Cancion *a,int tam);
void buscar_Frase(Cancion *arreglodin, int tam);
int getSubSet(Cancion arregloC[], int tamA, int *aux, int k, int segundos);
void imprimirListaT(Cancion arreglo[],int tam,int *aux);
void printArray(Cancion array[], int size);
void countingSort1(Cancion array[], int size);
void modificarCancion(Cancion cancion);
void Listarpaginas(int num_canciones);
void ListarCategorias(int num_canciones);
void ListarTop5(int num_canciones);
void ListarO15(int num_canciones);
void ListarListaT(int num_canciones);
void ListarBusquedaFrase(int num_canciones );



int main(void) {
  int opcion1, opcion2, opc, i,j,y,numeropaginas;
  float x;
  float num_canciones;
  Cancion cancion;
  
  //modificarCancion( cancion);
  //mediante leer archivo obtengo cuantas canciones tenemos guardadas
  num_canciones=leerarchivo(cancion);

  //si nos devuelve 0 el archivo esta vacio 
  
if(num_canciones<=0)
		{
			printf("Aun no existen canciones");
      ingresarcanciones(cancion);
      ingresarcanciones(cancion);
      ingresarcanciones(cancion);
      ingresarcanciones(cancion);
		}
		else{
      // ceil devuelve el redondeo por arriba 
      //si num_canciones=12 x=2= numero de paginas
			x=ceil(num_canciones/10);
			numeropaginas=x;  // declaramos cuantas paginas tenemos en base al numero de canciones registradas
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
        printf("[6] regresar al menú principal\n");
        printf("\n Selecciona una opcion     ");
        scanf("%d", &opcion2);

        switch (opcion2) {
        case 1:
          {
           Cancion *arreglocanciones=(Cancion*)malloc(num_canciones*sizeof(Cancion));
		        if(!arreglocanciones)				
			      {
				      printf("No se pudo alojar la memoria \n");
				      return 0;	
			      }

			    llenararray(cancion,num_canciones,arreglocanciones);
          // Aqui se hace la impresion de las canciones de 10 en 10
        	do{
            
        	Imprimir_canciones(pagina,numeropaginas,arreglocanciones,num_canciones);
          printf("\t\t Opciones \n");
          if(pagina==1 && pagina!=numeropaginas){
          	printf("\t\t [ 2 ] pagina siguiente\n");
          }
          if(pagina==numeropaginas && pagina!=1)
          {
          	printf("\t\t [ 1 ] pagina pagina anterior\n");

          }
          if(pagina>1 && pagina <numeropaginas)
          {
          	printf("\t\t [ 1 ] pagina anterior\n");
          	printf("\t\t [ 2 ] pagina siguiente \n\n");
          }

          printf("\t\t [ 3 ] regresar al menu principal\n");
          printf (" ************************************************************************\n");
          printf("\t\t digita la opcion ");
          scanf("%i",&opc);
          
          if(opc==1){
            //para pasar a la pagina siguiente
          	pagina--;
          }
            
          if(opc==2){
            //para pasar a la pagina anterior
          	pagina++;
          
          }

          if(opc!=1 && opc!=2){
          	printf("Volviendo a el menu principal...");
          	opcion2=6;
            break;
            }
          	

        	}while(opc==2 || opc ==1);  
          free(arreglocanciones);
            }
          break;
          
        
        case 2:
          {
          //impresion por categorias 
        	Cancion *arregloCategorias=(Cancion*)malloc(num_canciones*sizeof(Cancion));
			    if(!arregloCategorias)				
			      {
				      printf("No se pudo alojar la memoria \n");
				      return 0;	
			      }
			    llenararray(cancion,num_canciones,arregloCategorias);
          // Agrupamos las canciones por categoría
          //Con mergeSort ordenamos por categorias 
          mergeSort(0, num_canciones-1, arregloCategorias,num_canciones+10);
        	Imprimir_Categoria(arregloCategorias,num_canciones);
        	printf(" \n \n  seleccione ""1"" para ir al menu principal ");
        	scanf("%i",&opcion2);
        	opcion2=6;
        	free(arregloCategorias);
          break;

            }
        case 3:
          {
          Cancion *arregloMasescuchadas=(Cancion*)malloc(num_canciones*sizeof(Cancion));
			    if(!arregloMasescuchadas)				
			  {
				printf("No se pudo alojar la memoria \n");
				return 0;	
			  }
          //Hace el llenado del arreglo
			llenararray(cancion,num_canciones,arregloMasescuchadas);
      //Se ordenan los datos con QuickSort
          quickSort(arregloMasescuchadas,0,num_canciones-1);
      // metodo `para listar las 5 canciones mas reproducidas
      top5(arregloMasescuchadas,num_canciones);
        	printf(" \n \n  seleccione ""1"" para ir al menu principal ");
        	scanf("%i",&opcion2);
          opcion2=6;
          free(arregloMasescuchadas);
          
          break;
            }
        case 4:
          {
           printf("entramos al case");
          // obtenemos las canciones ordenadas por puntiacion de mayor a menor
          Cancion *arreglopuntuacion=(Cancion*)malloc(num_canciones*sizeof(Cancion));
			    if(!arreglopuntuacion)				
			  {
				printf("No se pudo alojar la memoria \n");
				return 0;	
			  }
         
          llenararray(cancion, num_canciones, arreglopuntuacion);
          countingSort1(arreglopuntuacion,num_canciones);
          printArray(arreglopuntuacion,num_canciones);
          free(arreglopuntuacion);
         
          
          break;
            }
        case 5:
          {

          Cancion *arreglorecorrido=(Cancion*)malloc(num_canciones*sizeof(Cancion));
			    if(!arreglorecorrido)				
			  {
				printf("No se pudo alojar la memoria \n");
				return 0;	
			  }
          int *c = (int *) malloc(sizeof(int)*num_canciones);

          //Hace el llenado del arreglo
			llenararray(cancion,num_canciones,arreglorecorrido);
          printf("Ingresa el tiempo en segundos \n");
          int t; // Variable para obtener el tiempo en Segundos
          scanf("%i",&t);
          
          if(getSubSet(arreglorecorrido, num_canciones,c,0,t))
          {
            printf("\n\tlista de canciones en tiempo %i\n",t);
            imprimirListaT(arreglorecorrido,num_canciones,c);
          }
              
          else
            printf("No hubo coincidencia");
          free(arreglorecorrido);   
          free(c);
          break;
            }
          
        default:
            opcion2 = 6;
          
        }

      } while (opcion2 != 6);
      break;
    }

    case 2:
      //Realizar busqueda a partir de una frase
      {
            Cancion *arreglobusqueda=(Cancion*)malloc(num_canciones*sizeof(Cancion));
		        if(!arreglobusqueda)				
			      {
				      printf("No se pudo alojar la memoria    \n");
				      return 0;	
			      }
      llenararray(cancion, num_canciones, arreglobusqueda);
      buscar_Frase(arreglobusqueda, num_canciones);
        	printf(" \n \n  seleccione ""1"" para ir al menu principal ");
        	scanf("%i",&opcion1); 
      free(arreglobusqueda);
      break;
        }

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
		scanf(" %[^\n]", cancion.nombre_cancion);fflush(stdin);
		printf("Ingrese el nombre del artista: ");
		scanf(" %[^\n]", cancion.artista);fflush(stdin);
		printf("ingresa el id de la  categoria : (1) Pop, (2) Rock, (3) salsa, (4) Reggaeton ");
		scanf("%i",&cancion.id_categoria);fflush(stdin);
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

//Metodo que lee el archivo y obtiene el numero total de registros 
//que han sido almacenados en el archivo
//ya que obtenemos la cantidad de registros podemos llenar el arreglo
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

//*******************************Funcion para imprimir las listas de canciones ****************************
// Función para imprimir la lista de canciones de 10 en 10
//   Edith
void Imprimir_canciones(int pagina,int paginas, Cancion *arreglodin, int tamano) {
  int inicio_Indice = (pagina - 1) * 10;
  int final_Indice = inicio_Indice + 10;
  if(final_Indice>=tamano)
  	final_Indice=tamano;

int i;

printf (" ************************************************************************\n");
  
  for ( i = inicio_Indice; i < final_Indice; i++) {

    printf("\t %i << Nombre de la cancion :%s >>\n     \t<< nombre del artista :%s >> \n\n",i+1,arreglodin[i].nombre_cancion,arreglodin[i].artista);
   
  }
   printf("\n \t \tPágina %d / %d:\n", pagina,paginas);
   printf (" ************************************************************************\n");
  

  printf("\n");
}

// ****************Funciones para imprimir canciones por categoria ****************************
// Con mergeSort ordeno las canciones 
void merge(int left, int centro, int right, Cancion *a,int tam){
  Cancion temp[tam];
  int x,y,i;
  x=i=left; //x representa el indice temporal del lado izquierdo
  y = centro + 1;// y representa el indice temporal del lado derecho
  
  //aqui alguno de los dos lados se va a quedar vacío
  while(x<=centro && y<= right){
    if(a[x].id_categoria <= a[y].id_categoria)
      temp[i++] = a[x++];
    else
      temp[i++] = a[y++];
  }
  
  //luego, vaciar el lado que se haya quedado con elementos
  while(x<=centro)
    temp[i++] = a[x++];
  
  while(y<=right)
    temp[i++] = a[y++];
    
  //copiar el merge al arreglo original desde los índices mandados
  for(i = left; i<= right; i++)
    a[i] = temp[i]; //en el temp se almacenó el merge en las mismas posiciones del arreglo original
}
  
void mergeSort(int left, int right, Cancion *a,int tam){
  if(left<right){
    int centro = (left + right)/2;
    mergeSort(left, centro, a,tam);
    mergeSort(centro+1, right, a,tam);
    merge(left, centro, right, a, tam);
  }
}


//Este metodo tiene como parametro el arreglo previamente ordenado
//para asi verificar si la categoria cambia en el arreglo imprime la categoria siguiente
void Imprimir_Categoria(Cancion *array,int tam){

int i,x=1;

	printf("\n *******************************************************************\n");
	printf("\t \t  Categoria %i \n",array[0].id_categoria);
	printf(" \t %i.- << nombre de la cancion : %s >> \n \t\t<< Nombre del Artista :%s >> \n\n",x,array[0].nombre_cancion,array[0].artista);
  x++;
	for(i=1;i<tam;i++)
	{
		if(array[i-1].id_categoria!=array[i].id_categoria)
    {
      printf(" \t \t  Categoria %i \n\n",array[i].id_categoria);
      x=1;
    }
			
		printf(" \t %i.- << nombre de la cancion :%s >> \n \t\t<< Nombre del Artista : %s >> \n\n",x,array[i].nombre_cancion,array[i].artista);

     x++;
   
	}
	printf("\n *******************************************************************\n");
	return;
}

///////////////////////*******************Funciones para imprimir el Top 5****************///////////////

//Este metodo lo utilizo para ordenar el arreglo por el numero de reproducciones para despues imprimir de 
//Manera mas sencilla
//Hecho por Osmar Hernandez

void quickSort(Cancion *v, int primero, int ultimo){
  int i, j, central;
  Cancion pivote;
  central = (primero + ultimo)/2;
  pivote = v[central];
  i=primero;
  j=ultimo;
  
  do{
    while(v[i].num_reproducciones<pivote.num_reproducciones)i++;
    while(v[j].num_reproducciones>pivote.num_reproducciones)j--;
    if(i<=j){
      Cancion temp = v[i];
      v[i] = v[j];
      v[j] = temp;
      i++;
      j--;
    }    
  }while(i<=j);
  
  if(primero<j)
    quickSort(v, primero, j);
  if(i<ultimo)
    quickSort(v, i, ultimo);
  
}

//para listar el top 5 utilizamos quicksort para ordenar el arreglo
// y despues solo imprimir los 5 primeros lugares.
void top5(Cancion *a,int tam){
  int i,j=1,fin=tam-5;
  printf(" \n \t\tLista de las 5 canciones mas escuchadas \n \n");
if(fin<=0)
  fin=0;
  
  	printf("\n *******************************************************************\n");
  for(i=tam-1;i>=fin;i--)
    {
      printf("\t %i << %s >>\n     \t<< %s >> \n \t<< Numero de veces reproducida :%i >>\n\n",j,a[i].nombre_cancion,a[i].artista,a[i].num_reproducciones);
      j++;
    }
  	printf("\n *******************************************************************\n");
}

/////*************************Funciones para imprimir las canciones por puntuacion ************/////////
//Hecho por Osmar Hernandez 

// Counting sort in C programming
void countingSort1(Cancion array[], int size) {
  int tam=size;
  Cancion output[100];
  // Encuentra la mayor calificacion
  int max = array[0].Puntuacion;
  for (int i = 1; i < size; i++) {
    //printf("%i\n", array[i].Puntuacion);
    if (array[i].Puntuacion > max)
      max = array[i].Puntuacion;
  }


  // The size of count must be at least (max+1) but
  // we cannot declare it as int count(max+1) in C as
  // it does not support dynamic memory allocation.
  // So, its size is provided statically.
  int count[7];

  // Initialize count array with all zeros.
  for (int i = 0; i <= max; ++i) {
    count[i] = 0;
  }

  // Store the count of each element
  for (int i = 0; i < size; i++) {
    count[array[i].Puntuacion]++;
  }

  // Store the cummulative count of each array
  for (int i = 1; i <= max; i++) {
    count[i] += count[i - 1];
  }

  // Find the index of each element of the original array in count array, and
  // place the elements in output array

  for (int i = size - 1; i >= 0; i--) {
    
    output[count[array[i].Puntuacion] - 1] = array[i];
    count[array[i].Puntuacion]--;
  }
 
  
  
  // Copy the sorted elements into original array
  for (int i = 0; i < size; i++) {
    array[i] = output[i];
  }

  
}

void printArray(Cancion array[], int size) {
  	printf("\n *******************************************************************\n");
  for (int i = size-1; i >= 0; --i) {
    printf("\n\t<< %s >>\n \t<< Rating: %i >>\n\n", array[i].nombre_cancion, array[i].Puntuacion);
  }
  	printf("\n *******************************************************************\n");
  printf("\n");
  
}


/////*************************Funciones para obtener lista en tiempo T=Segundos *****//////////////////
////Hecho por Edith Colorado

//Algoritmo de la mochila
int getSubSet(Cancion arregloC[], int tamA, int *aux, int k, int segundos){
  
  if(segundos==0)
    return 1;
  if(k >= tamA)
    return 0;
    
  for(int i = k; i < tamA; i++){
    if(arregloC[i].duracion<=segundos){
        aux[i] = 1;
        if(getSubSet(arregloC, tamA, aux, i+1, segundos - arregloC[i].duracion))
          return 1;
        aux[i] = 0;
    }
  }
  return 0;
}

void imprimirListaT(Cancion arreglo[],int tam,int *aux){
  
  int i=0;
  	printf("\n *******************************************************************\n");
  for(int i=0;i<tam;i++){
    if(aux[i]==1){
      printf("\t << %s >>\n \t<< %s >> \n\n",arreglo[i].nombre_cancion,arreglo[i].artista);
    }
  }
  	printf("\n *******************************************************************\n");
}


///////*************************Funcion para buscar una cancion a partir de una frase*****************/////
//Hecho por alan Medina

//metodo que verifica coincidencia en 2 cadenas 
int existMatch(char cad[], char c[]){
  int i, j = 0, n_c = strlen(c), n_cad = strlen(cad);  
  for(i = 0; i<=(n_cad - n_c) && j<n_c; i++)
  for(j = 0; j<n_c && cad[i+j]==c[j]; j++);
  return (j==n_c) ? 1 : 0; 
}


//Función para buscar una cancion a partir de una frase 

void buscar_Frase(Cancion *arreglodin, int tam) {
  char frase[100];
  printf("Ingresa una frase \n");
  scanf(" %[^\n]", frase);fflush(stdin);
  int i,j=0;
    printf("Las canciones que coinciden con %s son : \n", frase);
    printf("********************************************");
  for(i=0;i<tam;i++){
    if(existMatch(arreglodin[i].nombre_cancion,frase)){
      printf("\n \t  %s\n", arreglodin[i].nombre_cancion);
      j=1;
    }
    
      
  }
  if(j==0)
      printf("\n No Existen coincidencias \n");
    printf("******************************************** \n");
  }

//Este codigo lo utilizamos porque al ingresar las canciones no nos dimos cuenta
//que a algunas le pusimos como puntaje un numero mayor a 5

void modificarCancion(Cancion cancion)
{
	FILE *file8;
	int codigo,e=0,cantidad;
	
	if(!(file8=fopen("canciones.bin", "r+b")))
	{
		printf("Se ha producido un error al intentar abrir el archivo.\n");
		return;
	}
	
		printf("ingresa el codigo del prodcuto \n");
		scanf("%i",&codigo);
		fseek(file8,0,SEEK_SET);			//regreso el archivo a la posicion 0 
		fread(&cancion,sizeof(Cancion),1,file8);
		while(!feof(file8))
		{
			if (codigo==cancion.Puntuacion)
			{
				e=1;
				cancion.Puntuacion=4;
				int posicion=ftell(file8)-sizeof(Cancion);
				fseek(file8,posicion,SEEK_SET);
				fwrite(&cancion,sizeof(Cancion),1,file8);
        printf("Cambio el puntaje");
				
        
			}
			fread((&cancion),sizeof(Cancion),1,file8);
		}
		if (e==0)
		{
			printf("La cancion no existe\n");
		}

		fclose(file8);
}


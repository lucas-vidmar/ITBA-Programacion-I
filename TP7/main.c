//funcion main
int main(void) {

  char matriz[MAXFIL][MAXCOL];
  int maxfil ,maxcol, density, i=1;

  //preguntar por fila
  do {  //mientras haya un error, seguir preguntando
    printf("\n------------------------------------------\n");
    printf("Ingrese cantidad de filas (entre 1 y 100).\n");
    printf("------------------------------------------\n");
    maxfil=request();
    if (maxfil>MAXFIL)
      printf("La cantidad de filas debe ser menor a 100.\n");
  } while ((maxfil==0)||(maxfil>MAXFIL));

  //preguntar por columna
  do {  //mientras haya un error, seguir preguntando
    printf("\n--------------------------------------------\n");
    printf("Ingrese cantidad de columnas (entre 1 y 50).\n");
    printf("--------------------------------------------\n");
    maxcol=request();;
    if (maxcol>MAXCOL)
      printf("La cantidad de columna debe ser menor o igual a 50.\n");
  } while ((maxcol==0)||(maxcol>MAXCOL));

  do {  //mientras haya un error, seguir preguntando
    printf("\n---------------------------------------------\n");
    printf("Ingrese densidad de particulas (entre 1 y 5).\n");
    printf("---------------------------------------------\n");
    density=request();
    if (density>5)
      printf("La densidad debe ser menor o igual a 5.\n");
  } while ((density==0)||(density>5));

  //generamos matriz random
  density= 6 - density; //la densidad es inversa a la probabilidad
  generate(matriz, density);

  //miscellaneous
  miscellaneous();

  //imprimimos la matriz
  printf("\n");
  print(matriz,maxfil,maxcol);

  //se termino el ingreso de datos y generacion de matriz, se procede a generar las siguientes matrices
  while (1)
  {
    sleep(1); //decidimos usar el sleep con fines didacticos pero podria no utilizarse y hacer una funcion que simplemente espere la presion de una tecla
    //recibe la matriz de juego y la cantidad de columnas y filas
    printf("\nGeneration %d \n\n",i++);
    nxtgeneration(matriz, maxfil, maxcol);
  }
  
  return 0;
}

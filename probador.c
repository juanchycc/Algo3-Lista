#include"probador.h"
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"colores.h"

typedef struct probador{
	int cantidad_exitosas;
	int cantidad_pruebas;
}probador;



probador_t* crear_probador(){
	return calloc(1,sizeof(probador_t));
}


/*void avisar_prueba(probador_t* probador,char*aviso){

}*/

void describir_prueba(probador_t* probador,char* descripcion,bool paso_prueba){
	if(probador==NULL)
		return;

	if(paso_prueba)
		probador->cantidad_exitosas++;

	probador->cantidad_pruebas++;
	if(paso_prueba){
		printf("PRUEBA: %s"COLOR_VERDE" %s\n",descripcion,"EXITO"FONDO_NORMAL);
	}else{
		printf("PRUEBA: %s"COLOR_ROJO" %s\n",descripcion,"FALLO"FONDO_NORMAL);
	}
	
}

void estadisticas_prueba(probador_t* probador){
	if(!probador)
		return;
	int exito=(probador->cantidad_exitosas);
	int pruebas=(probador->cantidad_pruebas);
	if(exito==pruebas){
		printf("Pruebas exitosas" FONDO_VERDE" %i de %i\n"FONDO_NORMAL,probador->cantidad_exitosas,probador->cantidad_pruebas);
	}else{
		printf("Pruebas exitosas" FONDO_ROJO" %i de %i\n"FONDO_NORMAL,probador->cantidad_exitosas,probador->cantidad_pruebas);
	}
	
}

void destruir_probador(probador_t* probador){
	free(probador);
}



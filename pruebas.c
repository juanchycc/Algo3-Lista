#include"lista.h"
#include"probador.h"

#define MAX_DESCRIPCION 50
#define EXITO 0

typedef struct nodo{
	void* elemento;
	struct nodo* siguiente;
}nodo_t;

typedef struct lista{
	nodo_t* nodo;
	int cantidad;
}lista_t;

typedef struct lista_iterador{
	nodo_t* nodo;
}lista_iterador_t;


bool probar_crear(lista_t* lista){

	if(lista!=NULL && (lista->cantidad)==0 && lista->nodo==NULL)
		return true;
	else
		return false;
}

bool probar_insertar_vacio(lista_t* lista){

	int cantidad = lista->cantidad;
	long elemento = 2;
	int retorno = lista_insertar(lista,(void*)elemento);

	if( (lista->cantidad)-1==cantidad && (lista->nodo->siguiente)==NULL && retorno==EXITO && (long)(lista_ultimo(lista))==elemento)
		return true;
	else
		return false;	
}

bool probar_insertar_final(lista_t* lista){

	long elemento=3;
	int cantidad = lista->cantidad;
	int retorno = lista_insertar(lista,(void*)elemento);

	if( (lista->cantidad)-1==cantidad && retorno==EXITO && (long)(lista_ultimo(lista))==elemento )
		return true;
	else
		return false;
}

bool probar_insertar_primero(lista_t* lista){
	
	long elemento = 3;
	int cantidad = lista->cantidad;
	int posicion = 0;
	int retorno = lista_insertar_en_posicion(lista,(void*)elemento,posicion);

	if( (lista->cantidad)-1==cantidad && retorno==EXITO && (long)(lista_elemento_en_posicion(lista,posicion))==elemento )
		return true;
	else
		return false;	
}

bool probar_insertar_posicion_alta(lista_t* lista){
	long elemento = 8;
	int cantidad = lista->cantidad;
	int posicion = 80;
	int retorno = lista_insertar_en_posicion(lista,(void*)elemento,posicion);

	if( (lista->cantidad)-1==cantidad && retorno==EXITO &&(long)lista_ultimo(lista)==elemento )
		return true;
	else
		return false;
}

bool probar_eliminar_ultimo(lista_t* lista){

	int cantidad= lista->cantidad;
	int retorno = lista_borrar(lista);

	if( lista->cantidad==(cantidad-1) && retorno==EXITO)
		return true;
	else 
		return false;

}

bool probar_eliminar_primero(lista_t* lista){

	int cantidad = lista->cantidad;
	int retorno = lista_borrar_de_posicion(lista,0);

	if( lista->cantidad==(cantidad-1) && retorno==EXITO )
		return true;
	else
		return false;
}

bool probar_mostrar_primero(lista_t* lista){

	void* elemento = lista_elemento_en_posicion(lista,0);

	 if( elemento !=NULL && elemento == lista->nodo->elemento)
	 	return true;
	 else
	 	return false;
}

bool probar_mostrar_ultimo(lista_t* lista){

	void* elemento = lista_ultimo(lista);

	if( elemento !=NULL && elemento == lista->nodo->elemento)
		return true;
	else 
		return false;
}

bool probar_apilar(lista_t* lista){

	long elemento_enviado = 2;
	int cantidad = (lista->cantidad);

	int retorno = lista_apilar(lista,(void*)elemento_enviado);
	
	if( retorno==EXITO && ((lista->cantidad))-1==(cantidad) && (long)(lista_ultimo(lista))==elemento_enviado )
		return true;
	else
		return false;
}

bool probar_desapilar(lista_t* lista){

	int cantidad = lista->cantidad;
	int retorno = lista_desapilar(lista);

	if( retorno==EXITO && lista->cantidad==(cantidad-1) )
		return true;
	else
		return false;
}

bool probar_lista_nula_tope(lista_t* lista){

	lista_desapilar(lista);
	void* elemento = lista_tope(lista);

	if( elemento ==NULL && lista->cantidad==0 )
		return true;
	else 
		return false;
}

bool probar_encolar(lista_t* lista){

	int cantidad = lista->cantidad;
	long elemento_enviado = 5;
	int retorno = lista_encolar(lista,(void*)elemento_enviado);

	if( retorno==EXITO && cantidad==((lista->cantidad)-1) && elemento_enviado==(long)lista_ultimo(lista) )
		return true;
	else 
		return false;
}

bool probar_desencolar(lista_t* lista){

	int cantidad = lista->cantidad;
	int retorno = lista_desencolar(lista);

	if( retorno == EXITO && cantidad==(lista->cantidad)+1 )
		return true;
	else
		return false;
}

bool probar_lista_primero(lista_t* lista){

	lista_encolar(lista,(void*)2);

	void* elemento = lista->nodo->elemento;

	if( elemento==lista_primero(lista) )
		return true;
	else
		return false;
}

void mostrar_elementos(void* elemento,void* contexto){
	if(elemento==NULL)
		return;

	*(int*)contexto +=1;
	printf("\tElemento %i = %li\n",(*(int*)contexto),(long)elemento);
}

void iterador_interno_mostrar(lista_t* lista){
	printf("Iterador interno--->cantidad de elementos:%li \n",lista_elementos(lista));

	void* contexto = malloc(sizeof(void*));
	*(int*)contexto=0;
	if(contexto!=NULL){
		lista_con_cada_elemento(lista,&(mostrar_elementos),contexto);
		free(contexto);
	}
}

void elemento_posicion(lista_t* lista){

	char agregar;
	printf("Queres seguir agregando elementos?(S/N)\n");
	scanf(" %c",&agregar);
	long elemento;
	int posicion;

	while(agregar=='S'){
		printf("Escribi un elemento y una posicion\n");
		scanf("%li %i",&elemento,&posicion);

		lista_insertar_en_posicion(lista,(void*)elemento,posicion);

		printf("Queres seguir agregando elementos?(S/N)\n");
		scanf(" %c",&agregar);

	}
}

void probar_caja_negra(lista_t* lista){
	printf("Prueba de caja negra\n");
	long elemento;
	printf("Escribi tu primer elemento a insertar:\n");
	scanf("%li",&elemento);

	lista_insertar(lista,(void*)elemento);

	elemento_posicion(lista);

	iterador_interno_mostrar(lista);

}

bool probar_iterador_externo(lista_t* lista){

	lista_iterador_t* iterador = lista_iterador_crear(lista);

	int contador=0;
	bool error = false;

	while( contador < lista->cantidad && !error){
		if( lista_elemento_en_posicion(lista,contador) != lista_iterador_siguiente(iterador))
			error = true;
		contador++;
	}
	lista_iterador_destruir(iterador);

	if( !error)
		return true;
	else
		return false;
}


void probar(lista_t* lista,probador_t* probador,bool (*prueba)(lista_t*),char descripcion[MAX_DESCRIPCION]){
	bool paso = prueba(lista);

	describir_prueba(probador,descripcion,paso);
}

void llamar_pruebas(lista_t* lista,probador_t* probador){

	probar(lista,probador,(&probar_crear),"Crear lista correctamente");
	
	probar(lista,probador,(&probar_insertar_vacio),"Insertar en la ultima posicion si esta vacia la lista");

	probar(lista,probador,(&probar_insertar_final),"Insertar al final de la lista");

	probar(lista,probador,(&probar_insertar_primero),"Insertar en primera posicion");

	probar(lista,probador,(&probar_insertar_posicion_alta),"Insertar en una posicion mas alta que mi cantidad");

	lista_borrar(lista);

	probar(lista,probador,(&probar_eliminar_ultimo),"Eliminar el ultimo elemento");

	probar(lista,probador,(&probar_eliminar_primero),"Eliminar el primero");

	probar(lista,probador,(&probar_mostrar_primero),"Mostrar elemento en la primera posicion");

	probar(lista,probador,(&probar_mostrar_ultimo),"Mostrar el ultimo elemento");

	probar(lista,probador,(&probar_apilar),"Apilar en la lista");

	probar(lista,probador,(&probar_desapilar),"Desapilar en la lista");

	probar(lista,probador,(&probar_lista_nula_tope),"Lista tope con lista nula");

	probar(lista,probador,(&probar_encolar),"Encolar en la lista");

	probar(lista,probador,(&probar_desencolar),"Desencolar en la lista");

	probar(lista,probador,(&probar_lista_primero),"Primer elemento de la cola correcto");

	probar(lista,probador,(&probar_iterador_externo),"Iterador Externo");

	while( lista->cantidad >0){
		lista_borrar(lista);
	}

	probar_caja_negra(lista);
}

int main(){
	probador_t* probador=crear_probador();

	lista_t* lista=lista_crear();

	llamar_pruebas(lista,probador);

	lista_destruir(lista);

	destruir_probador(probador);
}

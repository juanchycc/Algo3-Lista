# Algo3-Lista
Enunciado:
Se pide implementar una Lista simplemente enlazada. Para ello se brindan las firmas de las funciones públicas a imple-
mentar y se deja a criterio del alumno la creación de las funciones privadas del TDA para el correcto funcionamiento de
la Lista cumpliendo con las buenas prácticas de programación.
Dentro de este TDA, se pide incluir también la implementación de las funciones básicas de los TDAs Pila y Cola, cumpliendo
asi que este satisfaga el comportamiento de las tres estructuras.
Adicionalmente se pide la creación de un iterador interno y uno externo para la lista.

Tda lista, pila y cola:

En este TP implemente una lista simplemente enlazada y las operaciones propuestas en el archivo lista.h, que estas involucran no solo operaciones basicas de la lista sino tambien operaciones basicas de pila y cola asi como tambien los respectivos iteradores externo e interno.
El hecho de que sea una lista simplemente enlazada implica que los elementos de esta lista sean nodos que tienen una referencia a su elemento (en este caso) proximo, de esta manera al insertar un nuevo nodo tengo que reservar memoria y cuando borro un nodo tengo que liberar memoria.

Para su compilacion en la terminar utilizamos la siguiente linea:

    gcc *.c -o lista_se -g -std=c99 -Wall -Wconversion -Wtype-limits -pedantic -Werror -O0

y para chequear la memoria y ejecutarlo utilizamos esta linea de código:

    valgrind --leak-check=full --track-origins=yes --show-reachable=yes ./ lista_se

El funcionamiento de mi implementacion es la siguiente:

Se crea una lista, para ello se reserva memoria en el heap del tamaño de mi tipo de dato lista, esa memoria va a ser apuntada por mi lista la cual tiene como elementos la cantidad de nodos y un puntero a un tipo de dato nodo.
Una vez insertado el primer nodo la cantidad se va a sumar y el elemento nodo de la lista mencionado va a apuntar hacia la direccion de la memoria reservada para el nuevo nodo, este nodo va a tener un elemento y un puntero a nodo que va a ser el siguiente nodo (al ser insertado estos elementos son inicializados). Si se inserta otro nodo puede ser en la ultima posicion o en la primera, si se llama a lista_insertar se va a insertar en la ultima posicion entonces el elemento siguiente del nodo en la primera posicion va a apuntar a una direccion de memoria que reservamos para el nuevo nodo y la cantidad ahora va a ser 2, en el caso que se inserte en la primer posicion,es decir, se llama a lista_insertar_en_posicion y especificamos que queremos la primer posicion(0), tendremos que darle la direccion de la memoria reservada a un nodo auxiliar hacer que el elemento siguiente de este auxiliar apunte al nodo que tengo en la primera posicion y por ultimo que el elemento nodo de mi lista apunte a este nuevo elemento, asi funcionan las inserciones, para borrar sucede algo parecido, tenemos borrar ultimo o borrar en posicion, donde el cuidado hay que tenerlo en borrar en posicion, ya que, tenemos que liberar al nodo pero no tenemos que perder la direccion del nodo siguiente.
Para facilitar estar y otras operaciones implemente dos funciones: una que busca el ultimo nodo pero me devuelve al ante ultimo y otra que busca el nodo en la posicion pedida y devuelve el nodo en la posicion anterior (para ambas:siempre y cuando la cantidad sea >1).

*A diferencia de una lista simplemente enlazada, en una lista doblemente enlazada los nodos no solo tienen la referencia al nodo siguiente, sino que tambien, tienen la referencia al nodo anterior.
*La caracteristica fundamental de una pila es que se maneja como un LIFO eso quiere decir justamente que los elementos se van apilando "uno encima del otro" y cuando se desapila se hace desde el ultimo. 
En una cola esto es distinto ya que se maneja como un FIFO eso quiere decir que inserta por el final pero elimina por el frente.
*Un iterador es un tda que permite recorrer el contenido (en este caso) de la lista, al ser una lista simplemente enlazada podemos hacer que el iterador "recuerde" en que nodo se quedo, sin tener que pasar por todos los elementos anteriores.
*Un iterador interno recorre todos los nodos interactuando con los elementos de acuerdo a la funcion mandada por el usuario es decir itera y opera, mientra que un iterador externo no necesariamente tiene que operar ni hacer la iteracion de todos los elementos.


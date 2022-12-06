/*
========================================================================
*                                                                      *
*   #####  #### ##### #   # ####  # ##### #     # ####  ##### #     #  *
*   #     #       #   #   # #   # # #   # ##    # #   # #     #     #  *
*   #     #       #   #   # #   # # #   # # #   # #   # #     #     #  *
*   ###    ###    #   #   # #   # # ##### #  #  # #   # ###   #     #  *
*   #         #   #   #   # #   # # #   # #   # # #   # #      #   #   *
*   #         #   #   #   # #   # # #   # #    ## #   # #       # #    *
*   ##### ####    #    ###  ####  # #   # #     # ####  #####    #     *
*                                                                      *
========================================================================

  Ejercicio: Manipulando una lista enlazada simple

  Concepto: Es un tipo especial de lista lineal en la que la eliminacion se realiza al principio de la lista, las inserciones se realizan al final de la lista.

  Caracteristicas: 
    - En las colas el elemento que entro primero sale primero, y elk que entra ultimo sale ultimo. Debido a esto a estas estructuras se les denomina FIFO(First-in, First-on)
    - Las colas se pueden implementar con arreglos o punteros.
    - Para trabajar con colas, es conveniente disenar subprogramas para insertar y sacar elementos.

  Bicola: es un tipo especial de cola en la que las eliminaciones y las inserciones se pueden realizar en cualquiera de los dos extremos de la lista.

  Tipos:
  - Doble cola de entrada restringida: acepta inserciones solo al final de la cola.
  - Doble cola de salida restringida: acepta eliminaciones solo al frente de la cola.
*/

// ---------- Operaciones con colas ---------------

// Insercion del nodo con valor 4

aux = (struct nodo *)malloc(sizeof(struct nodo));
aux->sig = null;
final->sig = aux;
final = aux;

// Eliminacion del nodo con valor 1

aux = frente;
elemento=aux->elem;
frente=frente->sig;
free(aux);



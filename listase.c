
#include<stdio.h>
#include<stdlib.h>

typedef struct Nodo{
    char* name;
    struct Nodo* sig;
}Libro;

Libro* inicializarLista(Libro* List);

Libro* addLibro(char *name,Libro* List);
Libro *deleteLibro(char *name, Libro *List);
void showList(Libro* List);


int main(){

    Libro* List = inicializarLista(List);
    
    List = addLibro("Hola Mundo",List);
    List = addLibro("Hola jose",List);
    List = addLibro("Hola Eduardo",List);
    List = addLibro("Hola boludo",List);
    List = addLibro("Hola bobo",List);

    showList(List);
    
    List = deleteLibro("Hola Eduardo",List);

    printf("\n\n");

    showList(List);

    return 0;
}

Libro* inicializarLista(Libro* List){

    List = NULL;
    return List;
}

Libro* addLibro(char *name,Libro* List){

    Libro* newBook ;
    newBook = (Libro*) malloc(sizeof(Libro));//reservar memoria
    newBook->name=name;
    newBook->sig=NULL;
    if(List == NULL){ //si List es null es el primer elemento de la lista que se ingresa
        List = newBook;
    }else{
        Libro* aux = List; //un auxiliar que es igual list
        while(aux->sig!=NULL){ //si este nodo apunta a otro nodo has el ciclo
            aux = aux->sig; //cambiando de nodo hacia el siguiente
        }
        //aqui quedaria el nodo final que apunta hacia NULL
        aux->sig=newBook;//Ahora el ultimo nodo que apunta hacia null apunta hacia el newBook
        
    }

    return List;
}

Libro *deleteLibro(char *name, Libro *List){
    Libro *previous_Book;
    previous_Book = (Libro*)malloc(sizeof(Libro));
    Libro *actual_Book;
    actual_Book = (Libro*)malloc(sizeof(Libro));
    actual_Book = List;
    
    if(actual_Book->name == name){
        List = actual_Book->sig;
    }else{
        while (actual_Book != NULL)
        {
            
            if (actual_Book->name != name)
            {
                previous_Book = actual_Book;
                actual_Book = actual_Book->sig;
            }
            if(actual_Book->name == name){
                previous_Book->sig = actual_Book->sig;
                actual_Book = NULL;
            }
            
        }
        free(actual_Book);
        
    }
    

    return List;
}

void showList(Libro* List){
    while (List != NULL) //si el segundo campon del struct que es un nodo esta en null si no existe nodo siguiente
    {
        printf("%s\n",List->name);//imprimir name del nodo
        List = List->sig;   //pasar al siguiente nodo
    }
    
}

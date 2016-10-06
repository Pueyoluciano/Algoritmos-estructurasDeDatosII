#include <iostream>
#include "mini_test.h"

#include "DiccString.hpp"


//Chequea que el diccionario vacio no tenga claves
void test_claves_dicc_vacio() {
	DiccString<int> d;
	ASSERT(d.Claves().cardinal() == 0);
}


//Chequea el definir y definido
void test_definir_definido() {
	DiccString<int> d;
	d.Definir("hola",42);
	ASSERT( d.Definido("hola") );
	ASSERT( !d.Definido("casona") );
 	ASSERT( !d.Definido("casa") );

	d.Definir("casona",13);
	ASSERT( d.Definido("hola") );
	ASSERT( d.Definido("casona") );
  	ASSERT( !d.Definido("casa") );

  	d.Definir("casa",6);
	ASSERT( d.Definido("hola") );
	ASSERT( d.Definido("casona") );
  	ASSERT( d.Definido("casa") );
}



//cheque el obtener
void test_obtener() {
	DiccString<int> d;
	d.Definir("hola",42);
	d.Definir("casa",22);

	ASSERT( d.Obtener("hola") == 42 );
	ASSERT( d.Obtener("casa") == 22 );

}



//cheque el borrar
void test_borrar() {
	//Completar este test para:
	//Verificar que al borrar una palabra, esta deja de estar definida en el diccionario
	//Chequear que si dos palabras comparten prefijos y una de ellas se borrar, la otra debe seguir estando definida
	//Analizar que el borrado funciona bien si el diccionario tiene definido una sola palabra y esta se borra.
	
	DiccString<int> d;
	d.Definir("hola",42);
	d.Definir("casa",22);
 	d.Borrar("casa");
	ASSERT( d.Definido("hola") );
	ASSERT(!d.Definido("casa") );

}


int main() {
	RUN_TEST(test_claves_dicc_vacio);
	RUN_TEST(test_definir_definido);
	RUN_TEST(test_obtener);
	RUN_TEST(test_borrar);
	//Realizar más test para chequear el funcionamiento del diccionario sobre trie.
	
	return 0;

}

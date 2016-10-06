#ifndef CONJ_HPP_
#define CONJ_HPP_

#include <iostream>
#include <set>

using namespace std;

template <class T>
class Conj
{
	public:

		// Constructor. Genera un conjunto vacio.
		Conj();


		// Constructor por copia
		Conj(const Conj<T>&);


		// Destructor. Deja limpia la memoria.
		~Conj();

		// Inserta un elemento en el conjunto. Si ya existe,
		// el conjunto no se modifica.
		void insertar(const T&);


		// Decide si un elemento pertenece al conjunto o no.
		bool pertenece(const T&) const;

		// borra un elemento del conjunto. Si no existe,
		// el conjunto no se modifica.
		void remover(const T&);

		// devuelve el minimo elemento del conjunto segun <.
		const T& minimo() const;


		// devuelve la cantidad de elementos que tiene el conjunto.
		int cardinal() const;



	private:

		// El conjunto se va a impementar sobre la libreria set de c++
		set<T> conjunto;

};


template <class T>
Conj<T>::Conj(){
}

template <class T>
Conj<T>::Conj(const Conj<T>& otro): conjunto(otro.conjunto) {

}

template <class T>
Conj<T>::~Conj()
{
}


template <class T>
bool Conj<T>::pertenece(const T& clave) const {
	return (conjunto.find(clave) != conjunto.end());
}

template <class T>
void Conj<T>::insertar(const T& clave)
{
	(this->conjunto).insert(clave);
}



template <class T>
int Conj<T>::cardinal() const
{
	return (this->conjunto).size();
}


// Pre: el conjunto debe tener al menos un elemento
template <class T>
void Conj<T>::remover(const T& clave)
{
	conjunto.erase(clave);
}



template <class T>
const T&  Conj<T>::minimo() const
{

	  return *(conjunto.begin());
}




#endif // CONJUNTO_HPP_

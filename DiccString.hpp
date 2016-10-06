#ifndef DICC_STRING_H_
#define DICC_STRING_H_

#include "Conj.hpp"
#include <string>
#include <iostream>
#include <cassert>
using namespace std;


template<typename T>
class DiccString {
    public:
        /**
        CONSTRUCTOR
        * Construye un diccionario vacio.
        **/
        DiccString();

        /**
        CONSTRUCTOR POR COPIA
        * Construye un diccionario por copia.
        **/
        DiccString(const DiccString<T>&);


        /**
        DESTRUCTOR
        **/
        ~DiccString();

        /**
        DEFINIR
        * Recibe una clave con su significado de tipo T y la define.
        * Si ya estaba definida, la reescribe.
        **/
        void Definir(const string& clave, const T& significado);

        /**
        DEFINIDO?
        * Devuelve un bool, que es true si la clave pasada está definida en
        * el diccionario.
        **/
        bool Definido(const string& clave) const;

        /**
        OBTENER
        * Dada una clave, devuelve su significado.
        * PRE: La clave está definida.
        --PRODUCE ALIASING--
        -- Versión modificable y no modificable
        **/
        const T& Obtener(const string& clave) const;
        T& Obtener(const string& clave);

        /**
        OBTENER
        * Dada una clave, la borra del diccionario junto a su significado.
        * PRE: La clave está definida.
        --PRODUCE ALIASING--
        **/
        void Borrar(const string& clave);


        /**
        CLAVES
        * Devuelve las claves del diccionario.
        --NO PRODUCE ALIASING--
        **/
        const Conj<string>& Claves() const;

    private:

        struct Nodo{
            Nodo** siguientes;
            T* definicion;
            Nodo(){
                siguientes = new Nodo*[256];
                for (int i = 0; i < 256; i++){
                    siguientes[i] = NULL;
                }
                definicion = NULL;
            }
            ~Nodo(){
                delete definicion;
                delete [] siguientes;
            }
        };

        //TODO: funciones auxiliares

        Nodo* raiz;
        Conj<string> claves;
                
        int toAscii(char);

        
};


template <typename T>
DiccString<T>::DiccString()
    : raiz(NULL), claves(){
}


template <typename T>
DiccString<T>::DiccString(const DiccString& d) {

	//TODO
    assert(false);
}

template <typename T>
DiccString<T>::~DiccString(){

	//TODO
    assert(false);
}


template <typename T>
void DiccString<T>::Definir(const string& clave, const T& significado){
    
    //TODO
    assert(false);
}


template <typename T>
bool DiccString<T>::Definido(const string& clave) const{
    if(raiz){
        
        Nodo* actual = raiz;
        
        for (int i = 0; i < clave.length() ; i++){
            int ascii = toAscii(clave[i]);
            if(actual->siguientes[ascii]){
                if(actual->definicion){
                    return true;
                    
                } else {
                    actual = actual->siguientes[toAscii(clave[i])];
                }
                
            } else{
                return false;
            }
        }
    }

    return false;
}

template <typename T>
T& DiccString<T>::Obtener(const string& clave) {
	
	//TODO
    assert(false);
}


template <typename T>
const T& DiccString<T>::Obtener(const string& clave) const {
	
    //TODO
    assert(false);
}


template <typename T>
const Conj<string>& DiccString<T>::Claves() const{
    return claves;
}


template <typename T>
void DiccString<T>::Borrar(const string& clave) {
	//TODO
    assert(false);
}


#endif

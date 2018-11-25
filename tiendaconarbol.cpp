///Brayan Guadalupe Hernandez Ico 22 Tienda con arboles
#include <iostream>
#include <stdio.h>
#include<conio.h>
#include <stdlib.h>
#include <iomanip>
using namespace std;


string arreglo[]= {   "CocaCola","Pepsi","Fanta","Mirinda","Bonafont","Agua","Sabritas","Rancheritos","Pollo","pan",""};
float cantidadapagar=0;
struct Nodo
{
    string dato;
    Nodo *der;
    Nodo *izq;

};

Nodo *arbol =NULL;
///prototipos
///void funcion de menu
void menu();

Nodo *crearNodo(int);
int posicion=0;
void insertarNodo(Nodo *&, string);
void mostrarArbol(Nodo *, int,int);
void enOrden(Nodo *);
void postOrden(Nodo *);
void preOrden(Nodo *);
void presentation ();


void niveles(Nodo *,int);

int main()
{

    menu();


    getch();
    return 0;
}
///FUNCION PARA CREAR UN NUEVO NODO
Nodo *crearNodo(string n)
{

    Nodo *nuevo_nodo = new Nodo();

    nuevo_nodo->dato = n;
    nuevo_nodo->der = NULL;
    nuevo_nodo->izq = NULL;
    return nuevo_nodo;

}

void insertarNodo(Nodo *&arbol, string n)
{
    if(arbol==NULL)
    {
        ///si el arbol esta vacio crear nuevo nodo
        Nodo *nuevo_nodo =crearNodo(n);
        arbol=nuevo_nodo;
    }
    else
    {
///si el arbol tiene un nodo o mas
        string valorRaiz= arbol->dato;///obtenemos el valor de la raiz
        /*if (n==valorRaiz)
        {
            return;
        }*/
        if(n< valorRaiz) ///SI EL ELEMTO ES MENOS A LA RAIZ insertar a izq
        {
            insertarNodo(arbol->izq,n);
        }
        else
        {
            ///si el elemento es mayor ala raiz inserata a la derecha
            insertarNodo(arbol->der,n);
        }


    }


}

void niveles(Nodo *arbol, int cont)
{
    if(arbol==NULL)
    {
        return;
    }
    else
    {
        niveles(arbol->der, cont+1);
        if(posicion<cont)
        {
            posicion=cont;
        }
        niveles(arbol->izq, cont+1);
    }
}

void menu()
{
    int  opcion, contador=1, banco;
    string masdatos,dato;
    do
    {
        presentation();
        cout<<"\t._ _ _ _ _ _ _ _ _MENU:_ _ _ _ _ _ _ _ _ _ "<<endl;

        cout<<"Comprar productos existentes  [press 1]\n";
        cout<<"Insertar producto y precio [press 2]\n";
        cout<<"Ver arbol [press 3]\n같같캳ALIR같같 [press 4]\n";
        cout<<"_ _ _ _ _ _ _ _  _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _";
        cout<<"\nOpcion ----->";
        cin>>opcion;
        switch(opcion)
        {
        case 1:
            do
            {
                cout<< "CocaCola $15 [press 0],\nPepsi $10[press 1],\nFanta $10[press 2],\nMirinda $8[press 3],\nBonafont $12[press 4],\nAgua $8[press 5],\nSabritas $12[press 6],\nRancheritos $9[press 7], \nPollo $45 [press 8],\nPan $3 [press 9]\nSalir [press 10]\n";
                cin>>banco;

                dato= arreglo[banco];
                insertarNodo(arbol,dato);
                if (banco==0)
                {
                    cantidadapagar=cantidadapagar+15;
                }
                else if (banco==1)
                {
                    cantidadapagar=cantidadapagar+10;
                }
                else if (banco==2)
                {
                    cantidadapagar=cantidadapagar+10;
                }
                else if (banco==3)
                {
                    cantidadapagar=cantidadapagar+8;
                }
                else if (banco==4)
                {
                    cantidadapagar=cantidadapagar+12;
                }
                else if (banco==5)
                {
                    cantidadapagar=cantidadapagar+8;
                }
                else if (banco==6)
                {
                    cantidadapagar=cantidadapagar+12;
                }
                else if (banco==7)
                {
                    cantidadapagar=cantidadapagar+9;
                }
                else if (banco==8)
                {
                    cantidadapagar=cantidadapagar+45;
                }
                else  if (banco==9)
                {
                    cantidadapagar=cantidadapagar+3;
                }
                cout<<"ELEMTO INSERTADO CORRECTAMENTE\n";
                system("pause");
                system("cls");

            }
            while (banco !=10);


            break;
        case 2:
            int qw,ms;
            presentation();
            cout<<"\nCuantos productos quieres\n";
            cin>>qw;
            for (int i=0; i<qw; i++)
            {
                cout<<"Nombre del producto\n";
                cin>> dato;
                cout<<"Precio ......$";
                cin>>ms;
                cantidadapagar=cantidadapagar+ms;
                insertarNodo(arbol,dato);
                cout<<"Dato insertado correctamente\n";
            }



            break;
        case 3:
            presentation();
            cout << "\nMostrar el arbol:\n\n";
            niveles(arbol,contador);

            for(int i=1; i<posicion+1; i++)
            {
                mostrarArbol(arbol,contador, i);
                cout << endl;
            }
            cout<<"\n\nCantidad a pagar 같같같같�> $"<<cantidadapagar<<endl;

            cout << "\n\n En orden   :  ";
            enOrden(arbol);
            cout << "\n\n Pre Orden  :  ";
            preOrden(arbol);
            cout << "\n\n Post Orden :  ";
            postOrden(arbol);
            break;

        }
        cout<<"\n\n\n\n";
        system("pause");
        system("cls");
    }
    while (opcion !=4);
    presentation();

}

void mostrarArbol(Nodo *arbol, int cont, int posicionactual)
{
    if(arbol==NULL)
    {
        return;
    }
    else
    {
        mostrarArbol(arbol->izq, cont+1, posicionactual);
        if(cont==posicionactual)
        {

            cout << arbol->dato;
        }
        else
        {
            cout << "같같";
        }
        mostrarArbol(arbol->der, cont+1, posicionactual);
    }
}

void preOrden( Nodo *arbol)
{
    if(arbol!=NULL)
    {if (arbol->dato == "."){
            cout<<"  ";
        }
        else
        cout << arbol->dato <<" ";
        preOrden(arbol->izq);
        preOrden(arbol->der);
    }
}

void enOrden(Nodo *arbol)
{
    if(arbol!=NULL)
    {
        enOrden(arbol->izq);
        if (arbol->dato == "."){
            cout<<"  ";
        }
        else{
        cout << arbol->dato << " ";
        }

        enOrden(arbol->der);
    }
}

void postOrden(Nodo *arbol)
{
    if(arbol!=NULL)
    {
        postOrden(arbol->izq);
        postOrden(arbol->der);
        if (arbol->dato == "."){
            cout<<"  ";
        }
        else
        cout << arbol->dato << " ";
    }
}

void presentation ()
{

    cout<<"\t\t              * * * \n";
    cout<<"\t\t         **      BY      *"<<endl;
    cout<<"\t\t      ***        BRAYAN    *\n";
    cout<<"\t\t     ***    GUADALUPE     ^  *\n";
    cout<<"\t\t    ***     HERNANDEZ   <   > *\n";
    cout<<"\t\t    ***                      *\n";
    cout<<"\t\t     ***       ICO22       *\n";
    cout<<"\t\t       **                *\n";
    cout<<"\t\t          ** ** ** * *\n";
    cout<<"\t\t             **\n";
    cout<<"\t\t               **\n";
    cout<<"\t\t              **\n";
    cout<<"\t\t            **\n";
    cout<<"\t\t             **\n";
    cout<<"\t\t               **\n";
}










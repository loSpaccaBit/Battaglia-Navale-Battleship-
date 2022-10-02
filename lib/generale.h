#ifndef BC451333_AF9F_4E96_A19C_FFA10E15E08E
#define BC451333_AF9F_4E96_A19C_FFA10E15E08E
/**================================================================================================
 * *                                           INFO
 *  Autore    : Francesco Pio Nocerino
 *  @email    : kekko.dev16@gmail.com
 *  File      : generale.h
 *  Versione  : 1.0
 *  Data      : 27/09/2022
 *  Descr     :
 * ? Libreria usata x tutti i giocatori
 *================================================================================================**/
#ifdef _WIN32
#include <windows.h>
#elif defined __APPLE__ || defined(__linux) || defined(__LINUX__) || defined(__gnu_linux__)
#include <unistd.h>
#endif
#include <iostream>
#include <time.h>
#include "controlli.h"
#include "grafica.h"
using namespace std;

#define R 10 // numero righe
#define C 10 // numero colonne

void slp(int s); // sleep

void inizializza(string v[R][C]); // inizializza la matrice
int colpito(string v[R][C], int x, int y);
int n_ran(int max);

void slp(int s)
{
    /**----------------------------------------------
    **              slp
    *?  sleep programma
    *@param s int
    *@return void
    *---------------------------------------------**/
#ifdef _WIN32
    Sleep(s * 1000);
#elif defined __APPLE__ || defined(__linux) || defined(__LINUX__) || defined(__gnu_linux__)
    sleep(s);
#endif
}

void inizializza(string v[R][C])
{
    /**----------------------------------------------
     **              inizializza
     *?  inizializza la matrice
     *@param v[R][C] string
     *@return void
     *---------------------------------------------**/
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < R; j++)
        {
            v[i][j] = ' ';
        }
    }
}

int colpito(string v[R][C], int x, int y)
{
    /**----------------------------------------------
     **              colpito
     *?  Controlla se la posizione e' occupata
     *@param x,y int
     *@param v[R][C] string
     *@return void
     *---------------------------------------------**/
    if (cntrl_ps(v, x, y) == true) // se la posizione e' occupata
    {
        v[x][y] = SIMBOLO2; // verrà' sostituita con un altro simbolo
        return 1;
    }
    else
        return 0;
}

int n_ran(int max)
{
    /**----------------------------------------------
     **              n_ran
     *?  Numeri random
     *@param max int
     *@return void
     *---------------------------------------------**/
    srand(unsigned(time(NULL)));
    int num = rand() % max;
    return num;
}

#endif /* BC451333_AF9F_4E96_A19C_FFA10E15E08E */

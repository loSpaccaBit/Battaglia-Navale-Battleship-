#ifndef D092D6DE_69C1_4835_9135_5D23C68D63DD
#define D092D6DE_69C1_4835_9135_5D23C68D63DD
/**================================================================================================
 * *                                           INFO
 *  Autore    : Francesco Pio Nocerino
 *  @email    : kekko.dev16@gmail.com
 *  File      : pc.h
 *  Versione  : 1.0
 *  Data      : 27/09/2022
 *  Descr     :
 * ? Libreria per mosse del pc
 *================================================================================================**/
#ifdef _WIN32
#include <windows.h>
#elif defined(__APPLE__)
#include <unistd.h>
#endif
#include <iostream>
#include <time.h>
#include "controlli.h"
#include "grafica.h"
using namespace std;

#define R 10 // numero righe
#define C 10 // numero colonne

void navi_pc(string v[R][C]); // Inserimento navi x pc

void navi_pc(string v[R][C])
{
    /**----------------------------------------------
     **              navi_pc
     *?  Inserimento navi x pc
     *@param v[R][C] string
     *@return void
     *---------------------------------------------**/
    srand(unsigned(time(NULL)));
    int celle[4] = {4, 3, 2, 1};    // numero di celle delle barche
    int n_barche[6] = {1, 2, 2, 1}; // numero di barche disponibili
    const int n_b = 6;              // numero di navi in tot
    int x, y;                       // indici
    bool found = false;
    for (int i = 0; i < n_b; i++) // x il numero massimo di barche
    {
        for (int j = 0; j < n_barche[i]; j++)
        {
            x = rand() % 7; // genera posizioni random
            y = rand() % 7;
            for (int k = 0; k < celle[i] || y > R; k++, y++)
            {
                do
                {
                    if (cntrl_ps(v, x, y)) // controllo se la posizione e occupata
                    {
                        x = rand() % 7;
                        y = rand() % 7;
                    }
                    else // se non e occupata verrà inserita la nave
                    {
                        found = true;
                        v[x][y] = SIMBOLO; // █
                    }
                } while (!found);
            }
        }
    }
}

#endif /* D092D6DE_69C1_4835_9135_5D23C68D63DD */

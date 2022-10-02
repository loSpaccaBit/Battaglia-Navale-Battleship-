#ifndef B16E3226_1FAD_459F_912E_C334A16C6004
#define B16E3226_1FAD_459F_912E_C334A16C6004
/**================================================================================================
 * *                                           INFO
 *  Autore    : Francesco Pio Nocerino
 *  @email    : kekko.dev16@gmail.com
 *  File      : ply.h
 *  Versione  : 1.0
 *  Data      : 27/09/2022
 *  Descr     :
 * ? Libreria x giocatore umano
 *================================================================================================**/
#include <iostream>
#include "controlli.h"
#include "grafica.h"
using namespace std;

void navi_ply(string v[R][C]); // inserimento navi x utente

void navi_ply(string v[R][C])
{
    /**----------------------------------------------
    **              navi_ply
    *?  Inserimento navi x umano
    *@param v[R][C] string
    *@return void
    *---------------------------------------------**/
    int x, y;
    bool found = false;
    int celle[4] = {4, 3, 2, 1};    // numero di celle delle barche
    int n_barche[6] = {1, 2, 2, 1}; // numero di barche disponibili
    const int n_b = 6;              // numero totale di navi

    cout << "BARCHE DISPONIBILI:\n";
    for (int i = 0; i < 4; i++)
    {
        cout << n_barche[i] << " nave da " << celle[i] << endl;
    }
    cout << "-----------------------------------\n";
    for (int i = 0; i < n_b; i++)
    {
        for (int j = 0; j < n_barche[i]; j++)
        {
            cout << "Nave con " << celle[i] << " celle" << endl;
            cout << "Inserisci posizione dove metto? > ";
            cin >> x >> y;             // inserimento coordinate
            cntrl_ins(x, y);           // controllo coordinate inserite
            cntrl_spazio(x, celle[i]); // controllo spazi navi
            cntrl_spazio(y, celle[i]);
            for (int k = 0; k < celle[i] || y > R; k++, y++)
            {
                do
                {
                    if (cntrl_ps(v, x, y)) // Controlla se la posizione inserita e' libera
                    {
#ifdef _WIN32 // stampa errore
                        set_console_color(RED);
                        cout << bold_on << "[ERROR 001] POSIZIONE OCCUPATA\n"
                             << bold_off;
                        set_console_color(YELLOW);
                        cout << "Suggerimento:\nSi parte dalla posizione 0;0" << endl;
                        set_console_color(WHITE_OFF);
#elif defined(__APPLE__) || defined(__linux) || defined(__LINUX__) || defined(__gnu_linux__)
                        cout << color(RED, BOLD, "[ERROR 001] POSIZIONE OCCUPATA\n");
                        cout << color(YELLOW, "", "Suggerimento:\nSi parte dalla posizione 0;0") << endl;
#endif
                        cout << "Nave con " << celle[j] << endl;
                        cout << "Inserisci posizione dove metterla > ";
                        cin >> x >> y;
                    }
                    else // se e' libera la nave verrà inserita
                    {
                        found = true;
                        v[x][y] = SIMBOLO;
                    }
                } while (!found);
            }
        }
    }
}

#endif /* B16E3226_1FAD_459F_912E_C334A16C6004 */

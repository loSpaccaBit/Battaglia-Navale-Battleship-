#ifndef B08905E1_D28A_4447_8379_8F58E190E866
#define B08905E1_D28A_4447_8379_8F58E190E866
/**================================================================================================
 * *                                           INFO
 *  Autore    : Francesco Pio Nocerino
 *  @email    : kekko.dev16@gmail.com
 *  File      : controlli.h
 *  Versione  : 1.0
 *  Data      : 27/09/2022
 *  Descr     :
 * ? Libreria x controlli
 *================================================================================================**/
#include <iostream>
#include "grafica.h"
using namespace std;

#define R 10 // numero righe
#define C 10 // numero colonne

/*================== ERROR LIST =================*/
/**
 * [ERROR 001] POSIZIONE OCCUPATA
 * [ERROR 002] POSIZIONE NON VALIDA
 */

bool cntrl_ps(string v[R][C], int &x, int &y); // controllo posizioni
void cntrl_ins(int &x, int &y);                // controllo inserimento coordinate
void cntrl_spazio(int &x, int n);              // controllo spazio disponibile

bool cntrl_ps(string v[R][C], int &x, int &y)
{
    /**----------------------------------------------
     **             cntrl_ps
     *?  Controllo posizione
     *@param v[R][C] string
     *@param &x, &y int
     *@return bool
     *---------------------------------------------**/
    bool r = false;
    if (v[x][y].compare(SIMBOLO) == 0)
        r = true;
    return r;
}

void cntrl_ins(int &x, int &y)
{
    /**----------------------------------------------
    **             cntrl_ins
    *?  Controllo inserimento coordinate
    *@param &x, &y int
    *@return void
    *---------------------------------------------**/
    bool found = false;
    while (x < 0 || x >= 10 || y < 0 || y >= 10)
    {
#ifdef _WIN32
        set_console_color(RED);
        cout << bold_on << "[ERROR 002] POSIZIONE NON VALIDA!\n"
             << bold_off;
        set_console_color(YELLOW);
        cout << "Suggerimento:\nSi parte dalla posizione 0;0" << endl;
        set_console_color(WHITE_OFF);
#elif defined(__APPLE__) || defined(__linux) || defined(__LINUX__) || defined(__gnu_linux__)
        cout << color(RED, BOLD, "[ERROR 002] POSIZIONE NON VALIDA!\n");
        cout << color(YELLOW, "", "Suggerimento:\nSi parte dalla posizione 0;0") << endl;
#endif
        cout << "Inserisci posizione > ";
        cin >> x >> y;
    }
}

void cntrl_spazio(int &x, int n)
{
    /**----------------------------------------------
     **             cntrl_spazio
     *?  Controllo spazio
     *@param &x, n int
     *@return void
     *---------------------------------------------**/
    int t = x + n;
    if (t >= 10)
    {
        x -= n;
    }
}
#endif /* B08905E1_D28A_4447_8379_8F58E190E866 */

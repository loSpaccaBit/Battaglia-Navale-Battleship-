/**================================================================================================
 * *                                           INFO
 *  Autore    : Francesco Pio Nocerino
 *  @email    : kekko.dev16@gmail.com
 *  File      : main.cpp
 *  Versione  : 1.0
 *  Data      : 27/09/2022
 *  Descr     :
 * ? Scrivere un programma che simuli il gioco della battaglia navale, che avviene tra un giocatore e il PC
 *================================================================================================**/
#include <iostream>
#include <iomanip>
#include "../lib/pc.h"
#include "../lib/ply.h"
#include "../lib/generale.h"
#include "../lib/grafica.h"
using namespace std;

#define R 10		 // numero righe
#define C 10		 // numero colonne
#define TENTATIVI 10 // numero di tentativi massimo

int main()
{
	cl();
	string pc[R][C], npl[R][C]; // matrici: pc (giocatore macchina), npl (giocatore umano)
	int x, y, x1, y1, conta = 0, conta2 = 0;
	/*==============================================================*/
	banner();
	inizializza(pc);  // inizializza matrice dell pc
	inizializza(npl); // inizializza matrice dell utente

	navi_pc(pc);   // inserimento navi
	navi_ply(npl); // inserimento navi utente

	slp(2); // sleep
	cl();	// pulisci schermo

	do
	{

#ifdef _WIN32 // stampa punteggio
		cout << "MOSSE PC: ";
		set_console_color(MAGENTA);
		cout << bold_on << conta2 << bold_off << " ";
		set_console_color(WHITE_OFF);
		cout << "MOSSE UOMO ";
		set_console_color(GREEN);
		cout << bold_on << conta << bold_off << endl;
		set_console_color(WHITE_OFF);
#elif defined __APPLE__ || defined(__linux) || defined(__LINUX__) || defined(__gnu_linux__)
		cout << "MOSSE PC: " << color(MAGENTA, BOLD, conta2);
		cout << endl
			 << "MOSSE UOMO " << color(GREEN, BOLD, conta) << endl;
#endif
		cout << "UOMO: Inserisci coordinate > "; // stampa inserimento coordinate uomo
		cin >> x >> y;
		cntrl_ins(x, y);
		conta += colpito(pc, x, y); // controllo vincita
		cout << "UTENTE\n";
		stampa(npl); // stampa tabella umano

		x1 = n_ran(10); // gen numeri random x coordinate
		y1 = n_ran(9);
		cout << "PC: coordinate < " << x1 << ";" << y1 << endl;
		conta2 += colpito(npl, x1, y1);

		slp(2); // sleep 2s
		cl();	// pulisci schermo
	} while (conta < TENTATIVI && conta2 < TENTATIVI);

	if (conta >= TENTATIVI)
		banner_umano(); // vincita umano
	else
		banner_pc(); // vincita pc

	return 0;
}

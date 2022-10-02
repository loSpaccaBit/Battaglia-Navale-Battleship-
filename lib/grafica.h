#ifndef DCBF1E02_B005_4B3E_99EC_F94997673209
#define DCBF1E02_B005_4B3E_99EC_F94997673209
/**================================================================================================
 * *                                           INFO
 *  Autore    : Francesco Pio Nocerino
 *  @email    : kekko.dev16@gmail.com
 *  File      : grafica.h
 *  Versione  : 1.1
 *  Data      : 27/09/2022
 *  Descr     :
 * ? Libreria grafica
 *================================================================================================**/
#ifdef _WIN32 //? implementazione Win
#include <windows.h>
/*================================ COLORI ==============================*/
#define GREEN 10
#define RED 12
#define WHITE 15
#define WHITE_OFF 7
#define YELLOW 14
#define BLUE 9
#define MAGENTA 13
/*==============*/
#elif defined(__APPLE__) || defined(__linux) || defined(__LINUX__) || defined(__gnu_linux__)
#define GREEN "92"
#define RED "91"
#define YELLOW "93"
#define BLUE "94"
#define WHITE "97"
#define MAGENTA "95"
#define BOLD "1"
#endif
#include <iostream>
#include <iomanip>
using namespace std;

#define R 10 // numero righe
#define C 10 // numero colonne

#ifdef _WIN32 // simbolo per barche
const char s1 = 219;
const char s2 = 176;
const string SIMBOLO(1, s1); // costruttore per la trasformazione in stringa
const string SIMBOLO2(1, s2);
#elif defined __APPLE__ || defined(__linux) || defined(__LINUX__) || defined(__gnu_linux__)
#define SIMBOLO "█"
#define SIMBOLO2 "░"
#endif
/*==============================================================*/
void cl(); // pulisci schermo
/*================================ TESTO ==============================*/

#ifdef _WIN32
void set_console_color(int dim);   //*Win
void size_shell(int h, int w);     //* Ridimensiona la shell
ostream &bold_on(std::ostream &os) //! testo in bold per win
{
    return os << "\e[1m";
}

ostream &bold_off(std::ostream &os)
{
    return os << "\e[0m";
}
#elif defined(__APPLE__) || defined(__linux) || defined(__LINUX__) || defined(__gnu_linux__) //*MacOs
//! overloading color
void size_shell_MacOS(string h, string w); //* RIdimensiona shell
string color(string word, string back, string frase);
string color(string word, string back, char frase);
string color(string word, string back, int num);
string color(string word, string back, float num);
#endif
/*================================ SIS ==============================*/
void stampa(string v[R][C]);
void banner();
void banner_pc();
void banner_umano();
/*================================ FINE PROTOTIPI ==============================*/

void cl()
{
    /**----------------------
     **   CL
     *? Pulisci schermo
     *@param void
     *@return void
     *------------------------**/
#ifdef _WIN32
    system("cls");
#elif defined(__APPLE__) || defined(__linux) || defined(__LINUX__) || defined(__gnu_linux__)
    system("clear");
#endif
}

//? Colori x tutti i SO
#ifdef _WIN32
/**----------------------
 **   SET_CONSOLE_COLOR
 *? Colori x shell Win
 *@param cl int
 *@return void
 *------------------------**/
void set_console_color(int cl)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, cl);
}
/**----------------------
 **   SIZE_SHELL
 *? Ridimensionamento terminale Win
 *@param cl int
 *@return void
 *------------------------**/
void size_shell(int h, int w) //! Ridimensiona shell data altezza e larghezza
{
    HWND console = GetConsoleWindow();
    RECT ConsoleRect;
    GetWindowRect(console, &ConsoleRect);

    MoveWindow(console, ConsoleRect.left, ConsoleRect.top, h, w, TRUE);
}
/*=============================================*/
#elif defined(__APPLE__) || defined(__linux) || defined(__LINUX__) || defined(__gnu_linux__)
/**----------------------
 **   SIZE_SHELL_MacOS
 *? Ridimensionamento terminale MacOS
 *@param h e w string
 *@return void
 *------------------------**/
void size_shell_MacOS(string h, string w) //! Ridimensiona shell data altezza e largehzza su UNIX
{
    cout.flush();
    cout << "\e[8;" + w + ";" + h + "t";
}
/**----------------------
 **   COLOR
 *? Colori x shell MacOS
 *@param word, back e frase string
 *@return string
 *------------------------**/
string color(string word, string back, string frase)
{
    string tot = "\033[" + back + ";" + word + "m" + frase + "\033[0m";
    return tot;
}
string color(string word, string back, char frase)
{
    string frase2(1, frase);
    string tot = "\033[" + back + ";" + word + "m" + frase2 + "\033[0m";
    return tot;
}
string color(string word, string back, int num)
{
    string n = to_string(num);
    string tot = "\033[" + back + ";" + word + "m" + n + "\033[0m";
    return tot;
}
string color(string word, string back, float num)
{
    string n = to_string(num);
    string tot = "\033[" + back + ";" + word + "m" + n + "\033[0m";
    return tot;
}
#endif

void stampa(string v[R][C])
{
    int k = 0;
    char car[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'L'};
    for (int i = 0; i < R; i++)
        cout << setw(3) << i << "";

    cout << endl;
    cout << setw(33) << "+-----------------------------+" << endl;
    for (int i = 0; i < R; i++, k++)
    {
        cout << setw(2) << i << "|";
        for (int j = 0; j < R; j++)
            cout << setw(1) << v[i][j] << setw(2) << "|";

        cout << i;
        cout << endl;
    }

    cout << setw(33) << "+-----------------------------+" << endl;
    for (int i = 0; i < R; i++)
        // cout << setw(3) << car[i] << "";
        cout << setw(3) << i << "";
    cout << endl;
}

void banner()
{

#ifdef _WIN32
    set_console_color(WHITE);
    cout << "                               )___( \n";
    cout << "                        _______/__/_                   +---------------------------+\n";
    cout << "                __     /===========|   ___             |";
    set_console_color(MAGENTA);
    cout << bold_on << ">" << bold_off;
    set_console_color(YELLOW);
    cout << " By:FRANCESCO PIO NOCERINO";
    set_console_color(WHITE);
    cout << " |\n";
    cout << "____       _   [\\\\]___/____________|__[///]    __      +---------------------------+\n";
    cout << "\\   \\_____[\\]__/___________________________\\__[//]____\n";
    cout << " \\";
    set_console_color(GREEN);
    cout << "BATTAGLIA NAVALE";
    set_console_color(WHITE_OFF);
    cout << "                                   |\n";
    cout << "  \\                                            ";
    set_console_color(RED);
    cout << bold_on << "KKN17" << bold_off << " /\n ";
    set_console_color(BLUE);
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    set_console_color(WHITE_OFF);
#elif defined(__APPLE__) || defined(__linux) || defined(__LINUX__) || defined(__gnu_linux__)
    size_shell_MacOS("85", "25");
    cout << color(WHITE, "", "                               )___( \n");
    cout << color(WHITE, "", "                        _______/__/_                   +----------------------------+\n");
    cout << color(WHITE, "", "                __     /===========|   ___             |") << color(MAGENTA, BOLD, ">") << color(YELLOW, BOLD, " By:FRANCESCO PIO NOCERINO") << color(WHITE, "", " |\n");
    cout << color(WHITE, "", "____       _   [\\\\]___/____________|__[///]    __      +----------------------------+\n");
    cout << color(WHITE, "", "\\   \\_____[\\]__/___________________________\\__[//]____\n");
    cout << color(WHITE, "", " \\") << color(GREEN, BOLD, "BATTAGLIA NAVALE") << color(WHITE, "", "                                    |\n");
    cout << color(WHITE, "", "  \\                                            ") << color(RED, BOLD, "KKN17") << color(WHITE, "", " /\n");
    cout << color(BLUE, "", "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
#endif
}

void banner_pc()
{
#ifdef _WIN32
    set_console_color(WHITE);
    cout << "                __/___\n";
    cout << "          _____/______|\n";
    cout << " _______/_____\\_______\\_____\n";
    cout << "\\\t";
    set_console_color(YELLOW);
    cout << bold_on << "WIN PC" << bold_off;
    set_console_color(MAGENTA);
    cout << " < < <";
    set_console_color(WHITE);
    cout << "\t    |\n";
    set_console_color(BLUE);
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    set_console_color(WHITE_OFF);
#elif defined(__APPLE__) || defined(__linux) || defined(__LINUX__) || defined(__gnu_linux__)
    cout << color(WHITE, "", "                __/___\n");
    cout << color(WHITE, "", "          _____/______|\n");
    cout << color(WHITE, "", " _______/_____\\_______\\_____\n");
    cout << color(WHITE, "", "\\ \t") << color(YELLOW, BOLD, "WIN PC ") << color(MAGENTA, "", " < < <") << color(WHITE, "", "\t    |\n");
    cout << color(BLUE, "", "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
#endif
}

void banner_umano()
{
#ifdef _WIN32
    set_console_color(WHITE);
    cout << "                __/___\n";
    cout << "          _____/______|\n";
    cout << " _______/_____\\_______\\_____\n";
    cout << "\\\t";
    set_console_color(YELLOW);
    cout << bold_on << "WIN UMANO" << bold_off;
    set_console_color(MAGENTA);
    cout << " < < <";
    set_console_color(WHITE);
    cout << "\t    |\n";
    set_console_color(BLUE);
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    set_console_color(WHITE_OFF);
#elif defined(__APPLE__) || defined(__linux) || defined(__LINUX__) || defined(__gnu_linux__)
    cout << color(WHITE, "", "                __/___\n");
    cout << color(WHITE, "", "          _____/______|\n");
    cout << color(WHITE, "", " _______/_____\\_______\\_____\n");
    cout << color(WHITE, "", "\\ \t") << color(YELLOW, BOLD, "WIN UMANO ") << color(MAGENTA, "", " < < <") << color(WHITE, "", "    |\n");
    cout << color(BLUE, "", "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
#endif
}

#endif /* DCBF1E02_B005_4B3E_99EC_F94997673209 */

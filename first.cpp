/* /author Allen Walker
 * /version 1.0
 * /date 2022/02/08
 */
#include <iostream>
#include "Translator.h"
#include <windows.h>
#include <conio.h>
using   std::cout;
using   std::cin;
using   std::endl;

int main() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
Translate a;
    SetConsoleTextAttribute(hConsole,11);
    cout<<"\t ============= MORSE CODE =============\n\n";
    cout<<"\t _________________________________________\n";
    cout<<"\t|\\________________________________________\\\n";
    cout<<"\t| |A .-    |  B -... |  C -.-. |  D -..  | |\n";
    cout<<"\t| |E .     |  F ..-. |  G --.  |  H .... | |\n";
    cout<<"\t| |I ..    |  J .--- |  K -.-  |  L .-.. | |\n";
    cout<<"\t| |M --    |  N -.   |  O ---  |  P .--. | |\n";
    cout<<"\t| |Q --.-  |  R .-.  |  S ...  |  T -    | |\n";
    cout<<"\t| |U ..-   |  V ...- |  W .--  |  X -..- | |\n";
    cout<<"\t| |Y -.--  |  Z --.. |         |         | |\n";
    cout<<"\t\\_|______________________________________\\_|\n";

    SetConsoleTextAttribute(hConsole, 9);
    cout << "\n\nType your text: ";

    SetConsoleTextAttribute(hConsole, 11);
    cin >> a;

    SetConsoleTextAttribute(hConsole, 9);
    cout << "\nTranslated text: ";

    SetConsoleTextAttribute(hConsole, 11);
    cout << a << endl;

    getch();

}
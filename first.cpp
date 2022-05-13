/* /author Allen Walker
 * /version 1.0
 * /date 2022/02/08
 */
#include <iostream>
#include "Translator.h"
using   std::cout;
using   std::cin;
using   std::endl;

int main() {

Translate a;

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


    cout << "\n\nType your text: ";

    cin >> a;

    cout << "\nTranslated text: ";
    
    cout << a << endl;

}
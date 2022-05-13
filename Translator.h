//
// Created by Allen Walker on 2/20/2022.
//

#ifndef TEXTENCRIPTION_TRANSLATOR_H
#define TEXTENCRIPTION_TRANSLATOR_H
#include <iostream>
#include <vector>

using std::ostream;
using std::istream;
using std::string;
using std::vector;

class Translate{
public:
    Translate();
    friend ostream &operator<<(ostream&,const Translate &);
    friend istream &operator>>(istream &, Translate &);


    string MorsetoText(string character)const;

    char morsealphabet( const string &r)const;

    string text2Morse(const string &language)const;
    void ImprimeTradMorse()const;
    static bool  textid(vector<string> );
    static bool  textid(string);

private:
    const char alphabet[27]{'0','A','B','C','D','E',
                            'F','G','H','I','J','K',
                            'L','M','N', 'O','P','Q','R',
                            'S','T','U','V','W','X','Y','Z'};

    const string morse[27]{"0",".-","-...","-.-.","-..",".","..-.",
                           "--.","....","..",".---","-.-",".-..","--",
                           "-.","---",".--.","--.-",".-.","...","-",
                           "..-","...-",".--","-..-","-.--","--.."};

   vector <string> storedText;
};
#endif //TEXTENCRIPTION_TRANSLATOR_H

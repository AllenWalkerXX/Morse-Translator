/*
 * \author Allen Walker
 * \date 2022/02/20
 * \version 1.0.0
 */

#include "Translator.h"
#include <iostream>
#include <vector>

using   std::cout;
using   std::istream;
using   std::ostream;
using   std::string;
using   std::vector;
using   std::isalpha;



Translate::Translate():alphabet{{'0','A','B','C','D','E','F','G','H','I','J','K','L','M','N', 'O','P','Q','R','S','T','U','V','W','X','Y','Z'}}{}
/* Esta función se encarga de convertir la cadena codificada en Morse a texto
 */
string Translate::MorsetoText(string character)const{
    char m[5]{}; //Almacena las letras codificadas en morse
    string chain{};//Almacena la cadena convertida a texto
    for (size_t i{}, j{}; i <= character.size(); ++i) {
        if (character[i]!=' '&& character.size()>i){
            m[j] = character[i];
            j++;
            /*Mientras va iterando el ciclo a medida que se cumplan las condiciones establecidas
             * se va asignando a m los caracteres correspondientes, una vez esta condicion no se cumpla,
             * indica que ya se completo una letra o terminó la cadena de texto*/
        }
        else    {
            /*Una vez la condicion de arriba no se cumpla, se llama a la función šmorsealphabet, con m
             * como parametro,  para agregarle a chain la letra correspondiente al codigo morse enviado*/
            j = 0;
            chain+= morsealphabet(m);
            m[0] = m[1] = m[2] = m[3] = m[4]='\0';
        }

    }
    return chain;
}

/*Esta funcion imprime el texto codificado en morse*/
void Translate::ImprimeTradMorse()const{
    for (int i = 0; i < storedText.size(); ++i) {

        cout << MorsetoText(storedText[i]);
    }

}
/* Tiene como parametro una referencia a una cadena, esta va comparando la entrada con cada
 * una de las letras codificadas en morse y devuelve su equivalente en texto, en caso de que
 * se haga una entrada no válida, retorna š?š*/
char Translate::morsealphabet( const string &r)const {
    for (int i {}; i < 27; ++i) {
        if (r==morse[i]){

            return alphabet[i];
        }
    }
    return '?';

}
/* Tiene como parámetro una referencia a una cadena, se encarga de convertir cada uno de los caracteres de
 * la cadena en texto a su respectiva codificación en morse haciendo una seleccion de casos*/
string Translate::text2Morse(const string &language)const {
    char val=language[0];
        switch (val) {
            case 'A':
                return ".-";

            case 'B':
                return "-...";

            case 'C':
                return "-.-.";

            case 'D':
                return "-..";

            case 'E':
                return ".";

            case 'F':
                return "..-.";

            case 'G':
                return "--.";

            case 'H':
                return "....";

            case 'I':
                return "..";

            case 'J':
                return ".---";

            case 'K':
                return "-.-";

            case 'L':
                return ".-..";

            case 'M':
                return "--";

            case 'N':
                return "-.";

            case 'O':
                return "---";

            case 'P':
                return ".--.";

            case 'Q':
                return "--.-";

            case 'R':
                return ".-.";

            case 'S':
                return "...";

            case 'T':
                return "-";

            case 'U':
                return "..-";

            case 'V':
                return "...-";

            case 'W':
                return ".--";

            case 'X':
                return "-..-";

            case 'Y':
                return "-.--";

            case 'Z':
                return "--..";
            default:
                return "";
    }
}
/*Esta funcion (sobrecargada) se encarga de identificar si el valor introducido está en texto o codificado en morse*/
bool  Translate::textid(vector<string> vect) {
    size_t contT{}, contM{}; //Contadores
    string textstring;
    for (size_t i{}; i <vect.size() ; ++i) {
        textstring=vect[i];
        for (size_t j{}; j <textstring.size() ; ++j) {

            if(isalpha(textstring[j])!=0){
                contT++;
                //Si el caracter a evaluar es una letra, entonces contT se incrementa en 1
            }
            else if (textstring[j]=='.'||textstring[j]=='-') {
                contM++;
                //De lo contrario, si es un "." o una "," contM aumenta en 1
            }
        }
    }
    if (contT>contM)return true;
// Si contT>contM retorna true, indicando que la cadena introducida es texto, en caso contrario, retorna false
    return false;
}
bool  Translate::textid(string vect) {
    size_t contT{}, contM{};
    string textstring;
    for (size_t i{}; i <vect.size() ; ++i) {
        textstring=vect[i];
        for (size_t j{}; j <textstring.size() ; ++j) {

            if(isalpha(textstring[j])!=0){
                contT++;
            }
            else if (textstring[j]=='.'||textstring[j]=='-') {
                contM++;
            }
        }
    }
    if (contT>contM)return true;

    return false;
}
ostream &operator<<(ostream &output,const Translate &letter){

    if (Translate::textid(letter.storedText)){

        for (size_t i{}; i < letter.storedText.size(); ++i) {

            output << letter.text2Morse(letter.storedText[i]) << " ";
        }
    }

    else {

            letter.ImprimeTradMorse();
        }


    return output;
}

istream &operator>>(istream &input, Translate &letter){
    string chain;
    getline(input,chain);
    if (letter.textid(chain)) {
        for (size_t i{}; i < chain.size(); i++) {
            letter.storedText.push_back(chain.substr(i, 1));
        }
    } else{
        char m[5]{};
        string chain2{};
        for (size_t i{}, j{}; i <= chain.size(); ++i) {
            if (chain[i]!=' '&& chain.size()>i){
                m[j] = chain[i];
                j++;
            }
            else    {
                j = 0;
                letter.storedText.push_back(m);
                m[0] = m[1] = m[2] = m[3] = m[4]='\0';
            }

        }
    }
    return input;

}
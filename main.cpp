#include <locale.h>
//#include "Vector.h"
#include "Sentence.h"

int main()
{
    setlocale(LC_ALL, ".1251"); //подключаем локаль с поддержкой русского языка для ввода/вывода
    //callMenuToVectorEdit(0);
    callMenuToSentenceEdit(0);
    return 0;
}
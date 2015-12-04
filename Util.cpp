//
// Created by Dislike on 01.12.2015.
//

#include <ctype.h>
#include <windows.h>
#include "Util.h"

char *scanNewWord(int printMessage) {
    const size_t CHAR_SIZE = sizeof(char);

    char *word = (char *) malloc(CHAR_SIZE * 11);
    int count = 0;
    int i = 0;
    char c = '1';
    int ok = false;
    do {
        fflush(stdin);
        if(printMessage)
            printf("Введите новое слово -> ");
        while (!isspace((c = getchar()))) {
            word[count++] = c;
            i++;
            if (i == 10) {
                word = (char *) realloc(word, ((count + 10) * CHAR_SIZE));
                if (word == NULL)
                    failMemoryAllocate();
                i = 0;
            }
        }
        word[count] = '\0';
        if(!strlen(word)) {
            if(!printMessage)
                printf("-> ");
            continue;
        }
        ok = true;
    } while (!ok);

    return word;
}

void listenAnswer()
{
    printf("Нажмите любую клавишу для продолжения..."); //выводим сообщение
    fflush(stdin);
    getch();//вызов функци, ожидающей любое нажатие
}

int scanRequaredIndex()
{
    printf("Введи нужный индекc: -> ");
    int i = scanIntValue();
    return  i;
}

void failMemoryAllocate()
{
    printf("Не удалось выделить память, завершение программы!");
    exit(-1);
}

void setDefaultColorText() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, (WORD) ((0 << 4) | 15));
}

void setYellowColorText() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, (WORD) ((0 << 4) | 14));
}

int scanIntValue() {
    int value = -1;
    int ok;
    char* buffer = NULL;
    while(true)
    {
        buffer = scanNewWord(false);
        ok = true;
        if(buffer != NULL)
        {
            int len = strlen(buffer);
            for(int i = 0; i < len; i++) {
                char c = *(buffer + i);
                if (!(isdigit(c) || (!i && (c == '+' || c == '-')))) {
                    printf("Ошибка при считывании целого числа.\n");
                    ok = false;
                    break;
                }
            }
            if(ok)
                break;
            free(buffer);
        }
    }
    value = atoi(buffer);
    free(buffer);
    return value;
}

void printLine() {
    printf("----------------------------------------------------\n");
}

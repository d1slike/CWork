//
// Created by Dislike on 29.11.2015.
//

#include <ctype.h>
#include "Sentence.h"

#define SENTENCE_MENU   "1. Инициализировать предложение.\n"\
                        "2. Очистить предложение.\n"\
                        "3. Предложение пустое?\n"\
                        "4. Установить указатель на первое слово.\n"\
                        "5. Указатель указывает на последнее слово?\n"\
                        "6. Передвинуть указатель на следующее слово.\n"\
                        "7. Напечатать слово за указателем.\n"\
                        "8. Удалить слово за указателем.\n"\
                        "9. Взять слово за указателем.\n"\
                        "10. Изменить слово за указателем.\n"\
                        "11. Добавить новое слово за указателем.\n"\
                        "12. Вернуться в меню для работы с текстом.\n"\
                        "13. Завершить программу.\n\n"



char* scanNewWord()
{
    fflush(stdin);

    const size_t CHAR_SIZE = sizeof(char);

    char *word = (char *) malloc(CHAR_SIZE * 10);
    int count = 0;
    int i = 0;
    char c = '1';
    printf("Введите новое слово -> ");
    while (!isspace((c = getchar()))) {
        word[count++] = c;
        i++;
        if (i == 10) {
            word = (char *) realloc(word, ((count + 10) * CHAR_SIZE));
            if (word == NULL)
                fail();
            i = 0;
        }
    }

    return word;
}

Sentence *callMenuToSentenceEdit(Sentence *s) {
    Sentence* sentence = s;
    int cmd;

    while(true)
    {
        system("cls");//очищаем консоль от предыдущий записей
        printf(SENTENCE_MENU);//печатаем все пункты меню
        printSentence(sentence);
        printf("\n->"); //печатаем стрелку
        scanf("%d", &cmd); //считываем команду с консоли

        if(cmd == 12)
            return sentence;
        if(cmd == 13)
            exit(0);

        switch (cmd)
        {
            case 1:
                if(sentence == NULL)
                    sentence = initSentence();
                else
                    printf("Предложение уже инициализировано\n");
                break;
            case 2:
                clearSList(sentence->list);
                break;
            case 3:
                printf(SListIsEmpty(sentence->list) ? "Предложение пустое.\n" : "Предложение НЕ пустое.\n");
                break;
            case 4:
                setCurrentToFirst(sentence->list);
                break;
            case 5:
                printf(currentIsOnTail(sentence->list) ? "Текущий указатель указывает на последне слово в предложении.\n"
                                                : "Текущий указаетель НЕ указывает на последнее слово в предложении\n");
                break;
            case 6:
                moveCurrentToNextInSList(sentence->list);
                break;
            case 7:
                printf("%s", (char*)getNextElementInSList(sentence->list)->data);
                break;
            case 8: {
                SingleNode *node = removeNextElementInSList(sentence->list);
                free(node);
            }
                break;
            case 9:
            {
                SingleNode *node = removeNextElementInSList(sentence->list);
                printf("Взятое слово - %s", (char*)node->data);
                free(node);
            }
                break;
            case 10: {
                free(getNextElementInSList(sentence->list)->data);
                void* newWord = scanNewWord();
                changeNextElementInSList(sentence->list, &newWord);
            }
                break;
            case 11:
            {
                void* newWord = scanNewWord();
                addAfterCurrentInSList(sentence->list, &newWord);
            }
                break;
            default:
                printf("Неизвестная команда.\n");
                break;
        }
    }

}

Sentence *initSentence() {
    Sentence* sentence = (Sentence*) malloc(sizeof(sentence));
    if(!sentence)
        fail();
    SingleLinkedList* list = initSList();
    sentence->list = list;

    return sentence;
}

void terminateSentence(Sentence *sentence) {
    clearSList(sentence->list);
    free(sentence->list);
}

void printSentence(Sentence *sentence) {
    if(sentence == NULL)
    {
        printf("Предложение не инициализировано.\n");
        return;
    }

    if(SListIsEmpty(sentence->list))
    {
        printf("Предложение пустое.\n");
        return;
    }

    SingleNode* cur = sentence->list->first;
    while(cur != NULL)
    {
        if(cur == sentence->list->current)
            printf("->%s<- ", (char*)cur->data);
        else
            printf("%s ", (char*)cur->data);
        cur = cur->next;
    }

    printf("\n");
}

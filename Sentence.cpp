//
// Created by Dislike on 29.11.2015.
//

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




Sentence *callMenuToSentenceEdit(Sentence *s) {
    Sentence* sentence = s;
    int cmd;

    while(true)
    {
        system("cls");//очищаем консоль от предыдущий записей
        printf(SENTENCE_MENU);//печатаем все пункты меню
        printSentence(sentence, true);
        printf("\n\n->"); //печатаем стрелку
        //scanf("%d", &cmd); //считываем команду с консоли
        cmd = scanIntValue();


        if(cmd == 12)
            return sentence;
        if(cmd == 13)
            exit(0);

        if (cmd != 1 && sentence == NULL) {
            printf("Операция не допустима!\n"); //выводим сообщение о недопустимости операции
            listenAnswer();//ожидаем нажатие любой клавиши от пользователя
            continue; //продолжаем итерации цикла
        }

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
                if (SListIsEmpty(sentence->list))
                    printf("Предложение пустое. Текущий указатель не установлен.\n");
                else
                    printf(currentIsOnTail(sentence->list)
                           ? "Текущий указатель указывает на последне слово в предложении.\n"
                           : "Текущий указаетель НЕ указывает на последнее слово в предложении\n");
                break;
            case 6:
                moveCurrentToNextInSList(sentence->list);
                break;
            case 7: {
                if(SListIsEmpty(sentence->list))
                {
                    printf("Предложение пустое\n");
                    break;
                }
                char *word = (char *) getNextElementInSList(sentence->list)->data;
                if (word != NULL)
                    printf("%s\n", word);
            }
                break;
            case 8: {
                SingleNode *node = removeNextElementInSList(sentence->list);
                if (node != NULL)
                    free(node);
            }
                break;
            case 9:
            {
                SingleNode *node = removeNextElementInSList(sentence->list);
                if (node != NULL) {

                    printf("Взятое слово - %s\n", (char *) node->data);
                    free(node);
                }
            }
                break;
            case 10: {
                SingleNode *node = getNextElementInSList(sentence->list);
                if (node != NULL) {
                    if (node->data != NULL)
                        free(node->data);
                    void *newWord = scanNewWord(true);
                    changeNextElementInSList(sentence->list, &newWord);
                }
            }
                break;
            case 11:
            {
                void* newWord = scanNewWord(true);
                addAfterCurrentInSList(sentence->list, &newWord);
            }
                break;
            default:
                printf("Неизвестная команда.\n");
                break;
        }

        listenAnswer();
    }

}

Sentence *initSentence() {
    Sentence* sentence = (Sentence*) malloc(sizeof(sentence));
    if(!sentence)
        failMemoryAllocate();
    SingleLinkedList* list = initSList();
    sentence->list = list;

    return sentence;
}

void terminateSentence(Sentence *sentence) {
    terminateSLIst(sentence->list);
    free(sentence);
}

void printSentence(Sentence *sentence, int showCurrent) {
    if(sentence == NULL)
    {
        printf("Предложение не инициализировано.");
        return;
    }

    if(SListIsEmpty(sentence->list))
    {
        printf("Пустое предложение.");
        return;
    }

    SingleNode* cur = sentence->list->first;
    while(cur != NULL)
    {
        if (cur == sentence->list->current && showCurrent) {
            setYellowColorText();
            printf("%s ", (char *) cur->data);
            setDefaultColorText();
        }
        else
            printf("%s ", (char*)cur->data);
        cur = cur->next;
    }
}

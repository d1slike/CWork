//
// Created by Dislike on 29.11.2015.
//

#include "Text.h"
#include "Sentence.h"

#define TEXT_MENU    "1. Начать работу с текстом.\n"\
                "2. Сделать текст пустым.\n"\
                "3. Текст пуст?.\n"\
                "4. Установить указатель на первое предложение в тексте.\n"\
                "5. Установить указатель на последнее предложение в тексте.\n"\
                "6. Текущий указатель указывает на первый элемент текста?\n"\
                "7. Текущий указатель указывает на последний элемент текста?\n"\
                "8. Передвинуть текущий указатель вперед.\n"\
                "9. Передвинуть текущий указатель назад.\n"\
                "10. Вывести предложение до текущего указателя.\n"\
                "11. Вывести предложение после текущего указателя.\n"\
                "12. Удалить предложение до указателя.\n"\
                "13. Удалить предложение после указателя.\n"\
                "14. Взять предложение до указателя.\n"\
                "15. Взять предложение после указателя.\n"\
                "16. Изменить предложение до указателя.\n"\
                "17. Изменить предложение после указателя.\n"\
                "18. Вставить новое предложение до указателя.\n"\
                "19. Вставить новое предложение после указателя.\n"\
                "20. Вернуться в меню работы с вектором.\n"\
                "21. Завершение программы.\n\n"

Text *callMenuToTextEdit(Text *text) {
    Text *t = text;
    int cmd;
    while (true) {
        system("cls");//очищаем консоль от предыдущий записей
        printf(TEXT_MENU);//печатаем все пункты меню
        printText(t);
        printf("\n->"); //печатаем стрелку
        scanf("%d", &cmd); //считываем команду с консоли

        if (cmd == 20)
            return t;
        if (cmd == 21)
            exit(0);

        if (cmd != 1 && t == NULL) {
            printf("Операция не допустима!\n"); //выводим сообщение о недопустимости операции
            listenAnswer();//ожидаем нажатие любой клавиши от пользователя
            continue; //продолжаем итерации цикла
        }

        switch (cmd) {
            case 1:
                if (t != NULL)
                    printf("Вектор уже инициализирован\n");
                else
                    t = initText();
                break;
            case 2:
                clearText(text);
                break;
            case 3:
                printf(DListIsEmpty(t->list) ? "Тект пуст.\n" : "Тект НЕ пуст.\n");
                break;
            case 4:
                setCurrentToHead(t->list);
                break;
            case 5:
                setCurrentToTail(t->list);
                break;
            case 6:
                printf(currentIsOnHead(t->list) ? "Текущий указатель указывает на первый элемент текста.\n"
                                                : "Текущий указаетель НЕ указывает на первый элемент текста.\n");
                break;
            case 7:
                printf(currentIsOnTail(t->list) ? "Текущий указатель указывает последний элемент текста\n"
                                                : "Текущий указаетель НЕ указывает последний элемент текста\n");
                break;
            case 8:
                moveCurrentToNextInDList(t->list);
                break;
            case 9:
                moveCurrentToPrevInDList(t->list);
                break;
            case 10: {
                Sentence *sentence = (Sentence *) getNextElementInDList(t->list);
                printSentence(sentence);
            }
                break;
            case 11: {
                Sentence *sentence = (Sentence *) getPrevElementInDList(t->list);
                printSentence(sentence);
            }
                break;
            case 12: {
                Sentence *sentence = (Sentence *) removePrevElementInDList(t->list);
                if (sentence != NULL) {
                    terminateSentence(sentence);
                    free(sentence);
                }
            }
                break;
            case 13: {
                Sentence *sentence = (Sentence *) removePrevElementInDList(t->list);
                if (sentence != NULL) {
                    terminateSentence(sentence);
                    free(sentence);
                }
            }

                break;
            case 14: {
                Sentence *sentence = (Sentence *) removePrevElementInDList(t->list);
                if (sentence != NULL) {
                    printf("Взятое предложение - ");
                    printSentence(sentence);
                    terminateSentence(sentence);
                    free(sentence);
                }
            }
                break;
            case 15: {
                Sentence *sentence = (Sentence *) removeNextElementInDLIst(t->list);
                if (sentence != NULL) {
                    printf("Взятое предложение - ");
                    printSentence(sentence);
                    terminateSentence(sentence);
                    free(sentence);
                }
            }
                break;
            case 16: {
                Sentence *sentence = (Sentence *) getPrevElementInDList(t->list);
                callMenuToSentenceEdit(sentence);
            }
                break;
            case 17: {
                Sentence *sentence = (Sentence *) getNextElementInDList(t->list);
                callMenuToSentenceEdit(sentence);
            }
                break;
            case 18: {
                void *sentence = callMenuToSentenceEdit(NULL);
                if (sentence != NULL)
                    addBeforeCurrentInDList(t->list, &sentence);
            }
                break;
            case 19: {
                void *sentence = callMenuToSentenceEdit(NULL);
                if (sentence != NULL)
                    addAfterCurrentInDList(t->list, &sentence);
                break;
            }
            default:
                printf("Неизвестная команда.\n");
                break;
        }
    }
}

void terminateText(Text *text) {
    clearText(text);
    //free(text);
}

void printText(Text *text) {
    if(text == NULL)
    {
        printf("Текст не инициализирован\n");
        return;
    }

    if(DListIsEmpty(text->list))
    {
        printf("Текст пуст\n");
        return;
    }

    DoubleNode* cur = text->list->head;
    while(cur != NULL)
    {
        printf("   \t");
        if(cur == text->list->current) {
            printf("->");
            printSentence((Sentence*)cur->data);
            printf("<-");
        }
        else
            printSentence((Sentence *) cur->data);
        printf("\n");
        cur = cur->next;
    }
}

Text *initText() {
    Text* text = (Text*) malloc(sizeof(Text));
    if(!text)
        fail();
    DoubleLinkedList* list = initDList();
    text->list = list;
}

void clearText(Text *text) {
    DoubleNode* cur = text->list->head;
    while(cur != NULL)
    {
        terminateSentence((Sentence*) cur->data);
        cur = cur->next;
    }
    clearDList(text->list);
}


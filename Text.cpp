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

Text *callMenuToTextEdit(Text *tx) {
    Text *text = tx;
    int cmd;
    while (true) {
        system("cls");//очищаем консоль от предыдущий записей
        printf(TEXT_MENU);//печатаем все пункты меню
        printText(text, true);
        printf("\n->"); //печатаем стрелку
        //scanf("%d", &cmd); //считываем команду с консоли
        cmd = scanIntValue();
        if (cmd == 20)
            return text;
        if (cmd == 21)
            exit(0);

        if (cmd != 1 && text == NULL) {
            printf("Операция не допустима!\n"); //выводим сообщение о недопустимости операции
            listenAnswer();//ожидаем нажатие любой клавиши от пользователя
            continue; //продолжаем итерации цикла
        }

        switch (cmd) {
            case 1:
                if (text != NULL)
                    printf("Вектор уже инициализирован\n");
                else
                    text = initText();
                break;
            case 2:
                clearText(text);
                break;
            case 3:
                printf(DListIsEmpty(text->list) ? "Тект пуст.\n" : "Тект НЕ пуст.\n");
                break;
            case 4:
                setCurrentToHead(text->list);
                break;
            case 5:
                setCurrentToTail(text->list);
                break;
            case 6:
                if (DListIsEmpty(text->list))
                    printf("Текст пуст. Текущий указатель не установлен.\n");
                else
                    printf(currentIsOnHead(text->list) ? "Текущий указатель указывает на первый элемент текста.\n"
                                                       : "Текущий указаетель НЕ указывает на первый элемент текста.\n");
                break;
            case 7:
                if (DListIsEmpty(text->list))
                    printf("Текст пуст. Текущий указатель не установлен.\n");
                printf(currentIsOnTail(text->list) ? "Текущий указатель указывает последний элемент текста\n"
                                                   : "Текущий указаетель НЕ указывает последний элемент текста\n");
                break;
            case 8:
                moveCurrentToNextInDList(text->list);
                break;
            case 9:
                moveCurrentToPrevInDList(text->list);
                break;
            case 10: {
                DoubleNode *sentence = getPrevElementInDList(text->list);
                if (sentence != NULL)
                    printSentence((Sentence *) sentence->data, false);
            }
                break;
            case 11: {
                DoubleNode *sentence = getNextElementInDList(text->list);
                if (sentence != NULL)
                    printSentence((Sentence *) sentence->data, false);
            }
                break;
            case 12: {
                DoubleNode *sentence = removePrevElementInDList(text->list);
                if (sentence != NULL) {
                    terminateSentence((Sentence *) sentence->data);
                    free(sentence);
                }
            }
                break;
            case 13: {
                DoubleNode *sentence = removeNextElementInDLIst(text->list);
                if (sentence != NULL) {
                    terminateSentence((Sentence *) sentence->data);
                    free(sentence);
                }
            }

                break;
            case 14: {
                DoubleNode *sentence = removePrevElementInDList(text->list);
                if (sentence != NULL) {
                    printf("Взятое предложение - ");
                    printSentence((Sentence *) sentence->data, false);
                    terminateSentence((Sentence *) sentence->data);
                    free(sentence);
                }
            }
                break;
            case 15: {
                DoubleNode *sentence = removeNextElementInDLIst(text->list);
                if (sentence != NULL) {
                    printf("Взятое предложение - ");
                    printSentence((Sentence *) sentence->data, false);
                    terminateSentence((Sentence *) sentence->data);
                    free(sentence);
                }
            }
                break;
            case 16: {
                DoubleNode *sentence = getPrevElementInDList(text->list);
                if (sentence != NULL)
                    callMenuToSentenceEdit((Sentence *) sentence->data);
            }
                break;
            case 17: {
                DoubleNode *sentence = getNextElementInDList(text->list);
                if (sentence != NULL)
                    callMenuToSentenceEdit((Sentence *) sentence->data);
            }
                break;
            case 18: {
                void *sentence = callMenuToSentenceEdit(NULL);
                if (sentence != NULL)
                    addBeforeCurrentInDList(text->list, &sentence);
            }
                break;
            case 19: {
                void *sentence = callMenuToSentenceEdit(NULL);
                if (sentence != NULL)
                    addAfterCurrentInDList(text->list, &sentence);
                break;
            }
            default:
                printf("Неизвестная команда.\n");
                break;
        }
        listenAnswer();
    }
}


void printText(Text *text, int showCurrent) {
    if(text == NULL)
    {
        printf("Текст не инициализирован.\n");
        return;
    }

    if(DListIsEmpty(text->list))
    {
        printf("Пустой текст.\n");
        return;
    }

    DoubleNode* cur = text->list->head;
    while(cur != NULL)
    {
        if (cur == text->list->current && showCurrent) {
            setYellowColorText();
            printSentence((Sentence *) cur->data, false);
            setDefaultColorText();
        }
        else
            printSentence((Sentence *) cur->data, false);
        cur = cur->next;
        printf("\n");
    }
    if(showCurrent) {
        printLine();
        printf("Обратный порядок\n\n");
        cur = text->list->tail;
        while (cur != NULL) {
            if (cur == text->list->current && showCurrent) {
                setYellowColorText();
                printSentence((Sentence *) cur->data, false);
                setDefaultColorText();
            }
            else
                printSentence((Sentence *) cur->data, false);
            cur = cur->prev;
            printf("\n");
        }
    }
}

Text *initText() {
    Text* text = (Text*) malloc(sizeof(Text));
    if(!text)
        failMemoryAllocate();
    DoubleLinkedList* list = initDList();
    text->list = list;
    return text;
}

void clearText(Text *text) {
    DoubleNode* cur = text->list->head;
    while(cur != NULL)
    {
        terminateSentence((Sentence*) cur->data);
        cur->data = NULL;
        cur = cur->next;
    }
    clearDList(text->list);
}

void terminateText(Text *text) {
    clearText(text);
    terminateDList(text->list);
    free(text);
}

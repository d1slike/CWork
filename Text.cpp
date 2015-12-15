//
// Created by Dislike on 29.11.2015.
//

#include "Text.h"
#include "Sentence.h"

#define TEXT_MENU    "1. ������ ������ � �������.\n"\
                "2. ������� ����� ������.\n"\
                "3. ����� ����?.\n"\
                "4. ���������� ��������� �� ������ ����������� � ������.\n"\
                "5. ���������� ��������� �� ��������� ����������� � ������.\n"\
                "6. ������� ��������� ��������� �� ������ ������� ������?\n"\
                "7. ������� ��������� ��������� �� ��������� ������� ������?\n"\
                "8. ����������� ������� ��������� ������.\n"\
                "9. ����������� ������� ��������� �����.\n"\
                "10. ������� ����������� �� �������� ���������.\n"\
                "11. ������� ����������� ����� �������� ���������.\n"\
                "12. ������� ����������� �� ���������.\n"\
                "13. ������� ����������� ����� ���������.\n"\
                "14. ����� ����������� �� ���������.\n"\
                "15. ����� ����������� ����� ���������.\n"\
                "16. �������� ����������� �� ���������.\n"\
                "17. �������� ����������� ����� ���������.\n"\
                "18. �������� ����� ����������� �� ���������.\n"\
                "19. �������� ����� ����������� ����� ���������.\n"\
                "20. ��������� � ���� ������ � ��������.\n"\
                "21. ���������� ���������.\n\n"

Text *callMenuToTextEdit(Text *tx) {
    Text *text = tx;
    int cmd;
    while (true) {
        system("cls");//������� ������� �� ���������� �������
        printf(TEXT_MENU);//�������� ��� ������ ����
        printText(text, true);
        printf("\n->"); //�������� �������
        //scanf("%d", &cmd); //��������� ������� � �������
        cmd = scanIntValue();
        if (cmd == 20)
            return text;
        if (cmd == 21)
            exit(0);

        if (cmd != 1 && text == NULL) {
            printf("�������� �� ���������!\n"); //������� ��������� � �������������� ��������
            listenAnswer();//������� ������� ����� ������� �� ������������
            continue; //���������� �������� �����
        }

        switch (cmd) {
            case 1:
                if (text != NULL)
                    printf("������ ��� ���������������\n");
                else
                    text = initText();
                break;
            case 2:
                clearText(text);
                break;
            case 3:
                printf(DListIsEmpty(text->list) ? "���� ����.\n" : "���� �� ����.\n");
                break;
            case 4:
                setCurrentToHead(text->list);
                break;
            case 5:
                setCurrentToTail(text->list);
                break;
            case 6:
                if (DListIsEmpty(text->list))
                    printf("����� ����. ������� ��������� �� ����������.\n");
                else
                    printf(currentIsOnHead(text->list) ? "������� ��������� ��������� �� ������ ������� ������.\n"
                                                       : "������� ���������� �� ��������� �� ������ ������� ������.\n");
                break;
            case 7:
                if (DListIsEmpty(text->list))
                    printf("����� ����. ������� ��������� �� ����������.\n");
                printf(currentIsOnTail(text->list) ? "������� ��������� ��������� ��������� ������� ������\n"
                                                   : "������� ���������� �� ��������� ��������� ������� ������\n");
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
                    printf("������ ����������� - ");
                    printSentence((Sentence *) sentence->data, false);
                    terminateSentence((Sentence *) sentence->data);
                    free(sentence);
                }
            }
                break;
            case 15: {
                DoubleNode *sentence = removeNextElementInDLIst(text->list);
                if (sentence != NULL) {
                    printf("������ ����������� - ");
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
                printf("����������� �������.\n");
                break;
        }
        listenAnswer();
    }
}


void printText(Text *text, int showCurrent) {
    if(text == NULL)
    {
        printf("����� �� ���������������.\n");
        return;
    }

    if(DListIsEmpty(text->list))
    {
        printf("������ �����.\n");
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
        printf("�������� �������\n\n");
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

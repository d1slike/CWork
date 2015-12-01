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

Text *callMenuToTextEdit(Text *text) {
    Text *t = text;
    int cmd;
    while (true) {
        system("cls");//������� ������� �� ���������� �������
        printf(TEXT_MENU);//�������� ��� ������ ����
        printText(t);
        printf("\n->"); //�������� �������
        scanf("%d", &cmd); //��������� ������� � �������

        if (cmd == 20)
            return t;
        if (cmd == 21)
            exit(0);

        if (cmd != 1 && t == NULL) {
            printf("�������� �� ���������!\n"); //������� ��������� � �������������� ��������
            listenAnswer();//������� ������� ����� ������� �� ������������
            continue; //���������� �������� �����
        }

        switch (cmd) {
            case 1:
                if (t != NULL)
                    printf("������ ��� ���������������\n");
                else
                    t = initText();
                break;
            case 2:
                clearText(text);
                break;
            case 3:
                printf(DListIsEmpty(t->list) ? "���� ����.\n" : "���� �� ����.\n");
                break;
            case 4:
                setCurrentToHead(t->list);
                break;
            case 5:
                setCurrentToTail(t->list);
                break;
            case 6:
                printf(currentIsOnHead(t->list) ? "������� ��������� ��������� �� ������ ������� ������.\n"
                                                : "������� ���������� �� ��������� �� ������ ������� ������.\n");
                break;
            case 7:
                printf(currentIsOnTail(t->list) ? "������� ��������� ��������� ��������� ������� ������\n"
                                                : "������� ���������� �� ��������� ��������� ������� ������\n");
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
                    printf("������ ����������� - ");
                    printSentence(sentence);
                    terminateSentence(sentence);
                    free(sentence);
                }
            }
                break;
            case 15: {
                Sentence *sentence = (Sentence *) removeNextElementInDLIst(t->list);
                if (sentence != NULL) {
                    printf("������ ����������� - ");
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
                printf("����������� �������.\n");
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
        printf("����� �� ���������������\n");
        return;
    }

    if(DListIsEmpty(text->list))
    {
        printf("����� ����\n");
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


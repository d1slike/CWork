//
// Created by Dislike on 29.11.2015.
//

#include <ctype.h>
#include "Sentence.h"

#define SENTENCE_MENU   "1. ���������������� �����������.\n"\
                        "2. �������� �����������.\n"\
                        "3. ����������� ������?\n"\
                        "4. ���������� ��������� �� ������ �����.\n"\
                        "5. ��������� ��������� �� ��������� �����?\n"\
                        "6. ����������� ��������� �� ��������� �����.\n"\
                        "7. ���������� ����� �� ����������.\n"\
                        "8. ������� ����� �� ����������.\n"\
                        "9. ����� ����� �� ����������.\n"\
                        "10. �������� ����� �� ����������.\n"\
                        "11. �������� ����� ����� �� ����������.\n"\
                        "12. ��������� � ���� ��� ������ � �������.\n"\
                        "13. ��������� ���������.\n\n"



char* scanNewWord()
{
    fflush(stdin);

    const size_t CHAR_SIZE = sizeof(char);

    char *word = (char *) malloc(CHAR_SIZE * 10);
    int count = 0;
    int i = 0;
    char c = '1';
    printf("������� ����� ����� -> ");
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
        system("cls");//������� ������� �� ���������� �������
        printf(SENTENCE_MENU);//�������� ��� ������ ����
        printSentence(sentence);
        printf("\n->"); //�������� �������
        scanf("%d", &cmd); //��������� ������� � �������

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
                    printf("����������� ��� ����������������\n");
                break;
            case 2:
                clearSList(sentence->list);
                break;
            case 3:
                printf(SListIsEmpty(sentence->list) ? "����������� ������.\n" : "����������� �� ������.\n");
                break;
            case 4:
                setCurrentToFirst(sentence->list);
                break;
            case 5:
                printf(currentIsOnTail(sentence->list) ? "������� ��������� ��������� �� �������� ����� � �����������.\n"
                                                : "������� ���������� �� ��������� �� ��������� ����� � �����������\n");
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
                printf("������ ����� - %s", (char*)node->data);
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
                printf("����������� �������.\n");
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
        printf("����������� �� ����������������.\n");
        return;
    }

    if(SListIsEmpty(sentence->list))
    {
        printf("����������� ������.\n");
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

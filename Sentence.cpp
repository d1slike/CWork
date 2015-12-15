//
// Created by Dislike on 29.11.2015.
//

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




Sentence *callMenuToSentenceEdit(Sentence *s) {
    Sentence* sentence = s;
    int cmd;

    while(true)
    {
        system("cls");//������� ������� �� ���������� �������
        printf(SENTENCE_MENU);//�������� ��� ������ ����
        printSentence(sentence, true);
        printf("\n\n->"); //�������� �������
        //scanf("%d", &cmd); //��������� ������� � �������
        cmd = scanIntValue();


        if(cmd == 12)
            return sentence;
        if(cmd == 13)
            exit(0);

        if (cmd != 1 && sentence == NULL) {
            printf("�������� �� ���������!\n"); //������� ��������� � �������������� ��������
            listenAnswer();//������� ������� ����� ������� �� ������������
            continue; //���������� �������� �����
        }

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
                if (SListIsEmpty(sentence->list))
                    printf("����������� ������. ������� ��������� �� ����������.\n");
                else
                    printf(currentIsOnTail(sentence->list)
                           ? "������� ��������� ��������� �� �������� ����� � �����������.\n"
                           : "������� ���������� �� ��������� �� ��������� ����� � �����������\n");
                break;
            case 6:
                moveCurrentToNextInSList(sentence->list);
                break;
            case 7: {
                if(SListIsEmpty(sentence->list))
                {
                    printf("����������� ������\n");
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

                    printf("������ ����� - %s\n", (char *) node->data);
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
                printf("����������� �������.\n");
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
        printf("����������� �� ����������������.");
        return;
    }

    if(SListIsEmpty(sentence->list))
    {
        printf("������ �����������.");
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

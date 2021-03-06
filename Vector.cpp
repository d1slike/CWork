//
// Created by Dislike on 29.11.2015.
//

#include "Vector.h"
#define VECTOR_MENU "1. ������ ������ � ��������.\n"\
                    "2. ������� ������ ������.\n"\
                    "3. ������ ����?\n"\
                    "4. ������� ���������� ��������� � �������.\n"\
                    "5. �������� �������� i-��� ��������.\n"\
                    "6. ������� ������� � ����� �������.\n"\
                    "7. ����� i-�� �������.\n"\
                    "8. �������� �������� i-��� ��������.\n"\
                    "9. �������� ����� ������� � ����� �������.\n"\
                    "10. ��������� ������ � ��������.\n"\
                    "11. ����� �� ���������.\n\n"



int checkIndex(Vector* vector ,int i) {
    int ok = i >= 0 && i < vector->size;
    if(!ok)
        printf("�������� ������!\n");
    return ok;
}


void moveToRequaredIndex(Vector* vector, int i) {
    setCurrentToFirst(vector->source);
    int cur = 0;
    while (cur < i) {
        moveCurrentToNextInSList(vector->source);
        cur++;
    }

}

void callMenuToVectorEdit(Vector *v) {
    Vector* vector = v;
    int cmd;

    while(true)
    {
        system("cls");//������� ������� �� ���������� �������
        printf(VECTOR_MENU);//�������� ��� ������ ����
        printVector(vector);
        printf("\n->"); //�������� �������
        //scanf("%d", &cmd); //��������� ������� � �������
        cmd = scanIntValue();
        if(cmd == 11)
            return;

        if(cmd != 1 && vector == NULL)
        {
            printf("�������� �� ���������!\n"); //������� ��������� � �������������� ��������
            listenAnswer();//������� ������� ����� ������� �� ������������
            continue; //���������� �������� �����
        }

        if(vector != NULL && vectorIsEmpty(vector) && cmd >= 5 && cmd <= 8)
        {
            printf("������ ����\n");
            listenAnswer();
            continue;
        }

        switch (cmd)
        {
            case 1:
                if(vector != NULL)
                    printf("������ ��� ���������������\n");
                else
                    vector = initVector();
                break;
            case 2:
                clearVector(vector);
                break;
            case 3:
                printf(vectorIsEmpty(vector) ? "������ ����.\n" : "������ �� ����.\n");
                break;
            case 4:
                printf("���������� ��������� � ������� �����: %d\n", getVectorSize(vector));
                break;
            case 5:
                printElement(vector, scanRequaredIndex());
                break;
            case 6: {
                if(vectorIsEmpty(vector))
                {
                    printf("������ ����\n");
                    break;
                }
                Text *text = removeLast(vector);
                if(text != NULL)
                    terminateText(text);

            }
                break;
            case 7: {
                Text *text = remove(vector, scanRequaredIndex());
                if (text != NULL) {
                    printf("�������� ������� ��������: \n");
                    printText(text, false);
                    terminateText(text);
                    //free(text);
                }
            }
                break;
            case 8:
                changeElement(vector, scanRequaredIndex());
                break;
            case 9:
                addLast(vector);
                break;
            case 10:
                terminateVector(vector);
                vector = NULL;
                break;
            default:
                //���� �� ����������� �� ���� �� ��������� �����, ������� ��������� � ����������� �������
                printf("����������� �������.\n");
                break;
        }

        listenAnswer();
    }

}

Vector *initVector() {
    Vector* vector = (Vector*) malloc(sizeof(Vector));
    if(vector == NULL)
        failMemoryAllocate();
    vector->source = initSList();
    addAfterCurrentInSList(vector->source, NULL);
    vector->size = 0;

    return vector;
}

void clearVector(Vector *v) {
    if (vectorIsEmpty(v))
        return;
    setCurrentToFirst(v->source);
    while(v->source->current->next != NULL)
    {
        SingleNode* node = removeNextElementInSList(v->source);
        terminateText((Text*) node->data);
        free(node);
    }
    v->source->first->next = NULL;
    v->size = 0;
}

int vectorIsEmpty(Vector *v) {
    return !v->size;
}

int getVectorSize(Vector *v) {
    return v->size;
}

void printElement(Vector *v, int i) {
    if (!checkIndex(v, i))
        return;
    moveToRequaredIndex(v, i);
    SingleNode *node = getNextElementInSList(v->source);
    if (node != NULL)
        printText((Text *) node->data, false);

}

Text *removeLast(Vector *v) {
    return remove(v, v->size - 1);
}

Text *remove(Vector *v, int i) {
    if (!checkIndex(v, i))
        return NULL;
    moveToRequaredIndex(v, i);
    SingleNode *node = removeNextElementInSList(v->source);
    if(node != NULL)
        v->size--;
    return node == NULL ? NULL : (Text *) node->data;
}

void changeElement(Vector *v, int i) {
    if (!checkIndex(v, i))
        return;
    moveToRequaredIndex(v, i);
    SingleNode *text = getNextElementInSList(v->source);
    if (text != NULL)
        callMenuToTextEdit((Text *) text->data);
}

void addLast(Vector *v) {
    if(v->size == MAX_SIZE)
    {
        printf("���������� �������� ������ ��������� � ������\n");
        return;
    }
    void* text = callMenuToTextEdit(NULL);
    if(text != NULL) {
        moveToRequaredIndex(v, v->size);
        addAfterCurrentInSList(v->source,  &text);
        v->size++;
    }
}

void terminateVector(Vector *v) {
    clearVector(v);
    terminateSLIst(v->source);
    free(v);
}

void printVector(Vector *v) {
    if(v == NULL)
    {
        printf("������ �� ���������������.\n");
        return;
    }

    if(vectorIsEmpty(v))
    {
        printf("������ ����.\n");
        return;
    }

    int i = 0;
    SingleNode *node = v->source->first->next;
    while (node != NULL)
    {
        printf("[%d]\n", i);
        printText((Text *) node->data, false);
        node = node->next;
        i++;
        printLine();
    }
    printf("\n");
}


#include "basis/SingleLinkedList.h"

struct Sentence {
    SingleLinkedList* list;
};

Sentence* callMenuToSentenceEdit(Sentence* sentence, int clearScr);

void printSentence(Sentence* sentence);
void terminateSentence(Sentence* sentence);
struct Element{
    int val;
    struct Element* next;
    struct Element* prev;
} *head, *tail;

void addTail(int value);
void addHead(int value);
void addMiddle(int value, int pos);
void delValue(int value);
void printFromBeginning();
void printFromEnd();

void addTail(int value){
    struct Element* newElem = (struct Element*) malloc(sizeof(struct Element));
    newElem->val=value;
    newElem->next=NULL;
    newElem->prev=tail;

    if(head==NULL){
        head = newElem;
        tail = newElem;
    } else{
        tail->next = newElem;
        tail = newElem;
    }
}

void addHead(int value){
    struct Element* newElem = (struct Element*) malloc(sizeof(struct Element));
    newElem->val=value;
    newElem->next=head;
    newElem->prev=NULL;

    if(head==NULL){
        head = newElem;
        tail = newElem;
    } else{
        head->prev = newElem;
        head = newElem;
    }
}

void addMiddle(int value, int pos){
    struct Element* newElem, *temp;
    newElem = (struct Element*)malloc(sizeof(struct Element));
    newElem->val = value;
    newElem->next = NULL;
    temp = head;
    for(int i=2; i<=pos-1; i++){
        temp = temp->next;
        if(temp == NULL)
            break;
    }
    if(temp != NULL){
        newElem->next = temp->next;
        newElem->prev = temp;
        temp->next->prev = newElem;
        temp->next = newElem;
    }

}

void delValue(int value){
    struct Element* iter = head;
    struct Element* next;
    while (iter != NULL) {
        if (iter->val == value) {
            if (head == NULL || iter == NULL)
                return;
            if (head == iter)
                head = iter->next;
            if (iter->next != NULL)
                iter->next->prev = iter->prev;
            if (iter->prev != NULL)
                iter->prev->next = iter->next;
            next = iter->next;
            iter = next;
        }
        else
            iter = iter->next;
    }
}

void printFromBeginning(){
    struct Element* iter = head;
    while(iter!=NULL){
        printf("%d ", iter->val);
        iter = iter->next;
    }
    printf("\n");
}

void printFromEnd(){
    struct Element* iter = tail;
    while(iter!=NULL){
        printf("%d ", iter->val);
        iter = iter->prev;
    }
    printf("\n");
}

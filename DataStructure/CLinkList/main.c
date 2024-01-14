#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <assert.h>

const int INF = 2147483647;

typedef struct Node {
    int value;
    struct Node *next;
} Node;

typedef struct NodeList {
    char name[11];
    struct Node *head;
    struct NodeList *next;
} NodeList;

// function for NodeList
void appendList(NodeList *head, char name[]);
void deleteList(NodeList *head, char name[]);
void nameList(NodeList *head, char name[], char newName[]);
void sort(NodeList *head, char name[]);
void merge(NodeList *head, char targetName[], char dataName[]);
void reverse(NodeList *head, char name[]);
void printall(NodeList *head);
Node* findList(NodeList *head, char name[]);
int NodeListSize(NodeList *head);


// function for Node
void print(NodeList *head, char name[]);
void append(NodeList *head, char name[], int data);
void update(NodeList *head, char name[], int target, int data);
void insert(NodeList *head, char name[], int target, int data);
void delete(NodeList *head, char name[], int target);


// other function
int min( int a, int b );
int errorCheck( int command, char *firstparam, char *secondparam, char *thirdpara );
int intRange( char *s );
int stoi( char *s );
void helper();


int main()
{
    struct NodeList *ListHead = (NodeList *)malloc(sizeof(struct NodeList));
    ListHead -> next = NULL;
    helper();
    char command[1001];
    const char delim[] = " \n  \r";
    while(fgets(command, 1001, stdin) != NULL) {

        char *token = strtok(command, delim);
        if( !token ) continue;
        // appendList name
        if(strcmp(token, "appendList") == 0) {
            // get the parameter and check parameter number
            char *name;
            name = strtok(NULL, delim);
            // check parameter type and range
            if( errorCheck(0, name, NULL, NULL) ) continue;
            appendList(ListHead, name);
        }
        // deleteList name
        else if(strcmp(token, "deleteList") == 0) {
            // get the parameter and check parameter number
            char *name;
            name = strtok(NULL, delim);
            // check parameter type and range
            if( errorCheck(0, name, NULL, NULL) ) continue;
            deleteList(ListHead, name);
        }
        // nameList name newName
        else if(strcmp(token, "nameList") == 0) {
            // get the parameter and check parameter number
            char *name, *newName;
            name = strtok(NULL, delim);
            newName = strtok(NULL, delim);
            // check parameter type and range
            if( errorCheck(1, name, newName, NULL) ) continue;
            nameList(ListHead, name, newName);
        }
        // sort name
        else if(strcmp(token, "sort") == 0) {
            // get the parameter and check parameter number
            char *name;
            name = strtok(NULL, delim);
            // check parameter type and range
            if( errorCheck(0, name, NULL, NULL) ) continue;
            sort(ListHead, name);
        }
        // merge targetName dataName
        else if(strcmp(token, "merge") == 0) {
            // get the parameter and check parameter number
            char *targetName;
            char *dataName;
            targetName = strtok(NULL, delim);
            dataName = strtok(NULL, delim);
            // check parameter type and range
            if( errorCheck(1, targetName, dataName, NULL) ) continue;
            merge(ListHead, targetName, dataName);
        }
        // reverse name
        else if(strcmp(token, "reverse") == 0) {
            // get the parameter and check parameter number
            char *name;
            name = strtok(NULL, delim);
            // check parameter type and range
            if( errorCheck(0, name, NULL, NULL) ) continue;
            reverse(ListHead, name);
        }
        // print name
        else if(strcmp(token, "print") == 0) {
            // get the parameter and check parameter number
            char *name;
            name = strtok(NULL, delim);
            // check parameter type and range
            if( errorCheck(0, name, NULL, NULL) ) continue;
            print(ListHead, name);
        }
        // append name data
        else if(strcmp(token, "append") == 0) {
            // get the parameter and check parameter number
            char *name, *data;
            name = strtok(NULL, delim);
            data = strtok(NULL, delim);
            // check parameter type and range
            if( errorCheck(2, name, data, NULL) ) continue;
            append(ListHead, name, atoi(data));
        }
        // update name target data
        else if(strcmp(token, "update") == 0) {
            // get the parameter and check parameter number
            char *name, *target, *data;
            name = strtok(NULL, delim);
            target = strtok(NULL, delim);
            data = strtok(NULL, delim);
            // check parameter type and range
            if( errorCheck(3, name, target, data) ) continue;
            update(ListHead, name, atoi(target), atoi(data));
        }
        // insert name target data
        else if(strcmp(token, "insert") == 0) {
            // get the parameter and check parameter number
            char *name, *target, *data;
            name = strtok(NULL, delim);
            target = strtok(NULL, delim);
            data = strtok(NULL, delim);
            // check parameter type and range
            if( errorCheck(3, name, target, data) ) continue;
            insert(ListHead, name, atoi(target), atoi(data));
        }
        // delete name target
        else if(strcmp(token, "delete") == 0) {
            // get the parameter and check parameter number
            char *name, *target;
            name = strtok(NULL, delim);
            target = strtok(NULL, delim);
            // check parameter type and range
            if( errorCheck(2, name, target, NULL) ) continue;
            delete(ListHead, name, atoi(target));
        }
        else if(strcmp(token, "printall") == 0) {
            if( errorCheck(4, NULL, NULL, NULL) ) continue;
            printall(ListHead);
        }
        else if(strcmp(token, "NodeListSize") == 0) {
            if( errorCheck(4, NULL, NULL, NULL) ) continue;
            printf("Node List Size is: %d\n", NodeListSize(ListHead));
        }
        else if( strcmp(token, "exit") == 0 ) {
            break;
        }
        else if( strcmp(token, "help") == 0 ) {
            helper();
        }
        else {
            // syntax error
            printf("SyntaxError : The command does not exist\n");
        }
    }
}

// -+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// function for NodeList
// -+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

NodeList* newNodeList(char name[]) {
    NodeList *newNodeList = (NodeList *)malloc(sizeof(NodeList));
    strcpy(newNodeList->name, name);
    newNodeList->head = (Node*)malloc(sizeof(Node));
    newNodeList->head->next = NULL;
    newNodeList->next = NULL;
    return newNodeList;
}

void appendList(NodeList *head, char name[]) {
    // create new NodeList
    for(; head && head->next ; head = head->next );
    head->next = newNodeList(name);

    printf("appendList_SUCC\n");
}

void deleteList(NodeList *head, char name[]){
    // delete the whole NodeList
    for( ; head->next && strcmp(head->next->name, name) ; head = head->next );
    // remember to free the every Node and free the Head and NodeList head
    if( head->next ) {
        NodeList *temp = head->next;
        Node *tempNode = temp->head;
        for(; tempNode ;) {
            Node *deleted = tempNode;
            tempNode = tempNode->next;
            free(deleted);
        }
        head->next = head->next->next;
        free(temp);
        printf("deleteList_SUCC\n");
    }
    else printf("deleteList_FAIL\n");
}

void nameList(NodeList *head, char name[], char newName[]){
    // find the NodeList and change the name
    for( ; head && strcmp(head->name, name) ; head = head->next );
    if( head ) strcpy(head->name, newName), printf("nameList_SUCC\n");
    else printf("nameList_FAIL\n");
}

Node* sortList(Node* head) {
    if( !head || !head->next ) return head;
    Node *slow = head, *fast = head, *last = NULL;
    for( ; fast && fast->next ; ) {
        last = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    Node *R =last->next, *ret = (Node*)malloc(sizeof(Node*)), *cur = ret;
    last->next = NULL;
    head = sortList(head), R = sortList(R);
    for(; head || R ;) {
        int mini = INF;
        if( head ) mini = min(mini, head->value);
        if( R ) mini = min(mini, R->value);
        if( head && mini == head->value ) cur->next = head, head = head->next;
        else cur->next = R, R = R->next;
        cur = cur->next;
    }
    return ret->next;
}

void sort(NodeList *head, char name[]){
    // sort the NodeList
    Node *temp = findList(head, name);
    if( !temp ) {
        printf("sort_FAIL\n");
        return;
    }
    temp->next = sortList(temp->next);
    // the easiest way is do like bubble sort
    // but remember that is pointer, you need to do sth to avoid some nodes would cannot operate
    printf("sort_SUCC\n");
}

void merge(NodeList *head, char target[], char data[]){
    // merge Two NodeLists (target and data)
    Node *first = findList(head, target);
    Node *second = findList(head, data);
    if( !first || !second ) {
        printf("merge_FAIL\n");
        return;
    }
    for( ; first && first->next ; first = first->next );
    first ->next = second->next;
    second->next = NULL;
    // remember free the data NodeLists
    deleteList(head, data);
    printf("merge_SUCC\n");
}

void reverse(NodeList *head, char name[]){
    // reverse the NodeList
    Node *temp = findList(head, name);
    if( !temp ) {
        printf("reverse_FAIL\n");
        return;
    }
    Node *cur = temp->next, *last = NULL;
    // hint : you can try to insert every node into the first place (use another head) recursively
    for( ; cur ; ) {
        Node *next = cur->next;
        cur->next = last;
        last = cur;
        cur = next;
    }
    temp->next = last;
    printf("reverse_SUCC\n");
}

void printall(NodeList *head) {
    // print all data of the NodeList
    for( head = head->next ; head ; head = head->next ) {
        printf("%s: ", head->name);
        for( Node *temp = head->head->next ; temp ; temp = temp->next ) printf("%d ", temp->value);
        printf("\n");
    }
}

int NodeListSize(NodeList *head) {
    int size = 0;
    for( head = head->next ; head ; head = head->next ) size++;
    return size;
}

// -+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// function for Node
// -+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

Node* findList(NodeList *head, char name[]) {
    for( ; head && strcmp(head->name, name) ; head = head->next );
    if( !head ) return printf("Name Error: String variable does not exist\n"), NULL;
    return head->head;
}

void print(NodeList *head, char name[]){
    // print all data of the NodeList
    Node *temp = findList(head, name);
    if( !temp ) {
        printf("print_FAIL\n");
        return;
    }
    for( temp = temp->next ; temp ; temp = temp->next ) printf("%d ", temp->value);
    printf("\n");
}

void append(NodeList *head, char name[], int data){
    // create a new Node and put it on the last place of the NodeList
    Node *temp = findList(head, name);
    if( !temp ) {
        printf("append_FAIL\n");
        return;
    }
    for( ; temp && temp->next ; temp = temp->next );

    temp->next = (Node *)malloc(sizeof(Node));
    temp->next->value = data;
    temp->next->next = NULL;
    
    printf("append_SUCC\n");
}

void update(NodeList *head, char name[], int target, int data){
    // find the target and update the value
    Node *temp = findList(head, name);
    if( !temp ) {
        printf("update_FAIL\n");
        return;
    }
    for( temp->next ; temp && temp->value != target ; temp = temp->next );

    if( temp ) temp->value = data, printf("update_SUCC\n");
    else printf("Value Error: Integer variable does not exist\n");
}

void insert(NodeList *head, char name[], int target, int data){
    // find the target and insert Node before the target
    Node *temp = findList(head, name);
    if( !temp ) {
        printf("insert_FAIL\n");
        return;
    }
    for( ; temp && temp->next && temp->next->value != target ; temp = temp->next );
    if( temp->next ) {
        Node *temp2 = temp->next;
        temp->next = (Node *)malloc(sizeof(Node));
        temp->next->value = data;
        temp->next->next = temp2;
        printf("insert_SUCC\n");
    }
    else printf("Value Error: Integer variable does not exist\n");
}


void delete(NodeList *head, char name[], int target){
    // find the target and delete it
    Node *temp = findList(head, name);
    if( !temp ) {
        printf("delete_FAIL\n");
        return;
    }
    for( ; temp && temp->next && temp->next->value != target ; temp = temp->next );
    // don't forget free every Nodes in this NodeList and the head
    if( temp->next ) {
        Node *temp2 = temp->next;
        temp->next = temp->next->next;
        free(temp2);
        printf("delete_SUCC\n");
    }
    else printf("delete_FAIL\n");
}

// -+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// other function
// -+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

int min( int a, int b ) {
    return a < b ? a : b;
}

int errorCheck( int command, char *firstparam, char *secondparam, char *thirdparam ) {
    // check the parameter type and range
    // return 0 if the parameter is correct
    // return 1 if the parameter is wrong
    switch (command) {
        case 0:
            if( !firstparam ) return printf("ParameterError : The command should have 1 parameters\n"), 1;
          break;
        case 1:
            if( !firstparam || !secondparam ) {
                printf("ParameterError : The command should have 2 parameters\n");
                return 1;
            }
          break;
        case 2:
            if( !firstparam || !secondparam ) {
                printf("ParameterError : The command should have 2 parameters\n");
                return 1;
            }
          break;
        case 3:
            if( !firstparam ) {
                printf("ParameterError : The command should have 3 parameters\n");
                return 1;
            }
          break;
        case 4:
            if( strtok(NULL, " \n  \r") ) {
                printf("ParameterError : The command should have 0 parameters\n");
                return 1;
            }
            return 0;
        default:
            assert(0);
    }
    if( strtok(NULL, " \n  \r") ) {
        printf("ParameterError : The command length exceed\n");
        return 1;
    }
    if( strlen(firstparam) > 10 ) {
        printf("ParameterError : The parameter should not exceed 10 characters\n");
        return 1;
    }
    if( command == 1 && strlen(secondparam) > 10 ) {
        printf("ParameterError : The parameter should not exceed 10 characters\n");
        return 1;
    }
    else if( !(command == 1) && secondparam && intRange(secondparam) ) {
        return 1;
    }
    if( thirdparam && intRange(thirdparam) ) {
        return 1;
    }
    return 0;
}

int stoi( char *s ) {
    long long sum = 0;
    int flag = 0;
    if( *s == '-' ) s++, flag = 1;
    while( *s ) {
        if( isdigit(*s) ) {
            sum = sum * 10 + (*s - '0');
        }
        else return printf("TypeError : The parameter should be integer\n"), 1;
        s++;
    }
    if( flag ) sum = -sum;
    if( sum > INF || sum < -INF-1 ) return printf("RangeError : Out of INT range (-2,147,483,648 to 2,147,483,647)\n"), 1;
    return 0;
}

int intRange( char *s ) {
    // check the parameter is in the range of int
    // return 0 if the parameter is correct
    // return 1 if the parameter is wrong
    if( strlen(s) > 15 ) {
        printf("RangeError : Out of INT range (-2,147,483,648 to 2,147,483,647)\n");
        return 1;
    }
    return stoi(s);
}

void helper() {
    printf("Commands:\n");
    printf("  appendList name\n");
    printf("  deleteList name\n");
    printf("  nameList name newName\n");
    printf("  sort name\n");
    printf("  merge targetName dataName\n");
    printf("  reverse name\n");
    printf("  print name\n");
    printf("  append name data\n");
    printf("  update name target data\n");
    printf("  insert name target data\n");
    printf("  delete name target\n");
    printf("  printall\n");
    printf("  NodeListSize\n");
    printf("  exit\n");
    printf("  help\n");
}
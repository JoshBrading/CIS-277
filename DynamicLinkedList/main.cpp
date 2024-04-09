#include <iostream>

using namespace std;

struct ListNode{
    int id;
    string name;

    ListNode* next;
};

struct List{
    ListNode* head;
};

List* list_create() 
{
    List* list = new List;
    list->head = NULL;
    cout << "List created\n";
    return list;
}

void list_add_node( List* list )
{
    if( list == NULL )
    {
        cout << "List does not exist\n";
        return;
    }

    ListNode* newNode = new ListNode;
    newNode->next = NULL;
    cout << "Enter ID: ";
    cin >> newNode->id;
    cout << "Enter Name: ";
    cin >> newNode->name;

    if( list->head == NULL )
    {
        list->head = newNode;
        return;
    }

    ListNode* curr = list->head;
    ListNode* prev = list->head;

    while( true )
    {
        if( curr == NULL )
        {
            prev->next = newNode;
            break;
        }

        if( prev->id < newNode->id && curr->id > newNode->id )
        {
            prev->next = newNode;
            newNode->next = curr;
            break;
        }

        prev = curr;
        curr = curr->next;
    }
}

void list_delete_node( List* list, int id )
{
    if( list == NULL )
    {
        cout << "List does not exist\n";
        return;
    }
    ListNode* curr = list->head;
    ListNode* prev = list->head;

    if( curr == NULL )
    {
        cout << "List is empty\n";
        return;
    }

    while( curr != NULL )
    {
        if( curr->id == id )
        {
            prev->next = curr->next;
            delete curr;
            cout << "Node with ID: " << id << " deleted\n";
            return;
        }
    }
    cout << "Node with ID: " << id << " not found\n";
}

void list_print( List* list )
{
    if( list == NULL )
    {
        cout << "List does not exist\n";
        return;
    }

    ListNode* tmp = list->head;
    if( tmp == NULL )
    {
        cout << "List is empty\n";
        return;
    }

    while( tmp != NULL )
    {
        cout << "ID: " << tmp->id << ",  NAME: " << tmp->name << "\n";
        tmp = tmp->next;
    }
}

//MARK: main
main()
{
    List* list = NULL;
    int id;
    string name;
    while(true)
    {
        char choice;
        cout << "\nA: Create list\n";
        cout << "B: Add node to list\n";
        cout << "C: Delete not from list\n";
        cout << "D: Modify node in list\n";
        cout << "E: Search for node\n";
        cout << "F: Print List\n";
        cout << "G: Purge list\n\n";
        cin >> choice;
        switch(toupper(choice))
        {
            case 'A':
                list = list_create();
                break;
            case 'B':
                list_add_node( list );
                break;
            case 'C':
                list_delete_node( list, id );
                break;
            case 'F':
                list_print(list);
                break;
        }
    }

}
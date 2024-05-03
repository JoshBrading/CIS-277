#include <iostream>
#include <list>
#include <string>
using namespace std;

struct ListNode
{
    int id;
    string name;
    float gpa;
    
    ListNode* next;
};

struct List
{
    ListNode* head;
};

void list_create( List* &list ) 
{
    if( list == NULL )
    {
        list = new List;
        list->head = NULL;
        cout << "List created\n";
    }
    else
    {
        cout << "List already exists\n";
    }
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
    cout << "Enter GPA: ";
    cin >> newNode->gpa;
    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, newNode->name);

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

        if( curr->id == newNode->id )
        {
            cout << "ID already exists in list\n";
            delete newNode;
            break;
        }

        if( prev->id < newNode->id && curr->id > newNode->id )
        {
            prev->next = newNode;
            newNode->next = curr;
            break;
        }
        
        if( curr->id > newNode->id )
        {
            newNode->next = curr;
            list->head = newNode;
            break;
        }
        
        prev = curr;
        curr = curr->next;
    }
}

void list_print_node( ListNode* node )
{
    if( node == NULL )
        return;
    cout << "ID: " << node->id << "  |  Name: " << node->name << "  |  GPA: " << node->gpa << "\n";
}

void list_modify_node( List* list )
{
    if( list == NULL )
    {
        cout << "List does not exist\n";
        return;
    }

    if( list->head == NULL )
    {
        cout << "List is empty\n";
        return;
    }
    
    int id;
    string name;
    float gpa;
    ListNode* node = list->head;
    
    cout << "Modify ID: ";
    cin >> id;
    while( node != NULL )
    {
        if( node->id == id )
            break;
        node = node->next;
    }

    if( node == NULL )
    {
        cout << "ID does not exist\n";
        return;
    }

    cout << "Enter new GPA: ";
    cin >> gpa;
    cout << "Enter new name: ";
    cin.ignore();
    getline(cin, name);

    cout << "Before\n";
    list_print_node(node);
    node->name = name;
    node->gpa = gpa;
    cout << "After\n";
    list_print_node(node);
}

void list_delete_node( List* list )
{
    if( list == NULL )
    {
        cout << "List does not exist\n";
        return;
    }

    if( list->head == NULL )
    {
        cout << "List is empty\n";
        return;
    }
    
    int id;
    ListNode* curr = list->head;
    ListNode* prev = NULL;
    
    cout << "Delete ID: ";
    cin >> id;

    while( curr != NULL )
    {
        if( curr->id == id )
        {
            if( prev == NULL )
                list->head = curr->next;
            else
                prev->next = curr->next;
            delete curr;
            cout << "ID: " << id << " deleted\n";
            return;
        }
        prev = curr;
        curr = curr->next;
    }
    cout << "ID: " << id << " not found\n";
}

void list_print( List* list )
{
    if( list == NULL )
    {
        cout << "List does not exist\n";
        return;
    }

    ListNode* node = list->head;
    if( node == NULL )
    {
        cout << "List is empty\n";
        return;
    }

    while( node != NULL )
    {
        list_print_node(node);
        node = node->next;
    }
}

void list_find_node( List* list )
{
    if( list == NULL )
    {
        cout << "List does not exist\n";
        return;
    }

    if( list->head == NULL )
    {
        cout << "List is empty\n";
        return;
    }
    
    int id;
    ListNode* curr = list->head;

    cout << "Find ID: ";
    cin >> id;
    
    while( curr != NULL )
    {
        if( curr->id == id )
        {
            list_print_node(curr);
            return;
        }
        curr = curr->next;
    }
    cout << "ID: " << id << " not found\n";
}

void list_purge(List *list)
{
    if( list == NULL )
    {
        cout << "List does not exist\n";
        return;
    }

    if( list->head == NULL )
    {
        cout << "List is empty\n";
        return;
    }

    ListNode* curr = list->head;
    while( curr != NULL )
    {
        ListNode* next = curr->next;
        delete curr;
        curr = next;
    }
    list->head = NULL;
    cout << "List purged\n";
}

int main()
{
    List* list = NULL;
    while(true)
    {
        char choice;
        cout << "\nA: Create list\n";
        cout << "B: Add node to list\n";
        cout << "C: Delete node from list\n";
        cout << "D: Modify node in list\n";
        cout << "E: Search for node\n";
        cout << "F: Print List\n";
        cout << "G: Purge list\n\n";
        cin >> choice;
        switch(toupper(choice))
        {
            case 'A':
                list_create( list );
                break;
            case 'B':
                list_add_node( list );
                break;
            case 'C':
                list_delete_node( list );
                break;
            case 'D':
                list_modify_node( list );
                break;
            case 'E':
                list_find_node( list );
                break;
            case 'F':
                list_print( list );
                break;
            case 'G':
                list_purge( list );
                break;
        }
    }
}
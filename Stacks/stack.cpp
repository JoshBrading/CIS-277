#include <iostream>
#include <string>
using namespace std;

struct Stack
{
    int arr[16];
    int size;
    int top;
};

Stack stack_create()
{
    Stack stack;
    stack.size = 16;
    stack.top = -1;
    return stack;
}

bool stack_is_empty(Stack &stack)
{
    if (stack.top == -1)
        return true;
    return false;
}

bool stack_is_full(Stack &stack)
{
    if (stack.top == stack.size - 1)
        return true;
    return false;
}

int stack_top(Stack &stack)
{
    int top = -1;
    if (stack_is_empty(stack))
        cout << "Stack Underflow" << "\n";
    else
        top = stack.arr[stack.top];
    return top;
}

void stack_push(Stack &stack, int number)
{
    if (stack_is_full(stack))
        cout << "Stack Overflow" << "\n";
    else if (number > 99 || number < 0)
        cout << "Wrong input try again" << "\n";
    else
    {
        stack.top++;
        stack.arr[stack.top] = number;
    }
}
int stack_pop(Stack &stack)
{
    int popped = -1;
    if (stack_is_empty(stack))
        cout << "Stack Underflow" << "\n";
    else
    {
        popped = stack.arr[stack.top];
        stack.top--;
    }
    return popped;
}

void stack_purge(Stack &stack)
{
    stack.top = -1;
}

void stack_print(Stack &stack)
{
    string print;
    if (!stack_is_empty(stack))
    {
        for (int i = 0; i <= stack.top; i++)
        {
            print += to_string(stack.arr[i]);
            if (i < stack.top)
                print += ", ";
        }
    }
    cout << "Current Stack: [" << print << "]\n";
}

int main()
{
    Stack stack = stack_create();
    int push, popped, top;
    while (true)
    {
        char choice;
        cout << "\nA: Push a number to the stack" << "\n";
        cout << "B: Pop a number from the stack" << "\n";
        cout << "C: Output the top of the stack" << "\n";
        cout << "D: Purge the stack" << "\n\n";
        cin >> choice;
        choice = toupper(choice);

        switch (choice)
        {
        case 'A':
            cout << "Enter a number between 0 and 99 to push to the stack:" << "\n";
            cin >> push;
            stack_push(stack, push);
            break;
        case 'B':
            popped = stack_pop(stack);
            if (popped != -1)
                cout << "Popped: " << popped << "\n";
            break;
        case 'C':
            top = stack_top(stack);
            if (top != -1)
                cout << "Top: " << top << "\n";
            break;
        case 'D':
            stack_purge(stack);
            break;
        default:
            cout << "bad input error" << "\n";
        }
        stack_print(stack);
    }
}
/*
Ryan Pepper
November 17th 2023
CIT 245
Linked List
*/

#pragma warning(disable: 4996)
#include<string>
#include<stdlib.h>
#include<time.h>
#include<iostream>

using namespace std;

class node 
{
public:
    string name;
    node *next;
    node *prev;
};

class linkedList
{
public:
    linkedList() : top(NULL) {}

    bool empty() { return top == NULL; }

    node *getTop() { return top; }

    void setTop(node *n) { top = n; }

    void add(string);

    void remove(string);

    void reversePrint();

    int menu();

    ~linkedList();

    friend ostream& operator<<(ostream&, const linkedList&);

private:
    node *top;
};

void linkedList::add(string s) 
{
    node *n = new node();
    n->name = s;
    n->next = NULL;
    n->prev = NULL;

    if (empty())
    {
      top = n;
    } else if (getTop()->name > s) 
    {
        n->next = getTop();
        getTop()->prev = n;
        setTop(n);
    } else 
    {
        node *curr = getTop(), *prev = curr;
        while (curr != NULL)
        {
            if (curr->name > s) break;
            prev = curr;
            curr = curr->next;
        }
        if (curr != NULL) 
        {
            n->next = curr;
            n->prev = prev;
            prev->next = n;
            curr->prev = n;
        } else if (curr == NULL) 
        {
            prev->next = n;
            n->prev = prev;
        }
    }
}

void linkedList::remove(string s) 
{
    bool found = false;
    node *curr = getTop(), *prev = NULL;
    while (curr != NULL)
    {
        if (curr->name == s)
        {
            found = true;
            if (prev == NULL) 
            {
                node *temp = getTop();
                setTop(curr->next);
                if (curr->next != NULL) 
                {
                    curr->next->prev = NULL;
                }
                delete (temp);
            } else
            {
                prev->next = curr->next;
                if (curr->next != NULL) 
                {
                    curr->next->prev = prev;
                }
                delete (curr);
            }
        }
        if (!found) 
        {
            prev = curr;
            curr = curr->next;
        } else 
        {
            curr = NULL;
        }
    }

    if (found) cout << "Deleted " << s << endl;
    else cout << s << " Not Found " << endl;
}

void linkedList::reversePrint() 
{
    node *curr = top;
    while (curr != NULL && curr->next != NULL) 
    {
        curr = curr->next;
    }
    while (curr != NULL) 
    {
        cout << curr->name << endl;
        curr = curr->prev;
    }
}

ostream& operator<<(ostream& os, const linkedList& ll) 
{
    node *n = ll.top;
    if (n == NULL) cout << "List is empty." << endl;
    else
        while (n != NULL) 
        {
            os << n->name << endl;
            n = n->next;
        }
    return os;
}

linkedList::~linkedList()
{
    cout << "~linkedList called." << endl;
    node *curr = getTop(), *del;
    while (curr != NULL) 
    {
        del = curr;
        curr = curr->next;
        delete (del);
    }
}

int linkedList::menu()
{
    int choice = 0;
    while (choice < 1 || choice > 5) 
    {
        cout << "\nEnter your choice" << endl;
        cout << " 1. Add a name." << endl;
        cout << " 2. Delete a name." << endl;
        cout << " 3. Show list." << endl;
        cout << " 4. Show reverse list. " << endl;
        cout << " 5. EXIT " << endl;
        cin >> choice;

        if (choice == 4) 
        {
            reversePrint();
            choice = 0;  
        }
    }
    return choice;
}

int main() 
{
    linkedList l;
    cout << l.empty() << endl;
    int option = 0;
    string s;
    bool go = true;
    while (go) 
    {
        option = l.menu();
        switch (option) 
        {
        case 1: cout << "enter a name: "; cin >> s; l.add(s); break;
        case 2: cout << "enter name to be deleted: "; cin >> s; l.remove(s); break;
        case 3: cout << l; break;
        case 5: cout << "exiting" << endl; go = false; break;
        }
    }
    return 0;
}
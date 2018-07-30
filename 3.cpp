#include <iostream>

using namespace std;

typedef struct List {
	struct List* next;
	int payload; //SomeDataType
};

// Дабавление в конец, параметр - ссылка на певый узел, и ключ
void push(List* &first, int payload)
{
    List *t = new List;
    t->payload = payload;
    t->next = NULL;
    
    if ( !first )   // Список еще не создан
        first = t;
    else
    {
        List *buf = first;
        while ( buf->next && (buf = buf->next) );
        buf->next = t;
    }
}

// Поиск, параметр - ссылка на певый узел, и ключ   
List* &search(List* &first, int payload) 
{
    static List* &t = first;
    t = first;
    static List *buf = first; 
    buf = first;
    if ( !first )
        exit (1);
    if ( first->payload == payload)
        return t;   
    while ( buf && (buf->next) && (buf->next->payload != payload) )
        buf = buf->next;
    if ( buf->next->payload == payload )
        return buf->next;
    else
        exit(1);
}
 
// Передаем указатель  предыдущего звена, на это
void del_node(List* &node) 
{ 
        List* t;
        if ( t = node->next ) 
        {
            node->payload = node->next->payload;
            node->next = node->next->next;
            delete t;
        }
        else // Если этот узел последний
        { 
                delete node;
                node = NULL;
        }
}

void delEvery(List* &first,int n,int max)
{
    bool flag = true;
    
    if(n >= max)
    {
        while(flag)
        {
             del_node(search(first, max));
             max +=5;
             if(n < max)
                flag=false;
                
        }
    }
    else
    {
        cout << "mass is small . Don't find 5 elements in List." <<endl;
    }
    
}
    
void print(List *first)
{
    while ( first )
    {
        cout << first->payload << " ";
        first = first->next;
    }
    cout << endl;
}

int main()
{
    List *first = NULL;
    
    int n = rand()%50;
    
    
    for(int i=0; i < n;i++)
    {
        push(first, i+1);
    }
    cout << "input\t: ";
    print(first);
    delEvery(first,n,5); 
    cout << "output\t: ";
    print(first); 
 
    return 0;
}
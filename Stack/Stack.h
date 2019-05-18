#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

template<class T>
class Stack
{
private:
    struct Node
    {
        Node* next;
        T elem;
        Node():elem(0), next(0){}
    };
    Node* head;
    Node* tail;

public:
    Stack():tail(0), head(0) {}


    ~Stack()
    {
        //std::cout<<"~Stack";
        while(head)
        {
            tail=head->next;
            delete head;
            head=tail;
        }
    }

    void push(T val)
    {
        Node* Temp;
        Temp=new Node;
        Temp->elem=val;
        if(tail==nullptr)
        {
            tail=Temp;
        }
        else
        {
            Temp->next=tail;
            tail=Temp;
        }
    }

    T top()
    {
        if(tail==nullptr)
        {
            std::cout<<"Stack is empty!";
        }
        return tail->elem;
    }

    T top_next()
    {
        if(tail==nullptr)
        {
            std::cout<<"Stack is empty!";
        }
        return tail->next->elem;
    }

    void pop()
    {
        if(tail==nullptr)
        {
            std::cout<<"Stack is empty!";
        }
        Node* delptr=tail;
        tail=tail->next;
        delete delptr;
    }

    void print()
    {
        if(tail==0)
        {
            std::cout<<"Stack is empty!";
        }
        for(Node* ptr=tail; ptr!=nullptr; ptr=ptr->next)
        {
            std::cout<<ptr->elem<<" ";
        }
        std::cout<<std::endl;
    }

    T min_el()
    {
        int min = tail->elem;
        for (Node* i = tail; i != nullptr; i = i->next)
        {
            if (i->elem < min)
            {
                min = i->elem;
            }
        }
        return min;
    }

    template<class UP>
    T accumulate(UP p)
    {
        T sum = 0;
        for (Node* i = tail; i != nullptr; i = i->next)
        {
            if(p(i->elem))
            {
                sum+=i->elem;
            }
        }
        return sum;
    }

    T head_elem()
    {
        Node* i = tail;
        for(; i != nullptr; i = i->next)
        return i->elem;
    }
};
#endif // STACK_H_INCLUDED

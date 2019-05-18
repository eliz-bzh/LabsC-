#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED
#include <cmath>


template<class T>
class NodeQueue
{
private:
    struct Node
    {
        Node():next(0), elem(0){};
        Node* next;
        T elem;
    };
    Node* head;
    Node* tail;
public:
    NodeQueue():head(0), tail(0){}

    ~NodeQueue()
    {
        while(head)
        {
            tail=head->next;
            delete head;
            head=tail;
        }
    }

    void push_back(T val)
    {
        Node* Temp=new Node;
        Temp->elem=val;
        if(head==0)
        {
            head=Temp;
            tail=Temp;
            return;
        }
        tail->next=Temp;
        tail=Temp;
    }

    void delete_()
    {
        if (empty())
        {
            throw std::string("Queue is empty");
        }
        Node* delPtr=head;
        std::cout<<"Element "<< head->elem <<" is deleted from the queue\n";
        head=head->next;
        delete delPtr;
    }

    const T& front()
    {
        if (empty())
        {
            throw std::string("Queue is empty");
        }
        return head->elem;
    }

    void print()
    {
        if (empty())
        {
            throw std::string("Queue is empty");
        }
        for(Node* ptr=head; ptr!=0; ptr=ptr->next)
            std::cout<<ptr->elem<<' ';
        std::cout<<'\n';
    }

    bool empty()
    {
        return head==0;
    }

    T min_el()
    {
        int min = head->elem;
        for (Node* i = head; i != nullptr; i = i->next)
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
        for (Node* i = head; i != nullptr; i = i->next)
        {
            if(p(i->elem))
            {
                sum+=i->elem;
            }
        }
        return sum;
    }
};
#endif // QUEUE_H_INCLUDED

#include "Stack.h"

Stack::Stack() :
    m_c('-'), m_s(NULL), m_ps(NULL)
{
}

Stack::Stack(char c, Stack* ps) :
    m_c(c), m_s(NULL), m_ps(ps)
{
}

Stack::~Stack()
{
    if (NULL != m_s) 
    {
        delete m_s;
        m_s = NULL;
    }
}

void Stack::push(char c)
{
    if (NULL == m_s)
        m_s = new Stack(c, this);
    else
        m_s->push(c);
}

char Stack::pull()
{
    if (NULL == m_s && NULL != m_ps) 
    {
        char c = m_c;
        m_ps->m_s = NULL;
        delete this;
        return c;
    } 
    else if (isEmpty()) 
    {
        return '-';
    }
    else
    {
        m_s->pull();
    }
    
}

char Stack::getI(int i) 
{
    if (i < 0) 
        return m_c;
    else 
    {
        Stack * stack = this->m_s;
        for (int j = 0; j < i; j++) 
            stack = stack->m_s;
        return stack->m_c;
    }
}

bool Stack::isEmpty()
{
    return NULL == m_s && NULL == m_ps;
}

int Stack::size()
{
    int i = 0;
    Stack * s = new Stack();
    while (!isEmpty()) {
        i++;
        s->push(pull());
    }
    while (!s->isEmpty())
        push(s->pull());
    return i;
}

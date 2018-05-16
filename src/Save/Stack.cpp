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
        else if (NULL == m_s && NULL == m_ps) 
        {
            return '-';
        }
        else
        {
            m_s->pull();
        }
    
}

#ifndef _STACK_H_
#define _STACK_H_

#include <string>
#include <sstream>
#include <fstream>
#include "../Board/Point.h"

class Stack
{
private :
    char m_c;
    Stack* m_s;
    Stack* m_ps;
    
public :
    Stack();
    Stack(char c, Stack* ps);
    ~Stack();
    
    void push(char c);
    char pull();
    char getI(int i);
    
    int size();
    bool isEmpty();
};

#endif /* _SAVE_H_ */

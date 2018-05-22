#ifndef _SAVE_H_
#define _SAVE_H_

#include <string>
#include <sstream>
#include <fstream>
#include <ctime>
#include "../Board/Point.h"
#include "Stack.h"

class Save
{
private:
    Stack* m_input;
    int m_nbMove;
    int m_nLevel;
    std::time_t m_timer;
    
public:
	Save(int level);
	~Save();

    void setNbMove(int nbMove);
    int getNbMove();
    void setTimer(std::time_t timer);
    std::time_t getTimer();
    
    void addInput(char c);
    void removeInput();
    int getNbInput();
    char getInput(int i);
	void writeSave();
	void readSave();
	std::string getPath();
};

#endif /* _SAVE_H_ */

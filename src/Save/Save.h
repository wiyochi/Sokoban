#ifndef _SAVE_H_
#define _SAVE_H_

#include <string>
#include <sstream>
#include <fstream>
#include "../Board/Point.h"
#include "Stack.h"

class Save
{
private:
    Stack* m_input;

public:
	Save(int level);
	~Save();

    void addInput(char c);
	void writeSave();
	void readSave();
	std::string getPath();
};

#endif /* _SAVE_H_ */

#ifndef _SAVE_H_
#define _SAVE_H_

#include <string>
#include <sstream>
#include <fstream>
#include "../Board/Point.h"

class Save
{
private:
	Point m_savePawn;
	Point* m_saveBoxes;
	int m_nbBoxes;
	int m_nLevel;

public:
	Save(int level);
	~Save();
	void addPawn(Point p);
	void addBox(Point p);
	void addBoxes(Point* p, int n);
	void writeSave(const char* path);
	void readSave(const char* path, int nLevel);
};

#endif /* _SAVE_H_ */
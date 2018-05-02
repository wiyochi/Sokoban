#ifndef _TARGET_H_
#define _TARGET_H_

#include <iostream>
#include "Case.h"

class Target : public Case
{
public:
	Target();
	~Target();
	virtual void draw();
	
};

#endif
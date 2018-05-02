#ifndef _CASE_H_
#define _CASE_H_

#include <iostream>

class Case
{
public:
	enum type
	{
		empty,
		wall,
		target
	};

	Case();
	~Case();
	void draw();

private:
	Case::type m_type;
	
};

#endif
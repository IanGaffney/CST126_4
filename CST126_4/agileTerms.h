#ifndef AGILE_TERMS_H
#define AGILE_TERMS_H
//#include "stdafx.h"
#include <string>

struct AgileTerm {
	std::string name;
	std::string definition;
	int firstYearUsed;
	AgileTerm * next;
};


class TermList
{
public:
	TermList();
	~TermList();


private:
	AgileTerm * m_head;
	


	
};

#endif /* AGILE_TERMS_H */
#ifndef AGILE_TERMS_H
#define AGILE_TERMS_H
#include "stdafx.h"
#include <string>

struct AgileTerm {
	AgileTerm() { name = ""; definition = ""; firstYearUsed = 0; next = nullptr; };
	AgileTerm(std::string newName, std::string newDefinition, int newYear) { name = newName; definition = newDefinition; firstYearUsed = newYear; next = nullptr; };
	std::string name;
	std::string definition;
	int firstYearUsed;
	void printTerm(const bool & verbose);
	AgileTerm * next;
};

class TermList
{
public:
	TermList() { m_head = nullptr; };
	~TermList();

	void addTerm(const std::string & name, const std::string & definition, const int & firstYearUsed);
	void printTerms();
	void searchForTerm(const std::string & termName);

private:
	AgileTerm * m_head;
};

#endif /* AGILE_TERMS_H */
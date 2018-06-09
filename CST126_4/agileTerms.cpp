#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include "agileTerms.h"

void AgileTerm::printTerm(const bool & verbose)
{
	std::cout.setf(std::ios::right);
	std::cout << std::setw(12) << name;
	std::cout.setf(std::ios::left);
	std::cout << ":  " << definition;
	if (verbose)
	{
		std::cout << "  First used in " << firstYearUsed;
	}
	std::cout << std::endl;
}

TermList::~TermList()
{
	std::cout << "Deleting List" << std::endl;
	while (m_head != nullptr)
	{
		AgileTerm * temp = m_head;
		m_head = temp->next;
		delete temp;
	}

}

// insert a term into the list in alphabetical order
void TermList::addTerm(const std::string & name, const std::string & definition, const int & firstYearUsed)
{
	AgileTerm * newTerm = new AgileTerm(name, definition, firstYearUsed);

	// if this is the first term, then this is our head
	if (m_head == nullptr)
	{
		m_head = newTerm;
	}
	else {
		// if this is lower alphabetically then this is our new head
		// used FlowersHandsOn.cpp as an example
		if (newTerm->name < m_head->name)
		{
			newTerm->next = m_head;
			m_head = newTerm;
		}
		// insert the term alphabetically in the list
		else {
			AgileTerm * temp = m_head;
			AgileTerm * prev = nullptr;

			while (temp != nullptr && (newTerm->name > temp->name)) {
				prev = temp;
				temp = temp->next;
			}

			prev->next = newTerm;
			newTerm->next = temp;
		}
	}
}

// print out all of the terms in the list
void TermList::printTerms()
{
	AgileTerm * temp;
	temp = m_head;
	while (temp != nullptr)
	{
		temp->printTerm(false);
		temp = temp->next;
	}
	std::cout << std::endl;

}

// search for the given term in the list of terms.
void TermList::searchForTerm(const std::string & termName)
{
	bool termFound = false;
	AgileTerm * temp = m_head;
	// loop through the terms and see if they match
	while (!termFound && temp != nullptr)
	{
		if (temp->name == termName)
		{
			termFound = true;
		}
		else {
			temp = temp->next;
		}
	}

	// if we found the term, print it out including the date
	if (termFound)
	{
		temp->printTerm(true);
	}
	// else print out an error
	else
	{
		std::cout << "Term not found" << std::endl;
	}

}
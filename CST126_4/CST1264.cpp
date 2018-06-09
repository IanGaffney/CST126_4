// CST1264.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "agileTerms.h"

int main()
{
	// hard code terms, in non-alphabetical order
	TermList agileTerms;
	agileTerms.addTerm("Timebox", "Maximum amount of time a goal will be worked on, at which point progress will be reviewed.", 1988);
	agileTerms.addTerm("Scrum", "A process framework used to manage product development", 1986);
	agileTerms.addTerm("Velocity", "Time that current iteration work took to complete, used to calculate future time estimates.", 2000);
	agileTerms.addTerm("Refactoring", "Improving an existing programs source code while preserving the programs behavior.", 1984);
	agileTerms.addTerm("Iteration", "A repeating fixed length timebox in which deveopment of a project takes place", 1991);
	agileTerms.addTerm("Epic", "A large, loosely defined idea that encompases multiple items in the backlog.", 2004);
	agileTerms.addTerm("Backlog", "A list of tasks and/or features that are nessisary to complete a project.", 1675);
	agileTerms.addTerm("Points", "A unit that represents the estimated time it will take to complete a task.", 1999);
	agileTerms.addTerm("Facilitation", "The role of conducting a meeting, where the facilitator takes little part in the meeting.", 0);
	agileTerms.addTerm("Personas", "Synthetic biographies of fake users created by the team to aid in facilitating the user experience.", 1999);

	bool end = false;
	// loop until the user says to not continue
	while (!end)
	{
		// print out all of the terms
		agileTerms.printTerms();

		// request user for a term to search for
		std::string searchString;
		std::cout << "What term do you want? ";
		std::cout.flush();

		std::cin >> searchString;

		// search for the term and output definition and first use date.
		agileTerms.searchForTerm(searchString);

		// check to see if the user wants to search for another term or to exit
		char yn{};
		std::cout << "Do you want to continue? ";
		std::cout.flush();

		std::cin >> yn;
		if (yn == 'n')
		{
			end = true;
		}
		else {
			std::cout << std::endl;
		}
	}
	
    return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "university.h"

/////////////////////////////////////////////////////////////////////////////////////////////
// add a college to the list
//	   1. Make sure a college by that name does not exist
//	   2. Add a new college with that name (add-at-front)
//    Error: If the college already exists, print "Error: college \"%s\" already exists.\n" and do nothing

College* addCollege(College *headCollegeList, char collegeName[])
{
	College* head;
	head = headCollegeList;

	if (strcmp(head->name,collegeName) == 0){
		printf("Error: college \"%s\" already exists.\n", collegeName);
		return headCollegeList;
	}
	else
	return head;
}

/////////////////////////////////////////////////////////////////////////////////////////////
// add a dept to the specified college
//   1. Make sure a college by that name exists (so you can add a dept to it).
//   2. If the specifed dept already exists, update the dept's enrollment to the new value
//   3. Otherwise, add the dept to the end of the college's dept list (add-at-end)
//   Error: If the college does not exist, print "Error: college \"%s\" does not exist.\n" and do nothing

void addDept(College *headCollegeList, char collegeName[], char deptName[], int enrollment)
{
	return;
}

/////////////////////////////////////////////////////////////////////////////////////////////
// return the number of colleges in the list
// Iterate through the college list to count the number of colleges, return that count

int count(College *headCollegeList)
{
	return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////
// return the total number of students enrolled in a college
//	1. Make sure a college with that name exists
//	2. for each dept in the college, sum their enrollment
//	3. Print the total enrollment of the college
// 4. If the college does not exist, return -1

int enrollment(College *headCollegeList, char collegeName[])
{
	return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////
// print all the depts for a given college
//	1. Make sure a college with that name exists
//	2. Print the name of that college
//	3. Print all the "deptname: enrollment" pairs for that college
// Error: If the college does not exist, print "Error: college \"%s\" does not exist.\n" and do nothing

void printCollege(College *headCollegeList, char collegeName[])
{
	return;
}

/////////////////////////////////////////////////////////////////////////////////////////////
// print all the colleges
// For each college
//	   a. Print the name of that college
//	   b. Print all the "deptname: enrollment" pairs for that college
// Error: If the college list is empty, print "Error: no colleges.\n" and do nothing

void print(College *headCollegeList)
{
	return;
}

/////////////////////////////////////////////////////////////////////////////////////////////
// add a college (in alphabetical order)
//	1. Make sure a college by that name does not exist
//	2. Add a college with that name (add-in-order)
// Error: if the college already exists, print "Error: college \"%s\" already exists.\n" and do nothing

College *addCollegeOrdered(College *headCollegeList, char collegeName[])
{
	return NULL;
}


/////////////////////////////////////////////////////////////////////////////////////////////
// adds a dept to the specified college in enrollment (desc) order.
// If enrollment is the same, order the depts with the same enrollment by alphabetically.
//	1. Make sure a college by that name exists (so you can add a dept to the college)
//	2. If the dept already exists, update the enrollment
//	3. Otherwise, add the dept to the college (add-in-order)
// Error: If the college does not exists, print "Error: college \"%s\" does not exist.\n" and do nothing

void addDeptOrdered(College *headCollegeList, char collegeName[], char deptName[], int enrollment)
{
	return;
}

/////////////////////////////////////////////////////////////////////////////////////////////
// remove a dept from a college
//	1. Make sure a college with that name exists
//	2. Make sure the dept exists in that college
//	3. Remove the dept from that college
// Error: If the college does not exist, print "Error: college \"%s\" does not exist.\n" and do nothing
// Error: If the dept does not exist, print "Error: dept \"%s\" does not exist in college \"%s\".\n" and do nothing

void removeDept(College *headCollegeList, char collegeName[], char deptName[])
{
	return;
}

/////////////////////////////////////////////////////////////////////////////////////////////
// remove a college
//	1. Make sure a college with that name exists
//	2. Remove that college and all the depts of that college
// Error: If the college does not exist, print "Error: college \"%s\" does not exist.\n" and do nothing

College *removeCollege(College *headCollegeList, char collegeName[])
{
	return NULL;
}

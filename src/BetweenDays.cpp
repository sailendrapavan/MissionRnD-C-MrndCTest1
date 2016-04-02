/*
Q4: Two dates are given in a 8 node single linked list form,where each node
has one digit only, dates 01-31, months 01-12, year 0000-9999.

Find the number of days in between those two dates .[Exclusive]

Ex : Date1:  0->1->0->1->2->0->0->4 .
     Date2 : 0->5->0->1->2->0->0->4 should return 3 .
As there are 3 days between Jan1st 2004 and Jan 5th 2004.

Ex 2 : Date1 : 3->1->1->2->2->0->1->2.
       Date2 : 0->2->0->1->2->0->1->3 should return 1 .
(There is only one day between 31st Dec 2012 and 2nd  Jan 2013 .)

Note : Consecutive Days and Same Days should return 0;
->Return -1 for NULL Inputs .
->Between Days have to be calculated by not including start and end date .
->The SLL will have 8 Nodes in all cases . Month 9 will be represented as 09.

Difficulty : Hard 
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct node{
	int data;
	struct node *next;
};
struct Date
{
	int d, m, y;
};
const int monthDays[12] = { 31, 28, 31, 30, 31, 30,
31, 31, 30, 31, 30, 31 };
int countLeapYears(Date d)
{
	int years = d.y;

	
	if (d.m <= 2)
		years--;

	
	return years / 4 - years / 100 + years / 400;
}
int getDifference(Date dt1, Date dt2)
{
	
	long int n1 = dt1.y * 365 + dt1.d;

	
	for (int i = 0; i<dt1.m - 1; i++)
		n1 += monthDays[i];

	
	n1 += countLeapYears(dt1);

	
	long int n2 = dt2.y * 365 + dt2.d;
	for (int i = 0; i<dt2.m - 1; i++)
		n2 += monthDays[i];
	n2 += countLeapYears(dt2);

	
	return (n2 - n1);
}
int d1, d2, m1, m2, p1, p2;
int between_days(struct node *date1head, struct node *date2head){
	d1 = date1head->data;
	d1 = d1 * 10 + (date1head->next->data);
	d2 = date2head->data;
	d2 = d2 * 10 + (date2head->next->data);
	m1 = date1head->next->next->data;
	m1 = m1 * 10 + date1head->next->next->data;
	m2 = date2head->next->next->data;
	m2 = m2 * 10 + date2head->next->next->next->data;
	p1 = date1head->next->next->next->next->data;
	p1 = p1 * 1000 + 100*(date1head->next->next->next->next->next->data);
	p1 = p1 + 10*(date1head->next->next->next->next->next->next->data);
	p1 = p1 + date1head->next->next->next->next->next->next->next->data;
	p2 = date2head->next->next->next->next->data;
	p2 = p2 * 1000 + 100 * (date2head->next->next->next->next->next->data);
	p2 = p2 + 10 * (date2head->next->next->next->next->next->next->data);
	p2 = p2 + date2head->next->next->next->next->next->next->next->data;
	Date dt1, dt2;
	dt1.d = d1;
	dt1.m = m1;
	dt1.y = p1;
	dt2.d = d2;
	dt2.m = m2;
	dt2.y = p2;
     return getDifference(dt1, dt2);
}
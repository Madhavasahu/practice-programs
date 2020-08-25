/*
 ============================================================================
 Name        : stringToInt.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MONTHS 12
#define MAX_DAYS 31

void findDate(const char *str, int *date, int *mon, int *year);
void processDate(int *date, int *mon, int *year);
void fixDate(int **date, int **mon, int **year);
int isLeapYear(int year);

typedef enum months {
	JAN = 1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC
} MONTHS;

int main(void) {
	int date, mon, year;
	const char *str = "50/02/2015";
	findDate(str, &date, &mon, &year);
	printf("Given date is %d\n", date);
	printf("Given month is %d\n", mon);
	printf("Given year is %d\n", year);
	processDate(&date, &mon, &year);
	return EXIT_SUCCESS;
}
void processDate(int *date, int *mon, int *year) {
	if ((*mon > MAX_MONTHS) || (*date > MAX_DAYS)) {
		fixDate(&date, &mon, &year);
		printf("\n\nCorrect date is:%d\n", *date);
		printf("Correct month is:%d\n", *mon);
		printf("Correct year is:%d\n", *year);
	} else {
		return;
	}
}
void fixDate(int **date, int **mon, int **year) {
	int actualDays = 0;
	switch (**mon) {
	case JAN:
		actualDays = 31;
		break;
	case FEB:
		if (isLeapYear(**year)) {
			actualDays = 29;
		} else {
			actualDays = 28;
		}
		break;
	case MAR:
		actualDays = 31;
		break;
	case APR:
		actualDays = 30;
		break;
	case MAY:
		actualDays = 31;
		break;
	case JUN:
		actualDays = 30;
		break;
	case JUL:
		actualDays = 31;
		break;
	case AUG:
		actualDays = 31;
		break;
	case SEP:
		actualDays = 30;
		break;
	case OCT:
		actualDays = 31;
		break;
	case NOV:
		actualDays = 30;
		break;
	case DEC:
		actualDays = 31;
		break;
	default:
		actualDays = **date;
		**mon = **mon - MAX_MONTHS;
		**year = **year + 1;
		break;
	}
	if (**date > actualDays) {
		**date = **date - actualDays;
		**mon = **mon + 1;
	}
}
int isLeapYear(int year) {
	if (year % 400 == 0)
		return 1;
	else if (year % 100 == 0)
		return 1;
	else if (year % 4 == 0)
		return 1;
	else
		return 0;
}
void findDate(const char *str, int *date, int *mon, int *year) {
	*date = strtol(str, (char**) &str, 10);
	str = str + 1;
	*mon = strtol(str, (char**) &str, 10);
	str = str + 1;
	*year = strtol(str, (char**) &str, 10);
}

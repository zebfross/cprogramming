static char daytab[][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(int year, int month, int day) {
	int i, leap, day_of_month;
	
	if(month < 1 || month > 12)
		return -1;

	day_of_month = day;
	leap = year%4 == 0 && year%100 != 0 || year%400 == 0;

	for(i = 1; i < month; ++i)
		day += *(daytab[leap] + i);

	if(day_of_month < 1 || day_of_month > daytab[leap][i])
		return -1;

	return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday) {
	int i, leap;

	leap = year%4 == 0 && year%100 != 0 || year%400 == 0;

	if(yearday < 1 || yearday > 365+leap) {
		*pmonth = *pday = -1;
		return;
	}
	
	for(i = 1; yearday > daytab[leap][i]; ++i)
		yearday -= daytab[leap][i];
	*pmonth = i;
	*pday = yearday;
}

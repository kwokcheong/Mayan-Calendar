#include <stdio.h>
#include <stdbool.h>

bool is_leap_year (int year) { 
bool is_leap = 0;
if (year % 4 == 0) { 
    is_leap = 1;
} 
if ( year % 100 == 0) { 
    if (year % 400 == 0){ 
        is_leap = 1;
    } else { 
        is_leap = 0;
    }
}
return is_leap;
}

int days_in_month (int month, int year) { 
 int day = 0;
 int array[4] = {4,6,9,11};
if (month == 2){ 
    if (is_leap_year(year)) { 
        day = 29;
    } else { 
        day = 28;
    }
} else {
    for (int i=0; i<=3; i++){ 
        if (month == array[i]){ 
        day = 30;
        break;
        } else { 
        day = 31;
        }
}
}
return day;
}

int inc_date (int date){ 

    date += 1;

    int day = date%100;
    int month = (date/100) % 100;
    int year = date/10000;


    int m_days = days_in_month(month,year);
    if (day > m_days){ 
        day = 1;
        month += 1;
    } if (month > 12){ 
        month = 1;
        year += 1;
    }
    date = year*10000 + month*100 + day;

    return date;
}


//Give a date and how much to add it by.
int new_date (int day, int month, int year, int add){ 
int date = day + month*100 + year *10000;
while (add > 0){
date = inc_date(date);
add--;
}
return date;
}

//Give baktun,katun... to get normal date
void mayan_to_greg(int baktun, int katun, int tun, int uinal, int kin){ 
//send to new_date a staple date and how many date has passed

int input_mayan = baktun*144000 + katun*7200 + tun*360 + uinal*20 + kin;

int add = input_mayan - 1137143;
int date = new_date (01,01,0001,add);
    int day = date%100;
    int month = (date/100) % 100;
    int year = date/10000;

printf ("%d/%d/%d", day,month,year);
}


int main (void){ 
mayan_to_greg (12,17,16,16,1);
}
#include <stdio.h>
#include <stdbool.h>
//days from epoch + 15695 scales it t0 21122012

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
    int day = date%100;
    int month = (date/100) % 100;
    int year = date/10000;

    if (day == days_in_month(month, year)){ 
        date = date + (101-day);
    } else { 
        date = date + 1;
    }
    if (((date/100) % 100) > 12){ 
        date = date + 8800;
    }
    return date;
}

int days_from_epoch (int day, int month, int year){ 
//assume input > epoch
int epoch = 19700101;
int t_year = year * 10000 + month * 100 + day;
int days=0;

if ( t_year > epoch){
while (epoch < t_year){
    epoch = inc_date(epoch);
    days++;
}
} else if (t_year < epoch) {
while (t_year < epoch){
    t_year = inc_date(t_year);
    days++;
}
days = days* -1;
} else { 
    days = 0;
}

return days;
}

void greg_to_mayan (int day, int month, int year) { 
int baktun=13, katun=0,tun=0,uinal=0,kin=0;
//21 dec 2012 = 13.0.0.0.0
int add = days_from_epoch(day,month,year) - 15695;
printf ("adding %d",add);

if (add >= 0){
int spillover = (kin+add)/20;
kin = (kin+add) % 20;

int spillover2 = (uinal+spillover)/18;
uinal = (uinal + spillover) % 18;

int spillover3 = (tun + spillover2)/20;
tun = (tun + spillover2) % 20;

int spillover4 = (katun + spillover3)/20;
katun = (katun + spillover3) % 20;

baktun = (baktun + spillover4);
} else { 
//Initiate from 0001.01.01
baktun = 7;
katun = 17;
tun = 18;
uinal = 13;
kin = 1;
add = days_from_epoch(day,month,year) + 719164;

int spillover = (kin+add)/20;
kin = (kin+add) % 20;

int spillover2 = (uinal+spillover)/18;
uinal = (uinal + spillover) % 18;

int spillover3 = (tun + spillover2)/20;
tun = (tun + spillover2) % 20;

int spillover4 = (katun + spillover3)/20;
katun = (katun + spillover3) % 20;

baktun = (baktun + spillover4);
}
printf ("\n%d.%d.%d.%d.%d", baktun, katun, tun, uinal, kin);
}


int main (void){ 
greg_to_mayan(01,01,0001);
//printf ("%d", 1/20);
}






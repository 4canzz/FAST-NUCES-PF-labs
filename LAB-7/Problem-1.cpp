//(c) 24L - 6116
#include <iostream>
using namespace std;

class dateType {
    private:
        int day, month, year;
        string mon;
    public:
    string getMonthName(int m) {
        string months[13] = {"NUL", "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
        return months[m];
    }

    int getDaysInMonth(int m, int y) {
        int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        if (m == 2 && ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))) {
            return 29;
        }
        return daysInMonth[m];
    }

public:
    dateType() {
        day = 1;
        month = 1;
        year = 1900;
        mon = getMonthName(month);
    }

    void setdate(int d, int m, int y) {
        if (m >= 1 && m <= 12) {
            month = m;
            mon = getMonthName(month);
            if (d >= 1 && d <= getDaysInMonth(m, y)) {
                day = d;
                year = y;
            }
        }
    }

    void printdate() {
        cout << day << "-" << mon << "-" << year << endl;
    }

    // Increment the day by 1
    void incday() {
        day++;
        if (day > getDaysInMonth(month, year)) {
            day = 1;
            incmonth();
        }
    }

    void incmonth() {
        month++;
        if (month > 12) {
            month = 1;
            incyear();
        }
        mon = getMonthName(month);
    }

    void incyear() {
        year++;
    }

    void equal(dateType& date) {
        if (day == date.day && month == date.month && year == date.year) {
            cout << "Dates are equal." << endl;
        }
        else {
            cout << "Dates are not equal." << endl;
        }
    }

    void incbyday(int n) {
        for (int i = 0; i < n; i++) {
            incday();
        }
    }
};

int main() {
    dateType D;
    dateType C;
    int d, y, m;
    cout << "Enter date" << endl;
    cin >> d >> m >> y;
    cout << endl;
    D.setdate(d,m,y);
    D.printdate();
    cout << endl;
    cout<< "********************" << endl;
    d = 31;
    m = 9;
    y = 1995;
    cout << "Set date: " << d << "-" << m << "-" << y <<endl;
    D.setdate(d,m,y);
    cout << endl;
    D.printdate();
    cout << endl;
    cout << "********************" << endl;

    d=28; m=2; y=1998;
    cout << "Set date: " << d << "-" << m << "-" << y <<endl;
    D.setdate(28,2,1998);
    D.printdate();
    cout << endl;
    cout << "********************" << endl;

    cout << "AFTER INCREMENTING BY 1 DAY" << endl;
    D.incday();
    D.printdate();
    cout << endl;
    cout << "********************" << endl;

    cout << "If " << endl;
    D.setdate(30,11,2007);
    D.printdate();
    cout << endl;
    cout << "AFTER INCREMENTING BY 1 MONTH" << endl;
    D.incmonth();
    D.printdate();
    cout << endl;
    cout << "********************" << endl;
    cout << "AFTER INCREMENTING BY 1 DAY" << endl;
    D.incyear();
    D.printdate();
    cout << endl;
    cout << "********************" << endl;

    C.setdate(12,3,1999);
    cout << "New object created: " <<endl;
    cout << "DATE1: " << endl;
    C.printdate();
    cout << "DATE2: " << endl;
    D.printdate();
    cout << endl;
    D.equal(C);

    cout << "********************" << endl;
    cout << "If ";
    D.printdate();
    cout << endl;
    cout << "Date after 9 days will be" <<endl;
    D.incbyday(9);
    D.printdate();
    return 0;
}

/*Exercise 1: (15 points)
Design and Implement a classdateTypethat manages a calendar. The class dateType should store day, month, and year and display it in
the following format (01-May-1998). For any object of dateType, your program should be able to perform the following operations on 
that object.

-Set the date
-Get the date
-Display the date
-Increment the day by 1
-Increment the month by 1
-Increment the year by 1
-Create another object of dateType and compare it with the object you created earlier; determine whether they are equal or not.
-Increment the day, month or year by certain number, suppose the date is 29-4-1976 and we add 4 days to it, now the date should be
3-5-1976.

Your class should be defined like this

Class dateType
{
private:
int day, month, year;
string mon; //Month name
	
public:
//define functions here with appropriate parameters and return type.
}

Sample main function:
the sample main function is the one implemented in the solution.
*/

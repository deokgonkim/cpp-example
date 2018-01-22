#include <string.h>
#include <iostream>
#include "Date.h"

Date::Date(int initMo, int initDay, int initYr, const char* initMsg) {
    mo = initMo;
    day = initDay;
    yr = initYr;
    msg = new char[strlen(initMsg) + 1];
    strcpy(msg, initMsg);
}

Date::Date(const Date& nn) {
   std::cout << "Copy constructor is called?" << std::endl;
}

Date::~Date() {
    delete[] msg;
}

void Date::CopyFrom(Date otherDate) {
    mo = otherDate.mo;
    day = otherDate.day;
    yr = otherDate.yr;
    
    delete []msg;
    msg = new char[strlen(otherDate.msg) + 1];
    strcpy(msg, otherDate.msg);
}

int main(int argc, char* argv[]) {
    Date d(1, 2, 2003, "2003");
    std::cout << "d created" << std::endl;
    Date d2(2, 3, 2004, "2004");
    std::cout << "d2 created" << std::endl;

    d2 = d;
    std::cout << "d2 copyed to d" << std::endl;
}

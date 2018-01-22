#include <iostream>
#include <iomanip>
#include <fstream>

const int NUM_DEPTS = 6;

enum DayType { MONDAY, TUSEDAY, WEDNESDAY, THURSDAY, FRIDAY };
enum DeptType { A, B, C, D, E, F };

typedef int TableType[NUM_DEPTS][5];
typedef char ChartType[10][5];

void ComputeAverages(const TableType, float[]);
void GetData(TableType, std::ifstream&);
void OpenForInput(std::ifstream&);
void OpenForOutput(std::ofstream&);
void SetAsterisks(ChartType, DayType, float);
void Summarize(const TableType, ChartType);
int TotalAbsences(const TableType);
void WriteBarChart(const ChartType, std::ofstream&);
void WriteTable(const TableType, const float[], std::ofstream&);

int main() {
    TableType absenteeData;
    ChartType barChart;
    float average[NUM_DEPTS];
    std::ifstream dataFile;
    std::ofstream reportFile;

    OpenForInput(dataFile);
    if (!dataFile) return 1;

    OpenForOutput(reportFile);
    if (!reportFile) return 1;

    GetData(absenteeData, dataFile);
    ComputeAverages(absenteeData, average);
    WriteTable(absenteeData, average, reportFile);
    Summarize(absenteeData, barChart);
    WriteBarChart(barChart, reportFile);
    return 0;
}

void OpenForInput(std::ifstream& someFile) {
    char fileName[51];

    std::cout << "Input file name : ";
    std::cin.get(fileName, 51);
    std::cin.ignore(100, '\n');

    someFile.open(fileName);
    if (!someFile) {
        std::cout << "** Can't open " << fileName << " **" << std::endl;
    }
}

void OpenForOutput(std::ofstream& someFile) {
    char fileName[51];
    
    std::cout << "Output file name : ";
    std::cin.get(fileName, 51);
    std::cin.ignore(100, '\n');

    someFile.open(fileName);
    if (!someFile) {
        std::cout << "** Can't open " << fileName << " **" << std::endl;
    }
}

void GetData(TableType absenteeData, std::ifstream& dataFile) {
    DayType day;
    DeptType dept;

    for (day = MONDAY; day <= FRIDAY; day = DayType(day + 1)) {
        for (dept = A; dept <= F; dept = DeptType(dept +1)) {
            dataFile >> absenteeData[dept][day];
        }
    }
}

void ComputeAverages(const TableType absenteeData, float average[]) {
    DayType day;
    DeptType dept;
    int total;

    for (dept = A; dept <= F; dept = DeptType(dept + 1)) {
        total = 0;

        for (day = MONDAY; day <= FRIDAY; day = DayType(day + 1)) {
            total = total + absenteeData[dept][day];
        }
        average[dept] = float(total) / 5.0;
    }
}

void WriteTable(const TableType absenteeData, const float average[], std::ofstream& reportFile) {
    DayType day;
    DeptType dept;
    char deptChar;
    float diffFromAvg;
    float percentDiff;

    reportFile << std::setw(49) << "ABSENTEE DATA" << std::endl
        << std::setw(20) << "Monday"
        << std::setw(13) << "Thusday"
        << std::setw(13) << "Wednesday"
        << std::setw(13) << "Thursday"
        << std::setw(13) << "Friday" << std::endl;


    reportFile << std::setw(7) << " ";
    for (day = MONDAY; day <= FRIDAY ; day = DayType(day + 1)) {
        reportFile << std::setw(13) << "Value  %";
    }

    reportFile << std::endl;

    deptChar = 'A';
    for (dept = A; dept <= F; dept = DeptType(dept + 1)) {
        reportFile << "Dept " << deptChar << ' ';
        for (day = MONDAY; day <= FRIDAY ; day = DayType(day + 1)) {
            reportFile << std::setw(6) << absenteeData[dept][day];
            if (average[dept] > 0.0) {
                diffFromAvg = float(absenteeData[dept][day]) - average[dept];
                percentDiff = diffFromAvg * 100.0 / average[dept];
            } else {
                percentDiff = 0.0;
            }
            if (percentDiff >= 0.0) {
                reportFile << std::setw(7) << int(percentDiff + 0.5);
            } else {
                reportFile << std::setw(7) << int(percentDiff - 0.5);
            }
        }
        reportFile << std::endl;
        deptChar ++;
    }

}

void Summarize(const TableType absenteeData, ChartType barChart) {
    DayType day;
    DeptType dept;
    float percent;
    int dailyTotal;
    int weeklyTotal;

    weeklyTotal = TotalAbsences(absenteeData);
    for (day = MONDAY ; day <= FRIDAY ; day = DayType(day + 1)) {
        dailyTotal = 0;
        for (dept = A ; dept <= F ; dept = DeptType(dept + 1) ) {
            dailyTotal += absenteeData[dept][day];
        }

        if (weeklyTotal > 0) {
            percent = float(dailyTotal) / float(weeklyTotal) * 100.0;
        } else {
            percent = 0.0;
        }
        SetAsterisks(barChart, day, percent);
    }
}

int TotalAbsences(const TableType absenteeData) {
    DayType day;
    DeptType dept;
    int total = 0;

    for (dept = A ; dept <= F ; dept = DeptType(dept + 1)) {
        for (day = MONDAY; day <= FRIDAY; day = DayType(day + 1)) {
            total += absenteeData[dept][day];
        }
    }
    return total;
}

void SetAsterisks(ChartType barChart, DayType day, float percent) {
    int nearestTen;
    int counter;

    nearestTen = int(percent / 10.0 + 0.5);
    for (counter = 9; counter >= nearestTen; counter --) {
        barChart[counter][day] = ' ';
    }
    for (counter = nearestTen - 1; counter >= 0; counter --) {
        barChart[counter][day] = '*';
    }
}


void WriteBarChart(const ChartType barChart, std::ofstream& reportFile) {
    int counter;
    DayType day;

    reportFile << std::endl
        << std::setw(42) << "BAR CHART: ABSENCES BY DAY" << std::endl
        << std::setw(11) << "Monday"
        << std::setw(11) << "Tuesday"
        << std::setw(11) << "Wednesday"
        << std::setw(11) << "Thursday"
        << std::setw(11) << "Friday" << std::endl;


    for (counter = 9; counter >= 0; counter --) {
        reportFile << std::setw(2) << counter + 1 << "0%";
        for (day = MONDAY; day <= FRIDAY; day = DayType(day + 1)) {
            reportFile << "   " << barChart[counter][day]
                << "       ";
        }
        reportFile << std::endl;
    }
}

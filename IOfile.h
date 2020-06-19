#ifndef IOFILE_H
#define IOFILE_H


#include <stdio.h>
#include <map>
#include <string>
using namespace std;

class Employee;
class AttendanceInfo;

class IOfile {

public:
    static string _resourceFile;

public:
    static void addEmployee(Employee *employee);
    static void addListEmployees(map<string,Employee> & employees);
    static void loadAllEmployee(map<string,Employee> & employees);
    static map<string,Employee> & readEmployeeFromCsv(string & path);
    static bool checkExist(string & path);
    static void addCheckPoint(const AttendanceInfo & Attendanceinfo); // Write to a file, indentify by employee_id
    static map<string,AttendanceInfo> loadCheckPoint(const string & idEmployee); // Get checkpoit of a employee by employee_id
    static void rewriteCheckPoint(string & idStaff, map<string,AttendanceInfo> checkPoints);
    static const string genCheckpointFileName(const string & idEmployee); // Specify checkpoint file by employeeId
};

#endif // IOFILE_H

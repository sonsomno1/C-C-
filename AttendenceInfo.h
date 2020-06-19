#ifndef ATTENDENCEINFO_H
#define ATTENDENCEINFO_H

#include <stdio.h>
#include <string>
#include <sstream>
#include <map>
#include <employee.h>
using namespace std;
class AttendanceInfo {
private:
    string _idEmployee; // id nhan vien
    string _date; // ngay thang diem danh
    string _month;
    string _status; // trang thai di lam cua nv

public:
    AttendanceInfo(const string &idEmployee,const string &date,const string &month,const string &status);
    AttendanceInfo();

public:
    const string &getIdStaff() const;
    const string &getDate() const;
    const string &getMonth() const;
    const string &getStatus() const;
    bool operator <(const AttendanceInfo &_AttendanceInfo) const;
    static  void read(map<string,Employee>list);

};
#endif // ATTENDENCEINFO_H

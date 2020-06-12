#include "EmployeeCheckIn.h"
#include "employee.h"
#include <fstream>
#include <string>
#include <iostream>
#include <ctime>
#include <map>

using namespace  std;

map<string,Employee> listEmployee = Employee::addMapEmployee("D:\\QT\\Homework\\EmployeeManagement\\data.csv");

EmployeeCheckIn::EmployeeCheckIn(string id,string workday,string status)
{
    _id = id;
    _workday = workday;
    _status = status;
}
string EmployeeCheckIn::getId()
{
    return _id;
}
string EmployeeCheckIn::getWorkday()
{
    return _workday;
}
string EmployeeCheckIn::getStatus()
{
    return _status;
}
EmployeeCheckIn inputStatusInfo()
{
    EmployeeCheckIn ec;
    string id,status;
    cin.ignore();
    cout << "nhap id nhan vien can cap nhat: "<< endl;
    getline(cin,id);
    for(map<string,Employee>::iterator it = listEmployee.begin();it != listEmployee.end();it++){
              if(ec.getId() != it->first){
                  cout << "nhap id de sua doi ";
                  getline(cin,id);
              }

        }
          cout << "nhap trang thai di lam: ";
          getline(cin,id);
}
void EmployeeCheckIn::createDataFile(string id)
{
    string s = "D:\\QT\\Homework\\EmployeeManagement\\"+id+".txt";
    ofstream fileInput(s);
    fileInput.close();
}
void EmployeeCheckIn::updateStatus(string status, string urlFile)
{
    cin.ignore();
       fstream output(urlFile, ios::app);;

       // lay thoi gian thuc


       getline(cin,status);

       output <<getWorkday() <<",";
       output <<status <<endl;
       fflush(stdin);
       output.close();
}
void EmployeeCheckIn::updateToFile(EmployeeCheckIn ec, string url)
{
    int check = 0;

        for(map<string,Employee>::iterator it = listEmployee.begin();it != listEmployee.end();it++){
            if(ec.getId() == it->first){
                check = 1;
                EmployeeCheckIn::updateStatus(ec.getStatus(),url);
            }
        }
        if( check == 0 ){
            cout<< "ID nhan vien khong ton tai trong danh sach" << endl;
        }
}


















#include <stdio.h>
#include <string>
#include <iostream>
#include <map>
#include <fstream>
#include <employee.h>
#include <helper.h>
#include "AttendenceInfo.h"
using namespace  std;

void AttendanceInfo::read(map<string, Employee> list){
    cin.ignore();
    string url = "D:\\QT\\Homework\\EmployeeManagement\\";
    string idEmployee;
    cout <<"Enter the employee id you want to time: ";

    getline(cin,idEmployee);
    while(Employee::checkIdInput(idEmployee,list) == 1){
        cout << "Enter the employee id you want to time! again: "<< endl;

        getline(cin,idEmployee);
    }
    ifstream ifs(url+idEmployee+".csv", ios::in);


    cout<< "Enter the date you want to timekeeping: ";
    string date;

    getline(cin,date);

    cout<< "Enter status of employee to work (DL-DLNN-N-NP)";
    string status;

    getline(cin,status);
    while(Helpper::checkStatus(status) ==0){
        cout<<"dinh dang sai , xin nhap lai ";

         getline(cin,status);
    }

    fflush(stdin);

    fstream output(url+idEmployee+".csv", ios::app);
    output << date<<","<<status<<endl;

    output.close();
    ifs.close();


}

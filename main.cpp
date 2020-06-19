#include <iostream>
#include <fstream>
#include "employee.h"
#include <map>
#include "EmployeeCheckIn.h"
#include <string>
#include<bits/stdc++.h>
#include <AttendenceInfo.h>

using namespace std;
void menu()
{
    cout <<"===========================================" <<endl;
    cout <<"= 1-Nhap thong tin nhan vien              =" << endl;
    cout <<"= 2-Tim Thong tin nhan vien               =" << endl;
    cout <<"= 3-In tat ca cac nhan vien               =" << endl;
    cout <<"= 4-Tao file luu nhan vien                =" << endl;
    cout <<"= 5-nhap thong tin diem danh nhan vien    =" << endl;
    cout <<"= 6-Lich su diem danh nhan vien           =" << endl;
    cout <<"===========================================" <<endl;
    cout << "Chon chuc nang (1-6):" << endl;
}
void work()
{
    Employee *employee;
    string urlFile = "D:\\QT\\Homework\\EmployeeManagement\\data.csv";
    /* ./list.txt

       ../../../Desk/list.txt */

    int choice;
    employee = new Employee();
    map<string,Employee> list = employee->addMapEmployee(urlFile);
    do
    {
        menu();
        cin >> choice;
        switch (choice) {
        case 1:
        {
            employee->inputEmployee(list);

        }
            break;

        case 2:
        {

            employee->searchEmployee(list);
        }
            break;

        case 3:
               {

                   employee->outEmployeeFile(list);

                   break;
               }
        case 4:
               {

                   for(map<string,Employee>::iterator it = list.begin();it != list.end();it++){

                       std::ofstream o( "D:\\QT\\Homework\\EmployeeManagement\\"+it->first+".csv");
                   }
                   cout << "File creation successful !!! " <<endl;
                   break;
               }


        case 5:
                {
                    cout << "------= Nhap thong tin diem danh=------ " <<endl;
                    //AttendanceInfo::read(list);

                    break;
                }
        }
    } while (choice != 0); {
        cout << "END" << endl;
    }
}
int main(){
    work();

    return  0;
}



















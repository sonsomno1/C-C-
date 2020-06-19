#include "employee.h"


#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <map>
#include<cstring>
#include <algorithm>
#include <helper.h>
#include <iomanip>
#include <stdlib.h>

using namespace std;

string urlFile = "D:\\QT\\Homework\\EmployeeManagement\\data.csv";




Employee::Employee(std::string id,  std::string name ,  std::string date
                   , std::string address ,  std::string department)
{
    _id = id;
    _name = name;
    _date = date;
    _address = address;
    _department = department;

}

void Employee::inputFile(string url,Employee employee){

    fstream output(url, ios::app);;
    string id = employee.getId();
    string name = employee.getName();
    string birthday = employee.getDate();
    string address = employee.getAddress();
    string department = employee.getDepartment();

    output <<id <<",";
    output <<name <<",";
    output <<birthday <<",";
    output <<address <<",";
    output <<department <<endl;

    output.close();
}


map<string,Employee> Employee::addMapEmployee(string urlfile){
    map<string,Employee> mapEmployee;
    ifstream output;
    output.open(urlfile,ios::in);

    if(!output.is_open()){
        cout << "ERROR: File Open" << '\n';
    }
    while (output.good()) {
        string lineId,lineName,lineDate,lineAddress,lineDepartment;
        getline(output,lineId,',');
        getline(output,lineName,',');
        getline(output,lineDate,',');
        getline(output,lineAddress,',');
        getline(output,lineDepartment,'\n');

        Employee employee = Employee(lineId,lineName,lineDate,lineAddress,lineDepartment);

        mapEmployee.insert(pair<string,Employee>(lineId,employee));

    }
    output.close();
    fflush(stdin);
    return  mapEmployee;
    map<string,Employee> list =  Employee::addMapEmployee(urlFile);
}



int validDate (string date )
{
    stringstream ss(date);
    int day, month, year;

    ss >> day >> month >> year;

    if (year >= 1000 && year <= 3000)
    {
        if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day > 0 && day <= 31)
            return 1;
        else
            if (month == 4 || month == 6 || month == 9 || month == 11 && day > 0 && day <= 30)
                return 1;
            else
                if (month == 2)
                {
                    if ((year % 400 == 0 || (year % 100 != 0 && year % 4 == 0)) && day > 0 && day <= 29)
                    {

                        if (day > 0 && day <= 28)
                            return 1;
                        else
                            return 0;
                    }

                }
                else
                    return 0;
    }
    else
        return 0;
    return 0;
}

int Employee::checkIdInput(string id,map<string,Employee> list){

    for(map<string,Employee>::iterator it = list.begin();it != list.end();it++){
           if(it->first == id){
               return 0;
           }
       }

       return 1;
}

void Employee::inputEmployee(map<string,Employee> list)
{
    cout <<"" <<endl;
       cin.ignore();

       cout << "nhap ID : ";
       getline(cin,_id);
       while (true) {
           if(checkIdInput(_id,list) == 0){


               cout << "ID trung : ";
               getline(cin,_id);
           }else{
               break;
           }
       }

       cout << "Nhap ten : ";
       getline(cin,_name);

       cout << "Nhap ngay sinh : ";
       getline(cin,_date);

       cout << "Nhap dia chi: ";
       getline(cin,_address);
       while ( _address == ""){
           cout << "Dia chi bi trong  " <<endl;
           cout << "Nhap lai : ";
           getline(cin,_address);
       }


       cout << "Nhap bo phan : ";
       getline(cin,_department);
       while ( _department == ""){
           cout << "Bo phan bi trong  "<< endl;
           cout << "Nhap lai : ";
           getline(cin,_department);
       }

       Employee employee = Employee(_id,_name,_date,_address,_department);



       inputFile(urlFile,employee);



       fflush(stdin);



}

int isSubstring(string s1, string s2)
{
    std::transform(s1.begin(), s1.end(),s1.begin(), ::tolower);
    std::transform(s2.begin(), s2.end(),s2.begin(), ::tolower);
    int M = s1.length();
    int N = s2.length();
    for (int i = 0; i <= N - M; i++) {
        int j;
        for (j = 0; j < M; j++)
            if (s2[i + j] != s1[j])
                break;

        if (j == M)
            return i;
    }

    return -1;
}
void Employee::printEmployee(Employee employee)
{
    cout << "" << endl;
    cout << "Nhan vien : \n" << employee.getName() <<endl;
    cout << "co id :" << employee.getId() << endl;
    cout << "ngay sinh : " << employee.getDate() << endl;
    cout << "song o : " << employee.getAddress() << endl;
    cout << " lam viec o bo phan : " << employee.getDepartment() << endl;

}

void Employee::outEmployeeFile(map<string,Employee> list){

    map<string,Employee>::iterator itr;

    cout << "The number of employees on the list:  "<< list.size() << endl;

    for(map<string,Employee>::iterator it = list.begin();it != list.end();it++){
        printEmployee(it->second);
    }
 }

void Employee::searchEmployee(map<string,Employee> list)
{
    map<string,Employee>::iterator itr;


      int choice;


      do {
          cout << ""<< endl;
          cout <<"------- MENU SEARCH-------" <<endl;
          cout <<"1-Tim ID           -" <<endl ;
          cout <<"2-Tim Ten         -" <<endl;
          cout <<"3-Tim Dia chi      -"<<endl ;
          cout <<"4-Tim Bo phan cong tac   -"<<endl ;
          cout <<"0-thoat   -"<<endl ;
          cout <<"--------------------------" <<endl;
          cout << "Nhap lua chon  " ;
          cin >> choice;
          switch (choice) {
          case 1:
          {

              string idSearch;
              cout << "=> Tim ID: " <<endl;
              cout << "Nhap Id := " ;
              cin >> idSearch;
              int check = 0;

              for(map<string,Employee>::iterator it = list.begin();it != list.end();it++){
                  if(it->first == idSearch){
                      printEmployee(it->second);
                      check = 1;
                  }
              }
              if(check == 0){

                  cout << "Khong co ID hop le ";

              }
              break;
          }
          case 2:
          {
              cout << "=> Tim ten" << endl;
              cin.ignore();
              string name;
              cout << "Nhap ten nhan vien := ";
              getline(cin,name);
              int check = 0;

              for(map<string,Employee>::iterator it = list.begin();it != list.end();it++){
                  if(isSubstring(name,it->second.getName()) >= 0){

                      printEmployee(it->second);
                      check = 1;
                  }
              }
              if(check == 0){

                  cout << "Khong co ten hop le ";

              }
              fflush(stdin);
              break;
          }

          case 3:
          {

              cout << "=> Tim dia chi " << endl;
              cin.ignore();
              string address;
              cout << "Nhap dia chi can tim:= ";
              getline(cin,address);
              int check = 0;
              cout << "----= LIST ADSRESS = "<<address <<"=----" <<endl;

              for(map<string,Employee>::iterator it = list.begin();it != list.end();it++){
                  if(isSubstring(address,it->second.getAddress()) >= 0){

                      printEmployee(it->second);
                      check = 1;
                  }
              }
              if(check == 0){

                  cout << "Khong co dia chi hop le  !";

              }
              fflush(stdin);
              break;
          }

          case 4:
          {
              cout << "=> Tim bo phan cong tac " <<endl;
              cin.ignore();
              string department;

              cout << "Nhap bo phan cong tac can tim:= ";
              getline(cin,department);
              cout << department <<"-------------"<< endl;
              int check = 0;

              for(map<string,Employee>::iterator it = list.begin();it != list.end();it++){
                  if(isSubstring(department,it->second.getDepartment()) >= 0){
                      printEmployee(it->second);
                      check = 1;
                  }
              }
              if(check == 0){

                  cout << "Khong co bo phan hop le ";

              }
              fflush(stdin);
              break;
          }
          }

      } while (choice != 0);



      fflush(stdin);

  }





















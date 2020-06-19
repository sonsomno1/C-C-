#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <iostream>
#include <map>
#include <string>
#include <vector>
#pragma once
#include<bits/stdc++.h>

using namespace  std;

class Employee
{
private:
    std::string _id;
    std::string _name;
    std::string _date;
    std::string _address;
    std::string _department;


public:
    Employee(){};
   Employee ( std::string id,  std::string name ,  std::string date
             , std::string address ,  std::string department);
public:

   ~Employee(){

   };
public:
   void setId(std::string id){
        _id = id;
   }
   void setName(std::string name){
        _name = name;
   }
   void setDate(std::string date){
        _date = date;
   }
   void setAddress(std::string address){
        _address = address;
   }
   void setDepartment(std::string department){
        _department = department;
   }

//public:

//    const std::string &id() const;

//    const std::string &name() const;

//    const std::string &date() const;

//    const std::string &address() const;

//    const std::string &department() const;
public:
    std::string &getId(){
        return this->_id;
    };

    std::string &getName(){
        return this->_name;
    };

    std::string &getDate(){
        return this->_date;
    };

   std:: string &getAddress(){
        return this->_address;
    };

    std::string &getDepartment(){
        return this->_department;
    };


public:
        static map<string,Employee>addMapEmployee(string urlfile);
        virtual void inputFile(string url,Employee employee);
        virtual void inputEmployee(map<string,Employee> list);

        virtual void printEmployee(Employee employee);
        virtual void outEmployeeFile(map<string,Employee> list);
        static int checkIdInput(string id,map<string,Employee> list);

        virtual void searchEmployee(map<string,Employee> list);

        static vector<string> cutStringDate(string s,string delimiter);


};

#endif // EMPLOYEE_H

#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <iostream>
#include <map>
#include <string>
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
    std::string _workday;
    std::string _status;

public:
    Employee();
   Employee ( std::string id,  std::string name ,  std::string date
             , std::string address ,  std::string department, std::string _workday, std::string _status);
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
   void setWorkday(std::string workday){
       _workday = workday;
   }
   void setStatus(std::string status){
       _status = status;
   }
//public:

//    const std::string &id() const;

//    const std::string &name() const;

//    const std::string &date() const;

//    const std::string &address() const;

//    const std::string &department() const;
public:
    std::string getId(){
        return this->_id;
    };

    std::string getName(){
        return this->_name;
    };

    std::string getDate(){
        return this->_date;
    };

   std:: string getAddress(){
        return this->_address;
    };

    std::string getDepartment(){
        return this->_department;
    };
    std::string getWorkday(){
        return this->_workday;
    }
    std::string getStatus(){
        return this->_status;
    }
public:
        static map<string,Employee>addMapEmployee(string urlfile);

        virtual void inputEmployee(string file);

        virtual void printEmployee(Employee employee);

        virtual int checkIdInput(string file,string id);


};

#endif // EMPLOYEE_H

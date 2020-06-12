#include "employee.h"

#include <string>
#include <fstream>
#include <sstream>
#include <map>
#include<cstring>

using namespace std;

string urlFile = "D:\\QT\\Homework\\EmployeeManagement\\data.csv";

Employee::Employee()
{
}


Employee::Employee(std::string id,  std::string name ,  std::string date
                   , std::string address ,  std::string department,std::string workday,std::string status)
{
    _id = id;
    _name = name;
    _date = date;
    _address = address;
    _department = department;
    _workday = workday;
    _status = status;
}
map<string,Employee> Employee::addMapEmployee(string urlfile){
    map<string,Employee> mapEmployee;
    ifstream output;
    output.open(urlfile,ios::in);

    if(!output.is_open()){
        cout << "ERROR: File Open" << '\n';
    }
    while (output.good()) {
        string lineId,lineName,lineDate,lineAddress,lineDepartment,line;
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

}
 map<string,Employee> list =  Employee::addMapEmployee(urlFile);
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

int Employee::checkIdInput(string file,string id){

    string line;
    ifstream fileInput(file, ios::in);
    if (fileInput.is_open())
    {

        while (!fileInput.eof())
        {
            getline(fileInput, line);
            string epl = line;
            istringstream stm(epl);
            string token;
            getline(stm, token, ',');
            if (token == id)
            {
                return 0;
            }

        }
        fileInput.close();
    }
    return 1;
}

void Employee::inputEmployee(string file)
{
    ofstream myfile(file, ios::app);
    if (myfile.is_open())
    {
       string id;
       string name;
       string date;
       string address;
       string department;
       string workday;
       string status;

            cout << "Nhap id : ";
            cin >> id;
            while (checkIdInput(file, id) == 0) {
                cout << "id bi trung  \n";
                cout << "Nhap id : ";
                cin >> id;
            }

            cout << "Nhap ten nhan vien: ";
            cin.ignore();
            getline(cin, name);

            cout << "Nhap ngay sinh: ";
            getline(cin, date);
            while (validDate(date)==0)
            {
                cout << " loi ngay sinh" << endl;
                cout << " nhap lai" << endl;
                getline(cin , date);
            }

            cout << "Nhap dia chi: ";
            getline(cin, address);
            while (address.empty())
            {
                cout << "Dia chi khong duoc bo trong \n";
                cout << "Nhap lai dia chi \n";
                getline(cin, address);
            }

            cout << "Nhap bo phan cong tac: ";
            getline(cin, department);
            while (department.empty())
            {
                cout << "Bo phan cong tac khong duoc bo trong \n";
                cout << "Nhap lai bo phan cong tac \n";
                getline(cin, department);
            }

            cout << "Nhap ngay di lam: ";
            getline(cin, workday);
            while(validDate(workday)==0)
            {
                cout << "loi" <<endl;
                getline(cin , workday);
            }



            cout << "Nhap trang thai di lam: ";
            getline(cin,status) ;
            if (status.empty()) {status = "X";}
            else
            {
             while (status != "DL" && status != "DLNN" && status != "N" && status != "NP")
             {
                cout << "loi " << endl;
                cout << "nhap lai " << endl;
                cin >> status;
              }
            }

            myfile << id << "," << name << "," << date << "," << address << "," << department << "," << workday << "," << status << endl;

        myfile.close();
    }


}


void Employee::printEmployee(Employee employee)
{
    cout << "" << endl;
    cout << "Nhan vien : \n" << employee.getName() <<endl;
    cout << "co id :" << employee.getId() << endl;
    cout << "ngay sinh : " << employee.getDate() << endl;
    cout << "song o : " << employee.getAddress() << endl;
    cout << " lam viec o bo phan : " << employee.getDepartment() << endl;
    cout << "ngay di lam : " << employee.getWorkday() << endl;
    cout << " trang thai " << employee.getStatus() << endl;
}


 Employee SearchId(string file , string id)
{
    Employee employee;
    string line;

    ifstream fileInput(file, ios::in);
    if (fileInput.is_open())
    {

        while (!fileInput.eof())
        {
            getline(fileInput, line);
            string epl = line;
            istringstream stm(epl);
            string token;
            getline(stm, token, ',');
            if (token == id)
            {
                employee.setId(id);
                getline(stm, token, ',');
                employee.setName(token);
                getline(stm, token, ',');
                employee.setDate(token);
                getline(stm, token, ',');
                employee.setAddress(token);
                getline(stm, token, ',');
                employee.setDepartment(token);
                getline(stm,token, ',');
                employee.setWorkday(token);
                getline(stm,token, ',');
                employee.setStatus(token);

            }

        }
//        myfile << id << "," << name << "," << date << "," << address << "," << department << "," << workday << "," << status << endl;
        fileInput.close();
    }
    return employee;
}
Employee changeStatus(string file , string id )
{
    Employee employee;
    string line;

    ifstream fileInput(file, ios::in);
    if (fileInput.is_open())
    {

        while (!fileInput.eof())
        {
            getline(fileInput, line);
            string epl = line;
            istringstream stm(epl);
            string token;
            string workday;
            string newstatus;
            getline(stm, token, ',');
            if (token == id)
            {
                //cout << "nhap ngay diem danh :" << endl;
               // cin >> workday;
                cout << "nhap trang thai: "<<endl;
                cin >> newstatus;
                employee.setId(id);
                getline(stm, token, ',');
                employee.setName(token);
                getline(stm, token, ',');
                employee.setDate(token);
                getline(stm, token, ',');
                employee.setAddress(token);
                getline(stm, token, ',');
                employee.setDepartment(token);
                getline(stm,token, ',');
                employee.setWorkday(token);
                getline(stm,token, ',');
                employee.setStatus(newstatus);

            }

        }
        fileInput.close();
    }
    return employee;
}


 void menu()
 {
     cout <<"===========================================" <<endl;
     cout <<"= 1-Nhap thong tin nhan vien              =" << endl;
     cout <<"= 2-Tim Thong tin nhan vien               =" << endl;
     cout <<"= 3-Cap nhat trang thai di lam            =" << endl;
     cout <<"===========================================" <<endl;
     cout << "Chon chuc nang (1-2-3):" << endl;
 }
int work()
{
    Employee *employee;
    string urlFile = "D:\\QT\\Homework\\EmployeeManagement\\Employee.txt";
    /* ./list.txt

       ../../../Desk/list.txt */

    int choice;
    employee = new Employee();
    do
    {
      menu();
      cin >> choice;
      switch (choice) {
      case 1:
      {
          employee->inputEmployee(urlFile);

      }
          break;

      case 2:
      {
          string id;
          cout << "nhap id"<< endl;
          cin >> id;
          employee->printEmployee(SearchId(urlFile,id));
      }
          break;

      case 3:
      {
          string id;
          cout << "nhap id"<< endl;
          cin >> id;
          employee->printEmployee(changeStatus(urlFile,id));
      }
          break;
      }
    } while (choice != 0); {
        return 0;
    }
}
















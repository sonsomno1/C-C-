#include "employee.h"

#include <string>
#include <fstream>
#include <sstream>


using namespace std;

Employee::Employee()
{
}


Employee::Employee(std::string id,  std::string name ,  std::string date
                   , std::string address ,  std::string department)
{
    _id = id;
    _name = name;
    _date = date;
    _address = address;
    _department = department;
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
                cin >> department;
            }

            myfile << id << "," << name << "," << date << "," << address << "," << department << endl;

        myfile.close();
    }


}


void Employee::printEmployee(Employee employee)
{
    cout << "" << endl;
    cout << "Nhan vien : " << employee.getName() << " co id :" << employee.getId() << endl;
    cout << "Ngay sinh : " << employee.getDate() << endl;
    cout << "Dia chi : " << employee.getAddress() << " lam viec o bo phan : " << employee.getDepartment()<< endl;
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
     cout <<"= 2-Tim thong tin nhan vien               =" << endl;
     cout <<"===========================================" <<endl;
     cout << "Chon chuc nang (1-2):" << endl;
 }
int work()
{
    Employee *employee;
    string urlFile = "D:\\QT\\Homework\\EmployeeManagement\\Employee.txt";
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
      }
    } while (choice != 0); {
        return 0;
    }
}
















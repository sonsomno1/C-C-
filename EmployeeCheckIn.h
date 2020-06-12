#ifndef EMPLOYEECHECKIN_H
#define EMPLOYEECHECKIN_H
#include <map>
#include "employee.h"

using namespace std;

class EmployeeCheckIn {
private:
    string _id;
    string _workday;
    string _status;
public:
    string getId();
    string getWorkday();
    string getStatus();
public:
    void setId(string id);
    void setWorkday(string workday);
    void setStatus(string status);
public:
    EmployeeCheckIn()
    {

    }
    ~EmployeeCheckIn(){

    }
    EmployeeCheckIn(string id,string workday,string status);
    void createDataFile(string id);
    void updateStatus(string status,string urlFile);
    void updateToFile(EmployeeCheckIn ec,string url);


};



#endif // EMPLOYEECHECKIN_H

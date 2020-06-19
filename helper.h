#ifndef HELPPER_H
#define HELPPER_H
#include <vector>
#include <sstream>
#include  <string>
#include <map>
#include <employee.h>
using namespace  std;
class Helpper
{
public:
     static int numberLine();
     static vector<string> split (const string &s, char delim) ;
     static int checkId(map<string,Employee>list, string id);
     static int checkDateOfBirth(string dateOfBirth);
     static int checkStatus(string status);
     static int checkDateStaff(string date);
};
#endif // HELPPER_H

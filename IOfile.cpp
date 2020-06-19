#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "employee.h"
#include "IOfile.h"
#include "AttendenceInfo.h"
using namespace std;

/*
 void addCheckPoint(const AttendanceInfo & Attendanceinfo)
{
    string fileName = IOfile::genCheckpointFileName(Attendanceinfo.getIdStaff());
    ofstream fout;
    fout.open(fileName, ios::app);
    if (fout.is_open()) {
        fout << Attendanceinfo.getDate() << "," << Attendanceinfo.getStatus() << endl;
    }
    fout.close();
}
map<string,AttendanceInfo> IOfile::loadCheckPoint(const string & idStaff)
{
   map<string,AttendanceInfo> checkpoints;

    string fileName = IOfile::genCheckpointFileName(idStaff);
    ifstream fin;
    fin.open(fileName, ios::in);
    if (fin.is_open()) {
        string line, word;

        while (getline(fin, line)) {
            stringstream s(line);
            int i = 0;
            string row[2];
            while (getline(s, word, ',')) {
                row[i++] = word;
            }
          AttendanceInfo *in = new AttendanceInfo(idStaff, row[0], row[1]);
         checkpoints.insert(pair<string,AttendanceInfo>(idStaff,*in));
        }
    }
    fin.close();

    return checkpoints;
}

const string IOfile::genCheckpointFileName(const string & idStaff)
{
    string fileName = "checkpoint-" + idStaff + ".csv";
    return fileName;
}

bool IOfile::checkExist(string &path)
{
    ifstream f(path.c_str());
    return f.good();
}

void IOfile::rewriteCheckPoint(string & idStaff, map<string,AttendanceInfo> checkPoints)
{
    string fileName = IOfile::genCheckpointFileName(idStaff);
    ofstream fstream_ob;
    fstream_ob.open(fileName, ios::trunc);

    if (fstream_ob.is_open()) {
       for(map<string,AttendanceInfo>::iterator it = checkPoints.begin();it != checkPoints.end();it++){
            fstream_ob << it->second.getDate() << "," << it->second.getStatus() << endl;
        }
    }
    fstream_ob.close();
}
*/

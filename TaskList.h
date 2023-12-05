#ifndef UNTITLED1_TASKLIST_H
#define UNTITLED1_TASKLIST_H
#include <bits/stdc++.h>
using namespace std;
class TaskList {
private:
    string Process_name,Session_Name,Session_Hash;
    int PID;
    double memory_usage;
public:
    TaskList();
    void Fill(const string& Process,const string& session_name,const string& session_Hash,int pid,double Memory_usage);
    static void get(vector<TaskList>& vec);
    friend ostream& operator<<(ostream& out,TaskList& a);
    friend bool operator<(const TaskList &a,const TaskList& b);
};


#endif //UNTITLED1_TASKLIST_H

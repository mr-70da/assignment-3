#include "TaskList.h"

TaskList::TaskList() {
    PID = 0;
    memory_usage = 0.0;
}

void TaskList::Fill(const string& Process,const string& session_name,const string& session_Hash, int pid, double Memory_usage){
    Process_name =Process;
    Session_Name = session_name;
    Session_Hash = session_Hash;
    PID = pid;
    memory_usage = Memory_usage;
}

void TaskList::get(vector<TaskList>& vec) {
    ifstream Filename("com.txt");
    string Tasks;
    int count = 0;
    while(getline(Filename,Tasks)){
        if(count>2){
            stringstream ss(Tasks);
            string copy, process, session_name, session_hash;
            int pid;
            double memory;
            vector<string> words;
            while (getline(ss, copy, ' ')) {
                if(!copy.empty()&&copy!="K"){ words.push_back(copy); }
            }
            int i;
            for (i = 0; i < words.size() && !isdigit(words[i][0]); ++i) {
                process += words[i] + " ";
            }
            pid = stoi(words[i++]);
            session_name += words[i++];
            session_hash += words[i++];
            memory = stoi(words[i++]);
            TaskList t;
            t.Fill(process, session_name, session_hash, pid, memory);
            vec.push_back(t);
        }
        count++;
    }
}

ostream &operator<<(ostream& out, TaskList &a) {
    out<<a.Process_name<<'\t'<<a.PID<<" \t "<<a.Session_Name<<'\t'<<"\t \t"<<a.Session_Hash<<"  \t     "<<a.memory_usage<<" k"<<'\n';
    return out;
}

bool operator<(const TaskList &a, const TaskList& b) {
    if (a.Process_name != b.Process_name)
        return a.Process_name < b.Process_name;
    if (a.PID != b.PID)
        return a.PID < b.PID;
    return a.memory_usage < b.memory_usage;
}


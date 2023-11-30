#ifndef UNTITLED1_FILELABELGENERATOR_H
#define UNTITLED1_FILELABELGENERATOR_H
#include "LabelGenerator.cpp"

class FileLabelGenerator:public LabelGenerator {
private:
    string File_name;
    vector<string>texts;
public:
    static int counter;
    FileLabelGenerator();
    FileLabelGenerator(const string& type,int number,const string& File_name);
    string nextLabel()override;
};


#endif //UNTITLED1_FILELABELGENERATOR_H

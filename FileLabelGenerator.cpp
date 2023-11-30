#include "FileLabelGenerator.h"
FileLabelGenerator::FileLabelGenerator():LabelGenerator() {
    File_name = "";
}

FileLabelGenerator::FileLabelGenerator(const string &type, int number, const string& File_name): LabelGenerator(type,number) {
    this->File_name = File_name;
    ifstream filename(File_name,ios::in);
    string copy;
    while(getline(filename,copy)){
        texts.push_back(copy);
    }
}
int FileLabelGenerator::counter = 0;
string FileLabelGenerator::nextLabel() {
    string output = type+to_string(number++)+" "+texts[counter++];
    return output;
}

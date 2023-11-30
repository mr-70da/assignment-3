#ifndef UNTITLED1_LABELGENERATOR_H
#define UNTITLED1_LABELGENERATOR_H
#include <bits/stdc++.h>
using namespace std;
class LabelGenerator {
protected:
    string type;
    int number;
public:
    LabelGenerator();
    LabelGenerator(const string& type,int number);
    virtual string nextLabel();
};


#endif //UNTITLED1_LABELGENERATOR_H

#include "LabelGenerator.h"

LabelGenerator::LabelGenerator() {
    type = "";
    number = 0;
}

LabelGenerator::LabelGenerator(const string &type, int number) {
    this->type = type;
    this->number = number;
}

string LabelGenerator::nextLabel() {
    string num = type;
    num+= to_string(number++);
    return num;
}

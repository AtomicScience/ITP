#ifndef ITP_STUDENT_H
#define ITP_STUDENT_H

#include "ExamDay.h"

struct Student {
    char name[30];
    char surname[30];
    int groupNumber;
    struct ExamDay examDay;
};
#endif //ITP_STUDENT_H
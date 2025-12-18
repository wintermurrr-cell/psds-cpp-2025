#include <map>

struct Date {

    Date(unsigned y = 0, unsigned m = 0, unsigned d = 0) {
        year = y;
        month = m;
        day = d;
    }

    unsigned year;
    unsigned month;
    unsigned day;
};

struct StudentInfo {
    size_t id;
    char mark;
    int score;
    unsigned course;
    Date birth_date;
};

bool operator==(const Date& a, const Date& b) {
    return a.year == b.year
    && a.month == b.month
    && a.day == b.day;
}

bool operator!=(const Date& a, const Date& b) {
    return !(a == b);
}

using FuncTypeCompare = bool (*)(const unsigned&, const unsigned&);
bool checkLess(const Date& a, const Date& b, FuncTypeCompare funcCompare) {
    if (funcCompare(a.year, b.year))
        return true;

    if (a.year == b.year
        && funcCompare(a.month, b.month))
        return true;

    if (a.year == b.year
        && a.month == b.month
        && funcCompare(a.day, b.day))
        return true;
    return false;
}

bool unsignedLess(const unsigned& a, const unsigned& b) {
    return a < b;
}
bool operator<(const Date& a, const Date& b) {
    if (checkLess(a, b, unsignedLess))
        return true;
    return false;
}

bool operator<=(const Date& a, const Date& b) {
    if (a < b)
        return true;
    if (a == b)
        return true;
    return false;
}

bool unsignedMore(const unsigned& a, const unsigned& b) {
    return a > b;
}
bool operator>(const Date& a, const Date& b) {
    if (checkLess(a, b, unsignedMore))
        return true;
    return false;
}

bool operator>=(const Date& a, const Date& b) {
    if (a > b)
        return true;
    if (a == b)
        return true;
    return false;
}

bool operator==(const StudentInfo& a, const StudentInfo& b) {
    return a.mark == b.mark
    && a.score == b.score;
}

bool operator!=(const StudentInfo& a, const StudentInfo& b) {
    return !(a == b);
}

bool operator<(const StudentInfo& a, const StudentInfo& b) {
    const std::map<char, int> markMap { { 'A', 5 },
                                        { 'B', 4 },
                                        { 'C', 3 },
                                        { 'D', 2 },
                                        { 'Z', 1 } };

    const int markNumA = markMap.at(a.mark);
    const int markNumb = markMap.at(b.mark);
    if (markNumA < markNumb)
        return true;

    const bool eqMark = markNumA == markNumb;
    if (eqMark && a.score < b.score)
        return true;

    const bool eqScore = a.score == b.score;
    if (eqMark && eqScore
        && a.course > b.course)
        return true;

    const bool eqCourse = a.course == b.course;
    if (eqMark && eqScore && eqCourse
        && a.birth_date < b.birth_date)
        return true;

    return false;
}

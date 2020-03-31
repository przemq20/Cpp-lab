#ifndef PROGRAMMERS_DETAILS_H
#define PROGRAMMERS_DETAILS_H

#if __cplusplus < 201103L && !defined(_MSC_FULL_VER)
    #error C++11 or greater is required!
#endif

namespace StudentsInfo
{
    constexpr const char* const FIRSTNAME = "Przemyslaw";
    constexpr const char* const SURNAME   = "Lechowicz";

    constexpr const char* const MAIL    = "plechowicz[at]student.agh.edu.pl";
    constexpr const char* const BOOK_ID = "305353";

    void validateStudentsInfo();

    constexpr const char* const teacherMail = "bazior[at]agh.edu.pl"; // please do not change!
}

#endif // PROGRAMMERS_DETAILS_H

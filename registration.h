#ifndef REGISTRATION_H
#define REGISTRATION_H

#include<QDate>
#include "person.h"

class Registration : public QObject {

    Q_OBJECT

public:
    Registration(Person a) : m_Attendee(a.getName(), a.getAffiliation(), a.getEmail()), m_BookingDate(QDate::currentDate()) {}
    Person getAttendee();
    QDate getBookingDate();
    virtual double calculateFee(); //virtual allows the child classes to explicitly call their own functions and not the parent function
    QString toString();
    static const double STANDARD_FEE;

    //virtual destructor is essential for parent classes to ensure child classes are cleaned up properly
    virtual ~Registration();

private:
    Person m_Attendee;
    QDate m_BookingDate;

};

#endif // REGISTRATION_H

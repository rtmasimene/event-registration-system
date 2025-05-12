#ifndef REGISTRATIONLIST_H
#define REGISTRATIONLIST_H

#include "registration.h"
#include<QList>

class RegistrationList {
public:
    RegistrationList() {}
    ~RegistrationList(); //destructor
    bool addRegistration(Registration* r);
    bool isRegistered(QString n);
    double totalFee(QString t);
    int totalRegistrations(QString a);
    QList<Registration*> getAttendeeList();

private:
    QList<Registration*> m_AttendeeList;
};

#endif // REGISTRATIONLIST_H

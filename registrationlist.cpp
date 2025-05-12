#include "registrationlist.h"

RegistrationList::~RegistrationList() {

    /*
    for (Registration* reg: m_AttendeeList) {
        delete reg;
        reg = nullptr;
    }
    */

    qDeleteAll(m_AttendeeList);
    m_AttendeeList.clear();
}

bool RegistrationList::addRegistration(Registration* r) {

    //Rules:
    //  1) No two registrations are allowed to have attendees with the same e-mail addresses,
    //     unless the names are different.

    //exit and return false if a duplicate registration is found
    for (Registration* reg: m_AttendeeList) {
        if (r->getAttendee().getEmail() == reg->getAttendee().getEmail() &&
                r->getAttendee().getName() == reg->getAttendee().getName()) {
            return false;
        }
    }

    m_AttendeeList.append(r);
    return true;

}

bool RegistrationList::isRegistered(QString n) {

    //iterate through list and check if a person  with the given name is registered

    for (Registration* reg: m_AttendeeList) {
        if (n == reg->getAttendee().getName()) {
            return true;
        }
    }

    return false;
}

double RegistrationList::totalFee(QString t) {

    // t is the registration type

    //Instructions:
    //1 - Request the total registration fees for a type (“Registration”,
    //   “StudentRegistration”, “GuestRegistration” or “All”) of registration.
    //   Use Qt’s metaobject system to access the type of Registration in RegistrationList

    double total = 0;

    if (t == "All") {
        for (Registration* reg: m_AttendeeList) {
            total += reg->calculateFee();
        }
    }
    else {
        for (Registration* reg: m_AttendeeList) {
            if (t == reg->metaObject()->className()) {
                total += reg->calculateFee();
            }
        }
    }

    return total;
}

int RegistrationList::totalRegistrations(QString a) {

    //Instructions:
    //1 - A RegistrationList can also return the number of attendees
    //    that are registered for the conference from an institution

    int count = 0;

    for (Registration* reg: m_AttendeeList) {
        if (a == reg->getAttendee().getAffiliation()) {
            count++;
        }
    }

    return count;
}

QList<Registration*> RegistrationList::getAttendeeList() {
    return m_AttendeeList;
}

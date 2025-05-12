#include "registrationfactory.h"

Registration* RegistrationFactory::createRegistration(QString regType, Person p, QString studentQualification, QString guestCategory) {

    if (regType == "Registration" || regType == "Standard") {
        Registration* reg = new Registration(p);
        return reg;
    }
    else if (regType == "StudentRegistration" || regType == "Student") {
        StudentRegistration* reg = new StudentRegistration(p, studentQualification);
        return reg;
    }
    else if (regType == "GuestRegistration" || regType == "Guest") {
        GuestRegistration* reg = new GuestRegistration(p, guestCategory);
        return reg;
    }

    else {
        return nullptr;
    }
}

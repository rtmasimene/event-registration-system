#ifndef REGISTRATIONFACTORY_H
#define REGISTRATIONFACTORY_H

#include "registration.h"
#include "guestregistration.h"
#include "studentregistration.h"


class RegistrationFactory {
public:

    //this is to make sure that the code follows the Singleton principle
    //meaning only one instance of this class can exist (one object)
    static RegistrationFactory& getInstance() {
            static RegistrationFactory instance;
            return instance;
    }

    Registration* createRegistration(QString regType, Person p, QString studentQualification="", QString guestCategory="");

private:
    RegistrationFactory() = default;
    ~RegistrationFactory() = default;
    RegistrationFactory(const RegistrationFactory&) = delete;
    RegistrationFactory& operator=(const RegistrationFactory&) = delete;
};

#endif // REGISTRATIONFACTORY_H

#ifndef STUDENTREGISTRATION_H
#define STUDENTREGISTRATION_H

#include "registration.h"

class StudentRegistration : public Registration {
    Q_OBJECT
public:
    StudentRegistration(Person a, QString q) : Registration(a) {}
    double calculateFee() override;
    QString toString();

private:
    QString m_Qualification;
};

#endif // STUDENTREGISTRATION_H

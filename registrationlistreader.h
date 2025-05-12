#ifndef REGISTRATIONLISTREADER_H
#define REGISTRATIONLISTREADER_H

#include <QXmlStreamReader>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
#include <QMessageBox>
#include <QDebug>
#include <QList>
#include <QString>

#include "registration.h"
#include "guestregistration.h"
#include "studentregistration.h"

#include "registrationfactory.h"

class RegistrationListReader {
public:
    RegistrationListReader();
    bool readXML();
    QList<Registration*> processXMLRegistrations();

private:
    QXmlStreamReader xmlStream;

    QList<QString> listRegTypes;
    QList<QString> listAttendeeNames;
    QList<QString> listAttendeeAffiliations;
    QList<QString> listAttendeeEmails;
    QList<QString> listBookingDates;
    QList<QString> listRegFees;

    QList<Registration*> regList;

    RegistrationFactory& regFactory = RegistrationFactory::getInstance();

};

#endif // REGISTRATIONLISTREADER_H

#include "registrationlistreader.h"

RegistrationListReader::RegistrationListReader() {

}

bool RegistrationListReader::readXML() {

    //open the file dialog and get the filename
    QString fileName = QFileDialog::getOpenFileName(nullptr);

    //only XML files are allowed to be used
    if (fileName.endsWith(".xml")) {

        //open the file
        QFile myFile(fileName);

        if (myFile.open(QIODevice::ReadOnly | QIODevice::Text)) {

                xmlStream.setDevice(&myFile); //point to where we must be reading the XML from
                QXmlStreamReader::TokenType token; //stores where we are in the XML document (we could either be at a tag or at inner text)

                while (xmlStream.atEnd() == false) {

                    token = xmlStream.readNext(); //move to the next one

                    if (xmlStream.name().toString() == "registration" && token == QXmlStreamReader::StartElement) {
                        //get the registration type
                        if (xmlStream.attributes().hasAttribute("type")) {
                            listRegTypes.append(xmlStream.attributes().value("type").toString()); //add to list
                        }
                    }

                    if (xmlStream.name().toString() == "name" && token == QXmlStreamReader::StartElement) {
                        token = xmlStream.readNext(); //move to the next one to get the inner text
                        if (token == QXmlStreamReader::Characters) {
                            listAttendeeNames.append(xmlStream.text().toString());
                        }
                    }

                    if (xmlStream.name().toString() == "affiliation" && token == QXmlStreamReader::StartElement) {
                        token = xmlStream.readNext(); //move to the next one to get the inner text
                        if (token == QXmlStreamReader::Characters) {
                            listAttendeeAffiliations.append(xmlStream.text().toString());
                        }
                    }

                    if (xmlStream.name().toString() == "email" && token == QXmlStreamReader::StartElement) {
                        token = xmlStream.readNext(); //move to the next one to get the inner text
                        if (token == QXmlStreamReader::Characters) {
                            listAttendeeEmails.append(xmlStream.text().toString());
                        }
                    }

                    if (xmlStream.name().toString() == "bookingdate" && token == QXmlStreamReader::StartElement) {
                        token = xmlStream.readNext(); //move to the next one to get the inner text
                        if (token == QXmlStreamReader::Characters) {
                            listBookingDates.append(xmlStream.text().toString());
                        }
                    }

                    if (xmlStream.name().toString() == "registrationfee" && token == QXmlStreamReader::StartElement) {
                        token = xmlStream.readNext(); //move to the next one to get the inner text
                        if (token == QXmlStreamReader::Characters) {
                            listRegFees.append(xmlStream.text().toString());
                        }
                    }

                } //end while

                if (xmlStream.hasError()) {
                    QMessageBox::critical(nullptr, "XML error", xmlStream.errorString());
                    return false;
                }

                /*
                let me explain my logic for future me who will be reading this:
                - since we are iterating from top to bottom,
                - and we know the structure of the XML tags,
                - all I'm doing is storing each data at each iteration into
                - lists for each XML tag, following the order of the structure.
                - Once you have the lists with all the XML information,
                - you can iterate through the lists and add registrations
                - to the registration list.
                - this can be confirmed by outputting the info in the lists
                - to the console window as I'm doing below.
                */
                for (int i=0; i<listAttendeeNames.count(); i++) {

                    qDebug() << listRegTypes.at(i) << ", "
                             << listAttendeeNames.at(i) << ", "
                             << listAttendeeAffiliations.at(i) << ", "
                             << listAttendeeEmails.at(i) << ", "
                             << listBookingDates.at(i) << ", "
                             << listRegFees.at(i) << ".\n";
                }

                myFile.close();
                return true;
        }
        else { //failed to open
            QMessageBox::critical(nullptr, "File", "File open procedure failed");
            return false;
        }
    }
    else {
        QMessageBox::critical(nullptr, "Incorrect file type", "Only XML files can be opened.");
        return false;
    } //endif: file is not an XML file

}

QList<Registration*> RegistrationListReader::processXMLRegistrations() {

    //iterate through the lists and
    //create the correct number of registrations


    for (int i=0; i<listAttendeeNames.count(); i++) {

        //we need a Person object to pass as an argument in the Registration constructors
        Person p(listAttendeeNames.at(i), listAttendeeAffiliations.at(i), listAttendeeEmails.at(i));
        regList.append(regFactory.createRegistration(listRegTypes.at(i), p, "", ""));
    }

    return regList;
}

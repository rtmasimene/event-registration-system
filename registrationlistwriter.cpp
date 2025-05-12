#include "registrationlistwriter.h"

RegistrationListWriter::RegistrationListWriter() {

}

bool RegistrationListWriter::createXML(RegistrationList* list) {

    //open the file and get the filename
    QString fileName = QFileDialog::getOpenFileName(nullptr);

    //only XML files are allowed to be used
    if (fileName.endsWith(".xml")) {

        //write the XML that will be saved to the file
        QDomDocument doc;
        QDomElement rootOfTree = doc.createElement("registrationlist");
        doc.appendChild(rootOfTree);

        for (Registration* r : list->getAttendeeList()) {

            //1 - creating the registration branch
            QDomElement reg = doc.createElement("registration");
            reg.setAttribute("type", r->metaObject()->className());
            rootOfTree.appendChild(reg);

                //2 - creating the registration branch's children
                QDomElement attendee = doc.createElement("attendee");
                reg.appendChild(attendee);

                    //3 - creating the attendee branch's children
                    QDomElement attendeeName = doc.createElement("name");
                    QDomElement attendeeAffiliation = doc.createElement("affiliation");
                    QDomElement attendeeEmail = doc.createElement("email");

                    attendee.appendChild(attendeeName);
                    attendee.appendChild(attendeeAffiliation);
                    attendee.appendChild(attendeeEmail);

                    //this is the text in the middle --> <>text in the middle</>
                    QDomText nameNode = doc.createTextNode(r->getAttendee().getName());
                    QDomText affiliationNode = doc.createTextNode(r->getAttendee().getAffiliation());
                    QDomText emailNode = doc.createTextNode(r->getAttendee().getEmail());

                    attendeeName.appendChild(nameNode);
                    attendeeAffiliation.appendChild(affiliationNode);
                    attendeeEmail.appendChild(emailNode);


                //2 - (see above)
                QDomElement bookingDate = doc.createElement("bookingdate");
                QDomElement regFee = doc.createElement("registrationfee");

                reg.appendChild(bookingDate);
                reg.appendChild(regFee);

                //this is the text in the middle --> <>text in the middle</>
                QDomText bookingDateNode = doc.createTextNode(r->getBookingDate().toString("yyyy-MM-dd") );
                QDomText regFeeNode = doc.createTextNode(QString::number(r->calculateFee()));

                bookingDate.appendChild(bookingDateNode);
                regFee.appendChild(regFeeNode);

        }

        //write the XML to the file
        QFile myFile(fileName);
        if (myFile.open(QIODeviceBase::WriteOnly)) {

            QTextStream stream(&myFile);
            stream << doc.toString();
            myFile.close();
            return true;

        }
        else {
            return false;
        }
    }
    else {
        return false;
    }

}


#include "registration.h"

const double Registration::STANDARD_FEE = 100;

//constructor initialiser list used in header file, so no need to instantiate constructor in cpp file.

Person Registration::getAttendee() {
    return m_Attendee;
}

QDate Registration::getBookingDate() {
    return m_BookingDate;
}

double Registration::calculateFee() {
    return STANDARD_FEE;
}

QString Registration::toString() {
    QString output="";

    //call Person toString to add information to the Registraiton toString
    output.append(m_Attendee.toString());

    output.append("Booking date: " + m_BookingDate.toString("yyyy-MM-dd") + "\n");
    output.append("Registration fee : R" + QString::number(this->calculateFee()) + "\n");

    return output;
}

Registration::~Registration() {

}

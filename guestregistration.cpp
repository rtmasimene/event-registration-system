#include "guestregistration.h"

//constructor initialiser list used in header file, so no need to instantiate constructor in cpp file.

double GuestRegistration::calculateFee() {

    //Rules:
    //  1) For those registered as guests, the conference fee is 10% of the standard registration fee.

    return Registration::STANDARD_FEE*0.10;
}

QString GuestRegistration::toString() {
    QString output = "";

    output.append(Registration::getAttendee().toString());

    output.append("Category: " + m_Category + "\n");
    output.append("Booking date: " + Registration::getBookingDate().toString("yyyy-MM-dd") + "\n");
    output.append("Registration fee : R" + QString::number(this->calculateFee()) + "\n");

    return output;
}

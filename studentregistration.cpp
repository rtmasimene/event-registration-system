#include "studentregistration.h"

//constructor initialiser list used in header file, so no need to instantiate constructor in cpp file.

double StudentRegistration::calculateFee() {

    //Rules:
    //  1) For those registered as students, the conference fee is half the price of the standard registration fee

    return Registration::STANDARD_FEE*0.50;

}

QString StudentRegistration::toString() {
    QString output = "";

    output.append(Registration::getAttendee().toString());

    output.append("Qualification: " + m_Qualification + "\n");
    output.append("Booking date: " + Registration::getBookingDate().toString("yyyy-MM-dd") + "\n");
    output.append("Registration fee : R" + QString::number(this->calculateFee()) + "\n");

    return output;
}

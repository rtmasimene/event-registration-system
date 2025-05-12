#include "person.h"

//constructor initialiser list used in header file, so no need to instantiate constructor in cpp file.

QString Person::getName() {
    return m_Name;
}

QString Person::getAffiliation() {
    return m_Affiliation;
}

QString Person::getEmail() {
    return m_Email;
}

QString Person::toString() {
    QString output="";

    output.append("Name: " + m_Name + "\n");
    output.append("Affiliation: " + m_Affiliation + "\n");
    output.append("Email: " + m_Email + "\n");

    return output;
}

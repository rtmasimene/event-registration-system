#ifndef PERSON_H
#define PERSON_H

#include<QString>

class Person {
public:
    Person(QString n, QString a, QString e) : m_Name(n), m_Affiliation(a), m_Email(e) {}
    QString getName();
    QString getAffiliation();
    QString getEmail();
    QString toString();

private:
    QString m_Name;
    QString m_Affiliation;
    QString m_Email;

};

#endif // PERSON_H

#ifndef REGISTRATIONLISTWRITER_H
#define REGISTRATIONLISTWRITER_H

#include <QDomDocument>
#include <QDomAttr>
#include <QDomElement>
#include <QDomNode>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
#include <QDomText>


#include "registrationlist.h"

class RegistrationListWriter {
public:
    RegistrationListWriter();
    bool createXML(RegistrationList* list);
};

#endif // REGISTRATIONLISTWRITER_H

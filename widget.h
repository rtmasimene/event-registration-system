#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QApplication>


#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDebug>
#include <QTableWidget>
#include <QComboBox>
#include <QStringList>
#include <QMessageBox>
#include <QInputDialog>

#include "registrationlist.h"
#include "registration.h"
#include "studentregistration.h"
#include "guestregistration.h"
#include "registrationlistwriter.h"
#include "registrationlistreader.h"

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void setLayout();
    static const double MAX_WIDGET_HEIGHT, MAX_WIDGET_WIDTH;
    static const int REG_STANDARD, REG_STUDENT, REG_GUEST, REG_ALL;
    static const int NUM_TABLE_COLUMNS;
    static const int NAME_COL, AFF_COL, EMAIL_COL, DATE_COL, REG_COL, FEE_COL;

private slots:
    void createRecord();
    void checkRegistrationStatus();
    void countAttendees();
    void calculateFees();
    void saveToXML();
    void readXMLFromDoc();
    //---------------------------------

private:
    QWidget *baseWidget; //parent of all the other widgets

    QLabel *lblHeading, *lblName, *lblAffiliation, *lblEmail, *lblRegistrationType;
    QLineEdit *edtName, *edtAffiliation, *edtEmail;
    QComboBox *cbRegistrationType;
    QPushButton *btnRegister, *btnCheckRegistrationStatus, *btnCountAttendees;

    QLabel *lblCalculateFees;
    QPushButton *btnCalculateFees;
    QComboBox *cbRegistrationCategory;

    QVBoxLayout *vlMain;
    QHBoxLayout *hlName, *hlAffiliation, *hlEmail, *hlButtons, *hlRegistrationType, *hlTable;
    QHBoxLayout *hlCalculateFees;

    QWidget *wdgNameContainer, *wdgAffiliationContainer, *wdgEmailContainer, *wdgButtonContainer;
    QWidget *wdgRegistrationTypeContainer;
    QWidget *wdgCalculateFeesContainer;
    QWidget *wdgTableContainer;
    QTableWidget *tblRegistrations;

    QStringList headerLabels;

    RegistrationList* regList;

    bool validateInputs();
    void addRecordToTable(Registration* r);

    QPushButton *btnSaveToXML;
    QHBoxLayout *hlXMLButtons;
    QWidget *wdgXMLButtonsContainer;
    RegistrationListWriter listWriterXML;

    QPushButton *btnReadXML;
    RegistrationListReader listReaderXML;


    //---------------------------------

};
#endif // WIDGET_H

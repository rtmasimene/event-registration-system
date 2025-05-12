#include "widget.h"
#include <QMessageBox>
#include <QDebug>
#include <QList>
#include <QTableWidgetItem>

const double Widget::MAX_WIDGET_WIDTH = 1000;
const double Widget::MAX_WIDGET_HEIGHT = 600;

// these static numbers will represent the index of each registration type in the combo box
const int Widget::REG_STANDARD = 0;
const int Widget::REG_STUDENT = 1;
const int Widget::REG_GUEST = 2;
const int Widget::REG_ALL = 3;

// this static number represents the number of columns we will have and display in our table
const int Widget::NUM_TABLE_COLUMNS = 6;

// setting column numbers for easy table navigation
const int Widget::NAME_COL = 0;
const int Widget::AFF_COL = 1;
const int Widget::EMAIL_COL = 2;
const int Widget::DATE_COL = 3;
const int Widget::REG_COL = 4;
const int Widget::FEE_COL = 5;


Widget::Widget(QWidget *parent) : QWidget(parent){

    //setting header names for the table
    headerLabels = {"Name", "Affiliation", "Email", "Booking date", "Registration type",
                    "Registration fee"};

    //creating window widget
    baseWidget = new QWidget(this);
    baseWidget->resize(MAX_WIDGET_WIDTH*0.9, MAX_WIDGET_HEIGHT*0.9);

    //creating labels
    lblHeading = new QLabel("Fill in your details for the conference registration");
    lblName = new QLabel("Name");
    lblAffiliation = new QLabel("Affiliation");
    lblEmail = new QLabel("Email");
    lblRegistrationType = new QLabel("Select your registration type");
    lblCalculateFees = new QLabel("Calculate total fees for registration category:");

    //creating input widgets
    edtName = new QLineEdit;
    edtAffiliation = new QLineEdit;
    edtEmail = new QLineEdit;

    //creating combobox widgets
    cbRegistrationType = new QComboBox;
    cbRegistrationType->insertItem(Widget::REG_STANDARD, "Standard");
    cbRegistrationType->insertItem(Widget::REG_STUDENT, "Student");
    cbRegistrationType->insertItem(Widget::REG_GUEST, "Guest");

    cbRegistrationCategory = new QComboBox;
    cbRegistrationCategory->insertItem(Widget::REG_STANDARD, "Registration");
    cbRegistrationCategory->insertItem(Widget::REG_STUDENT, "StudentRegistration");
    cbRegistrationCategory->insertItem(Widget::REG_GUEST, "GuestRegistration");
    cbRegistrationCategory->insertItem(Widget::REG_ALL, "All");

    //creating buttons
    btnRegister = new QPushButton("Register");
    btnCheckRegistrationStatus = new QPushButton("Check registration status");
    btnCountAttendees = new QPushButton("Count attendees");
    btnCalculateFees = new QPushButton("Calculate fees");
    btnSaveToXML = new QPushButton("Save to XML");
    btnReadXML = new QPushButton("Read XML from document");

    //connect button click signals to function slots
    //---------------------------------S L O T S ---------------------------------------

     connect(btnRegister, SIGNAL(clicked()), this, SLOT(createRecord()));
     connect(btnCheckRegistrationStatus, SIGNAL(clicked()), this, SLOT(checkRegistrationStatus()));
     connect(btnCountAttendees, SIGNAL(clicked()), this, SLOT(countAttendees()));
     connect(btnCalculateFees, SIGNAL(clicked()), this, SLOT(calculateFees()));

     connect(btnSaveToXML, SIGNAL(clicked()), this, SLOT(saveToXML()));
     connect(btnReadXML, SIGNAL(clicked()), this, SLOT(readXMLFromDoc()));

     //----------------------------------------------------------------------------------

    //creating table
    tblRegistrations = new QTableWidget(this);
    tblRegistrations->setColumnCount(Widget::NUM_TABLE_COLUMNS);
    tblRegistrations->setHorizontalHeaderLabels(headerLabels);

    //creating layouts to which we will add and position the widgets
    vlMain = new QVBoxLayout;

    hlName = new QHBoxLayout;
    hlAffiliation = new QHBoxLayout;
    hlEmail = new QHBoxLayout;
    hlRegistrationType = new QHBoxLayout;
    hlButtons = new QHBoxLayout;
    hlCalculateFees = new QHBoxLayout;
    hlTable = new QHBoxLayout;
    hlXMLButtons = new QHBoxLayout;

    //create widgets to hold horizontal layouts
    wdgNameContainer = new QWidget;
    wdgNameContainer->setMaximumWidth(MAX_WIDGET_WIDTH*0.4);

    wdgAffiliationContainer = new QWidget;
    wdgAffiliationContainer->setMaximumWidth(MAX_WIDGET_WIDTH*0.4);

    wdgEmailContainer = new QWidget;
    wdgEmailContainer->setMaximumWidth(MAX_WIDGET_WIDTH*0.4);

    wdgRegistrationTypeContainer = new QWidget;
    wdgRegistrationTypeContainer->setMaximumWidth(MAX_WIDGET_WIDTH*0.4);

    wdgButtonContainer = new QWidget;
    wdgButtonContainer->setMaximumWidth(MAX_WIDGET_WIDTH*0.7);

    wdgCalculateFeesContainer = new QWidget;
    wdgCalculateFeesContainer->setMaximumWidth(MAX_WIDGET_WIDTH*0.7);

    wdgTableContainer = new QWidget;
    wdgTableContainer->setMaximumWidth(MAX_WIDGET_WIDTH*0.95);

    wdgXMLButtonsContainer = new QWidget;
    wdgXMLButtonsContainer->setMaximumWidth(MAX_WIDGET_WIDTH*0.4);

    regList = new RegistrationList;

}

Widget::~Widget() {

    //--------------------------------------------------------------------
    //Memory management
    //--------------------------------------------------------------------

    /*
    QList<QWidget*> widgetsList = {lblHeading, lblName, lblAffiliation, lblEmail, lblRegistrationType,
                                  edtName, edtAffiliation, edtEmail, cbRegistrationType,
                                  btnRegister, btnCheckRegistrationStatus, tblRegistrations,
                                  wdgNameContainer, wdgAffiliationContainer,
                                  wdgEmailContainer, wdgRegistrationTypeContainer,
                                  wdgButtonContainer, wdgTableContainer,
                                  baseWidget};

    QList<QLayout*> layoutsList = {vlMain, hlName, hlAffiliation, hlEmail,
                                   hlRegistrationType, hlButtons, hlTable};
                                   */

    //1 - free up the dynamically allocated memory
    delete lblHeading;
    delete lblName;
    delete lblAffiliation;
    delete lblEmail;
    delete lblRegistrationType;
    delete lblCalculateFees;

    delete edtName;
    delete edtAffiliation;
    delete edtEmail;

    delete cbRegistrationType;
    delete cbRegistrationCategory;

    delete btnRegister;
    delete btnCheckRegistrationStatus;
    delete btnCountAttendees;
    delete btnCalculateFees;
    delete btnSaveToXML;
    delete btnReadXML;

    delete tblRegistrations;

    delete vlMain;

    delete hlName;
    delete hlAffiliation;
    delete hlEmail;
    delete hlRegistrationType;
    delete hlButtons;
    delete hlCalculateFees;
    delete hlTable;
    delete hlXMLButtons;

    delete wdgNameContainer;
    delete wdgAffiliationContainer;
    delete wdgEmailContainer;
    delete wdgRegistrationTypeContainer;
    delete wdgButtonContainer;
    delete wdgCalculateFeesContainer;
    delete wdgTableContainer;
    delete wdgXMLButtonsContainer;

    delete baseWidget;

    delete regList;

    //2 - ensure all pointers are not pointing to random memory addresses

    lblHeading = nullptr;
    lblName = nullptr;
    lblAffiliation = nullptr;
    lblEmail = nullptr;
    lblRegistrationType = nullptr;
    lblCalculateFees = nullptr;

    edtName = nullptr;
    edtAffiliation = nullptr;
    edtEmail = nullptr;

    cbRegistrationType = nullptr;
    cbRegistrationCategory = nullptr;

    btnRegister = nullptr;
    btnCheckRegistrationStatus = nullptr;
    btnCountAttendees = nullptr;
    btnCalculateFees = nullptr;
    btnSaveToXML = nullptr;
    btnReadXML = nullptr;

    tblRegistrations = nullptr;

    vlMain = nullptr;

    hlName = nullptr;
    hlAffiliation = nullptr;
    hlEmail = nullptr;
    hlRegistrationType = nullptr;
    hlButtons = nullptr;
    hlCalculateFees = nullptr;
    hlTable = nullptr;
    hlXMLButtons = nullptr;

    wdgNameContainer = nullptr;
    wdgAffiliationContainer = nullptr;
    wdgEmailContainer = nullptr;
    wdgRegistrationTypeContainer = nullptr;
    wdgButtonContainer = nullptr;
    wdgCalculateFeesContainer = nullptr;
    wdgTableContainer = nullptr;
    wdgXMLButtonsContainer = nullptr;

    baseWidget = nullptr;

    regList = nullptr;
}

void Widget::setLayout() {

    //adding widgets to layouts
    //add label heading to vertical layout
    vlMain->addWidget(lblHeading);

    //1 - add label name + line edit to to horizontal layout
    //2 - place that horizontal layout in a widget container
    //3 - and then place that widget container into the main vertical layout
    //repeat steps 1-3 for each horizontal layout

    //adding the "name" block of widgets
    hlName->addWidget(lblName); //step 1
    hlName->addWidget(edtName); //
    wdgNameContainer->setLayout(hlName); //step 2
    vlMain->addWidget(wdgNameContainer); //step 3

    //adding the "affiliation" block of widgets
    hlAffiliation->addWidget(lblAffiliation);
    hlAffiliation->addWidget(edtAffiliation);
    wdgAffiliationContainer->setLayout(hlAffiliation);
    vlMain->addWidget(wdgAffiliationContainer);

    //adding the "email" block of widgets
    hlEmail->addWidget(lblEmail);
    hlEmail->addWidget(edtEmail);
    wdgEmailContainer->setLayout(hlEmail);
    vlMain->addWidget(wdgEmailContainer);

    //adding the "registration type" block of widgets
    hlRegistrationType->addWidget(lblRegistrationType);
    hlRegistrationType->addWidget(cbRegistrationType);
    wdgRegistrationTypeContainer->setLayout(hlRegistrationType);
    vlMain->addWidget(wdgRegistrationTypeContainer);

    //adding the "buttons" block of widgets
    hlButtons->addWidget(btnRegister);
    hlButtons->addWidget(btnCheckRegistrationStatus);
    hlButtons->addWidget(btnCountAttendees);
    wdgButtonContainer->setLayout(hlButtons);
    vlMain->addWidget(wdgButtonContainer);

    //adding the "calculate fees" block of widgets
    hlCalculateFees->addWidget(lblCalculateFees);
    hlCalculateFees->addWidget(cbRegistrationCategory);
    hlCalculateFees->addWidget(btnCalculateFees);
    wdgCalculateFeesContainer->setLayout(hlCalculateFees);
    vlMain->addWidget(wdgCalculateFeesContainer);

    //adding the table to the base widget
    hlTable->addWidget(tblRegistrations);
    wdgTableContainer->setLayout(hlTable);
    vlMain->addWidget(wdgTableContainer);

    //adding the "XMl" block to the base widget
    hlXMLButtons->addWidget(btnSaveToXML);
    hlXMLButtons->addWidget(btnReadXML);
    wdgXMLButtonsContainer->setLayout(hlXMLButtons);
    vlMain->addWidget(wdgXMLButtonsContainer);


    //4 - add main vertical layout to the base/parent widget
    baseWidget->setLayout(vlMain);
}


//Logic portion
//----------------------------------------------------------------------------

void Widget::createRecord() {

    if (validateInputs()==true) {
        Person newPerson(edtName->text().trimmed(), edtAffiliation->text().trimmed(), edtEmail->text().trimmed());

        //ensure we create the correct registration object based on the combobox selection

        if (cbRegistrationType->currentIndex() == Widget::REG_STANDARD) {
            Registration* newReg = new Registration(newPerson);
            addRecordToTable(newReg);
        }

        else if (cbRegistrationType->currentIndex() == Widget::REG_STUDENT) {
            QString qualification = QInputDialog::getText(nullptr, "Qualification", "Enter your qualification");

            //ensure input value is never empty
            if (qualification.trimmed()=="") {
                QMessageBox::warning(nullptr, "Input invalid", "Qualification cannot be empty");
                return;
                //qualification = QInputDialog::getText(nullptr, "Qualification", "Enter your qualification");
            }
            else {
                StudentRegistration* newReg = new StudentRegistration(newPerson, qualification);
                addRecordToTable(newReg);
            }
        }

        else if (cbRegistrationType->currentIndex() == Widget::REG_GUEST) {
            QString category = QInputDialog::getText(nullptr, "Guest category", "Enter your category");

            //ensure input value is never empty
             if (category.trimmed()=="") {
                QMessageBox::warning(nullptr, "Input invalid", "Category cannot be empty");
                return;
                //category = QInputDialog::getText(nullptr, "Guest category", "Enter your category");
            }
            else {
                 GuestRegistration* newReg = new GuestRegistration(newPerson, category);
                 addRecordToTable(newReg);
            }
        }

    }
}

void Widget::addRecordToTable(Registration* r) {

    //NOTE: this slot calls the addRegistration(Registration* r) function in RegistrationList

        //add new registration to the registration list

        if (regList->addRegistration(r) != true) {
            QMessageBox::warning(nullptr, "Duplicate information", "Duplicate registration found. Could not complete registration. No two registrations are allowed to have attendees with the same e-mail addresses, unless the names are different.");
            return;
        }
        else {
            // get row count
            // insert row at row count
            // create multiple widget items for each column
            // add widget items to each column at rowcount in order to create a single record

            tblRegistrations->insertRow(tblRegistrations->rowCount());

            QTableWidgetItem *cellName = new QTableWidgetItem(r->getAttendee().getName());
            QTableWidgetItem *cellAffiliation = new QTableWidgetItem(r->getAttendee().getAffiliation());
            QTableWidgetItem *cellEmail = new QTableWidgetItem(r->getAttendee().getEmail());
            QTableWidgetItem *cellBookingDate = new QTableWidgetItem(r->getBookingDate().toString("yyyy-MM-dd"));
            QTableWidgetItem *cellRegType = new QTableWidgetItem(r->metaObject()->className());
            QTableWidgetItem *cellRegFee = new QTableWidgetItem(QString::number(r->calculateFee()));

            tblRegistrations->setItem(tblRegistrations->rowCount()-1, NAME_COL, cellName);
            tblRegistrations->setItem(tblRegistrations->rowCount()-1, AFF_COL, cellAffiliation);
            tblRegistrations->setItem(tblRegistrations->rowCount()-1, EMAIL_COL, cellEmail);
            tblRegistrations->setItem(tblRegistrations->rowCount()-1, DATE_COL, cellBookingDate);
            tblRegistrations->setItem(tblRegistrations->rowCount()-1, REG_COL, cellRegType);
            tblRegistrations->setItem(tblRegistrations->rowCount()-1, FEE_COL, cellRegFee);


            // no need to worry about a memory leak:
            // we don't need to explicitly free up the dynamically allocated memory because
            // the setItem function takes ownership of the pointer we created
            // and the memory will be deleted when the table itself is deleted

            QMessageBox::information(nullptr, "Success", "Registration successful.");
        }
    }


void Widget::checkRegistrationStatus() {

    //NOTE: this slot calls the isRegistered(QString n) function in RegistrationList
    if (edtName->text().trimmed()=="") {
        QMessageBox::information(nullptr, "Input empty", "Please provide a name to search for");
    }

    else if (regList->isRegistered(edtName->text().trimmed())) {
        QMessageBox::information(nullptr, "Found", "The person with the name '" + edtName->text().trimmed() + "' is registered.");
    }
    else {
        QMessageBox::information(nullptr, "Not found", "No registration found with the given name '" + edtName->text().trimmed() + "'.");
    }
}

void Widget::countAttendees() {
    //NOTE: this slot calls the totalRegistrations(QString a) function in RegistrationList

    if (edtAffiliation->text().trimmed()=="") {
        QMessageBox::information(nullptr, "Input empty", "Please provide an affiliation/institution for which total number of attendees will be counted.");
    }

    else {
        QMessageBox::information(nullptr, "Attendee count", "Total number of attendees registered from the institution '" + edtAffiliation->text().trimmed() + "': " + QString::number(regList->totalRegistrations(edtAffiliation->text().trimmed())));
    }

}

void Widget::calculateFees() {
    //NOTE: this slot calls the totalFee(QString t) function in RegistrationList
    QMessageBox::information(nullptr, "Total fees", "Total fees for " + cbRegistrationCategory->currentText() + ": " + QString::number(regList->totalFee(cbRegistrationCategory->currentText())));
}

bool Widget::validateInputs() {

    //input validation

    //1 - ensure inputs are not empty
    //2 - the trimmed() function removes whitespace at the beginning and end of a string
    //returns true if all inputs are valid and returns false otherwise

    if (edtName->text().trimmed()!="" && edtAffiliation->text().trimmed()!="" && edtEmail->text().trimmed()!="") {
        return true;
    }
    else {
        QMessageBox::warning(nullptr, "Missing information", "Inputs cannot be empty");
        return false;
    }
}


void Widget::saveToXML() {

    if (regList->getAttendeeList().empty()) {
        QMessageBox::information(nullptr, "Empty list", "Cannot save empty registration list.");
    }
    else {
        if (listWriterXML.createXML(regList)) {
            QMessageBox::information(nullptr, "Success", "List saved to XML document.");
        }
        else {
            QMessageBox::warning(nullptr, "File open error", "File must be an XML file.");
        }
    }
}

void Widget::readXMLFromDoc() {

    if (listReaderXML.readXML()) {
        QMessageBox::information(nullptr, "Success", "The XML data has been read from the file. Duplicates will not be added if found.");

        //processXMLRegistrations returns QList<Registration*>
        //therefore, we iterate through it and append the list to the regList (RegistrationList)

        for (Registration* r: listReaderXML.processXMLRegistrations()) {
            //this will add the registration to the RegistrationList and display it in the table
            addRecordToTable(r);
        }
    }
    else {
        QMessageBox::critical(nullptr, "Failure", "XML could not be read from the file.");
    }
}

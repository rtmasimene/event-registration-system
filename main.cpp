#include <QApplication>

#include "widget.h"

int main(int argc, char *argv[])
{
    //--------------------------------------------------------------------
    // - Manual GUI setup
    //--------------------------------------------------------------------

    //main window
    QApplication a(argc, argv);
    Widget *mainWidget = new Widget;
    mainWidget->setWindowTitle("Event Registration System");
    mainWidget->resize(Widget::MAX_WIDGET_WIDTH, Widget::MAX_WIDGET_HEIGHT);
    mainWidget->setLayout();

    //--------------------------------------------------------------------
    // - Execute program
    //--------------------------------------------------------------------

    //display the main window
    mainWidget->show();

    //execute the application
    int result = a.exec();

    //--------------------------------------------------------------------
    // - Memory management
    //--------------------------------------------------------------------
    delete mainWidget;
    mainWidget = nullptr;

    //--------------------------------------------------------------------
    //- End
    //--------------------------------------------------------------------

    return result;
}


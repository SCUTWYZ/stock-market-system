#include "widget.h"
#include<iostream>
#include <QApplication>
using namespace std;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Widget *w=new Widget();
    w->show();
    return a.exec();
}

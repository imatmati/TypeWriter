#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include <iostream>
#include <QFontDatabase>
#include <QDir>
#include <QDesktopWidget>
/*
 *
 * QWidget {background-image: url(:/typewriter2.jpg) }\nPageEditor{border: 0px;}
 *
 * ***********************************************************************************/

using namespace std;

void initializeFonts ();
void initializeEditor (MainWindow * win);

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    initializeFonts();
    MainWindow w;
    initializeEditor(&w);
    w.typeWriter1();
    w.showFullScreen();
    return a.exec();
}

void initializeFonts () {
    QDir searchFontDir ("fontes");
    QStringList filterFonte ;
    filterFonte<< "*.ttf" << "*.TTF" << "*otf" << "*.OTF";
    QStringList fontesFiles = searchFontDir.entryList(filterFonte);
    QStringList::const_iterator iter;
    QFontDatabase::removeAllApplicationFonts();
    QFontDatabase dbFont;
    for (iter=fontesFiles.constBegin();iter!=fontesFiles.constEnd();iter++) {

        QString fonte = (*iter).toLocal8Bit().constData();
        dbFont.addApplicationFont("fontes/"+fonte);
    }
}

void initializeEditor (MainWindow * win) {
    PageEditor * editor = win->getUI()->editor;
    editor->setFont(QFont ("Special Elite",PageEditor::SIZE));
    editor->setStyleSheet("border: 0px;background:transparent");

}

#ifndef PAGEEDITOR_H
#define PAGEEDITOR_H
#include <QPlainTextEdit>
#include "mainwindow.h"
#include <iostream>


class PageEditor : public QPlainTextEdit {

    MainWindow* root;

    Q_OBJECT
    QString * file=NULL;
public:
    explicit PageEditor(QWidget *parent = 0) : PageEditor ("",parent) {}
    explicit PageEditor(const QString &text, QWidget *parent = 0) : QPlainTextEdit (text, parent){
        root=static_cast<MainWindow*>(this->parent()->parent());
        this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        this->setCursorWidth(3);
    }
    virtual ~PageEditor () { delete file;}
    static int SIZE;

public slots:
    void save ();
    void open ();
    void saveInFile (const QString & file);
    void openFile (const QString & file);
    void Font1 ();
    void Font2 ();
    void Font3 ();
    void Font4 ();
    void Font5 ();
    void Font6 ();
    void Font7 ();
    void Font8 ();
    void Font9 ();
    void Font0 ();

};

#endif // PAGEEDITOR_H

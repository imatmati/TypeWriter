#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <iostream>
#include <QFileDialog>
#include <QDesktopWidget>

using namespace std;

namespace Ui {
class MainWindow ;
}


class MainWindow : public QMainWindow
{
    Q_OBJECT

    Ui::MainWindow *ui;
    QFileDialog * fileChooser;
    QFileDialog * openFileChooser;
    void setFonts();
    const double wRatio =0.45;
    const double hRatio =0.52;
    const double wMoveRatio =0.27;
    const double hMoveRatio =0.08;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void setVisibilityFileChooser (bool visible) const { fileChooser->setVisible(visible);}
    void setVisibilityOpenFileChooser (bool visible) const { openFileChooser->setVisible(visible);}
    Ui::MainWindow * getUI () const {return ui;}

public slots:
    void typeWriter1 ();
    void typeWriter2 ();

};

#endif // MAINWINDOW_H

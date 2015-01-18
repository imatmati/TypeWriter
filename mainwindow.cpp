#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QShortcut>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->fileChooser = new QFileDialog (this);
    this->fileChooser-> setWindowModality(Qt::WindowModal);
    this->fileChooser-> setWindowTitle("Sauvegarde fichier");
    this->openFileChooser = new QFileDialog (this);
    this->openFileChooser-> setWindowModality(Qt::WindowModal);
    this->openFileChooser-> setWindowTitle("Ouverture fichier");
    //this->fileChooser->setOption(QFileDialog::DontUseNativeDialog);
    this->fileChooser->setVisible(false);
    this->openFileChooser->setVisible(false);
    new QShortcut (QKeySequence(Qt::CTRL + Qt::Key_Q), this, SLOT(close()));
    new QShortcut (QKeySequence(Qt::CTRL + Qt::Key_S), ui->editor, SLOT(save()));
    new QShortcut (QKeySequence(Qt::CTRL + Qt::Key_O), ui->editor, SLOT(open()));
    setFonts();
    QObject::connect (this->fileChooser,SIGNAL(fileSelected(const QString &)),ui->editor,SLOT(saveInFile(const QString &)));
    QObject::connect (this->openFileChooser,SIGNAL(fileSelected(const QString &)),ui->editor,SLOT(openFile(const QString &)));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setFonts()  {
    new QShortcut (QKeySequence(Qt::CTRL + Qt::Key_1), ui->editor, SLOT(Font1()));
    new QShortcut (QKeySequence(Qt::CTRL + Qt::Key_2), ui->editor, SLOT(Font2()));
    new QShortcut (QKeySequence(Qt::CTRL + Qt::Key_3), ui->editor, SLOT(Font3()));
    new QShortcut (QKeySequence(Qt::CTRL + Qt::Key_4), ui->editor, SLOT(Font4()));
    new QShortcut (QKeySequence(Qt::CTRL + Qt::Key_5), ui->editor, SLOT(Font5()));
    new QShortcut (QKeySequence(Qt::CTRL + Qt::Key_6), ui->editor, SLOT(Font6()));
    new QShortcut (QKeySequence(Qt::CTRL + Qt::Key_7), ui->editor, SLOT(Font7()));
    new QShortcut (QKeySequence(Qt::CTRL + Qt::Key_8), ui->editor, SLOT(Font8()));
    new QShortcut (QKeySequence(Qt::CTRL + Qt::Key_9), ui->editor, SLOT(Font9()));
    new QShortcut (QKeySequence(Qt::CTRL + Qt::Key_0), ui->editor, SLOT(Font0()));
    new QShortcut (QKeySequence(Qt::ALT + Qt::Key_1), this, SLOT(typeWriter1()));
    new QShortcut (QKeySequence(Qt::ALT + Qt::Key_2), this, SLOT(typeWriter2()));

}


void MainWindow::typeWriter1 () {

    QRect rec = QApplication::desktop()->screenGeometry();
    int height = rec.height();
    int width = rec.width();
    int newHeight=height*hRatio ;
    int newWidth=width*wRatio;

    this->getUI()->main->setStyleSheet("QWidget#main {border-image: url(:/underwood.png) 0 0 0 0  stretch stretch}");
    this->getUI()->editor->resize(newWidth,newHeight);
    this->getUI()->editor->move(width*wMoveRatio,height*hMoveRatio);
}

void MainWindow::typeWriter2 () {
    QRect rec = QApplication::desktop()->screenGeometry();
    int height = rec.height();
    int width = rec.width();
    int newHeight=height*hRatio ;
    int newWidth=width*wRatio;

    this->getUI()->main->setStyleSheet("QWidget#main {border-image: url(:/typewriter1.png) 0 0 0 0  stretch stretch}");
    this->getUI()->editor->resize(newWidth,newHeight);
    this->getUI()->editor->move(width*wMoveRatio,height*hMoveRatio);
}

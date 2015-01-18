#include "pageeditor.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <fstream>

using namespace std;


void PageEditor::save() {

    cout << "Sauvegarde" << endl;
    if (this->file == NULL) {
        root->setVisibilityFileChooser(true);
    }
    else  {
        saveInFile(*file);
    }
}


void PageEditor::open() {

    root->setVisibilityOpenFileChooser(true);

}

void PageEditor::saveInFile(const QString & file) {

    root->setVisibilityFileChooser(false);
    ofstream diskFile;
    diskFile.open(file.toStdString());
    diskFile << root->getUI()->editor->toPlainText().toStdString();
    diskFile.close();
    this->file = new QString (file);
}

void PageEditor::openFile (const QString & file) {
    QString text;
    string line;
    ifstream diskFile;
    diskFile.open(file.toStdString());
    while (getline (diskFile,  line )) {
        text.append (line.c_str());
        text.append('\n');
    }
    root->getUI()->editor->setPlainText(text);
    diskFile.close();
    this->file = new QString (file);
}

int PageEditor::SIZE = 18;

void PageEditor::Font1 () {
    this->setFont(QFont ("Special Elite",SIZE));
}

void PageEditor::Font2 () {
    this->setFont(QFont ("Another TypeWriter",SIZE));
}
void PageEditor::Font3 () {
    this->setFont(QFont ("Bohemian TypeWriter",SIZE));
}
void PageEditor::Font4 () {
    this->setFont(QFont ("USIS 1949",SIZE));
}
void PageEditor::Font5 () {
    this->setFont(QFont ("Incognitype",SIZE));
}

void PageEditor::Font6 () {
    this->setFont(QFont ("My Underwood",SIZE));
}
void PageEditor::Font7 () {
    this->setFont(QFont ("Triumph Tippa",SIZE));
}
void PageEditor::Font8 () {
    this->setFont(QFont ("Underwood1913",SIZE));
}

void PageEditor::Font9 () {
    this->setFont(QFont ("AFL Font nonmetric",SIZE));
}

void PageEditor::Font0 () {
    this->setFont(QFont ("fzm Old Typewriter",SIZE));
}

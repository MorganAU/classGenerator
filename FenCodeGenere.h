#ifndef FENCODEGENERE_H
#define FENCODEGENERE_H

#include <QApplication>
#include <QDialog>
#include <QBoxLayout>
#include <QTextEdit>

class FenCodeGenere : public QDialog
{
    Q_OBJECT

public:
    FenCodeGenere();
    ~FenCodeGenere();
    FenCodeGenere(QString code);

private:
    QDialog *m_fenetreCodeGenere;
    QVBoxLayout *m_codeGenere;
    QTextEdit *m_codeFinal;
    QPushButton *m_fermer;

};

#endif // FENCODEGENERE_H

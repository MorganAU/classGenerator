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

private:
    QDialog *m_fenetreCodeGenere;
    QVBoxLayout *m_codeGenere;
    QTextEdit *m_codeFinal;
};

#endif // FENCODEGENERE_H

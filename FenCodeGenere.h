#ifndef FENCODEGENERE_H
#define FENCODEGENERE_H

#include <QApplication>
#include <QTextEdit>
#include <QMessageBox>
#include <QVBoxLayout>

class FenCodeGenere : public QWidget
{
    Q_OBJECT

public:
    FenCodeGenere();
    ~FenCodeGenere();

private:
    QVBoxLayout *m_fenetre;
    QString *m_codeACopier;
    QTextEdit *m_codeGenere;

};

#endif // FENCODEGENERE_H

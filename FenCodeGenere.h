#ifndef FENCODEGENERE_H
#define FENCODEGENERE_H

#include <QApplication>
#include <QDialog>
#include <QBoxLayout>
#include <QTextEdit>
#include <QMessageBox>
#include <QTabWidget>

class FenCodeGenere : public QDialog
{
    Q_OBJECT

public:
    FenCodeGenere();
    ~FenCodeGenere();
    FenCodeGenere(QString &codeHeader, QString &codeCpp);

public slots:
    void accepter();

private:
    QDialog *m_fenetreCodeGenere;
    QVBoxLayout *m_codeGenere;
    QTextEdit *m_codeHeader;
    QTextEdit *m_codeCpp;
    QTabWidget *m_fichiers;
    QPushButton *m_fermer;

};

#endif // FENCODEGENERE_H

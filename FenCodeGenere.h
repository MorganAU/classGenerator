#ifndef FENCODEGENERE_H
#define FENCODEGENERE_H

#include <QApplication>
#include <QDialog>
#include <QBoxLayout>
#include <QTextEdit>
#include <QMessageBox>
#include <QTabWidget>
#include <QFileDialog>

class FenCodeGenere : public QDialog
{
    Q_OBJECT

public:
    FenCodeGenere();
    ~FenCodeGenere();
    FenCodeGenere(QString &codeHeader, QString &codeCpp, QString &nom, QWidget *parent);

public slots:
    void sauvegarder();

private:
    QString nomClasse;
    QDialog *m_fenetreCodeGenere;
    QVBoxLayout *m_codeGenere;
    QTextEdit *m_codeHeader;
    QTextEdit *m_codeCpp;
    QTabWidget *m_fichiers;
    QPushButton *m_fermer;
    QPushButton *m_sauvegarder;
    QHBoxLayout *m_layoutBoutons;

};

#endif // FENCODEGENERE_H

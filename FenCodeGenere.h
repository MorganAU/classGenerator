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
    QTextEdit *m_fenetre;
};

#endif // FENCODEGENERE_H

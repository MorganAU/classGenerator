#ifndef CREERATTRIBUTS_H
#define CREERATTRIBUTS_H

#include <QApplication>
#include <QListWidget>
#include <QPushButton>
#include <QLayout>
#include <QMainWindow>
#include <QGroupBox>
#include <QLineEdit>
#include <QComboBox>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

class FenetreTest : public QWidget
{
    Q_OBJECT

public:
    FenetreTest();
    ~FenetreTest();
    void lireClasses();

public slots:
    QString creer();
    void ajouter();
    void enlever();
    void supprimer();


private:
    QLineEdit *m_texteAAjouter;
    QListWidget *m_listeAttributsACreer;
    QListWidget * m_listeAttributsAAjouter;
    QListWidget *m_listeAccesseurAAjouter;
    QPushButton *m_creer;
    QPushButton *m_ajouter;
    QPushButton *m_enlever;
    QPushButton *m_supprimer;
    QPushButton *m_quitter;
    QVBoxLayout *m_layout;
    QHBoxLayout *m_layoutListe;
    QListWidgetItem *m_item;
    QListWidget *m_listeWidgets;



};

#endif // CREERATTRIBUTS_H

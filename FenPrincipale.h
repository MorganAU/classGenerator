#ifndef FENPRINCIPALE_H
#define FENPRINCIPALE_H

#include "FenCodeGenere.h"
#include <QApplication>
#include <QLineEdit>
#include <QFormLayout>
#include <QGroupBox>
#include <QCheckBox>
#include <QTextEdit>
#include <QPushButton>
#include <QDialog>
#include <QDateEdit>
#include <QMessageBox>

class FenPrincipale : public QWidget
{
    Q_OBJECT

public:
    FenPrincipale();
    ~FenPrincipale();
    QString genererCode();

public slots:
    void montrerCodeGenere();
    void valideOuPas();

private:
    //Définition de la classe à créer
    QGroupBox *m_defClasse;
    QFormLayout *m_infosClasse;
    QLineEdit *m_nomClasse;
    QLineEdit *m_classeMere;

    //Options pouvant être choisis
    QGroupBox *m_options;
    QVBoxLayout *m_listeOptions;
    QCheckBox *m_protectHeader;
    QCheckBox *m_constructeur;
    QCheckBox *m_destructeur;

    //Commentaires à ajouter
    QCheckBox *m_confComm;
    QGroupBox *m_commentaires;
    QFormLayout *m_listeCommentaires;
    QLineEdit *m_auteur;
    QDateEdit *m_creation;
    QTextEdit *m_role;

    //Boutons
    QHBoxLayout *m_boutons;
    QPushButton *m_generer;
    QPushButton *m_quitter;

    //LayoutPrincipale
    QVBoxLayout *m_layoutPrincipale;

};

#endif // FENPRINCIPALE_H

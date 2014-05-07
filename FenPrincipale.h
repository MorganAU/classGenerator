#ifndef FENPRINCIPALE_H
#define FENPRINCIPALE_H

#include "FenCodeGenere.h"
#include <QLineEdit>
#include <QFormLayout>
#include <QGroupBox>
#include <QCheckBox>
#include <QPushButton>
#include <QDateEdit>
#include <QComboBox>

class FenPrincipale : public QWidget
{
    Q_OBJECT

public:
    FenPrincipale();
    ~FenPrincipale();
    QString genererCodeH();
    QString genererCodeCpp();
    QString licenceGPL();

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
    QGroupBox *m_commentaires;
    QFormLayout *m_listeCommentaires;
    QLineEdit *m_Auteur;
    QDateEdit *m_creation;
    QTextEdit *m_role;

    //Choix d'une licence
    QGroupBox *m_licence;
    QFormLayout *m_optionsLicence;
    QLineEdit *m_nomAuteur;
    QLineEdit *m_prenomAuteur;
    QComboBox *m_listeLicence;

    //Boutons
    QHBoxLayout *m_boutons;
    QPushButton *m_generer;
    QPushButton *m_quitter;

    //LayoutPrincipale
    QVBoxLayout *m_layoutPrincipale;


};

#endif // FENPRINCIPALE_H

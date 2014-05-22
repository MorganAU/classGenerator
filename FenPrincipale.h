#ifndef FENPRINCIPALE_H
#define FENPRINCIPALE_H

#include "FenCodeGenere.h"
#include <QApplication>
#include <QLineEdit>
#include <QFormLayout>
#include <QGroupBox>
#include <QCheckBox>
#include <QPushButton>
#include <QDateEdit>
#include <QComboBox>
#include <QListWidget>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

class FenPrincipale : public QWidget
{
    Q_OBJECT

public:
    FenPrincipale();
    ~FenPrincipale();
    QString genererCodeH();
    QString genererCodeCpp();
    QString licenceGPL();
    QString licenceLGPL();
    QString licenceChoisi();
    QString header();
    void lireClasses();

public slots:
    void montrerCodeGenere();
    void valideOuPas();
    void headerCacheOuPas();
    void attributsCacheOuPas();
    void genererHeader();
    void creerAttributs(QListWidgetItem *item);
    void ajouter();
    void supprimer();
    void toutSupprimer();
    void rechercher();

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
    QCheckBox *m_ifndef;
    QCheckBox *m_define;
    QCheckBox *m_endif;
    QLineEdit *m_header;
    QCheckBox *m_constructeur;
    QCheckBox *m_destructeur;
    QCheckBox *m_attributs;
        //Pour les attributs
    QHBoxLayout *m_parametreAttribut;
    QLineEdit *m_classeAttributs;
    QLineEdit *m_nomVariableAttributs;
    QListWidget *m_listeWidgets;
    QLineEdit *m_rechercher;
    QPushButton *m_ajouter;
    QListWidget *m_attributsAAjouter;
    QHBoxLayout *m_boutonsAttributs;
    QPushButton *m_supprimer;
    QPushButton *m_toutSuppr;

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

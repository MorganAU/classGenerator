#include "FenPrincipale.h"


FenPrincipale::FenPrincipale() : QWidget()
{


    //Définition de la classe
    m_defClasse = new QGroupBox(QString::fromUtf8("Définition de la classe"));
    m_infosClasse = new QFormLayout(m_defClasse);
    m_nomClasse = new QLineEdit();
    m_classeMere = new QLineEdit();
    m_infosClasse->addRow("&Nom :", m_nomClasse);
    m_infosClasse->addRow(QString::fromUtf8("Classe &mère :"), m_classeMere);

    //Options
    m_options = new QGroupBox("Options");
    m_listeOptions = new QVBoxLayout(m_options);
    m_protectHeader = new QCheckBox(QString::fromUtf8("Protéger le &header contre les inclusions multiples"));
    m_constructeur = new QCheckBox(QString::fromUtf8("Générer un &constructeur par défaut"));
    m_destructeur = new QCheckBox(QString::fromUtf8("Générer un &destructeur"));
    m_listeOptions->addWidget(m_protectHeader);
    m_listeOptions->addWidget(m_constructeur);
    m_listeOptions->addWidget(m_destructeur);

    //Commentaires
    m_commentaires = new QGroupBox("Ajouter des commentaires");
    m_commentaires->setCheckable(true);
    m_commentaires->setChecked(false);
    m_listeCommentaires = new QFormLayout(m_commentaires);
    m_auteur = new QLineEdit();
    m_creation = new QLineEdit();
    m_role = new QTextEdit();
    m_listeCommentaires->addRow("&Auteur", m_auteur);
    m_listeCommentaires->addRow(QString::fromUtf8("Da&te de création"), m_creation);
    m_listeCommentaires->addRow(QString::fromUtf8("&Rôle de la classe"), m_role);

    //Boutons
    m_boutons = new QHBoxLayout();
    m_generer = new QPushButton(QString::fromUtf8("Générer !"));
    m_quitter = new QPushButton("Quitter");
    m_boutons->addWidget(m_generer);
    m_boutons->addWidget(m_quitter);

    //Regroupement
    m_layoutPrincipale = new QVBoxLayout(this);
    m_layoutPrincipale->addWidget(m_defClasse);
    m_layoutPrincipale->addWidget(m_options);
    m_layoutPrincipale->addWidget(m_commentaires);
    m_layoutPrincipale->addLayout(m_boutons);

    //Paramétrage des boutons
    QObject::connect(m_quitter, SIGNAL(clicked()), qApp, SLOT(quit()));
    QObject::connect(m_generer, SIGNAL(clicked()), this, SLOT(montrerCodeGenere()));

}

FenPrincipale::~FenPrincipale()
{}

void FenPrincipale::montrerCodeGenere()
{
    FenCodeGenere fenetre;
}




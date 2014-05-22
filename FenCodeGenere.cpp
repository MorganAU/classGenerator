#include "FenCodeGenere.h"
#include "FenPrincipale.h"

FenCodeGenere::FenCodeGenere() : QDialog()
{}

FenCodeGenere::~FenCodeGenere()
{}

FenCodeGenere::FenCodeGenere(QString &codeHeader, QString &codeCpp, QString &nom, QWidget *parent = 0) : QDialog(parent)
{
     nomClasse = nom;
    //Création de la seconde fenêtre
    m_fenetreCodeGenere = new QDialog();
    m_fenetreCodeGenere->setModal(true);
    setGeometry(600, 600, 600, 600);
    m_codeGenere = new QVBoxLayout(this);
    m_fichiers = new QTabWidget();

    //Fichier .h
    m_codeHeader = new QTextEdit(m_fichiers);
    m_codeHeader->setTabStopWidth(25);
    m_codeHeader->setFont(QFont("Courier"));
    m_codeHeader->setReadOnly(true);
    m_codeHeader->setPlainText(codeHeader);

    //Fichier .cpp
    m_codeCpp = new QTextEdit(m_fichiers);
    m_codeCpp->setTabStopWidth(25);
    m_codeCpp->setFont(QFont("Courier"));
    m_codeCpp->setReadOnly(true);
    m_codeCpp->setPlainText(codeCpp);

    //Bouton
    m_layoutBoutons = new QHBoxLayout();
    m_fermer = new QPushButton("Fermer");
    m_sauvegarder = new QPushButton("Sauvegarder");
    m_layoutBoutons->addWidget(m_sauvegarder);
    m_layoutBoutons->addWidget(m_fermer);

    //Layouts
    m_codeGenere->addWidget(m_fichiers);
    m_codeGenere->addLayout(m_layoutBoutons);

    m_fichiers->addTab(m_codeHeader, nom + ".h");
    m_fichiers->addTab(m_codeCpp, nom + ".cpp");

    //Connection bouton
    connect(m_sauvegarder, SIGNAL(clicked()), this, SLOT(sauvegarder()));
    connect(m_fermer, SIGNAL(clicked()), this, SLOT(accept()));

}

void FenCodeGenere::sauvegarder()
{
    QString fichier = QFileDialog::getSaveFileName(this, "Enregistrer", nomClasse, "Tout");

    if (!fichier.isEmpty())
        {
        //Enregistrement
            /* .h */
            QFile sauvegardeH(fichier + ".h");
            if (sauvegardeH.open(QFile::WriteOnly))
            {
                QTextStream out(&sauvegardeH);
                out << m_codeHeader->toPlainText();
            }
            /* .cpp */
            QFile sauvegardeCpp(fichier + ".cpp");
            if (sauvegardeCpp.open(QFile::WriteOnly))
            {
                QTextStream out(&sauvegardeCpp);
                out << m_codeCpp->toPlainText();
            }
        }
}


#include "FenCodeGenere.h"
#include "FenPrincipale.h"

FenCodeGenere::FenCodeGenere() : QDialog()
{}

FenCodeGenere::~FenCodeGenere()
{}

FenCodeGenere::FenCodeGenere(QString &codeHeader, QString &codeCpp)
{
    //Création de la seconde fenêtre
    m_fenetreCodeGenere = new QDialog();
    m_fenetreCodeGenere->setModal(true);
    m_fenetreCodeGenere->setGeometry(600, 600, 600, 600);
    m_codeGenere = new QVBoxLayout(m_fenetreCodeGenere);
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
    m_fermer = new QPushButton("Fermer");

    //Layouts
    m_codeGenere->addWidget(m_fichiers);
    m_codeGenere->addWidget(m_fermer);

    m_fichiers->addTab(m_codeHeader, "Fichier .h");
    m_fichiers->addTab(m_codeCpp, "Fichier .cpp");

    //Connection bouton
    QObject::connect(m_fermer, SIGNAL(clicked()), this, SLOT(accepter()));
    m_fenetreCodeGenere->exec();
}

void FenCodeGenere::accepter()
{
    int reponse = emit QMessageBox::question(this, "Valider le code", QString::fromUtf8("Est-ce que ce code vous convient ?"), QMessageBox::Yes, QMessageBox::Cancel);

    if(reponse == QMessageBox::Yes)
    {
        QMessageBox::information(this, "Copie du code", QString::fromUtf8("Vous pouvez sélectionner le code. Après sélection, appuyer sur CTRL+C pour le copier et ensuite CTRL+V pour le coller."));
    }
}


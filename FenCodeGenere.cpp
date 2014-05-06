#include "FenCodeGenere.h"
#include "FenPrincipale.h"

FenCodeGenere::FenCodeGenere() : QDialog()
{}

FenCodeGenere::~FenCodeGenere()
{}

FenCodeGenere::FenCodeGenere(QString code)
{
    //Création de la seconde fenêtre
    m_fenetreCodeGenere = new QDialog();
    m_fenetreCodeGenere->setModal(true);
    m_codeGenere = new QVBoxLayout(m_fenetreCodeGenere);
    m_codeFinal = new QTextEdit();
    m_codeFinal->setTabStopWidth(25);
    m_codeFinal->setFont(QFont("Courier"));
    m_codeFinal->setReadOnly(true);
    m_codeFinal->setPlainText(code);
    m_fermer = new QPushButton("Fermer");

    //Layouts
    m_codeGenere->addWidget(m_codeFinal);
    m_codeGenere->addWidget(m_fermer);

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


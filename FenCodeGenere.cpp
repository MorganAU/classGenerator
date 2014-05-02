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
    m_codeFinal->setPlainText(code);
    m_fermer = new QPushButton("Fermer");

    //Layouts
    m_codeGenere->addWidget(m_codeFinal);
    m_codeGenere->addWidget(m_fermer);

    //Connection bouton
    m_fenetreCodeGenere->exec();
}


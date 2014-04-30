#include "FenCodeGenere.h"
#include "FenPrincipale.h"

FenCodeGenere::FenCodeGenere() : QDialog()
{
    //Création de la seconde fenêtre
    m_fenetreCodeGenere = new QDialog();
    m_codeGenere = new QVBoxLayout(m_fenetreCodeGenere);
    m_codeFinal = new QTextEdit();

    //Layouts
    m_codeGenere->addWidget(m_codeFinal);


    m_fenetreCodeGenere->show();
}

FenCodeGenere::~FenCodeGenere()
{}


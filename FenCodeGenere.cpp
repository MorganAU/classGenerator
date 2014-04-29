#include "FenCodeGenere.h"

FenCodeGenere::FenCodeGenere() : QWidget()
{
    m_fenetre = new QTextEdit("Données à rentrer");

    m_fenetre->setReadOnly(true);
    m_fenetre->show();
}

FenCodeGenere::~FenCodeGenere()
{}


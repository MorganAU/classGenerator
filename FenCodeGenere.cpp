#include "FenCodeGenere.h"

FenCodeGenere::FenCodeGenere() : QWidget()
{
    m_fenetre = new QVBoxLayout();
    m_codeACopier = new QString();
    m_codeGenere = new QTextEdit();
    m_codeGenere->setReadOnly(true);

    m_fenetre->addWidget("", m_codeACopier);
    m_fenetre->addWidget(m_codeGenere);
    m_fenetre->show();
}

FenCodeGenere::~FenCodeGenere()
{}


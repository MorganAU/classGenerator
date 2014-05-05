#include "FenPrincipale.h"
#include <string>


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
    m_constructeur->setChecked(false);
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
    m_creation = new QDateEdit(QDate::currentDate());
    m_creation->setMaximumDate(QDate::currentDate());
    m_creation->setMinimumDate(QDate::currentDate());
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
    QObject::connect(m_generer, SIGNAL(clicked()), this, SLOT(valideOuPas()));


    //QObject::connect(m_generer, SIGNAL(clicked()), this, SLOT(messageErreur()));
    QObject::connect(m_quitter, SIGNAL(clicked()), qApp, SLOT(quit()));
}

FenPrincipale::~FenPrincipale()
{}

QString FenPrincipale::genererCode()
{
    QString code;

    QString commentaires;
    commentaires = m_role->toPlainText();

    QString nomClasse;
    nomClasse = m_nomClasse->text();

    if(m_commentaires->isChecked() == true)
    {
        code = QString::fromAscii("/*") + '\n';

        if(m_auteur->text() != "")
        {
            code += "Auteur : " + m_auteur->text() + '\n';
        }
        code += QString::fromUtf8("Date de création : ") + m_creation->text() + '\n';
        code += '\n';

        if(commentaires != "")
        {
            code += commentaires + '\n';
        }
        code += QString::fromAscii("*/") + '\n' + '\n' + '\n' + '\n';
    }

    if(m_protectHeader->isChecked() == true)
    {
        code += "#ifndef " + nomClasse.toUpper() + "_H" + '\n';
        code += "#define " + nomClasse.toUpper() + "_H" + '\n' + '\n' + '\n';
    }
    code += "class " + m_nomClasse->text();

    QString classeMere;
    classeMere = m_classeMere->text();

    if(classeMere.isEmpty() == false)
    {
        code += " : public " + m_classeMere->text() + '\n';
    }
    else
    {
        code += '\n';
    }
    code += QString::fromAscii("{") + '\n';

    if(m_constructeur->isChecked() == true)
    {
        code += QString::fromAscii("public:") + '\n';

        if(m_destructeur->isChecked() == true)
        {
            code += '\t' + m_nomClasse->text() + "();" + '\n';
            code += '\t' + QString::fromAscii("~") + m_nomClasse->text() + "();" + '\n' + '\n';
        }
        else
        {
            code += '\t' + m_nomClasse->text() + "();" + '\n' + '\n' + '\n';
        }
    }
    else if(m_destructeur->isChecked() == true)
    {
        code += QString::fromAscii("public:") + '\n' + '\n';
        code += '\t' + QString::fromAscii("~") + m_nomClasse->text() + "();" + '\n' + '\n';
    }
    else
    {
        code += QString::fromAscii("public:") + '\n' + '\n' + '\n' + '\n';
    }
    code += QString::fromAscii("protected:") + '\n' + '\n' + '\n' + '\n';
    code += QString::fromAscii("private:") + '\n' + '\n' + '\n' + '\n';
    code += QString::fromAscii("};") + '\n' + '\n';

    if(m_protectHeader->isChecked() == true)
    {
        code += QString::fromAscii("#endif // ") + nomClasse.toUpper() + "_H";
    }

    return code;
}

void FenPrincipale::montrerCodeGenere()
{
    QString codeAGenerer = genererCode();
    FenCodeGenere fenetre(codeAGenerer);
}

void FenPrincipale::valideOuPas()
{
    QString nomDeLaClasse;
    nomDeLaClasse = m_nomClasse->text();

    QString nomClasseMere;
    nomClasseMere = m_classeMere->text();

    if(nomDeLaClasse.isEmpty() == false)
    {
        emit montrerCodeGenere();
    }
    else
    {
        emit QMessageBox::critical(this, "Erreur !!!", "Veuillez entrer le nom de la classe !!!");
    }
}

#include "FenPrincipale.h"
#include "FenCodeGenere.h"


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
    m_constructeur->setChecked(true);
    m_destructeur = new QCheckBox(QString::fromUtf8("Générer un &destructeur"));
    m_listeOptions->addWidget(m_protectHeader);
    m_listeOptions->addWidget(m_constructeur);
    m_listeOptions->addWidget(m_destructeur);

    //Commentaires
    m_commentaires = new QGroupBox("Ajouter des commentaires");
    m_commentaires->setCheckable(true);
    m_commentaires->setChecked(false);
    m_listeCommentaires = new QFormLayout(m_commentaires);
    m_Auteur = new QLineEdit();
    m_creation = new QDateEdit(QDate::currentDate());
    m_creation->setMaximumDate(QDate::currentDate());
    m_creation->setMinimumDate(QDate::currentDate());
    m_role = new QTextEdit();
    m_listeCommentaires->addRow("&Auteur", m_Auteur);
    m_listeCommentaires->addRow(QString::fromUtf8("Da&te de création"), m_creation);
    m_listeCommentaires->addRow(QString::fromUtf8("&Rôle de la classe"), m_role);

    //Licences
    m_licence = new QGroupBox("Ajouter une licence libre");
    m_licence->setCheckable(true);
    m_licence->setChecked(false);
    m_optionsLicence = new QFormLayout(m_licence);
    m_nomAuteur = new QLineEdit();
    m_prenomAuteur = new QLineEdit();
    m_listeLicence = new QComboBox();
    m_optionsLicence->addRow("&Votre nom", m_nomAuteur);
    m_optionsLicence->addRow(QString::fromUtf8("Votre &prénom"), m_prenomAuteur);
    m_optionsLicence->addRow("Choix de votre licence libre", m_listeLicence);

    //Liste des licences disponibles
    m_listeLicence->addItem("GPL");

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
    m_layoutPrincipale->addWidget(m_licence);
    m_layoutPrincipale->addLayout(m_boutons);


    //Paramétrage des boutons
    QObject::connect(m_generer, SIGNAL(clicked()), this, SLOT(valideOuPas()));
    QObject::connect(m_quitter, SIGNAL(clicked()), qApp, SLOT(quit()));
}

FenPrincipale::~FenPrincipale()
{}

QString FenPrincipale::genererCodeH()
{    
   //Fichier .h
    QString codeH;
    QString commentaires = m_role->toPlainText();
    QString nomClasse = m_nomClasse->text();

    if(m_commentaires->isChecked() == true)
    {
        codeH += QString::fromAscii("/*") + '\n';

        if(m_Auteur->text() != "")
        {
            codeH += "Auteur : " + m_Auteur->text() + '\n';
        }
        codeH += QString::fromUtf8("Date de création : ") + m_creation->text() + '\n';
        codeH += '\n';

        if(commentaires != "")
        {
            codeH += commentaires + '\n';
        }
        codeH += QString::fromAscii("*/") + '\n' + '\n' + '\n' + '\n';
    }

    if(m_protectHeader->isChecked() == true)
    {
        codeH += "#ifndef " + nomClasse.toUpper() + "_H" + '\n';
        codeH += "#define " + nomClasse.toUpper() + "_H" + '\n' + '\n' + '\n';
    }
    codeH += "class " + m_nomClasse->text();

    QString classeMere = m_classeMere->text();

    if(classeMere.isEmpty() == false)
    {
        codeH += " : public " + m_classeMere->text() + '\n';
    }
    else
    {
        codeH += '\n';
    }
    codeH += QString::fromAscii("{") + '\n';

    if(m_constructeur->isChecked() == true)
    {
        codeH += QString::fromAscii("public:") + '\n';

        if(m_destructeur->isChecked() == true)
        {
            codeH += '\t' + m_nomClasse->text() + "();" + '\n';
            codeH += '\t' + QString::fromAscii("~") + m_nomClasse->text() + "();" + '\n' + '\n';
        }
        else
        {
            codeH += '\t' + m_nomClasse->text() + "();" + '\n' + '\n' + '\n';
        }
    }
    else if(m_destructeur->isChecked() == true)
    {
        codeH += QString::fromAscii("public:") + '\n' + '\n';
        codeH += '\t' + QString::fromAscii("~") + m_nomClasse->text() + "();" + '\n' + '\n';
    }
    else
    {
        codeH += QString::fromAscii("public:") + '\n' + '\n' + '\n' + '\n';
    }
    codeH += QString::fromAscii("protected:") + '\n' + '\n' + '\n' + '\n';
    codeH += QString::fromAscii("private:") + '\n' + '\n' + '\n' + '\n';
    codeH += QString::fromAscii("};") + '\n' + '\n';

    if(m_protectHeader->isChecked() == true)
    {
        codeH += QString::fromAscii("#endif // ") + nomClasse.toUpper() + "_H";
    }

    return codeH;
}

QString FenPrincipale::genererCodeCpp()
{
    //Fichier .cpp
    QString codeCpp;

    if(m_licence->isChecked() == true)
    {
        QDateTime a = m_creation->dateTime();
        QString date = a.toString("yyyy");

        codeCpp += QString::fromAscii("/*") + '\n';
        codeCpp += "Copyright (C) " + date + " " + m_nomAuteur->text() + " " + m_prenomAuteur->text() + '\n' + '\n';
        codeCpp += licenceGPL() + '\n' + QString::fromAscii("*/") + '\n' + '\n';
    }

    codeCpp += "#include \"" + m_nomClasse->text() + "\"" + '\n' + '\n' + '\n';

    if(m_constructeur->isChecked() == true)
    {
        codeCpp += m_nomClasse->text() + QString::fromAscii("::") + m_nomClasse->text() + "()";

        QString classeMere = m_classeMere->text();

        if(classeMere.isEmpty() == false)
        {
            codeCpp += " : " + m_classeMere->text() + "()" + '\n';
        }
        else
        {
            codeCpp += '\n';
        }

        codeCpp += QString::fromAscii("{")  + '\n' + '\n' + QString::fromAscii("}") +  + '\n' + '\n';

        if(m_destructeur->isChecked() == true)
        {
            codeCpp += m_nomClasse->text() + QString::fromAscii("::~") + m_nomClasse->text() + '\n';
            codeCpp += QString::fromAscii("{")  + '\n' + '\n' + QString::fromAscii("}") + '\n' + '\n';
        }
    }
    else if(m_destructeur->isChecked() == true)
    {
        codeCpp += m_nomClasse->text() + QString::fromAscii("::~") + m_nomClasse->text() + '\n';
        codeCpp += QString::fromAscii("{")  + '\n' + '\n' + QString::fromAscii("}") + '\n' + '\n';
    }

    return codeCpp;
}

void FenPrincipale::montrerCodeGenere()
{
    QString codeH = genererCodeH();
    QString codeCpp = genererCodeCpp();
    FenCodeGenere fenetre(codeH, codeCpp);
}

void FenPrincipale::valideOuPas()
{
    QString nomDeLaClasse = m_nomClasse->text();
    QString nomAuteur = m_nomAuteur->text();
    QString prenomAuteur = m_prenomAuteur->text();

    if(nomDeLaClasse.isEmpty() == false)
    {
        if(m_licence->isChecked() == true)
        {
            if(nomAuteur.isEmpty() == true || prenomAuteur.isEmpty() == true)
            {
                emit QMessageBox::critical(this, "Erreur !!!", QString::fromUtf8("Si vous choississez une licence, vous devez entrer votre nom et votre prénom !!! "));
            }
            else
            {
                emit montrerCodeGenere();
            }
        }
        else
        {
            emit montrerCodeGenere();
        }
    }
    else
    {
        emit QMessageBox::critical(this, "Erreur !!!", "Veuillez entrer le nom de la classe !!!");
    }
}

QString FenPrincipale::licenceGPL()
{
    QString licence;
    licence += "This program is free software; you can redistribute it and/or modify ";
    licence += " it under the terms of the GNU General Public License as published by ";
    licence += " the Free Software Foundation; either version 2 of the License, or ";
    licence += " (at your option) any later version." + '\n' + '\n';

    licence += "This program is distributed in the hope that it will be useful, ";
    licence += " but WITHOUT ANY WARRANTY; without even the implied warranty of ";
    licence += " MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the ";
    licence += " GNU General Public License for more details." + '\n' + '\n';

    licence += "You should have received a copy of the GNU General Public License along ";
    licence += " with this program; if not, write to the Free Software Foundation, Inc., ";
    licence += " 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA." + '\n' + '\n';

    return licence;
}

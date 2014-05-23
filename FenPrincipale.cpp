#include "FenPrincipale.h"
#include "FenCodeGenere.h"


FenPrincipale::FenPrincipale() : QWidget()
{
    setGeometry(800, 800, 800, 1000);

    //Définition de la classe
    m_defClasse = new QGroupBox(QString::fromUtf8("Définition de la classe"), this);
    m_infosClasse = new QFormLayout(m_defClasse);
    m_nomClasse = new QLineEdit("Ex_emple");
    m_classeMere = new QLineEdit("Ex_emple");
    m_infosClasse->addRow("&Nom :", m_nomClasse);
    m_infosClasse->addRow(QString::fromUtf8("Classe &mère :"), m_classeMere);

    //Options
    m_options = new QGroupBox("Options");
    m_listeOptions = new QVBoxLayout(m_options);
    m_protectHeader = new QCheckBox(QString::fromUtf8("Protéger le &header contre les inclusions multiples"));
    m_header = new QLineEdit();
    m_header->hide();
    m_ifndef = new QCheckBox("Inclure #i&fndef");
    m_ifndef->hide();
    m_define = new QCheckBox("Inclure #&define");
    m_define->hide();
    m_endif = new QCheckBox("Inclure #&endif");
    m_endif->hide();
    m_constructeur = new QCheckBox(QString::fromUtf8("Générer un &constructeur par défaut"));
    m_constructeur->setChecked(true);
    m_destructeur = new QCheckBox(QString::fromUtf8("Générer un &destructeur"));

    //Pour ajouter des attributs
    m_attributs = new QCheckBox("Ajouter des attributs");
    m_rechercher = new QLineEdit("Rechercher");
    m_rechercher->hide();
    m_parametreAttribut = new QHBoxLayout;
    m_classeAttributs = new QLineEdit();
    m_classeAttributs->setReadOnly(true);
    m_classeAttributs->hide();
    m_nomVariableAttributs = new QLineEdit("*m_Ex_emple");
    m_nomVariableAttributs->hide();
    m_parametreAttribut->addWidget(m_classeAttributs);
    m_parametreAttribut->addWidget(m_nomVariableAttributs);
    m_ajouter = new QPushButton("Ajouter");
    m_ajouter->hide();
    m_listeWidgets = new QListWidget(this);
    m_listeWidgets->hide();
    m_listeWidgets->takeItem(831);
    m_attributsAAjouter = new QListWidget();
    m_attributsAAjouter->hide();
    m_boutonsAttributs = new QHBoxLayout();
    m_supprimer = new QPushButton("Supprimer");
    m_supprimer->hide();
    m_toutSuppr = new QPushButton("Tout supprimer");
    m_toutSuppr->hide();
    m_boutonsAttributs->addWidget(m_supprimer);
    m_boutonsAttributs->addWidget(m_toutSuppr);

    m_listeOptions->addWidget(m_protectHeader);
    m_listeOptions->addWidget(m_header);
    m_listeOptions->addWidget(m_ifndef);
    m_listeOptions->addWidget(m_define);
    m_listeOptions->addWidget(m_endif);
    m_listeOptions->addWidget(m_constructeur);
    m_listeOptions->addWidget(m_destructeur);
    m_listeOptions->addWidget(m_attributs);
    m_listeOptions->addWidget(m_listeWidgets);
    m_listeOptions->addWidget(m_rechercher);
    m_listeOptions->addLayout(m_parametreAttribut);
    m_listeOptions->addWidget(m_ajouter);
    m_listeOptions->addWidget(m_attributsAAjouter);
    m_listeOptions->addLayout(m_boutonsAttributs);

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
    m_listeLicence->addItem("LGPL");

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

    //Règles de caractères
    QRegExp rx("^[A-Z]+[A-Za-z_]+$");
    QValidator *validatorClasse = new QRegExpValidator(rx, this);
    m_classeMere->setValidator(validatorClasse);
    m_nomClasse->setValidator(validatorClasse);

    QRegExp rxAuteur("^[A-Za-z]+$");
    QValidator *validatorAuteur = new QRegExpValidator(rxAuteur, this);
    m_nomAuteur->setValidator(validatorAuteur);
    m_prenomAuteur->setValidator(validatorAuteur);

    QRegExp rxAttribut("^[*m_]+[a-z]+[A-Z]+$");
    QValidator *validatorAttribut = new QRegExpValidator(rxAttribut, this);
    m_nomVariableAttributs->setValidator(validatorAttribut);

    //Connections signaux et slots
    connect(m_generer, SIGNAL(clicked()), this, SLOT(valideOuPas()));
    connect(m_quitter, SIGNAL(clicked()), qApp, SLOT(quit()));
    connect(m_protectHeader, SIGNAL(stateChanged(int)), this, SLOT(headerCacheOuPas()));
    connect(m_attributs, SIGNAL(stateChanged(int)), this, SLOT(attributsCacheOuPas()));
    connect(m_nomClasse, SIGNAL(textChanged(QString)), this, SLOT(genererHeader()));
    connect(m_listeWidgets, SIGNAL(itemActivated(QListWidgetItem*)), this, SLOT(creerAttributs(QListWidgetItem*)));
    connect(m_ajouter, SIGNAL(clicked()), this, SLOT(ajouter()));
    connect(m_supprimer, SIGNAL(clicked()), this, SLOT(supprimer()));
    connect(m_toutSuppr, SIGNAL(clicked()), this, SLOT(toutSupprimer()));
    connect(m_rechercher, SIGNAL(textChanged(QString)), this, SLOT(rechercher()));
}

FenPrincipale::~FenPrincipale()
{}

QString FenPrincipale::genererCodeH()
{    
   //Fichier .h
    QString codeH;
    QString commentaires = m_role->toPlainText();

    QString header = m_header->text();

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
        if(m_ifndef->isChecked() == true)
        {
            if(m_define->isChecked() == true)
            {
                codeH += "#ifndef " + header.toUpper() + '\n';
                codeH += "#define " + header.toUpper() + '\n' + '\n' + '\n';
            }
            else
            {
                codeH += "#ifndef " + header.toUpper()  + '\n' + '\n' + '\n' + '\n';
            }
        }
        else if(m_define->isChecked() == true)
        {
            codeH += "#define " + header.toUpper() + '\n' + '\n' + '\n' + '\n';
        }
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

    if(m_attributs->isChecked() == true)
    {
        codeH += QString::fromAscii("private:") + '\n';
        QString item;
        int a = m_attributsAAjouter->count();
        for(int i = 0; i < a; i++)
        {
            item = m_attributsAAjouter->item(i)->text();
            codeH += '\t' + item + '\n';
        }
    }
    else
    {
        codeH += QString::fromAscii("private:") + '\n' + '\n' + '\n' + '\n';
    }
    codeH += QString::fromAscii("};") + '\n' + '\n';

    if(m_protectHeader->isChecked() == true)
    {
        if(m_endif->isChecked() == true)
        {
            codeH += QString::fromAscii("#endif // ") + header.toUpper();
        }
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
        codeCpp += licenceChoisi() + '\n' + QString::fromAscii("*/") + '\n' + '\n';
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

//Ouverture du fichier contenant les classes de Qt
void FenPrincipale::lireClasses()
{
    QString fileName = "/home/nouvalinux/Programmations/Qt/Tp Zero class Generator/classes.txt";
    QFile fichier(fileName);
    if(fichier.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream in(&fichier);
        QString classes;
        while(! in.atEnd())
        {
            classes = in.readLine();
            m_listeWidgets->addItem(classes);
        }
    }
    else
    {
        QMessageBox::critical(this, "Erreur", QString::fromUtf8("Le fichier contenant la liste des classes n'a pas pu être ouvert !!!"));
    }
    fichier.close();

}

void FenPrincipale::creerAttributs(QListWidgetItem *item)
{
    m_classeAttributs->setText(item->text());
}

//Licences
QString FenPrincipale::licenceGPL()
{
    QString licence;
    licence += "This program is free software; you can redistribute it and/or modify";
    licence += " it under the terms of the GNU General Public License as published by";
    licence += " the Free Software Foundation; either version 2 of the License, or";
    licence += " (at your option) any later version." + '\n' + '\n';

    licence += "This program is distributed in the hope that it will be useful,";
    licence += " but WITHOUT ANY WARRANTY; without even the implied warranty of";
    licence += " MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the";
    licence += " GNU General Public License for more details." + '\n' + '\n';

    licence += "You should have received a copy of the GNU General Public License along";
    licence += " with this program; if not, write to the Free Software Foundation, Inc.,";
    licence += " 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA." + '\n' + '\n';

    return licence;
}

QString FenPrincipale::licenceLGPL()
{
    QString licence;
    licence += "This program is free software; you can redistribute it and/or";
    licence += " modify it under the terms of the GNU Lesser General Public";
    licence += " License as published by the Free Software Foundation; either";
    licence += " version 2.1 of the License, or (at your option) any later version." + '\n' + '\n';

    licence += "This program is distributed in the hope that it will be useful,";
    licence += " but WITHOUT ANY WARRANTY; without even the implied warranty of";
    licence += " MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU";
    licence += " Lesser General Public License for more details." + '\n' + '\n';

    licence += "You should have received a copy of the GNU Lesser General Public";
    licence += " License along with this program; if not, write to the Free Software";
    licence += " Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA" + '\n' + '\n';

    return licence;
}


QString FenPrincipale::licenceChoisi()
{
    QString licence;

    if(m_nomAuteur->text().isEmpty() == true || m_prenomAuteur->text().isEmpty() == true)
    {
    emit QMessageBox::critical(this, "Erreur !!!", QString::fromUtf8("Pour choisir une licence, vous devez entrer votre nom et votre prénom !!! "));
    }
    else
    {
        if(m_listeLicence->currentIndex() == 0)
        {
            licence = licenceGPL();
        }
        else if(m_listeLicence->currentIndex() == 1)
        {
            licence = licenceLGPL();
        }
    }
    return licence;
}


//Slots

void FenPrincipale::montrerCodeGenere()
{
    QString nomClasse = m_nomClasse->text();
    QString codeH = genererCodeH();
    QString codeCpp = genererCodeCpp();
    FenCodeGenere *fenetre = new FenCodeGenere(codeH, codeCpp, nomClasse,  this);
    fenetre->exec();
}


void FenPrincipale::valideOuPas()
{
    if(m_nomClasse->text().isEmpty() == false)
    {
        emit montrerCodeGenere();
    }
    else
    {
        emit QMessageBox::critical(this, "Erreur !!!", "Veuillez entrer le nom de la classe !!!");
    }
}



void FenPrincipale::headerCacheOuPas()
{
    if(m_header->isHidden())
    {
        m_header->setVisible(true);
        m_ifndef->setVisible(true);
        m_define->setVisible(true);
        m_endif->setVisible(true);
    }
    else if(m_header->isVisible())
    {
        m_header->setHidden(true);
        m_ifndef->setHidden(true);
        m_define->setHidden(true);
        m_endif->setHidden(true);
    }
}


void FenPrincipale::attributsCacheOuPas()
{
    if(m_classeAttributs->isHidden())
    {
        m_classeAttributs->setVisible(true);
        m_listeWidgets->setVisible(true);
        m_ajouter->setVisible(true);
        m_supprimer->setVisible(true);
        m_attributsAAjouter->setVisible(true);
        m_toutSuppr->setVisible(true);
        m_nomVariableAttributs->setVisible(true);
        m_rechercher->setVisible(true);
        lireClasses();
    }
    else if(m_classeAttributs->isVisible())
    {
        m_classeAttributs->setHidden(true);
        m_listeWidgets->setHidden(true);
        m_ajouter->setHidden(true);
        m_supprimer->setHidden(true);
        m_attributsAAjouter->setHidden(true);
        m_toutSuppr->setHidden(true);
        m_nomVariableAttributs->setHidden(true);
        m_rechercher->setHidden(true);
        m_listeWidgets->clear();
    }
}


void FenPrincipale::genererHeader()
{
    QString nomClasse = m_nomClasse->text();
    m_header->setText("HEADER_" + nomClasse.toUpper());
}


void FenPrincipale::ajouter()
{
    QString condition = "*m_";
    if(m_classeAttributs->text().isEmpty() == false)
    {
        QString textPrincipale;
        QString text = m_classeAttributs->text();
        QString text2 = m_nomVariableAttributs->text();
        textPrincipale = text + " " + text2;
        m_attributsAAjouter->addItem(textPrincipale);
        m_classeAttributs->clear();
        m_nomVariableAttributs->clear();
        m_nomVariableAttributs->setText("*m_Ex_emple");

    }
    else
    {
        emit QMessageBox::critical(this, "Erreur !!!", "Certains champs ne sont pas remplis !!!");
    }
}


void FenPrincipale::supprimer()
{
    m_attributsAAjouter->takeItem(m_attributsAAjouter->currentRow());
}


void FenPrincipale::toutSupprimer()
{
    m_attributsAAjouter->clear();
}


void FenPrincipale::rechercher()
{
    QString text = m_rechercher->text();

    QList<QListWidgetItem *> list = m_listeWidgets->findItems(text, Qt::MatchStartsWith);
    m_listeWidgets->setCurrentItem(list.at(0));
}

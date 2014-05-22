#include "creerAttributs.h"

FenetreTest::FenetreTest() : QWidget()
{
    m_texteAAjouter = new QLineEdit();
    m_listeAttributsACreer = new QListWidget();
    m_listeAttributsAAjouter = new QListWidget();
    m_creer = new QPushButton(QString::fromUtf8("Créer"));
    m_supprimer = new QPushButton("Supprimer");
    m_quitter = new QPushButton("Quitter");
    m_ajouter = new QPushButton("Ajouter");
    m_enlever = new QPushButton("Enlever");
    m_listeWidgets = new QListWidget();
    lireClasses();
    m_listeWidgets->takeItem(831);
    m_layoutListe = new QHBoxLayout();
    m_layoutListe->addWidget(m_listeAttributsACreer);
    m_layoutListe->addWidget(m_listeAttributsAAjouter);
    m_layout = new QVBoxLayout(this);
    m_layout->addWidget(m_texteAAjouter);
    m_layout->addWidget(m_creer);
    m_layout->addLayout(m_layoutListe);
    m_layout->addWidget(m_listeWidgets);
    m_layout->addWidget(m_ajouter);
    m_layout->addWidget(m_enlever);
    m_layout->addWidget(m_supprimer);
    m_layout->addWidget(m_quitter);

    QObject::connect(m_creer, SIGNAL(clicked()), this, SLOT(creer()));
    QObject::connect(m_ajouter, SIGNAL(clicked()), this, SLOT(ajouter()));
    QObject::connect(m_enlever, SIGNAL(clicked()), this, SLOT(enlever()));
    QObject::connect(m_supprimer, SIGNAL(clicked()), this, SLOT(supprimer()));
    QObject::connect(m_quitter, SIGNAL(clicked()), this, SLOT(close()));
}

FenetreTest::~FenetreTest()
{}

void FenetreTest::lireClasses()
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
            fichier.close();
        }
    }
    else
    {
        QMessageBox::critical(this, "Erreur", QString::fromUtf8("Le fichier contenant la liste des classes n'a pas pu être ouvert !!!"));
    }
}

QString FenetreTest::creer()
{
    QString text = m_texteAAjouter->text();
    m_listeAttributsACreer->addItem(text);
    return text;
}

void FenetreTest::ajouter()
{
    QString text = m_listeAttributsACreer->currentItem()->text();
    m_listeAttributsAAjouter->addItem(text);
    m_listeAttributsACreer->takeItem(m_listeAttributsACreer->currentRow());
}

void FenetreTest::enlever()
{
    QString text = m_listeAttributsAAjouter->currentItem()->text();
    m_listeAttributsACreer->addItem(text);
    m_listeAttributsAAjouter->takeItem(m_listeAttributsAAjouter->currentRow());
}

void FenetreTest::supprimer()
{
    m_listeAttributsACreer->takeItem(m_listeAttributsACreer->currentRow());
}

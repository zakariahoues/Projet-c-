#include "fourniture.h"
#include <QDebug>
#include "connexion.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
fourniture::fourniture()
{
id_f=0;
nom="";
nom_fou="";
quantite=0;
prix=0;
}
fourniture::fourniture(int id_f,QString nom,QString nom_fou,float quantite,float prix)
{
 this->id_f=id_f;
    this->nom=nom;
    this->nom_fou=nom_fou;
    this->quantite=quantite;
    this->prix=prix;
}
bool fourniture::ajouter()
{
QSqlQuery query;
QString res= QString::number(id_f);
QString res1= QString::number(quantite);
QString res2= QString::number(prix);

query.prepare("INSERT INTO fourniture (ID_F, NOM, QUANTITE, PRIX, NOM_FOUR)"
                    "VALUES ( :id_f, :nom, :quantite, :prix, :nom_four)");
query.bindValue(":id_f",res);
query.bindValue(":nom",nom);
query.bindValue(":quantite",res1);
query.bindValue(":prix",res2);
query.bindValue(":nom_four",nom_fou);

return    query.exec();
}

QSqlQueryModel * fourniture::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from fourniture");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nom fournisseur"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Quantite"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("Prix"));
    return model;
}

bool fourniture::supprimer(int reff)
{
QSqlQuery query;
QString res= QString::number(reff);
query.prepare("Delete from fourniture where ID_F = :reff ");
query.bindValue(":reff", res);
return    query.exec();
}

QSqlQueryModel * fourniture::rechercher(const QString &arg1)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QSqlQuery query;
    query.bindValue(":nombre",arg1);

    model->setQuery("select * from fourniture where ID_F='"+arg1+"'");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nom fournisseur"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Quantite"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Prix"));



        return model;
}

QSqlQueryModel * fourniture::trierref()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from fourniture ORDER BY ID_F ASC");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nom fournisseur"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Quantite"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("Prix"));



    return model;
}

QSqlQueryModel * fourniture::trierarticle()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from fourniture ORDER BY nom ASC");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nom fournisseur"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Quantite"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("Prix"));
return model;
}

QSqlQueryModel * fourniture::trierp()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from fourniture ORDER BY prix DESC");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nom fournisseur"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Quantite"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("Prix"));



    return model;
}


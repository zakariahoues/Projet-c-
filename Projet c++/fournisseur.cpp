#include "fournisseur.h"

#include <QDebug>
#include "connexion.h"

fournisseur::fournisseur()
{
id =0;
nom="";
prenom="";
id_f=0;
id_e=0;
adresse ="";
mail="";


}
fournisseur::fournisseur(int id,QString nom,QString prenom,int id_f,int id_e,QString adresse,QString mail)
{
    this->id=id;
    this->nom=nom;
    this->prenom=prenom;
    this->id_e=id_e;
    this->id_f=id_f;
    this->adresse=adresse;
    this->mail=mail;

}

bool fournisseur::ajouter()
{
QSqlQuery query;

QString res= QString::number(id);
QString res1= QString::number(id_f);
QString res2= QString::number(id_e);


query.prepare("INSERT INTO fournisseur (ID,NOM,PRENOM,ID_F,ID_E,ADRESSE,MAIL)"
                    "VALUES ( :id, :nom, :prenom, :id_f,:id_e,:adresse,:mail)");
query.bindValue(":id", res);
query.bindValue(":nom",nom);
query.bindValue(":prenom",prenom);
query.bindValue(":id_f", res1);
query.bindValue(":id_e", res2);
query.bindValue(":adresse",adresse);
query.bindValue(":mail",mail);





return    query.exec();
}

QSqlQueryModel * fournisseur::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from fournisseur");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Id fourniture"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("Id equipement"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("Adresse"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("Mail"));





    return model;
}

bool fournisseur::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from fournisseur where id = :idd ");
query.bindValue(":idd", res);
return    query.exec();
}

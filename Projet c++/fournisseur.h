#ifndef fournisseur_H
#define fournisseur_H

#include <QMainWindow>
#include <QObject>
#include <QQuickItem>
#include <QSharedDataPointer>
#include <QWidget>
#include <QString>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlQueryModel>

class fournisseur
{public:
    fournisseur();
    fournisseur(int,QString,QString,int,int,QString,QString);
    int get_id();
    QString get_nom();
    QString get_prenom();
    int get_id_f();
    int get_id_e();
    QString get_adresse();
    QString get_mail();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
private:
    QString nom,prenom,adresse,mail;
    int id,id_f,id_e;
};
#endif // fournisseur_H

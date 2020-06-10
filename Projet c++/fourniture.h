#ifndef fourniture_H
#define fourniture_H

#include <QMainWindow>
#include <QObject>
#include <QQuickItem>
#include <QSharedDataPointer>
#include <QWidget>
#include <QString>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlQueryModel>

class fourniture
{public:
    fourniture();
    fourniture(int,QString,QString,float,float);
    int get_id();
    QString get_nom();
    QString get_nomfou();
    float get_quantite();
    float get_poids();
    bool ajouter();
    QSqlQueryModel * afficher();
    QSqlQueryModel * rechercher(const QString &arg1);
    QSqlQueryModel * trierref();
    QSqlQueryModel * trierarticle();
    QSqlQueryModel * trierp();
    bool charger(int);
    bool supprimer(int);

private:

    int id_f;
    float quantite,prix;
    QString nom,nom_fou;
};

#endif // fourniture_H

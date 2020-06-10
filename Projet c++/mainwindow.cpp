#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "fourniture.h"
#include "fournisseur.h"
#include <QMessageBox>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tabfourniture->setModel(tmpfourniture.afficher());//refresh
    ui->tabfournissseur->setModel(tmpfournisseur.afficher());//refresh

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_promotions_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_21_clicked()
{

    int id = ui->id->text().toInt();
    QString nom= ui->nomfs->text();
    QString prenom= ui->prenomfs->text();
    int id_f =ui->idfoufs->text().toInt();
    int id_e=ui->idfs->text().toInt();
    QString adresse=ui->adressefs->text();
    QString mail=ui->mailfs->text();


fournisseur f(id,nom,prenom,id_f,id_e,adresse,mail);
bool test=f.ajouter();

  if(test)
{
ui->tabfournissseur->setModel(tmpfournisseur.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un fournisseur"),
                  QObject::tr("Fournisseur ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un fournisseur"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_pushButton_6_clicked()
{
    int reff = ui->id->text().toInt();
    bool test=tmpfournisseur.supprimer(reff);
    if(test)
    {ui->tabfournissseur->setModel(tmpfournisseur.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un fournisseur"),
                    QObject::tr("fournisseur supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un fournisseur"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_lineEdit_14_textChanged(const QString &arg1)
{
    ui->tabfourniture->setModel(tmpfourniture.rechercher(arg1));//refresh
}

void MainWindow::on_radioButton_clicked()
{
    ui->tabfourniture->setModel(tmpfourniture.trierref());//refresh

}

void MainWindow::on_radioButton_2_clicked()
{
     ui->tabfourniture->setModel(tmpfourniture.trierarticle());//refresh
}

void MainWindow::on_radioButton_3_clicked()
{
   ui->tabfourniture->setModel(tmpfourniture.trierp());//refresh

}


void MainWindow::on_pushButton_clicked()
{
    QSqlQuery query;

    int id = ui->id->text().toInt();
    QString nom= ui->nomfs->text();
    QString prenom= ui->prenomfs->text();
    int id_f=ui->idfoufs->text().toInt();
    int id_e=ui->idfs->text().toInt();
    QString adresse=ui->adressefs->text();
    QString mail=ui->mailfs->text();
    QString res= QString::number(id);
    QString res1= QString::number(id_f);
    QString res2= QString::number(id_e);
            query.prepare("update FOURNISSEUR set ID=:id ,NOM=:nom ,PRENOM=:prenom ,ID_F=:id_f ,ID_E=:id_e ,ADRESSE=:adresse ,MAIL=:mail WHERE ID =:id");
            query.bindValue(":id", res);
            query.bindValue(":nom",nom);
            query.bindValue(":prenom",prenom);
            query.bindValue(":id_f", res1);
            query.bindValue(":id_e", res2);
            query.bindValue(":adresse",adresse);
            query.bindValue(":mail",mail);

            bool t=query.exec();
                   if(t)
                   {
                       ui->tabfournissseur->setModel(tmpfournisseur.afficher());//refresh
                   QMessageBox::information(nullptr, QObject::tr("Modifier"),
                                   QObject::tr("Promotion modifié.\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);

                   }
                   else
                      { QMessageBox::critical(nullptr, QObject::tr("Modifier"),
                                   QObject::tr("Erreur !.\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);
                      }
}

void MainWindow::on_pushButton_22_clicked()
{


    int id = ui->id_fou->text().toInt();
    QString nom= ui->lineEdit->text();
    QString nom_fou= ui->nomfou->text();
    float quantite =ui->quantite->text().toFloat();
    float prix=ui->poids->text().toFloat();

fourniture fo(id,nom,nom_fou,quantite,prix);
        bool test=fo.ajouter();

  if(test)
{
ui->tabfourniture->setModel(tmpfourniture.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un fournisseur"),
                  QObject::tr("Fournisseur ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un fournisseur"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);



}

void MainWindow::on_tabfourniture_activated(const QModelIndex &index)
{
    QString val=ui->tabfourniture->model()->data(index).toString();

        QSqlQuery query;
        query.prepare("SELECT * from FOURNITURE where ID_F ='"+val+"'");

        query.exec();
        while(query.next())
        {
            QString id_f=query.value(0).toString();
            QString nom=query.value(1).toString();
             QString nom_four=query.value(2).toString();
             QString prix=query.value(4).toString();
             QString quantite=query.value(3).toString();

            ui->id_fou->setText(id_f);
            ui->lineEdit->setText(nom);
            ui->nomfou->setText(nom_four);
            ui->quantite->setText(quantite);
            ui->poids->setText(prix);
         }


}

void MainWindow::on_pushButton_7_clicked()
{
    int id = ui->id_fou->text().toInt();
    bool test=tmpfourniture.supprimer(id);
    if(test)
    {ui->tabfourniture->setModel(tmpfourniture.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un fournisseur"),
                    QObject::tr("fournisseur supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un fournisseur"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_pushButton_3_clicked()
{
    QSqlQuery query;
    int id_f= ui->id_fou->text().toInt();
    QString nom= ui->lineEdit->text();
    QString nom_fou= ui->nomfou->text();
    float quantite =ui->quantite->text().toFloat();
    float prix=ui->poids->text().toFloat();


    QString res= QString::number(id_f);
    QString res1= QString::number(prix);
    QString res2= QString::number(quantite);
            query.prepare("update FOURNITURE set ID_F=:id_f ,NOM=:nom ,QUANTITE=:quantite ,PRIX=:prix,NOM_FOUR=:nom_four WHERE ID_F =:id_f");

            query.bindValue(":id_f",res);
            query.bindValue(":nom",nom);
            query.bindValue(":quantite",res1);
            query.bindValue(":prix",res2);
            query.bindValue(":nom_four",nom_fou);

            bool t=query.exec();
                   if(t)
                   {
                       ui->tabfourniture->setModel(tmpfourniture.afficher());//refresh
                   QMessageBox::information(nullptr, QObject::tr("Modifier"),
                                   QObject::tr("Promotion modifié.\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);

                   }
                   else
                      { QMessageBox::critical(nullptr, QObject::tr("Modifier"),
                                   QObject::tr("Erreur !.\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);
                      }

}

void MainWindow::on_fidel_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_tabfournissseur_activated(const QModelIndex &index)
{
    QString val=ui->tabfournissseur->model()->data(index).toString();

        QSqlQuery query;
        query.prepare("SELECT * from FOURNISSEUR where ID ='"+val+"'");

        query.exec();
        while(query.next())
        {
            QString id=query.value(0).toString();
            QString nom=query.value(1).toString();
             QString prenom=query.value(2).toString();
             QString id_f=query.value(3).toString();
             QString id_e=query.value(4).toString();
             QString adresse=query.value(5).toString();
             QString mail=query.value(6).toString();

             ui->id->setText(id);
             ui->nomfs->setText(nom);
             ui->prenomfs->setText(prenom);
             ui->idfoufs->setText(id_f);
             ui->idfs->setText(id_e);
             ui->adressefs->setText(adresse);
             ui->mailfs->setText(mail);


         }
}

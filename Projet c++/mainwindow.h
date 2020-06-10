#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "fourniture.h"
#include "fournisseur.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_promotions_clicked();

    void on_pushButton_21_clicked();

    void on_pushButton_6_clicked();

    void on_lineEdit_14_textChanged(const QString &arg1);

    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_radioButton_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_22_clicked();

    void on_tabfourniture_activated(const QModelIndex &index);

    void on_pushButton_7_clicked();

    void on_pushButton_3_clicked();

    void on_fidel_clicked();

    void on_tabfournissseur_activated(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
fournisseur tmpfournisseur;
fourniture tmpfourniture;

};
#endif // MAINWINDOW_H

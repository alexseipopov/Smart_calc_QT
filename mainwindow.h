#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <string>
#include "graph.h"
#include <QVector>

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
    void on_Button_0_clicked();

    void on_Button_1_clicked();

    void on_Button_2_clicked();

    void on_Button_3_clicked();

    void on_Button_4_clicked();

    void on_Button_5_clicked();

    void on_Button_6_clicked();

    void on_Button_7_clicked();

    void on_Button_8_clicked();

    void on_Button_9_clicked();

    void on_Plus_clicked();

    void on_Minus_clicked();

    void on_Div_clicked();

    void on_Mult_clicked();

    void on_Pow_clicked();

    void on_Mod_clicked();

    void on_Comma_clicked();

    void on_BRO_clicked();

    void on_BRC_clicked();

    void on_Sqrt_clicked();

    void on_Variable_clicked();

    void on_Sin_clicked();

    void on_Cos_clicked();

    void on_Asin_clicked();

    void on_Acos_clicked();

    void on_Tan_clicked();

    void on_Atan_clicked();

    void on_Ln_clicked();

    void on_Log_clicked();

    void on_Clear_clicked();

    void on_Equal_clicked();

    void on_ResultLine_returnPressed();


    void on_Graph_clicked();

private:
    Ui::MainWindow *ui;
    Graph *graphic;

signals:
    void signal_for_plotting(double, double, double, double, QVector<double>, QVector<double>, int, int);
};
#endif // MAINWINDOW_H

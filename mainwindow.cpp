#include "mainwindow.h"
#include "./ui_mainwindow.h"

extern "C" {
#include "s21_polish.h"
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    graphic = new Graph();
    connect(this, &MainWindow::signal_for_plotting, graphic, &Graph::slot);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_Button_0_clicked()
{
    ui->ResultLine->insert(QString("0"));
}


void MainWindow::on_Button_1_clicked()
{
    ui->ResultLine->insert(QString("1"));
}


void MainWindow::on_Button_2_clicked()
{
    ui->ResultLine->insert(QString("2"));
}


void MainWindow::on_Button_3_clicked()
{
    ui->ResultLine->insert(QString("3"));
}


void MainWindow::on_Button_4_clicked()
{
    ui->ResultLine->insert(QString("4"));
}


void MainWindow::on_Button_5_clicked()
{
    ui->ResultLine->insert(QString("5"));
}


void MainWindow::on_Button_6_clicked()
{
    ui->ResultLine->insert(QString("6"));
}


void MainWindow::on_Button_7_clicked()
{
    ui->ResultLine->insert(QString("7"));
}


void MainWindow::on_Button_8_clicked()
{
    ui->ResultLine->insert(QString("8"));
}


void MainWindow::on_Button_9_clicked()
{
    ui->ResultLine->insert(QString("9"));
}


void MainWindow::on_Plus_clicked()
{
    ui->ResultLine->insert(QString("+"));
}


void MainWindow::on_Minus_clicked()
{
    ui->ResultLine->insert(QString("-"));
}


void MainWindow::on_Div_clicked()
{
    ui->ResultLine->insert(QString("/"));
}


void MainWindow::on_Mult_clicked()
{
    ui->ResultLine->insert(QString("*"));
}


void MainWindow::on_Pow_clicked()
{
    ui->ResultLine->insert(QString("^"));
}


void MainWindow::on_Mod_clicked()
{
    ui->ResultLine->insert(QString("mod"));
}


void MainWindow::on_Comma_clicked()
{
    ui->ResultLine->insert(QString("."));
}


void MainWindow::on_BRO_clicked()
{
    ui->ResultLine->insert(QString("("));
}


void MainWindow::on_BRC_clicked()
{
    ui->ResultLine->insert(QString(")"));
}


void MainWindow::on_Sqrt_clicked()
{
    ui->ResultLine->insert(QString("sqrt("));
}


void MainWindow::on_Variable_clicked()
{
    ui->ResultLine->insert(QString("x"));
}


void MainWindow::on_Sin_clicked()
{
    ui->ResultLine->insert(QString("sin("));
}


void MainWindow::on_Cos_clicked()
{
    ui->ResultLine->insert(QString("cos("));
}


void MainWindow::on_Asin_clicked()
{
    ui->ResultLine->insert(QString("asin("));
}


void MainWindow::on_Acos_clicked()
{
    ui->ResultLine->insert(QString("acos("));
}


void MainWindow::on_Tan_clicked()
{
    ui->ResultLine->insert(QString("tan("));
}


void MainWindow::on_Atan_clicked()
{
    ui->ResultLine->insert(QString("atan("));
}


void MainWindow::on_Ln_clicked()
{
    ui->ResultLine->insert(QString("ln("));
}


void MainWindow::on_Log_clicked()
{
    ui->ResultLine->insert(QString("log("));
}


void MainWindow::on_Clear_clicked()
{
    ui->ResultLine->clear();
}


void MainWindow::on_Equal_clicked()
{
    std::string str = ui->ResultLine->text().toUtf8().constData();
    const char *st = str.c_str();
    auto at = const_cast<char*>(st);
    bool stat_read_varible = true;
    double result;
    double var = ui->lineEdit->text().toDouble(&stat_read_varible);
    if (stat_read_varible) {
        int status = s21_solve_result(at, var, &result);
        ui->ResultLine->clear();
        if (status == 0) {
            std::string sstr = std::to_string(result);
            ui->ResultLine->setText(QString::fromStdString(sstr));
        } else {
            ui->ResultLine->setText(QString("some error"));
        }
    } else {
        ui->ResultLine->setText(QString("unsupported variable"));
    }

}


void MainWindow::on_ResultLine_returnPressed()
{
    MainWindow::on_Equal_clicked();
}




void MainWindow::on_Graph_clicked()
{


    double xMin = ui->line_x_min->text().toDouble();
    double xMax = ui->line_x_max->text().toDouble();
    double yMin = ui->line_y_min->text().toDouble();
    double yMax = ui->line_y_max->text().toDouble();
    double step = (xMax - xMin) / 100000;
    QVector<double> data_x;
    QVector<double> data_y;
    int start_pos_x = window()->geometry().x(); // = ui->centralwidget->x() + ui->centralwidget->width();
    int start_pos_y = window()->geometry().y();; // = ui->centralwidget->y();
//    int w, h;
//    ui->centralwidget->geometry().getRect(&start_pos_x, &start_pos_y, &w, &h);
    window()->geometry().x();
    start_pos_x += ui->centralwidget->width();
    std::string str = ui->ResultLine->text().toUtf8().constData();
    const char *st = str.c_str();
    auto at = const_cast<char*>(st);
    double result;
    int status = 0;
    for (double x = xMin; x < xMax; x += step) {
        int status = s21_solve_result(at, x, &result);
        if (status == 0) {
//            if (result < yMax && result > yMin) {
                data_x.push_back(x);
                data_y.push_back(result);
//            }

        } else {
            ui->ResultLine->setText(QString("error plotting"));
            status = 1;
            break;
        }
    }
    if (status == 0) {
        emit signal_for_plotting(xMin, xMax, yMin, yMax, data_x, data_y, start_pos_x, start_pos_y);
        graphic->show();
    }

}


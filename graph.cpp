#include "graph.h"
#include "ui_graph.h"

Graph::Graph(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Graph)
{
    ui->setupUi(this);

}

Graph::~Graph()
{
    delete ui;
}

void Graph::slot(double xBegin, double xEnd, double yBegin, double yEnd, QVector<double> data_x, QVector<double> data_y, int window_x, int window_y)
{
    setGeometry(QRect(window_x, window_y, 500, 500));
    ui->widget->clearGraphs();
    ui->widget->xAxis->setRange(xBegin, xEnd);
    ui->widget->yAxis->setRange(yBegin, yEnd);

    ui->widget->addGraph();
    ui->widget->graph(0)->addData(data_x, data_y);
    ui->widget->replot();
}

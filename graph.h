#ifndef GRAPH_H
#define GRAPH_H

#include <QWidget>
#include <QVector>

namespace Ui {
class Graph;
}

class Graph : public QWidget
{
    Q_OBJECT

public:
    explicit Graph(QWidget *parent = nullptr);
    ~Graph();

private:
    Ui::Graph *ui;
    double xBegin = -1000000, xEnd = 1000000;

public slots:
    void slot(double xBegin, double xEnd, double yBegin, double yEnd, QVector<double> data_x, QVector<double> data_y, int window_x, int window_y);
};

#endif // GRAPH_H

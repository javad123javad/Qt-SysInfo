#ifndef SYSINFOWIDGET_H
#define SYSINFOWIDGET_H

#include <QWidget>
#include <QtCharts/QChartView>
#include <QTimer>
using namespace QtCharts;
class SysInfoWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SysInfoWidget(QWidget *parent = 0, int startDelaysMs = 500,
                           int updateSeriesDelaysMs = 500);
protected:
    QChartView& chartView();
protected slots:
    virtual void updateSeries() = 0;
private:
    QTimer mRefreshTimer;
    QChartView mChartView;
signals:

public slots:
};

#endif // SYSINFOWIDGET_H

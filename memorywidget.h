#ifndef MEMORYWIDGET_H
#define MEMORYWIDGET_H

#include "sysinfowidget.h"
#include <QtCharts/QPieSeries>
#include <QtCharts/QLineSeries>
class MemoryWidget : public SysInfoWidget
{
    Q_OBJECT
public:
    explicit MemoryWidget(QWidget* parent=0);
private slots:
    void updateSeries() override;
private:
    QPieSeries mSeries;
    QTimer *updateTimer;
    QLineSeries* lSeries;
    quint32 timeVal;
     QChart * chart;

};

#endif // MEMORYWIDGET_H

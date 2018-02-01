#ifndef CPUWINDGET_H
#define CPUWINDGET_H

#include <QtCharts/QPieSeries>
#include "sysinfowidget.h"

class CpuWindget : public SysInfoWidget
{
    Q_OBJECT
public:
   explicit CpuWindget(QWidget *parent = 0);
protected slots:
    void updateSeries() override;
private:
    QtCharts::QPieSeries * mSeries;
};

#endif // CPUWINDGET_H

#include "cpuwindget.h"
#include "sysinfo.h"
#include <QDebug>
CpuWindget::CpuWindget(QWidget *parent ):SysInfoWidget(parent), mSeries(new QPieSeries(this))
{
    mSeries->setHoleSize(0.3);
    mSeries->append("CPU Load", 30.0);
    mSeries->append("CPU Free", 70.0);

    QChart* chart = chartView().chart();
    chart->addSeries(mSeries);
    chart->setTitle("CPU Usage");


}

void CpuWindget::updateSeries()
{
    double cpuLoad = SysInfo::instance().cpuLoadAverage();
//    qDebug()<<cpuLoad;;
    mSeries->clear();
    mSeries->append("CPU Load", cpuLoad);
    mSeries->append("CPU Free", 100.0 - cpuLoad);

}

#include "memorywidget.h"
#include "sysinfo.h"
#include <QDebug>
MemoryWidget::MemoryWidget(QWidget * parent):
    SysInfoWidget(parent),
    mSeries(this),
    lSeries(new QLineSeries(this)),
    timeVal(0)
{
    mSeries.clear();
    mSeries.append("Memory Load",30.1);
    mSeries.append("Memory Fre", 69.9);


   lSeries->setPen(  QPen(Qt::red, 3, Qt::DotLine, Qt::RoundCap, Qt::RoundJoin));
    chart = chartView().chart();

    chart->setTitle("Memory Usage");
    chart->addSeries(lSeries);
    chart->createDefaultAxes();

    chart->axisX()->setRange(0,60);

    chart->axisY()->setRange(0,	10);

}

void MemoryWidget::updateSeries()
{
    double memoryUsed = SysInfo::instance().memoryUsed();
#ifdef _DEBUG_
    qDebug()<<"Used Memory:"<<memoryUsed<<"Time Val:"<<timeVal;

#endif
    mSeries.clear();
    mSeries.append("Memory Load",memoryUsed);
    mSeries.append("Memory Free", 100.0 - memoryUsed);
    if(timeVal > 60)
    {
//        timeVal = 0;
        lSeries->remove(0);
        chart->scroll(chart->plotArea().width()/60,	0);
//        chart->axisX()->setRange(60,60 * 2);

    }

    lSeries->append( timeVal++, memoryUsed);

}

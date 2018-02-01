#include "sysinfowidget.h"
#include <QVBoxLayout>
using namespace QtCharts;


SysInfoWidget::SysInfoWidget(QWidget *parent,
                             int startDelaysMs,
                             int updateSeriesDelaysMs) :
    QWidget(parent),
    mChartView(this)
{

    mRefreshTimer.setInterval(updateSeriesDelaysMs);
    connect(&mRefreshTimer, &QTimer::timeout, this, &SysInfoWidget::updateSeries);
    QTimer::singleShot(startDelaysMs, [this] {mRefreshTimer.start();});
    mChartView.setRenderHint(QPainter::Antialiasing);
    mChartView.chart()->legend()->setVisible(false);
    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(&mChartView);
    setLayout(layout);
}

QChartView& SysInfoWidget::chartView()
{
    return mChartView;
}

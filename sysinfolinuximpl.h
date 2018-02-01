#ifndef SYSINFOLINUXIMPL_H
#define SYSINFOLINUXIMPL_H

#include <QVector>
#include <QtGlobal>
#include "sysinfo.h"
class SysInfoLinuxImpl : public SysInfo
{
public:
    SysInfoLinuxImpl();
    void init() override;
    double cpuLoadAverage() override;
    double memoryUsed() override;

private:
    QVector<qulonglong> rawCpuData();
private:
    QVector<qulonglong> mCpuLoadLastValues;

};

#endif // SYSINFOLINUXIMPL_H

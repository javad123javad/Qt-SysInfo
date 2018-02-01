#include "sysinfolinuximpl.h"
#include <sys/types.h>
#include <sys/sysinfo.h>
#include <QtGlobal>
#include <QVector>
#include <QFile>
#include <QDebug>
SysInfoLinuxImpl::SysInfoLinuxImpl() :SysInfo(), mCpuLoadLastValues()
{

}

void SysInfoLinuxImpl::init()
{
    mCpuLoadLastValues = rawCpuData();

}

double SysInfoLinuxImpl::memoryUsed()
{
    struct sysinfo memInfo;
    sysinfo(&memInfo);

    qulonglong totalMemory = memInfo.totalram;
    totalMemory += memInfo.totalswap;
    totalMemory *= memInfo.mem_unit;

    qulonglong totalMemoryUsed = (memInfo.totalram + memInfo.totalswap) - (memInfo.freeswap + memInfo.freeram);
    totalMemoryUsed *= memInfo.mem_unit;

    double percent = ((double)totalMemoryUsed)/((double)totalMemory)*100.0;

    return qBound(0.0, percent, 100.0);

}

double SysInfoLinuxImpl::cpuLoadAverage()
{
    QVector<qulonglong> firstSample = mCpuLoadLastValues;
    QVector<qulonglong> secondSample = rawCpuData();
//    foreach (auto var, secondSample) {
//        qDebug()<< var;

//    }
    mCpuLoadLastValues = secondSample;

    double overall = (secondSample[0] - firstSample[0]) +
            (secondSample[1] - firstSample[1]) +
            (secondSample[2] - firstSample[2]);

    double total = overall + (secondSample[3] - firstSample[3]);
    double percent = (overall/total) * 100.0;
#ifdef _DEBUG_
    qDebug()<<"Percent:"<<percent<<"Overal"<<overall<<"total:"<<total;
#endif
    return qBound(0.0, percent, 100.0);
}

QVector<qulonglong> SysInfoLinuxImpl::rawCpuData()
{
    QFile file("/proc/stat");
    file.open(QIODevice::ReadOnly);
    QByteArray firstLine = file.readLine();
    file.close();
    qulonglong totalUser = 0, totalUserNice = 0, totalSystem = 0, totalIdle = 0;
    std::sscanf(firstLine.data(),"cpu %llu %llu %llu %llu", &totalUser, &totalUserNice,
                &totalSystem, &totalIdle);
    QVector<qulonglong> rawData;
    rawData.append(totalUser);
    rawData.append(totalUserNice);
    rawData.append(totalSystem);
    rawData.append(totalIdle);
//    foreach (auto var, rawData) {
//        qDebug()<< var;

//    }
    return rawData;
}

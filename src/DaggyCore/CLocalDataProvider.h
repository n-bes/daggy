/*
MIT License

Copyright (c) 2020 Mikhail Milovidov

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
#pragma once
#include <QObject>
#include <QList>

#include "IDataProvider.h"

class QProcess;

namespace daggycore {

class CLocalDataProvider : public IDataProvider
{
    Q_OBJECT
public:
    CLocalDataProvider(Commands commands,
                       QObject *parent = nullptr);

    ~CLocalDataProvider();


    void start() override;
    void stop() override;
    QString type() const override;

    constexpr static const char* provider_type = "local";

private slots:
    void onProcessDestroyed();
    void onProcessStart();
    void onProcessError(QProcess::ProcessError error);
    void onProcessReadyReadStandard();
    void onProcessReadyReadStandard(QProcess* process);
    void onProcessReadyReadError();
    void onProcessReadyReadError(QProcess* process);
    void onProcessFinished(int exit_code, QProcess::ExitStatus);

private:
    void terminate();

    QProcess* startProcess(const daggycore::Command& command);
    bool onProcessStop(QProcess* process);

    QList<QProcess*> processes() const;
    int activeProcessesCount() const;

    void startCommands();

    void startProcess(QProcess* process, const QString& command);
};

}

/*
Copyright 2017-2018 Milovidov Mikhail

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#ifndef CAPPLICATIONSETTINGS_H
#define CAPPLICATIONSETTINGS_H

#include <QStringList>

class QCoreApplication;

class CApplicationSettings
{
public:
    CApplicationSettings(QCoreApplication* pApplication);

    const QStringList& dataSourcesFiles() const;
    const QString& outputFolder() const;
    bool isReconnectionMode() const;
    int connectionTimeout() const;

private:
    QString getOutputFolderPath(const QStringList& dataSourcesFiles) const;

    QStringList m_dataSourcesFiles;
    QString m_outputFolder;
    int m_connectionTimeout;

    bool m_isReconnectionMode;
};

#endif // CAPPLICATIONSETTINGS_H

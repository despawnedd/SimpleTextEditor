/*
The MIT License (MIT)

Copyright (c) 2022 DespawnedDiamond

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

#include "mainwindow.h"

#include <QApplication>
#include <QStyleFactory>
#include <QPalette>
#include <QColor>
#include <QString>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // https://gist.github.com/QuantumCD/6245215
    a.setStyle(QStyleFactory::create("Fusion"));

    QPalette darkPalette;
    darkPalette.setColor(QPalette::Window, QColor(53,53,53));
    darkPalette.setColor(QPalette::WindowText, Qt::white);
    darkPalette.setColor(QPalette::Base, QColor(25,25,25));
    darkPalette.setColor(QPalette::AlternateBase, QColor(53,53,53));
    darkPalette.setColor(QPalette::ToolTipBase, Qt::white);
    darkPalette.setColor(QPalette::ToolTipText, Qt::white);
    darkPalette.setColor(QPalette::Text, Qt::white);
    darkPalette.setColor(QPalette::Button, QColor(53,53,53));
    darkPalette.setColor(QPalette::ButtonText, Qt::white);
    darkPalette.setColor(QPalette::BrightText, Qt::red);
    darkPalette.setColor(QPalette::Link, QColor(42, 130, 218));

    darkPalette.setColor(QPalette::Highlight, QColor(42, 130, 218));
    darkPalette.setColor(QPalette::HighlightedText, Qt::black);

    darkPalette.setColor(QPalette::PlaceholderText, QColor(128, 128, 128));
    darkPalette.setColor(QPalette::Disabled, QPalette::Text, QColor(128, 128, 128));

    a.setPalette(darkPalette);

    // Load an application style
    QFile styleFile(":/stylesheets/dark");
    styleFile.open(QFile::ReadOnly);

    // Apply the loaded stylesheet
    QString styleSheet(styleFile.readAll());
    a.setStyleSheet(styleSheet);
    //QString styleSheet("QToolTip { color: #ffffff; background-color: #2a82da; border: 1px solid white; }"
    //                   "QMenu::item:disabled { background-color: #1b1b1b; }"
    //                   "QFrame#titleBarC { background: #292929; padding-left: 6px; border-bottom: 1px solid #292929; }"
    //                   "QWidget#captionButtonsC { background: #1b1b1b; padding-right: 3px; }"
    //                   "QMenuBar { background: #353535; padding: 3px 0px 3px 0px; }"
    //                   "QMenuBar::item { spacing: 3px; padding: 4px; background: transparent; border-radius: 4px; }");
    //a.setStyleSheet(styleSheet);


    MainWindow w;
    w.show();
    return a.exec();
}

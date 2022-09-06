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

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QMainWindow>
#include <QGoodWindow>
#include <QPlainTextEdit>
#include <QMenuBar>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QDockWidget>
#include <QPushButton>
#include <QLabel>
#include <QSpacerItem>

class MainWindow : public QGoodWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void styleWindow();
    void testFunction();

private:
    void placeTitleWidget();
    bool event(QEvent *event);


    QFrame *captionButtonsWidget;
    QFrame *iconAndMenuBarWidget;
    QFrame *titleBarWidget;
    QLabel *titleWidget;
    QLabel *m_icon;
    QSpacerItem *m_title_bar_spacer__middle;
    QPushButton *m_button_minimize;
    QPushButton *m_button_maximize;
    QPushButton *m_button_restore;
    QPushButton *m_button_close;

    QHBoxLayout *icon_and_menu_bar_layout;
    QHBoxLayout *caption_buttons_layout;
    QHBoxLayout *title_layout;
    QHBoxLayout *title_bar_layout_h;
    //QGridLayout *title_bar_layout_g;

    QMainWindow *childMainWindow;
    QWidget *centralWidget;
    QWidget *subCentralWidget;
    QVBoxLayout *mainLayout;
    QVBoxLayout *subMainLayout;

    QMenuBar *mainMenuBar;

    QPlainTextEdit *textEditor;
    QDockWidget *toolDock;
    QDockWidget *fontDock;
};
#endif // MAINWINDOW_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>
#include <QMenuBar>
#include <QHBoxLayout>
#include <QDockWidget>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QWidget centralWidget;
    QTextEdit textEditor;
    QHBoxLayout mainLayout;
    QDockWidget toolDock, fontDock;

public slots:
    void testFunction();

};
#endif // MAINWINDOW_H

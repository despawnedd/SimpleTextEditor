#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setWindowTitle("SimpleTextEditor");
    this->resize(800, 600);



    QMenuBar *menuBar = this->menuBar();


    QMenu *fileMenu = menuBar->addMenu("File");

    QKeySequence newActionShortcut = QKeySequence("Ctrl+N");
    QAction *newAction = fileMenu->addAction("New", newActionShortcut);
    connect(newAction, SIGNAL(triggered()), this, SLOT(testFunction()));
    //connect(newAction, newAction->triggered(), this, &MainWindow::testFunction());


    QMenu *editMenu = menuBar->addMenu("Edit");

    QMenu *helpMenu = menuBar->addMenu("Help");



    textEditor.setPlaceholderText("Enter text here!");

    toolDock.setWindowTitle("Tools");
    toolDock.setMinimumWidth(200);

    fontDock.setWindowTitle("Fonts");
    fontDock.setMinimumWidth(200);

    mainLayout.addWidget(&textEditor);
    //mainLayout.addWidget(&dockWidget);
    mainLayout.setContentsMargins(0, 0, 0, 0);

    centralWidget.setLayout(&mainLayout);
    this->setCentralWidget(&centralWidget);
    this->addDockWidget(Qt::RightDockWidgetArea, &toolDock);
    this->addDockWidget(Qt::RightDockWidgetArea, &fontDock);
}

void MainWindow::testFunction()
{
    qDebug() << "hi";
}

MainWindow::~MainWindow()
{
}


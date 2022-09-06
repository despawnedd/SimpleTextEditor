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

// Some code was taken from an example

#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QGoodWindow(parent)
{
    setWindowTitle("SimpleTextEditor");
    resize(800, 600);


    mainMenuBar = new QMenuBar(this);


    QMenu *fileMenu = mainMenuBar->addMenu("File");

    QKeySequence newActionShortcut = QKeySequence("Ctrl+N");
    QAction *newAction = fileMenu->addAction("New", newActionShortcut);
    connect(newAction, SIGNAL(triggered()), this, SLOT(testFunction()));


    QMenu *editMenu = mainMenuBar->addMenu("Edit");

    QMenu *helpMenu = mainMenuBar->addMenu("Help");


    m_icon = new QLabel(this);
    m_icon->setObjectName("icon");
    m_icon->setFixedSize(16, 16);
    m_button_minimize = new QPushButton("_", this);
    m_button_minimize->setFixedWidth(32);
    m_button_maximize = new QPushButton("[+]", this);
    m_button_maximize->setFixedWidth(32);
    m_button_restore = new QPushButton("[-]", this);
    m_button_restore->setFixedWidth(32);
    m_button_close = new QPushButton("x", this);
    m_button_close->setFixedWidth(32);

    connect(this, &QGoodWindow::windowIconChanged, this, [=](const QIcon &icon){
        m_icon->setPixmap(icon.pixmap(16, 16));
    });
    connect(m_button_minimize, &QPushButton::clicked, this, &QGoodWindow::showMinimized);
    connect(m_button_maximize, &QPushButton::clicked, this, &QGoodWindow::showMaximized);
    connect(m_button_restore, &QPushButton::clicked, this, &QGoodWindow::showNormal);
    connect(m_button_close, &QPushButton::clicked, this, &QGoodWindow::close);

    iconAndMenuBarWidget = new QFrame(this);
    iconAndMenuBarWidget->setObjectName("iconAndMenuBarC");
    iconAndMenuBarWidget->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);

    icon_and_menu_bar_layout = new QHBoxLayout(iconAndMenuBarWidget);
    icon_and_menu_bar_layout->setContentsMargins(0, 0, 0, 0);
    icon_and_menu_bar_layout->setSpacing(0);
    icon_and_menu_bar_layout->addWidget(m_icon);
    icon_and_menu_bar_layout->addWidget(mainMenuBar);

    captionButtonsWidget = new QFrame(this);
    captionButtonsWidget->setObjectName("captionButtonsC");
    captionButtonsWidget->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);

    caption_buttons_layout = new QHBoxLayout(captionButtonsWidget);
    caption_buttons_layout->setContentsMargins(0, 0, 0, 0);
    caption_buttons_layout->setSpacing(0);
    caption_buttons_layout->addWidget(m_button_minimize);
    caption_buttons_layout->addWidget(m_button_maximize);
    caption_buttons_layout->addWidget(m_button_restore);
    caption_buttons_layout->addWidget(m_button_close);

    titleBarWidget = new QFrame(this);
    titleBarWidget->setObjectName("titleBarC");

    title_bar_layout_h = new QHBoxLayout(titleBarWidget);
    title_bar_layout_h->setContentsMargins(0, 0, 0, 0);
    title_bar_layout_h->setSpacing(0);
    title_bar_layout_h->addWidget(iconAndMenuBarWidget);
    title_bar_layout_h->addStretch();
    //title_bar_layout_h->addWidget(titleWidget);
    //title_bar_layout_h->addStretch();
    title_bar_layout_h->addWidget(captionButtonsWidget);


    textEditor = new QPlainTextEdit(this);
    textEditor->setPlaceholderText("Enter text here!");

    toolDock = new QDockWidget(this);
    toolDock->setWindowTitle("Tools");
    toolDock->setMinimumWidth(200);

    fontDock = new QDockWidget(this);
    fontDock->setWindowTitle("Fonts");
    fontDock->setMinimumWidth(200);

    childMainWindow = new QMainWindow(this);
    childMainWindow->setObjectName("childMainWindow");
    childMainWindow->addDockWidget(Qt::RightDockWidgetArea, toolDock);
    childMainWindow->addDockWidget(Qt::RightDockWidgetArea, fontDock);

    centralWidget = new QWidget(this);
    subCentralWidget = new QWidget(this);

    subMainLayout = new QVBoxLayout(subCentralWidget);
    subMainLayout->setContentsMargins(0, 0, 0, 0);
    subMainLayout->setSpacing(0);
    subMainLayout->addWidget(textEditor);

    childMainWindow->setCentralWidget(subCentralWidget);

    mainLayout = new QVBoxLayout(centralWidget);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(0);
    mainLayout->addWidget(titleBarWidget);
    mainLayout->addWidget(childMainWindow);
    //mainLayout.addWidget(&dockWidget);

    titleWidget = new QLabel("SimpleTextEditor", this);
    titleWidget->setAttribute(Qt::WA_TransparentForMouseEvents);
    titleWidget->setAlignment(Qt::AlignCenter);
    //placeTitleWidget();


    setCentralWidget(centralWidget);
    setWindowIcon(qApp->style()->standardIcon(QStyle::SP_DesktopIcon));
}

void MainWindow::styleWindow()
{
    setMargins(titleBarWidget->height() /*Title bar height*/,
               6 + m_icon->width() + 6 /*Icon size*/,
               mainMenuBar->width() /*Left margin*/,
               captionButtonsWidget->width() + 3 /*Right margin*/);

    bool maximized = isMaximized();

    m_button_maximize->setVisible(!maximized);
    m_button_maximize->setEnabled(!maximized);

    m_button_restore->setVisible(maximized);
    m_button_restore->setEnabled(maximized);
}

void MainWindow::placeTitleWidget() // bad code, but... hey, it works
{
    if (titleBarWidget->width() > 400)
    {
        titleWidget->setVisible(true);
        titleWidget->setGeometry(0, 0, titleBarWidget->width(), titleBarWidget->height());
    }
    else
    {
        titleWidget->setVisible(false);
    }
}

bool MainWindow::event(QEvent *event)
{
    switch (event->type())
    {
    case QEvent::Show:
    case QEvent::WindowActivate:
    case QEvent::WindowDeactivate:
    case QEvent::WindowStateChange:
    {
        styleWindow();
        placeTitleWidget();
        break;
    }
    case QEvent::Resize:
    {
        placeTitleWidget();
        break;
    }
    default:
        break;
    }

    return QGoodWindow::event(event);
}

void MainWindow::testFunction()
{
    qDebug() << "hi";
}

MainWindow::~MainWindow()
{
}

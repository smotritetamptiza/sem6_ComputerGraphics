#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "openglwidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // set up main layout
    openGLWidget = new OpenGLWidget(ui->mainHBox);
    ui->horizontalLayout->insertWidget(0, openGLWidget);
    ui->horizontalLayout->setStretch(0, 1);
    ui->horizontalLayout->setStretch(1, 0);

    // aligning items of control block
    ui->verticalLayout->setStretch(1, 1);
    ui->verticalLayout->setAlignment(ui->label, Qt::AlignmentFlag::AlignTop);
    ui->verticalLayout->setAlignment(ui->modeComboBox, Qt::AlignmentFlag::AlignTop);

    // fill control block
    ui->modeComboBox->insertItems(0, OpenGLWidget::MODES);
    QObject::connect(ui->modeComboBox, SIGNAL(currentIndexChanged(int)), openGLWidget, SLOT(onModeChanged(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onModeChanged(int mode) {

}

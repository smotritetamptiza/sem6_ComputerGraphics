#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "openglwidget.h"

const int MainWindow::SLIDER_MAX = 100;

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
    ui->verticalLayout->setStretch(ui->verticalLayout->children().length() - 1, 1);
    ui->verticalLayout->setAlignment(ui->dfactorComboBox, Qt::AlignmentFlag::AlignTop);

    // fill control block
    ui->alphaTestComboBox->insertItems(0, OpenGLWidget::ALPHA_TESTS_NAMES);
    ui->alphaTestSlider->setMaximum(SLIDER_MAX);
    ui->scissorXSlider->setMaximum(SLIDER_MAX);
    ui->scissorYSlider->setMaximum(SLIDER_MAX);
    ui->sfactorComboBox->insertItems(0, OpenGLWidget::SFACTORS_NAMES);
    ui->dfactorComboBox->insertItems(0, OpenGLWidget::DFACTORS_NAMES);

    QObject::connect(ui->alphaTestComboBox, SIGNAL(currentIndexChanged(int)), openGLWidget, SLOT(setAlphaTestFunc(int)));
    QObject::connect(ui->alphaTestSlider, SIGNAL(valueChanged(int)), this, SLOT(onAlphaTestChanged(int)));
    QObject::connect(ui->scissorXSlider, SIGNAL(valueChanged(int)), this, SLOT(onScissorXChanged(int)));
    QObject::connect(ui->scissorYSlider, SIGNAL(valueChanged(int)), this, SLOT(onScissorYChanged(int)));
    QObject::connect(ui->sfactorComboBox, SIGNAL(currentIndexChanged(int)), openGLWidget, SLOT(setSfactor(int)));
    QObject::connect(ui->dfactorComboBox, SIGNAL(currentIndexChanged(int)), openGLWidget, SLOT(setDfactor(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onAlphaTestChanged(int value) {
    openGLWidget->setAlphaTestRef(static_cast<float>(value) / SLIDER_MAX);
}

void MainWindow::onScissorXChanged(int value) {
    openGLWidget->setScissorX(static_cast<float>(value) / SLIDER_MAX);
}

void MainWindow::onScissorYChanged(int value) {
    openGLWidget->setScissorY(static_cast<float>(value) / SLIDER_MAX);
}

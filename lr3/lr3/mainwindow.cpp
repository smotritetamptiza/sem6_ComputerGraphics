#include "drawer.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "config.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    Drawer* drawer = new Drawer();

    ui->setupUi(this);
    ui->verticalLayout->addWidget(drawer, 1);

    Config *config = Config::instance;

    QObject::connect(ui->addButton, SIGNAL(clicked()), config, SLOT(addButtonClicked()));
    QObject::connect(ui->removeButton, SIGNAL(clicked()), config, SLOT(removeButtonClicked()));
    QObject::connect(config, SIGNAL(changed()), this, SLOT(configChanged()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::configChanged() {
    Config* config = Config::instance;

    if (ui->addButton->isChecked() != config->isAdding)
        ui->addButton->setChecked(config->isAdding);

    if (ui->removeButton->isChecked() != config->isRemoving)
        ui->removeButton->setChecked(config->isRemoving);
}

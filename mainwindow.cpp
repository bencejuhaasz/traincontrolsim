#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::fun() {
    palyaelemek = this->findChild<QGridLayout*>("palyaelemek");
    vezerloelemek = this->findChild<QGridLayout*>("vezerloelemek");
    for (int i = 0; i < palyaelemek->count(); ++i) {
        // Get the widget at index 'i'
        QLayoutItem *item = palyaelemek->itemAt(i);

        // Check if the item is a widget and if it's a QPushButton
        if (item && item->widget() && qobject_cast<QPushButton*>(item->widget())) {
            QPushButton *button = qobject_cast<QPushButton*>(item->widget());

            // Now 'button' is a pointer to each QPushButton in the grid
            // You can perform actions on 'button' here
            // For example, you might want to connect signals and slots:
            connect(button, &QPushButton::clicked, [=](bool clicked) {
                if(clicked) {
                    for (int j = 0; j < vezerloelemek->count(); ++j) {
                        // Get the widget at index 'i'
                        QLayoutItem *item = vezerloelemek->itemAt(j);

                        // Check if the item is a widget and if it's a QPushButton
                        if (item && item->widget() && qobject_cast<QPushButton*>(item->widget())) {
                            QPushButton *masik_layout_button = qobject_cast<QPushButton*>(item->widget());

                            // Now 'button' is a pointer to each QPushButton in the grid
                            // You can perform actions on 'button' here
                            // For example, you might want to connect signals and slots:
                            masik_layout_button->setChecked(false);
                        }
                    }
                    for (int j = 0; j < palyaelemek->count(); ++j) {
                        // Get the widget at index 'i'
                        QLayoutItem *item = palyaelemek->itemAt(j);

                        // Check if the item is a widget and if it's a QPushButton
                        if (item && item->widget() && qobject_cast<QPushButton*>(item->widget())) {
                            QPushButton *masik_gomb = qobject_cast<QPushButton*>(item->widget());

                            // Now 'button' is a pointer to each QPushButton in the grid
                            // You can perform actions on 'button' here
                            // For example, you might want to connect signals and slots:
                            if(masik_gomb!=button) {
                                masik_gomb->setChecked(false);
                            }
                        }
                    }
                }
            });
        }
    }

    for (int i = 0; i < vezerloelemek->count(); ++i) {
        // Get the widget at index 'i'
        QLayoutItem *item = vezerloelemek->itemAt(i);

        // Check if the item is a widget and if it's a QPushButton
        if (item && item->widget() && qobject_cast<QPushButton*>(item->widget())) {
            QPushButton *button = qobject_cast<QPushButton*>(item->widget());

            // Now 'button' is a pointer to each QPushButton in the grid
            // You can perform actions on 'button' here
            // For example, you might want to connect signals and slots:
            connect(button, &QPushButton::clicked, [=](bool clicked) {
                if(clicked) {
                    for (int j = 0; j < palyaelemek->count(); ++j) {
                        // Get the widget at index 'i'
                        QLayoutItem *item = palyaelemek->itemAt(j);

                        // Check if the item is a widget and if it's a QPushButton
                        if (item && item->widget() && qobject_cast<QPushButton*>(item->widget())) {
                            QPushButton *masik_layout_button = qobject_cast<QPushButton*>(item->widget());

                            // Now 'button' is a pointer to each QPushButton in the grid
                            // You can perform actions on 'button' here
                            // For example, you might want to connect signals and slots:
                            masik_layout_button->setChecked(false);
                        }
                    }
                    for (int j = 0; j < vezerloelemek->count(); ++j) {
                        // Get the widget at index 'i'
                        QLayoutItem *item = vezerloelemek->itemAt(j);

                        // Check if the item is a widget and if it's a QPushButton
                        if (item && item->widget() && qobject_cast<QPushButton*>(item->widget())) {
                            QPushButton *masik_gomb = qobject_cast<QPushButton*>(item->widget());

                            // Now 'button' is a pointer to each QPushButton in the grid
                            // You can perform actions on 'button' here
                            // For example, you might want to connect signals and slots:
                            if(masik_gomb!=button) {
                                masik_gomb->setChecked(false);
                            }
                        }
                    }
                }
            });
        }
    }
}



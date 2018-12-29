#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include <chrono>
#include <string>
#include <sstream>
#include <QString>
#include <iostream>
#include <fstream>
using namespace std::chrono;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(end_count()));
}


MainWindow::~MainWindow()
{
    delete ui;
}

int MainWindow::change_label()
{
    auto t = steady_clock::now();
    //stringstream ss;
    //ss<<t;
    //time_point_cast<milliseconds>(t).count();
    auto time_point = system_clock::now();
    //time_t now_c = system_clock::to_time_t(time_point);

    auto duration_in_ms = duration_cast<chrono::milliseconds>(time_point.time_since_epoch());
    uint64_t now = duration_in_ms.count();
    num_vec.push_back(now);
    num++;
    if(now - last> 1000){

        last = now;
        cout<<"current "<<num<<endl;;
        num = 0;
    }



    ui->test_label->setText(to_string(now).c_str());
    QTimer::singleShot(1, this, SLOT(change_label()));


}

int MainWindow::start_count()
{

    QTimer::singleShot(1, this, SLOT(change_label()));

}

int MainWindow::end_count()
{

    ofstream of{"test.txt", ios_base::trunc};
    for(auto p = num_vec.begin(); p != num_vec.end(); p++){
        of<<*p<<endl;
    }
    of.close();
}










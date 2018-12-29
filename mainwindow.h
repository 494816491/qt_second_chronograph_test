#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    int change_label();
    int start_count();
    int end_count();

private:
    Ui::MainWindow *ui;
    uint64_t num{};
    uint64_t last{};
    vector<uint64_t> num_vec{};
};

#endif // MAINWINDOW_H

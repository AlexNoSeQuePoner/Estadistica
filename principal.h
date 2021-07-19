#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QMainWindow>
#include <QPainter>
#include <QMessageBox>
#include <QFileDialog>
#include <QDir>
#include <QFile>

QT_BEGIN_NAMESPACE
namespace Ui { class Principal; }
QT_END_NAMESPACE

class Principal : public QMainWindow
{
    Q_OBJECT

public:
    Principal(QWidget *parent = nullptr);
    ~Principal();

private slots:
    void on_cmdGraficar_released();

    void on_actionGuardar_triggered();

private:
    Ui::Principal *ui;
    //declarar el objeto a crear
    QPixmap lienzoEst;
    void dibujar();
};
#endif // PRINCIPAL_H

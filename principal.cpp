#include "principal.h"
#include "ui_principal.h"

Principal::Principal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Principal)
{
    ui->setupUi(this);
    //crear lienzo
    lienzoEst = QPixmap(500, 500);
    //invocar al metodo dibujar
    this->dibujar();
    //mostrar el lienzo en el "cuadro"
    ui->cuadro->setPixmap(lienzoEst);
}

Principal::~Principal()
{
    delete ui;
}

void Principal::dibujar()
{
    //Rellenar lienzo
    lienzoEst.fill(Qt::white);

    //crear pintor
    QPainter painter(&lienzoEst);

    int x = 50;
    int y = 50;
    int ancho = 100;
    int alto_1 = ui->inNota1->value();
    int alto_2 = ui->inNota2->value();
    int alto_3 = ui->inNota3->value();
    //crear un pincel para el borde
    QPen pincel;
    pincel.setWidth(5);
    pincel.setColor(Qt::red);
    pincel.setJoinStyle(Qt::MiterJoin);

    //establecer el pincel al pintor
    painter.setPen(pincel);

    //Dibujar primera barra
    painter.drawRect(x, y+(400-alto_1), ancho, alto_1);
    //crear un nuevo color
    QColor colorBorde2(100,3,48);
    QColor colorRelleno2(190,120,162);
    //establecer nuevo colo al pincel
    pincel.setColor(colorBorde2);
    //volver establecer el pincel al painter
    painter.setPen(pincel);
    //establecer colo de la procha
    painter.setBrush(colorRelleno2);
    //Dibujar la segunda barra(rellena)
    painter.drawRect(x+150, y+(400-alto_2), ancho, alto_2);

    //Creando colores de la tercera barra
    QColor colorRelleno3(253, 253, 115);
    QColor colorBorde3(175,174,51);

    pincel.setColor(colorBorde3);
    painter.setPen(pincel);
    painter.setBrush(colorRelleno3);
    //Dibujar tercer pincel
    painter.drawRect(x+300, y+(400-alto_3), ancho, alto_3);

    //mostrar el lienzo en el "cuadro"
    ui->cuadro->setPixmap(lienzoEst);

}


void Principal::on_cmdGraficar_released()
{
    dibujar();
}

void Principal::on_actionGuardar_triggered()
{
    //Crear un objeto QDir a partir del directorio del usuario
    QDir directorio = QDir::home();
    QString pathArchivo = directorio.absolutePath() + "/Grafico de barras.png";
    //Abrir un cuadro de dialogo para seleccionar el nombre y ubicacion del archivo
    QString fileName = QFileDialog::getSaveFileName(this, "Guardar Imagen",
                                                   pathArchivo,
                                                    "Imagen (*.png)");
    if (!fileName.isEmpty())
    {
      lienzoEst.save(fileName);
    }
}

#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./DB_Car.db");

    if( !db.open() )
        qDebug() << db.lastError();
    else
        qDebug()<< "DB is completely opened";


    ui->setupUi(this);
    ui->domesticTable->setColumnWidth(0,640);
    ui->domesticTable->setColumnWidth(1,78);
    ui->domesticTable->setColumnWidth(2,70);

    ui->overseasTable->setColumnWidth(0,640);
    ui->overseasTable->setColumnWidth(1,78);
    ui->overseasTable->setColumnWidth(2,70);

    ui->specificBrandTable->setColumnWidth(0,620);
    ui->specificBrandTable->setColumnWidth(1,78);
    ui->specificBrandTable->setColumnWidth(2,70);


}

Widget::~Widget()
{
    delete ui;
}
void Widget::insertComparedSalesData(QString month, QString brand)
{
    QStringList wholeMonthBrandTotalSales;

    for(int i = 1; i < 13; i++)
    {
        QString monthToString = QString::number(i);
        wholeMonthBrandTotalSales << monthlySpecificBrandTotalSalesFind(monthToString, brand);
    }

    if(brand == "1")
    {

        if(month == "1")
        {
            ui->hyundaiSales->setText(wholeMonthBrandTotalSales[1]);
            ui->hyundaiOnMonth->setText("전월 데이터가 존재하지 않습니다.");
        }

        else
        {
            for(int i = 2; i < 13; i++)
            {
                QString numberToString = QString::number(i);
                if(month == numberToString)
                {
                    ui->hyundaiSales->setText(wholeMonthBrandTotalSales[i]);
                    int previousSales=wholeMonthBrandTotalSales[i-1].toInt();
                    int currentSales=wholeMonthBrandTotalSales[i-1].toInt();

                    if(previousSales > currentSales)
                    {
                        int result = previousSales-currentSales;
                        QString resultToString = QString::number(result);
                        ui->hyundaiOnMonth->setText(wholeMonthBrandTotalSales[i-1]+"▼"+resultToString);
                    }

                    else
                    {
                        int result = currentSales - previousSales;
                        QString resultToString = QString::number(result);
                        ui->hyundaiOnMonth->setText(wholeMonthBrandTotalSales[i-1]+"▲"+resultToString);

                    }
                }
            }
        }
    }

    else if(brand == "2")
    {

        if(month == "1")
        {
            ui->kiaSales->setText(wholeMonthBrandTotalSales[1]);
            ui->kiaOnMonth->setText("전월 데이터가 존재하지 않습니다.");
        }

        else
        {
            for(int i = 2; i < 13; i++)
            {
                QString numberToString = QString::number(i);
                if(month == numberToString)
                {
                    ui->kiaSales->setText(wholeMonthBrandTotalSales[i]);
                    int previousSales=wholeMonthBrandTotalSales[i-1].toInt();
                    int currentSales=wholeMonthBrandTotalSales[i-1].toInt();

                    if(previousSales > currentSales)
                    {
                        int result = previousSales-currentSales;
                        QString resultToString = QString::number(result);
                        ui->kiaOnMonth->setText(wholeMonthBrandTotalSales[i-1]+"▼"+resultToString);
                    }

                    else
                    {
                        int result = currentSales - previousSales;
                        QString resultToString = QString::number(result);
                        ui->kiaOnMonth->setText(wholeMonthBrandTotalSales[i-1]+"▲"+resultToString);

                    }
                }
            }
        }
    }
    else if(brand == "3")
    {

        if(month == "1")
        {
            ui->genesisSales->setText(wholeMonthBrandTotalSales[1]);
            ui->genesisOnMonth->setText("전월 데이터가 존재하지 않습니다.");
        }

        else
        {
            for(int i = 2; i < 13; i++)
            {
                QString numberToString = QString::number(i);
                if(month == numberToString)
                {
                    ui->genesisSales->setText(wholeMonthBrandTotalSales[i]);
                    int previousSales=wholeMonthBrandTotalSales[i-1].toInt();
                    int currentSales=wholeMonthBrandTotalSales[i-1].toInt();

                    if(previousSales > currentSales)
                    {
                        int result = previousSales-currentSales;
                        QString resultToString = QString::number(result);
                        ui->genesisOnMonth->setText(wholeMonthBrandTotalSales[i-1]+"▼"+resultToString);
                    }

                    else
                    {
                        int result = currentSales - previousSales;
                        QString resultToString = QString::number(result);
                        ui->genesisOnMonth->setText(wholeMonthBrandTotalSales[i-1]+"▲"+resultToString);

                    }
                }
            }
        }
    }

    else if(brand == "4")
    {

        if(month == "1")
        {
            ui->chevorletSales->setText(wholeMonthBrandTotalSales[1]);
            ui->chevorletOnMonth->setText("전월 데이터가 존재하지 않습니다.");
        }

        else
        {
            for(int i = 2; i < 13; i++)
            {
                QString numberToString = QString::number(i);
                if(month == numberToString)
                {
                    ui->chevorletSales->setText(wholeMonthBrandTotalSales[i]);
                    int previousSales=wholeMonthBrandTotalSales[i-1].toInt();
                    int currentSales=wholeMonthBrandTotalSales[i-1].toInt();

                    if(previousSales > currentSales)
                    {
                        int result = previousSales-currentSales;
                        QString resultToString = QString::number(result);
                        ui->chevorletOnMonth->setText(wholeMonthBrandTotalSales[i-1]+"▼"+resultToString);
                    }

                    else
                    {
                        int result = currentSales - previousSales;
                        QString resultToString = QString::number(result);
                        ui->chevorletOnMonth->setText(wholeMonthBrandTotalSales[i-1]+"▲"+resultToString);

                    }
                }
            }
        }
    }

    else if(brand == "5")
    {

        if(month == "1")
        {
            ui->kgSales->setText(wholeMonthBrandTotalSales[1]);
            ui->kgOnMonth->setText("전월 데이터가 존재하지 않습니다.");
        }

        else
        {
            for(int i = 2; i < 13; i++)
            {
                QString numberToString = QString::number(i);
                if(month == numberToString)
                {
                    ui->kgSales->setText(wholeMonthBrandTotalSales[i]);
                    int previousSales=wholeMonthBrandTotalSales[i-1].toInt();
                    int currentSales=wholeMonthBrandTotalSales[i-1].toInt();

                    if(previousSales > currentSales)
                    {
                        int result = previousSales-currentSales;
                        QString resultToString = QString::number(result);
                        ui->kgOnMonth->setText(wholeMonthBrandTotalSales[i-1]+"▼"+resultToString);
                    }

                    else
                    {
                        int result = currentSales - previousSales;
                        QString resultToString = QString::number(result);
                        ui->kgOnMonth->setText(wholeMonthBrandTotalSales[i-1]+"▲"+resultToString);

                    }
                }
            }
        }
    }

    else if(brand == "6")
    {

        if(month == "1")
        {
            ui->renaultSales->setText(wholeMonthBrandTotalSales[1]);
            ui->renaultOnMonth->setText("전월 데이터가 존재하지 않습니다.");
        }

        else
        {
            for(int i = 2; i < 13; i++)
            {
                QString numberToString = QString::number(i);
                if(month == numberToString)
                {
                    ui->renaultSales->setText(wholeMonthBrandTotalSales[i]);
                    int previousSales=wholeMonthBrandTotalSales[i-1].toInt();
                    int currentSales=wholeMonthBrandTotalSales[i-1].toInt();

                    if(previousSales > currentSales)
                    {
                        int result = previousSales-currentSales;
                        QString resultToString = QString::number(result);
                        ui->renaultOnMonth->setText(wholeMonthBrandTotalSales[i-1]+"▼"+resultToString);
                    }

                    else
                    {
                        int result = currentSales - previousSales;
                        QString resultToString = QString::number(result);
                        ui->renaultOnMonth->setText(wholeMonthBrandTotalSales[i-1]+"▲"+resultToString);

                    }
                }
            }
        }
    }

    else if(brand == "7")
    {

        if(month == "1")
        {
            ui->bmwSales->setText(wholeMonthBrandTotalSales[1]);
            ui->bmwOnMonth->setText("전월 데이터가 존재하지 않습니다.");
        }

        else
        {
            for(int i = 2; i < 13; i++)
            {
                QString numberToString = QString::number(i);
                if(month == numberToString)
                {
                    ui->bmwSales->setText(wholeMonthBrandTotalSales[i]);
                    int previousSales=wholeMonthBrandTotalSales[i-1].toInt();
                    int currentSales=wholeMonthBrandTotalSales[i-1].toInt();

                    if(previousSales > currentSales)
                    {
                        int result = previousSales-currentSales;
                        QString resultToString = QString::number(result);
                        ui->bmwOnMonth->setText(wholeMonthBrandTotalSales[i-1]+"▼"+resultToString);
                    }

                    else
                    {
                        int result = currentSales - previousSales;
                        QString resultToString = QString::number(result);
                        ui->bmwOnMonth->setText(wholeMonthBrandTotalSales[i-1]+"▲"+resultToString);

                    }
                }
            }
        }
    }
    else if(brand == "8")
    {

        if(month == "1")
        {
            ui->benzSales->setText(wholeMonthBrandTotalSales[1]);
            ui->benzOnMonth->setText("전월 데이터가 존재하지 않습니다.");
        }

        else
        {
            for(int i = 2; i < 13; i++)
            {
                QString numberToString = QString::number(i);
                if(month == numberToString)
                {
                    ui->benzSales->setText(wholeMonthBrandTotalSales[i]);
                    int previousSales=wholeMonthBrandTotalSales[i-1].toInt();
                    int currentSales=wholeMonthBrandTotalSales[i-1].toInt();

                    if(previousSales > currentSales)
                    {
                        int result = previousSales-currentSales;
                        QString resultToString = QString::number(result);
                        ui->benzOnMonth->setText(wholeMonthBrandTotalSales[i-1]+"▼"+resultToString);
                    }

                    else
                    {
                        int result = currentSales - previousSales;
                        QString resultToString = QString::number(result);
                        ui->benzOnMonth->setText(wholeMonthBrandTotalSales[i-1]+"▲"+resultToString);

                    }
                }
            }
        }
    }
    else if(brand == "9")
    {

        if(month == "1")
        {
            ui->audiSales->setText(wholeMonthBrandTotalSales[1]);
            ui->audiOnMonth->setText("전월 데이터가 존재하지 않습니다.");
        }

        else
        {
            for(int i = 2; i < 13; i++)
            {
                QString numberToString = QString::number(i);
                if(month == numberToString)
                {
                    ui->audiSales->setText(wholeMonthBrandTotalSales[i]);
                    int previousSales=wholeMonthBrandTotalSales[i-1].toInt();
                    int currentSales=wholeMonthBrandTotalSales[i-1].toInt();

                    if(previousSales > currentSales)
                    {
                        int result = previousSales-currentSales;
                        QString resultToString = QString::number(result);
                        ui->audiOnMonth->setText(wholeMonthBrandTotalSales[i-1]+"▼"+resultToString);
                    }

                    else
                    {
                        int result = currentSales - previousSales;
                        QString resultToString = QString::number(result);
                        ui->audiOnMonth->setText(wholeMonthBrandTotalSales[i-1]+"▲"+resultToString);

                    }
                }
            }
        }
    }
    else if(brand == "11")
    {

        if(month == "1")
        {
            ui->porscheSales->setText(wholeMonthBrandTotalSales[1]);
            ui->porscheOnMonth->setText("전월 데이터가 존재하지 않습니다.");
        }

        else
        {
            for(int i = 2; i < 13; i++)
            {
                QString numberToString = QString::number(i);
                if(month == numberToString)
                {
                    ui->porscheSales->setText(wholeMonthBrandTotalSales[i]);
                    int previousSales=wholeMonthBrandTotalSales[i-1].toInt();
                    int currentSales=wholeMonthBrandTotalSales[i-1].toInt();

                    if(previousSales > currentSales)
                    {
                        int result = previousSales-currentSales;
                        QString resultToString = QString::number(result);
                        ui->porscheOnMonth->setText(wholeMonthBrandTotalSales[i-1]+"▼"+resultToString);
                    }

                    else
                    {
                        int result = currentSales - previousSales;
                        QString resultToString = QString::number(result);
                        ui->porscheOnMonth->setText(wholeMonthBrandTotalSales[i-1]+"▲"+resultToString);

                    }
                }
            }
        }
    }

}
void Widget::monthIndexChanged()
{

    // if(!(ui->pushButton_6->isEnabled()))
    //     QString brand = "1";
    // else if(!(ui->pushButton_7->isEnabled()))
    //     QString brand = "2";
    // else if(!(ui->pushButton_8->isEnabled()))
    //     QString brand = "3";
    // else if(!(ui->pushButton_9->isEnabled()))
    //     QString brand = "4";
    // else if(!(ui->pushButton_10->isEnabled()))
    //     QString brand = "5";
    // else if(!(ui->pushButton_11->isEnabled()))
    //     QString brand = "6";
    // else if(!(ui->pushButton_12->isEnabled()))
    //     QString brand = "7";
    // else if(!(ui->pushButton_13->isEnabled()))
    //     QString brand = "8";
    // else if(!(ui->pushButton_14->isEnabled()))
    //     QString brand = "9";
    // else if(!(ui->pushButton_15->isEnabled()))
    //     QString brand = "10";
    // else if(!(ui->pushButton_16->isEnabled()))
    //     QString brand = "11";

    // if(!(ui->pushButton_6->isEnabled()) || !(ui->pushButton_7->isEnabled()) || !(ui->pushButton_8->isEnabled()) || !(ui->pushButton_9->isEnabled()) ||
    //     !(ui->pushButton_10->isEnabled()) || !(ui->pushButton_11->isEnabled()) || !(ui->pushButton_12->isEnabled()) || !(ui->pushButton_13->isEnabled()) ||
    //     !(ui->pushButton_14->isEnabled()) || !(ui->pushButton_15->isEnabled()) || !(ui->pushButton_16->isEnabled()) )

    QString brand = "1";
    if(!(ui->monthPick->isEnabled()))//특정 브랜드 버튼 어느 것이라도 눌려 있다면)
    {
        QStringList wholeMonthBrandTotalSales;
        for(int i = 1; i<13; i++)
        {
            QString changedMonth = QString::number(i);
            wholeMonthBrandTotalSales << monthlySpecificBrandTotalSalesFind(changedMonth, brand);
        }



        QString extract = ui->monthIndex->currentText();
        QString month;

        if(extract.length() > 2)
            month = extract.left(2);
        else if(extract.length() < 3)
            month = extract.left(1);





        QString monthlyBrandTotalSales = monthlySpecificBrandTotalSalesFind(month, brand);


        monthlyModelTotalSalesFind(month, brand, monthlyBrandTotalSales);
    }

    else
    {
        QString extract = ui->monthIndex->currentText();
        QString month;
        if(extract.length() > 2)
            month = extract.left(2);
        else if(extract.length() < 3)
            month = extract.left(1);


        qDebug() << month;
        if(month == "1")
            monthlyBrandTotalSalesFind("1");
        else if(month == "2")
            monthlyBrandTotalSalesFind("2");
        else if(month == "3")
            monthlyBrandTotalSalesFind("3");
        else if(month == "4")
            monthlyBrandTotalSalesFind("4");
        else if(month == "5")
            monthlyBrandTotalSalesFind("5");
        else if(month == "6")
            monthlyBrandTotalSalesFind("6");
        else if(month == "7")
            monthlyBrandTotalSalesFind("7");
        else if(month == "8")
            monthlyBrandTotalSalesFind("8");
        else if(month == "9")
            monthlyBrandTotalSalesFind("9");
        else if(month == "10")
            monthlyBrandTotalSalesFind("10");
        else if(month == "11")
            monthlyBrandTotalSalesFind("11");
        else if(month == "12")
            monthlyBrandTotalSalesFind("12");
    }

}


void Widget::monthPickButtonClicked()
{
    ui->dateStack->setCurrentIndex(0);
}


void Widget::durationPickButtonClicked()
{
    ui->dateStack->setCurrentIndex(1);
    ui->monthIndex2->setCurrentText("12월");

}


void Widget::brandTapClicked()
{


    ui->monthPick->setEnabled(false);
    // 브랜드 색상 변경
    // ui->monthPick->setStyleSheet("QPushButton {clolor : red; }");
    ui->durationPick->setEnabled(true);
    ui->brandInfoStack->setCurrentIndex(0);
    ui->contentStack->setCurrentIndex(1);
    monthlyBrandTotalSalesFind("12");
}


void Widget::searchButtonClicked()
{

    QString extract1 = ui->monthIndex1->currentText();
    QString extract2 = ui->monthIndex2->currentText();

    BrandTotalSalesByPeriodFind(extract1, extract2);


}



void Widget::hyundaiButttonClicked()
{
    ui->brandInfoStack->setCurrentIndex(1);
    ui->contentStack->setCurrentIndex(0);
    ui->dateStack->setCurrentIndex(0);
    ui->monthPick->setEnabled(false); //버튼이름 변경
    ui->monthIndex->setCurrentText("12월");
    monthIndexChanged();


}
void Widget::kiaButtonClicked()
{
    ui->brandInfoStack->setCurrentIndex(1);
    ui->contentStack->setCurrentIndex(0);
    ui->dateStack->setCurrentIndex(0);
    ui->monthPick->setEnabled(false);
    ui->monthIndex->setCurrentText("12월");
    monthIndexChanged();
}

void Widget::genesisButtonClicked()
{
    ui->brandInfoStack->setCurrentIndex(1);
    ui->contentStack->setCurrentIndex(0);
    ui->dateStack->setCurrentIndex(0);
    ui->monthPick->setEnabled(false);
    ui->monthIndex->setCurrentText("12월");
    monthIndexChanged();}
void Widget::chevroletButtonClicked()
{
    ui->brandInfoStack->setCurrentIndex(1);
    ui->contentStack->setCurrentIndex(0);
    ui->dateStack->setCurrentIndex(0);
    ui->monthPick->setEnabled(false);
    ui->monthIndex->setCurrentText("12월");
    monthIndexChanged();
}
void Widget::kgMobilityButtonClicked()
{
    ui->brandInfoStack->setCurrentIndex(1);
    ui->contentStack->setCurrentIndex(0);
    ui->dateStack->setCurrentIndex(0);
    ui->monthPick->setEnabled(false);
    ui->monthIndex->setCurrentText("12월");
    monthIndexChanged();
}
void Widget::renaultButtonClicked()
{
    ui->brandInfoStack->setCurrentIndex(1);
    ui->contentStack->setCurrentIndex(0);
    ui->dateStack->setCurrentIndex(0);
    ui->monthPick->setEnabled(false);
    ui->monthIndex->setCurrentText("12월");
    monthIndexChanged();
}
void Widget::bmwButtonClicked()
{
    ui->brandInfoStack->setCurrentIndex(1);
    ui->contentStack->setCurrentIndex(0);
    ui->dateStack->setCurrentIndex(0);
    ui->monthPick->setEnabled(false);
    ui->monthIndex->setCurrentText("12월");
    monthIndexChanged();
}
void Widget::benzButtonClicked()
{
    ui->brandInfoStack->setCurrentIndex(1);
    ui->contentStack->setCurrentIndex(0);
    ui->dateStack->setCurrentIndex(0);
    ui->monthPick->setEnabled(false);
    ui->monthIndex->setCurrentText("12월");
    monthIndexChanged();
}
void Widget::audiButtonClicked()
{
    ui->brandInfoStack->setCurrentIndex(1);
    ui->contentStack->setCurrentIndex(0);
    ui->dateStack->setCurrentIndex(0);
    ui->monthPick->setEnabled(false);
    ui->monthIndex->setCurrentText("12월");
    monthIndexChanged();
}
void Widget::lexusButtonClicked()
{
    ui->brandInfoStack->setCurrentIndex(1);
    ui->contentStack->setCurrentIndex(0);
    ui->dateStack->setCurrentIndex(0);
    ui->monthPick->setEnabled(false);
    ui->monthIndex->setCurrentText("12월");
    monthIndexChanged();
}
void Widget::porscheButtonClicked()
{
    ui->brandInfoStack->setCurrentIndex(1);
    ui->contentStack->setCurrentIndex(0);
    ui->dateStack->setCurrentIndex(0);
    ui->monthPick->setEnabled(false);
    ui->monthIndex->setCurrentText("12월");
    monthIndexChanged();
}

QString Widget::monthlyTotalSalesFind(QString month, int type)
{

    QString basicSet = "2023_";
    basicSet += month;

    if(type == 1)
    {
        QSqlQuery query1;// 국산
        query1.prepare("SELECT SUM(\"" +basicSet+ "\") FROM CAR_TB WHERE BRAND = 1 OR BRAND = 2 OR BRAND = 3 OR BRAND = 4 OR BRAND = 5 OR BRAND = 6");

        if( !query1.exec() )
            qDebug() << query1.lastError();

        query1.first();
        QString domesticTotalSales = query1.value(0).toString(); // 12월 국내 전체 차량 판매 대수
        return domesticTotalSales;
    }

    else if(type == 2)
    {
        QSqlQuery query2;// 외제
        query2.prepare("SELECT SUM(\"" +basicSet+ "\")FROM CAR_TB WHERE BRAND = 7 OR BRAND = 8 OR BRAND = 9 OR BRAND = 10 OR BRAND = 11");

        if( !query2.exec() )
            qDebug() << query2.lastError();

        query2.first();
        QString overseasTotalSales = query2.value(0).toString(); // 12월 해외 전체 차량 판매 대수
        return overseasTotalSales;
    }
    QString nothing = "";
    return nothing;
}


void Widget::BrandTotalSalesByPeriodFind(QString extract1, QString extract2)
{

    ui->domesticTable->clearContents();
    ui->overseasTable->clearContents();

    while(ui->domesticTable->rowCount() > 0)
    {
        ui->domesticTable->removeRow(0);
    }

    while(ui->overseasTable->rowCount() > 0)
    {
        ui->overseasTable->removeRow(0);
    }

    QString month1, month2;
    int monthToInt1, monthToInt2;

    if(extract1.length() > 2)
        month1 = extract1.left(2);
    else if(extract1.length() < 3)
        month1 = extract1.left(1);
    monthToInt1 = month1.toInt();


    if(extract2.length() > 2)
        month2 = extract2.left(2);
    else if(extract2.length() < 3)
        month2 = extract2.left(1);
    monthToInt2 = month2.toInt();


    int domesticData = 0, overseasData = 0;

    if(monthToInt2 < monthToInt1)
    {
        QMessageBox::StandardButton warning;
        warning = QMessageBox::critical(this,
                                        "Warning",
                                        "두 번째 월이 첫 번째 월 보다 작을 수 없습니다.",
                                        QMessageBox::Retry);
    }

    else if((monthToInt1 - monthToInt2) == 0)
        monthlyBrandTotalSalesFind(month1);

    else if((monthToInt2 - monthToInt1) == 1)
    {
        domesticData += (monthlyTotalSalesFind(month1,1)).toInt();
        domesticData += (monthlyTotalSalesFind(month2,1)).toInt();

        overseasData += (monthlyTotalSalesFind(month1,2)).toInt();
        overseasData += (monthlyTotalSalesFind(month2,2)).toInt();

        QString domesticTotalDataToString = QString::number(domesticData);
        QString overseasTotalDataToString = QString::number(overseasData);

        ui->domesticTable->horizontalHeaderItem(0)->setText("국산차");
        ui->overseasTable->horizontalHeaderItem(0)->setText("수입차");
        ui->domesticTable->horizontalHeaderItem(2)->setText(domesticTotalDataToString+"대");
        ui->overseasTable->horizontalHeaderItem(2)->setText(overseasTotalDataToString+"대");


        double DTS = double(domesticData);
        double OTS = double(overseasData);
        QSqlQuery query1;
        QSqlQuery query2;
        QString basicSet = "2023_";
        QString fullSentence = "";

        fullSentence += "\"" + basicSet + month1 + "\" + ";
        fullSentence += "\"" + basicSet + month1 + "\"";


        qDebug() << fullSentence;

        query1.prepare("SELECT BRAND, SUM(" +fullSentence+ ")\n\
                               FROM CAR_TB\n\
                               GROUP BY BRAND\n\
                               HAVING BRAND < 7\n\
                                 ORDER BY SUM(" +fullSentence+ ") DESC");


                 if( !query1.exec() )
                 qDebug() << query1.lastError();

        int i = 0;

        while(query1.next())
        {
            ui->domesticTable->insertRow(i);
            int brand = query1.value(0).toInt();

            if(brand == 1)
               ui->domesticTable->setItem(i,0, new QTableWidgetItem("현대"));
            else if(brand == 2)
               ui->domesticTable->setItem(i,0, new QTableWidgetItem("기아"));
            else if(brand == 3)
               ui->domesticTable->setItem(i,0, new QTableWidgetItem("제네시스"));
            else if(brand == 4)
               ui->domesticTable->setItem(i,0, new QTableWidgetItem("쉐보레"));
            else if(brand == 5)
               ui->domesticTable->setItem(i,0, new QTableWidgetItem("KG모빌리티"));
            else if(brand == 6)
               ui->domesticTable->setItem(i,0, new QTableWidgetItem("르노코리아"));

            ui->domesticTable->setItem(i, 1, new QTableWidgetItem(query1.value(1).toString()));

            QString result = QString::number((query1.value(1).toDouble()/DTS)*100);

            ui->domesticTable->setItem(i, 2, new QTableWidgetItem(result+"%"));
            i +=1;

        }

        query2.prepare("SELECT BRAND, SUM(" +fullSentence+ ")\n\
                               FROM CAR_TB\n\
                               GROUP BY BRAND\n\
                               HAVING BRAND > 6\n\
                               ORDER BY SUM(" +fullSentence+ ") ASC");

        if( !query2.exec() )
            qDebug() << query1.lastError();

        int j = 0;

        while(query2.next())
        {
            ui->overseasTable->insertRow(j);
            int brand = query2.value(0).toInt();
            if(brand == 7)
            ui->overseasTable->setItem(j,0, new QTableWidgetItem("BMW"));
            else if(brand == 8)
            ui->overseasTable->setItem(j,0, new QTableWidgetItem("벤츠"));
            else if(brand == 9)
            ui->overseasTable->setItem(j,0, new QTableWidgetItem("아우디"));
            else if(brand == 10)
            ui->overseasTable->setItem(j,0, new QTableWidgetItem("렉서스"));
            else if(brand == 11)
            ui->overseasTable->setItem(j,0, new QTableWidgetItem("포르쉐"));

            ui->overseasTable->setItem(j, 1, new QTableWidgetItem(query2.value(1).toString()));

            QString result = QString::number((query2.value(1).toDouble()/OTS)*100);

            ui->overseasTable->setItem(j, 2, new QTableWidgetItem(result+"%"));
        }

    }


    else if((monthToInt2 - monthToInt1) > 1)
    {
        for(int i=monthToInt2; i> monthToInt1; i--)
        {
            QString changer = QString::number(i);
            domesticData += (monthlyTotalSalesFind(changer, 1)).toInt();
            overseasData += (monthlyTotalSalesFind(changer, 2)).toInt();
        }

        QString monthToString1 = QString::number(monthToInt1);
        domesticData += (monthlyTotalSalesFind(monthToString1, 1)).toInt();
        overseasData += (monthlyTotalSalesFind(monthToString1, 2)).toInt();

        QString domesticTotalDataToString = QString::number(domesticData);
        QString overseasTotalDataToString = QString::number(overseasData);

        ui->domesticTable->horizontalHeaderItem(0)->setText("국산차");
        ui->overseasTable->horizontalHeaderItem(0)->setText("수입차");
        ui->domesticTable->horizontalHeaderItem(2)->setText(domesticTotalDataToString+"대");
        ui->overseasTable->horizontalHeaderItem(2)->setText(overseasTotalDataToString+"대");

        double DTS = double(domesticData);
        double OTS = double(overseasData);


        QSqlQuery query1;
        QSqlQuery query2;
        QString basicSet = "2023_";
        QString fullSentence = "";

        for(int i = monthToInt2; i> monthToInt1; i--)
        {
            QString t = "\"" + basicSet + QString::number(i) + "\" + ";
            fullSentence += t;
            qDebug()<<i;
        }

        fullSentence += "\"" + basicSet + QString::number(monthToInt1) +"\"";

        qDebug() << fullSentence;

        query1.prepare("SELECT BRAND, SUM(" +fullSentence+ ")\n\
                               FROM CAR_TB\n\
                               GROUP BY BRAND\n\
                               HAVING BRAND < 7\n\
                           ORDER BY SUM(" +fullSentence+ ") DESC");


        if( !query1.exec() )
            qDebug() << query1.lastError();

        int i = 0;

        while(query1.next())
        {
            ui->domesticTable->insertRow(i);
            int brand = query1.value(0).toInt();

            if(brand == 1)
                ui->domesticTable->setItem(i,0, new QTableWidgetItem("현대"));
            else if(brand == 2)
                ui->domesticTable->setItem(i,0, new QTableWidgetItem("기아"));
            else if(brand == 3)
                ui->domesticTable->setItem(i,0, new QTableWidgetItem("제네시스"));
            else if(brand == 4)
                ui->domesticTable->setItem(i,0, new QTableWidgetItem("쉐보레"));
            else if(brand == 5)
                ui->domesticTable->setItem(i,0, new QTableWidgetItem("KG모빌리티"));
            else if(brand == 6)
                ui->domesticTable->setItem(i,0, new QTableWidgetItem("르노코리아"));

            ui->domesticTable->setItem(i, 1, new QTableWidgetItem(query1.value(1).toString()));

            QString result = QString::number((query1.value(1).toDouble()/DTS)*100);

            ui->domesticTable->setItem(i, 2, new QTableWidgetItem(result+"%"));
            i +=1;

        }

        query2.prepare("SELECT BRAND, SUM(" +fullSentence+ ")\n\
                               FROM CAR_TB\n\
                               GROUP BY BRAND\n\
                               HAVING BRAND > 6\n\
                           ORDER BY SUM(" +fullSentence+ ") ASC");

       if( !query2.exec() )
       qDebug() << query1.lastError();

       int j = 0;

       while(query2.next())
       {
           ui->overseasTable->insertRow(j);
           int brand = query2.value(0).toInt();
           if(brand == 7)
               ui->overseasTable->setItem(j,0, new QTableWidgetItem("BMW"));
           else if(brand == 8)
               ui->overseasTable->setItem(j,0, new QTableWidgetItem("벤츠"));
           else if(brand == 9)
               ui->overseasTable->setItem(j,0, new QTableWidgetItem("아우디"));
           else if(brand == 10)
               ui->overseasTable->setItem(j,0, new QTableWidgetItem("렉서스"));
           else if(brand == 11)
               ui->overseasTable->setItem(j,0, new QTableWidgetItem("포르쉐"));

           ui->overseasTable->setItem(j, 1, new QTableWidgetItem(query2.value(1).toString()));

           QString result = QString::number((query2.value(1).toDouble()/OTS)*100);

           ui->overseasTable->setItem(j, 2, new QTableWidgetItem(result+"%"));
       }

    }

}


void Widget::monthlyBrandTotalSalesFind(QString month)
{

    QString domesticTotalSales = monthlyTotalSalesFind(month,1); //12월 국내 전체 차량 판매 대수
    QString overseasTotalSales = monthlyTotalSalesFind(month,2); //12월 해외 전체 차량 판매 대수
    ui->domesticTable->horizontalHeaderItem(0)->setText("국산차 (2023." + month +")");
    ui->overseasTable->horizontalHeaderItem(0)->setText("수입차 (2023." + month +")");
    ui->domesticTable->horizontalHeaderItem(2)->setText(domesticTotalSales+"대");
    ui->overseasTable->horizontalHeaderItem(2)->setText(overseasTotalSales+"대");

    double DTS = domesticTotalSales.toDouble();
    double OTS = overseasTotalSales.toDouble();

    QSqlQuery query1;
    QSqlQuery query2;
    QString basicSet = "2023_";
    basicSet += month;

    query1.prepare("SELECT BRAND, SUM(\"" +basicSet+ "\")\n\
                  FROM CAR_TB\n\
                  GROUP BY BRAND\n\
                  HAVING BRAND < 7\n\
                  ORDER BY SUM(\"" +basicSet+ "\") DESC");

    if( !query1.exec() )
        qDebug() << query1.lastError();

    int i = 0;

    while(query1.next())
    {
        ui->domesticTable->insertRow(i);
        int brand = query1.value(0).toInt();
        if(brand == 1)
            ui->domesticTable->setItem(i,0, new QTableWidgetItem("현대"));
        else if(brand == 2)
            ui->domesticTable->setItem(i,0, new QTableWidgetItem("기아"));
        else if(brand == 3)
            ui->domesticTable->setItem(i,0, new QTableWidgetItem("제네시스"));
        else if(brand == 4)
            ui->domesticTable->setItem(i,0, new QTableWidgetItem("쉐보레"));
        else if(brand == 5)
            ui->domesticTable->setItem(i,0, new QTableWidgetItem("KG모빌리티"));
        else if(brand == 6)
            ui->domesticTable->setItem(i,0, new QTableWidgetItem("르노코리아"));

        ui->domesticTable->setItem(i, 1, new QTableWidgetItem(query1.value(1).toString()));

        QString result = QString::number((query1.value(1).toDouble()/DTS)*100);

        ui->domesticTable->setItem(i, 2, new QTableWidgetItem(result+"%"));
        i +=1;

    }


    query2.prepare("SELECT BRAND, SUM(\"" +basicSet+ "\")\n\
                           FROM CAR_TB\n\
                           GROUP BY BRAND\n\
                           HAVING BRAND > 6\n\
                       ORDER BY SUM(\"" +basicSet+ "\") ASC");

    if( !query2.exec() )
        qDebug() << query1.lastError();

    int j = 0;

    while(query2.next())
    {
        ui->overseasTable->insertRow(j);
        int brand = query2.value(0).toInt();
        if(brand == 7)
            ui->overseasTable->setItem(j,0, new QTableWidgetItem("BMW"));
        else if(brand == 8)
            ui->overseasTable->setItem(j,0, new QTableWidgetItem("벤츠"));
        else if(brand == 9)
            ui->overseasTable->setItem(j,0, new QTableWidgetItem("아우디"));
        else if(brand == 10)
            ui->overseasTable->setItem(j,0, new QTableWidgetItem("렉서스"));
        else if(brand == 11)
            ui->overseasTable->setItem(j,0, new QTableWidgetItem("포르쉐"));

        ui->overseasTable->setItem(j, 1, new QTableWidgetItem(query2.value(1).toString()));

        QString result = QString::number((query2.value(1).toDouble()/OTS)*100);

        ui->overseasTable->setItem(j, 2, new QTableWidgetItem(result+"%"));
    }

}


QString Widget::monthlySpecificBrandTotalSalesFind(QString month, QString brand)
{
    QString basicSet = "2023_";
    basicSet += month;

    QSqlQuery query1;
    query1.prepare("SELECT SUM(\"" +basicSet+ "\")\n\
                    FROM CAR_TB\n\
                    WHERE BRAND ==" + brand);

    if( !query1.exec() )
        qDebug() << query1.lastError();

    query1.first();
    QString monthlyBrandTotalSales = query1.value(0).toString(); // 특정 월 브랜드 전체 판매량
    return monthlyBrandTotalSales;

}

void Widget::monthlyModelTotalSalesFind(QString month, QString brand, QString totalSalesData)
{
    ui->specificBrandTable->clearContents();

    while(ui->specificBrandTable->rowCount() > 0)
    {
        ui->specificBrandTable->removeRow(0);
    }

    QSqlQuery query1;
    QString basicSet = "2023_";
    basicSet += month;

    double TS = totalSalesData.toDouble();


    query1.prepare("SELECT MODEL, SUM(\"" +basicSet+ "\")\n\
                           FROM CAR_TB\n\
                           GROUP BY MODEL\n\
                           HAVING BRAND ==" + brand + "\n\
                       ORDER BY SUM(\"" +basicSet+ "\") ASC");

    if( !query1.exec() )
        qDebug() << query1.lastError();
    int i = 0;

    while(query1.next())
    {

        ui->specificBrandTable->insertRow(i);

        ui->specificBrandTable->setItem(i, 0, new QTableWidgetItem(query1.value(0).toString()));

        ui->specificBrandTable->setItem(i, 1, new QTableWidgetItem(query1.value(1).toString()));

        QString result = QString::number((query1.value(1).toDouble()/TS)*100);

        ui->specificBrandTable->setItem(i, 2, new QTableWidgetItem(result+"%"));
    }

}




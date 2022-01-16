#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    cal = new calculations(this);

    //Updating the spin box as soon as the combo box text is changed
    connect(ui->nameCB_1,
    SIGNAL(currentTextChanged(QString)), this,
    SLOT(convert()));

    connect(ui->nameCB_2,
    SIGNAL(currentTextChanged(QString)), this,
    SLOT(convert()));

    //Realtime converion
    connect(ui->valueSpinBox_1,
    SIGNAL(valueChanged(double)), this,
    SLOT(convert()));

    //Realtime decimal update
    connect(ui->decimalSpinBox,
    SIGNAL(valueChanged(int)), this,
    SLOT(convert()));
}

Widget::~Widget()
{
    delete ui;
}

//Allowing spin boxes to accept negative values
void Widget::enableNegatives()
{
    ui->valueSpinBox_1->setMinimum(-9999999999);
    ui->valueSpinBox_2->setMinimum(-9999999999);
}

//Not allowing spin boxes to accept negative values
void Widget::disableNegatives()
{
    ui->valueSpinBox_1->setMinimum(0);
    ui->valueSpinBox_2->setMinimum(0);
}

//Clearing and setting the new combo box items
void Widget::clearAndSetComboBoxItems(QStringList list)
{
    ui->nameCB_1->clear();
    ui->nameCB_2->clear();
    ui->nameCB_1->addItems(list);
    ui->nameCB_2->addItems(list);
}

//Setting the inital unit to unit labels
void Widget::setInitialUnit(QString unit)
{
     ui->unitLabel_1->setText(unit);
     ui->unitLabel_2->setText(unit);
}

//Configuring the UI to suit the conversion type
void Widget::on_conversionTypeCB_currentTextChanged()
{
    if(ui->conversionTypeCB->currentText() == " Length")
    {
        QStringList list=(QStringList()<<"Centimeter"<<"Meter"<<"Kilometer");
        clearAndSetComboBoxItems(list);
        setInitialUnit("cm");
        disableNegatives();
    }

    if(ui->conversionTypeCB->currentText() == " Temperature")
    {
        QStringList list=(QStringList()<<"Celsius"<<"Kelvin"<<"Fahrenheit");
        clearAndSetComboBoxItems(list);
        setInitialUnit("°C");
        enableNegatives();
    }

    if(ui->conversionTypeCB->currentText() == " Mass")
    {
        QStringList list=(QStringList()<<"Milligram"<<"Gram"<<"Kilogram");
        clearAndSetComboBoxItems(list);
        setInitialUnit("mg");
        disableNegatives();
    }

    if(ui->conversionTypeCB->currentText() == " Time")
    {
        QStringList list=(QStringList()<<"Second"<<"Minute"<<"Hour");
        clearAndSetComboBoxItems(list);
        setInitialUnit("s");
        disableNegatives();
    }

    if(ui->conversionTypeCB->currentText() == " Plane Angle")
    {
        QStringList list=(QStringList()<<"Degree"<<"Radian"<<"Gradian");
        clearAndSetComboBoxItems(list);
        setInitialUnit("°");
        disableNegatives();
    }
}

//Setting the first unit label according
//to the current unit name of the
//first unit combo box
void Widget::on_nameCB_1_currentTextChanged()
{
    if(ui->conversionTypeCB->currentText() == " Length")
    {
        for (int i = 0; i < 3 ; i++ ) {
            if (cal->lengthUnits[0][i] == ui->nameCB_1->currentText())
            {
                ui->unitLabel_1->setText(cal->lengthUnits[1][i]);
            }
        }
    }

    if(ui->conversionTypeCB->currentText() == " Temperature")
    {
        for (int i = 0; i < 3 ; i++ ) {
            if (cal->temperatureUnits[0][i] == ui->nameCB_1->currentText())
            {
                ui->unitLabel_1->setText(cal->temperatureUnits[1][i]);
            }
        }
    }

    if(ui->conversionTypeCB->currentText() == " Mass")
    {
        for (int i = 0; i < 3 ; i++ ) {
            if (cal->massUnits[0][i] == ui->nameCB_1->currentText())
            {
                ui->unitLabel_1->setText(cal->massUnits[1][i]);
            }
        }
    }

    if(ui->conversionTypeCB->currentText() == " Time")
    {
        for (int i = 0; i < 3 ; i++ ) {
            if (cal->timeUnits[0][i] == ui->nameCB_1->currentText())
            {
                ui->unitLabel_1->setText(cal->timeUnits[1][i]);
            }
        }
    }

    if(ui->conversionTypeCB->currentText() == " Plane Angle")
    {
        for (int i = 0; i < 3 ; i++ ) {
            if (cal->angleUnits[0][i] == ui->nameCB_1->currentText())
            {
                ui->unitLabel_1->setText(cal->angleUnits[1][i]);
            }
        }
    }
}

//Setting the second unit label according
//to the current unit name of the
//second unit combo box
void Widget::on_nameCB_2_currentTextChanged()
{
    if(ui->conversionTypeCB->currentText() == " Length")
    {
        for (int i = 0; i < 3 ; i++ ) {
            if (cal->lengthUnits[0][i] == ui->nameCB_2->currentText())
            {
                ui->unitLabel_2->setText(cal->lengthUnits[1][i]);
            }
        }
    }

    if(ui->conversionTypeCB->currentText() == " Temperature")
    {
        for (int i = 0; i < 3 ; i++ ) {
            if (cal->temperatureUnits[0][i] == ui->nameCB_2->currentText())
            {
                ui->unitLabel_2->setText(cal->temperatureUnits[1][i]);
            }
        }
    }

    if(ui->conversionTypeCB->currentText() == " Mass")
    {
        for (int i = 0; i < 3 ; i++ ) {
            if (cal->massUnits[0][i] == ui->nameCB_2->currentText())
            {
                ui->unitLabel_2->setText(cal->massUnits[1][i]);
            }
        }
    }

    if(ui->conversionTypeCB->currentText() == " Time")
    {
        for (int i = 0; i < 3 ; i++ ) {
            if (cal->timeUnits[0][i] == ui->nameCB_2->currentText())
            {
                ui->unitLabel_2->setText(cal->timeUnits[1][i]);
            }
        }
    }

    if(ui->conversionTypeCB->currentText() == " Plane Angle")
    {
        for (int i = 0; i < 3 ; i++ ) {
            if (cal->angleUnits[0][i] == ui->nameCB_2->currentText())
            {
                ui->unitLabel_2->setText(cal->angleUnits[1][i]);
            }
        }
    }
}

//Setting the answer and formula
void Widget::setAnswerAndFormula(double answer, QString formula)
{
    ui->valueSpinBox_2->setValue(answer);
    ui->formulaLabel_2->setText(formula);
}

//Aloowing user to set the number of decimal points
void Widget::setDecimals()
{
    ui->valueSpinBox_1->setDecimals(ui->decimalSpinBox->value());
    ui->valueSpinBox_2->setDecimals(ui->decimalSpinBox->value());
}

//Conversions
void Widget::convert()
{
    setDecimals();

    if(ui->nameCB_2->currentText()==ui->nameCB_1->currentText())
    {
        answer = ui->valueSpinBox_1->value();
        setAnswerAndFormula(answer, "");
    }


    else if(ui->nameCB_2->currentText()== "Centimeter")
    {
        if(ui->nameCB_1->currentText()=="Meter")
        {
            answer = cal->metersToCentimeters(ui->valueSpinBox_1->value());
            setAnswerAndFormula(answer, "multiply by 100");
        }

        if(ui->nameCB_1->currentText()=="Kilometer")
        {
            answer = cal->kilometersToCentimeters(ui->valueSpinBox_1->value());
            setAnswerAndFormula(answer, "multiply by 100000");
        }
    }

    else if(ui->nameCB_2->currentText()== "Meter")
    {
        if(ui->nameCB_1->currentText()=="Centimeter")
        {
            answer = cal->centimetersToMeters(ui->valueSpinBox_1->value());
            setAnswerAndFormula(answer, "divide by 100");
        }

        if(ui->nameCB_1->currentText()=="Kilometer")
        {
            answer = cal->kilometersToMeters(ui->valueSpinBox_1->value());
            setAnswerAndFormula(answer, "multiply by 1000");
        }
    }

    else if(ui->nameCB_2->currentText()== "Kilometer")
    {
        if(ui->nameCB_1->currentText()=="Centimeter")
        {
            answer = cal->centimetersToKilometers(ui->valueSpinBox_1->value());
            setAnswerAndFormula(answer, "divide by 100000");
        }

        if(ui->nameCB_1->currentText()=="Meter")
        {
            answer = cal->metersToKilometers(ui->valueSpinBox_1->value());
            setAnswerAndFormula(answer, "divide by 1000");
        }
    }


    else if(ui->nameCB_2->currentText()== "Celsius")
    {
        if(ui->nameCB_1->currentText()=="Kelvin")
        {
            answer = cal->kelvinToCelsius(ui->valueSpinBox_1->value());
            setAnswerAndFormula(answer, "K - 273.15");
        }

        if(ui->nameCB_1->currentText()=="Fahrenheit")
        {
            answer = cal->fahrenheitToCelsius(ui->valueSpinBox_1->value());
            setAnswerAndFormula(answer, "(°F - 32) * 5/9");
        }
    }

    else if(ui->nameCB_2->currentText()== "Kelvin")
    {
        if(ui->nameCB_1->currentText()=="Celsius")
        {
            answer = cal->celsiusToKelvin(ui->valueSpinBox_1->value());
            setAnswerAndFormula(answer, "°C + 273.15");
        }

        if(ui->nameCB_1->currentText()=="Fahrenheit")
        {
            answer = cal->fahrenheitToKelvin(ui->valueSpinBox_1->value());
            setAnswerAndFormula(answer, "(°F - 32) * 5/9 + 273.15");
        }
    }

    else if(ui->nameCB_2->currentText()== "Fahrenheit")
    {
        if(ui->nameCB_1->currentText()=="Celsius")
        {
            answer = cal->celsiusToFahrenheit(ui->valueSpinBox_1->value());
            setAnswerAndFormula(answer, "(°C * 9/5) + 32");
        }

        if(ui->nameCB_1->currentText()=="Kelvin")
        {
            answer = cal->kelvinToFahrenheit(ui->valueSpinBox_1->value());
            setAnswerAndFormula(answer, "(K - 273.15) * 9/5 + 32");
        }
    }


    else if(ui->nameCB_2->currentText()== "Milligram")
    {
        if(ui->nameCB_1->currentText()=="Gram")
        {
            answer = cal->gramsToMilligrams(ui->valueSpinBox_1->value());
            setAnswerAndFormula(answer, "multiply by 1000");
        }

        if(ui->nameCB_1->currentText()=="Kilogram")
        {
            answer = cal->kilogramsToMilligrams(ui->valueSpinBox_1->value());
            setAnswerAndFormula(answer, "multiply by 1000000");
        }
    }

    else if(ui->nameCB_2->currentText()== "Gram")
    {
        if(ui->nameCB_1->currentText()=="Milligram")
        {
            answer = cal->milligramsToGrams(ui->valueSpinBox_1->value());
            setAnswerAndFormula(answer, "divide by 1000");
        }

        if(ui->nameCB_1->currentText()=="Kilogram")
        {
            answer = cal->kilogramsToGrams(ui->valueSpinBox_1->value());
            setAnswerAndFormula(answer, "multiply by 1000");
        }
    }

    else if(ui->nameCB_2->currentText()== "Kilogram")
    {
        if(ui->nameCB_1->currentText()=="Milligram")
        {
            answer = cal->milligramsToKilograms(ui->valueSpinBox_1->value());
            setAnswerAndFormula(answer, "divide by 1000000");
        }

        if(ui->nameCB_1->currentText()=="Gram")
        {
            answer = cal->gramsToKilograms(ui->valueSpinBox_1->value());
            setAnswerAndFormula(answer, "divide by 1000");
        }
    }

    else if(ui->nameCB_2->currentText()== "Second")
    {
        if(ui->nameCB_1->currentText()=="Minute")
        {
            answer = cal->minutesToSeconds(ui->valueSpinBox_1->value());
            setAnswerAndFormula(answer, "multiply by 60");
        }

        if(ui->nameCB_1->currentText()=="Hour")
        {
            answer = cal->hoursToSeconds(ui->valueSpinBox_1->value());
            setAnswerAndFormula(answer, "multiply by 3600");
        }
    }

    else if(ui->nameCB_2->currentText()== "Minute")
    {
        if(ui->nameCB_1->currentText()=="Second")
        {
            answer = cal->secondsToMinutes(ui->valueSpinBox_1->value());
            setAnswerAndFormula(answer, "divide by 60");
        }

        if(ui->nameCB_1->currentText()=="Hour")
        {
            answer = cal->hoursToMinutes(ui->valueSpinBox_1->value());
            setAnswerAndFormula(answer, "multiply by 60");
        }
    }

    else if(ui->nameCB_2->currentText()== "Hour")
    {
        if(ui->nameCB_1->currentText()=="Second")
        {
            answer = cal->secondsToHours(ui->valueSpinBox_1->value());
            setAnswerAndFormula(answer, "divide by 3600");
        }

        if(ui->nameCB_1->currentText()=="Minute")
        {
            answer = cal->minutesToHours(ui->valueSpinBox_1->value());
            setAnswerAndFormula(answer, "divide by 60");
        }
    }

    else if(ui->nameCB_2->currentText()== "Degree")
    {
        if(ui->nameCB_1->currentText()=="Radian")
        {
            answer = cal->radiansToDegrees(ui->valueSpinBox_1->value());
            setAnswerAndFormula(answer, " rad * 180 / π");
        }

        if(ui->nameCB_1->currentText()=="Gradian")
        {
            answer = cal->gradiansToDegrees(ui->valueSpinBox_1->value());
            setAnswerAndFormula(answer, "grad * 180 / 200");
        }
    }

    else if(ui->nameCB_2->currentText()== "Radian")
    {
        if(ui->nameCB_1->currentText()=="Degree")
        {
            answer = cal->degreesToRadians(ui->valueSpinBox_1->value());
            setAnswerAndFormula(answer, "°(Degree) * π / 180");
        }

        if(ui->nameCB_1->currentText()=="Gradian")
        {
            answer = cal->gradiansToRadians(ui->valueSpinBox_1->value());
            setAnswerAndFormula(answer, "grad * π / 200");
        }
    }

    else if(ui->nameCB_2->currentText()== "Gradian")
    {
        if(ui->nameCB_1->currentText()=="Degree")
        {
            answer = cal->degreesToGradians(ui->valueSpinBox_1->value());
            setAnswerAndFormula(answer, "°(Degree) * 200 / 180");
        }

        if(ui->nameCB_1->currentText()=="Radian")
        {
            answer = cal->radiansToGradians(ui->valueSpinBox_1->value());
            setAnswerAndFormula(answer, "rad * 200 / π");
        }
    }
}



// Dark Mode / Light Mode
void Widget::on_pushButton_toggled(bool checked)
{
    if(checked)
    {
        ui->widget->setStyleSheet("background-color:rgb(46, 47, 48);");
        ui->conversionTypeCB->setStyleSheet("color:white;border-style:solid;border-width:1;border-color:rgb(186, 186, 186)");
        ui->valueSpinBox_1->setStyleSheet("color:white;border-style:solid;border-width:1;border-color:rgb(186, 186, 186)");
        ui->nameCB_1->setStyleSheet("color:white;border-style:solid;border-width:1;border-color:rgb(186, 186, 186)");
        ui->unitLabel_1->setStyleSheet("color:white;");
        ui->valueSpinBox_2->setStyleSheet("color:white;border-style:solid;border-width:1;border-color:rgb(186, 186, 186)");
        ui->nameCB_2->setStyleSheet("color:white;border-style:solid;border-width:1;border-color:rgb(186, 186, 186)");
        ui->unitLabel_2->setStyleSheet("color:white;");
        ui->formulaLabel_2->setStyleSheet("color:white;");
        ui->decimalSpinBox->setStyleSheet("color:white;border-style:solid;border-width:1;border-color:rgb(186, 186, 186)");
        ui->decimalLabel->setStyleSheet("color:white;");
        ui->pushButton->setText("Light Mode");
        ui->pushButton->setStyleSheet("color:white;");
        ui->pushButton->setToolTip("");
    }
    else
    {
        ui->widget->setStyleSheet("background-color:white;");
        ui->conversionTypeCB->setStyleSheet("color:black;border-style:solid;border-width:1;border-color:rgb(186, 186, 186)");
        ui->valueSpinBox_1->setStyleSheet("color:black;border-style:solid;border-width:1;border-color:rgb(186, 186, 186)");
        ui->nameCB_1->setStyleSheet("color:black;border-style:solid;border-width:1;border-color:rgb(186, 186, 186)");
        ui->unitLabel_1->setStyleSheet("color:black;");
        ui->valueSpinBox_2->setStyleSheet("color:black;border-style:solid;border-width:1;border-color:rgb(186, 186, 186)");
        ui->nameCB_2->setStyleSheet("color:black;border-style:solid;border-width:1;border-color:rgb(186, 186, 186)");
        ui->unitLabel_2->setStyleSheet("color:black;");
        ui->formulaLabel_2->setStyleSheet("color:black;");
        ui->decimalSpinBox->setStyleSheet("color:black;border-style:solid;border-width:1;border-color:rgb(186, 186, 186)");
        ui->decimalLabel->setStyleSheet("color:black;");
        ui->pushButton->setText("Dark Mode");
        ui->pushButton->setStyleSheet("color:black;");
        ui->pushButton->setToolTip("Click to Activate Dark Mode");
    }
}


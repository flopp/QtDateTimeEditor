/*******************************************************************************
 * Copyright (c) 2015 Florian Pigorsch <mail@florian-pigorsch.de>               *
 *                                                                              *
 * Permission is hereby granted, free of charge, to any person obtaining a copy *
 * of this software and associated documentation files (the "Software"), to deal*
 * in the Software without restriction, including without limitation the rights *
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell    *
 * copies of the Software, and to permit persons to whom the Software is        *
 * furnished to do so, subject to the following conditions:                     *
 *                                                                              *
 * The above copyright notice and this permission notice shall be included in   *
 * all copies or substantial portions of the Software.                          *
 *                                                                              *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR   *
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,     *
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  *
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER       *
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,*
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN    *
 * THE SOFTWARE.                                                                *
 *******************************************************************************/

#include "demo.h"
#include "ui_demo.h"

DemoWidget::DemoWidget(QWidget* parent) :
  QWidget(parent),
  m_ui(new Ui::DemoWidget)
{
  m_ui->setupUi(this);
  m_ui->setDateTimeEdit->setDateTime(QDateTime::currentDateTimeUtc());
  connect(m_ui->dateTimeEditor, SIGNAL(dateTimeChanged(const QDateTime&)), this, SLOT(slotDateTimeChanged(const QDateTime&)));
  connect(m_ui->setDateTimeButton, SIGNAL(clicked()), this, SLOT(slotSetDateTime()));
  connect(m_ui->fontSizeEdit, SIGNAL(valueChanged(int)), this, SLOT(slotSetFontSize(int)));
}


DemoWidget::~DemoWidget()
{
  delete m_ui;
}


void DemoWidget::slotDateTimeChanged(const QDateTime& t)
{
  if (t.isValid())
  {
    m_ui->currentDateTimeLabel->setText(t.toString());
  }
  else
  {
    m_ui->currentDateTimeLabel->setText("invalid");
  }
}


void DemoWidget::slotSetDateTime()
{
  m_ui->dateTimeEditor->setDateTime(m_ui->setDateTimeEdit->dateTime());
}


void DemoWidget::slotSetFontSize(int size)
{
  setStyleSheet(QString("DateTimeEditor { font-size: %1px; } QDateTimeEdit { font-size: %1px; }").arg(size));
}

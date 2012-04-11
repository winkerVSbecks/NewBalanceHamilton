#ifndef CUSTOMWIDGET_FORM_WIDGET_TRY_HPP
#define CUSTOMWIDGET_FORM_WIDGET_TRY_HPP

#include <MultiWidgets/Widget.hpp>
#include <MultiWidgets/TextEdit.hpp>
#include <MultiWidgets/ImageWidget.hpp>
#include <MultiWidgets/TimerDial.hpp>

namespace CustomWidget
{
  class FormWidgetTry : public MultiWidgets::Widget
  {
  public:
    FormWidgetTry(MultiWidgets::Widget * parent = 0);
    virtual ~FormWidgetTry();
    void setupTheFormWidgetTry(float x, float y);

  private:
    virtual void input(MultiWidgets::GrabManager & gm, float dt);
    virtual void processMessage(const char * id, Radiant::BinaryData & data);

    MultiWidgets::ImageWidget * bg;

    MultiWidgets::TextEdit * cust_name;
    MultiWidgets::TextEdit * cust_add;
    MultiWidgets::TextEdit * cust_city;
    MultiWidgets::TextEdit * cust_prov;
    MultiWidgets::TextEdit * cust_em;
    MultiWidgets::TextEdit * cust_ph;
    MultiWidgets::TextEdit * skill_test;

    MultiWidgets::ImageWidget * t860;
    MultiWidgets::ImageWidget * t890;
    MultiWidgets::ImageWidget * t890_2;
    MultiWidgets::ImageWidget * t940;
    MultiWidgets::ImageWidget * t1080;
    MultiWidgets::ImageWidget * t1400;
    MultiWidgets::ImageWidget * troad;
    MultiWidgets::ImageWidget * ttrail;
    MultiWidgets::ImageWidget * tother;

    MultiWidgets::ImageWidget * selected;

    MultiWidgets::ImageWidget * accept;

    MultiWidgets::TimerDial * timer;

    MultiWidgets::ImageWidget * close;

    std::string shoeType;
    bool m_nothingEmpty;
    bool m_accepted;
  };
}

#endif

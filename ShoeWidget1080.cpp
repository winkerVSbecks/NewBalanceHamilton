#include "ShoeWidget1080.hpp"
#include "CustomSliderWidget.hpp"
#include "Global.hpp"
#include "ImageWithClose.hpp"

#include <MultiWidgets/ListWidget.hpp>
#include <MultiWidgets/ImageWidget.hpp>
#include <MultiWidgets/Plugins.hpp>
#include <MultiWidgets/TextBox.hpp>
#include <MultiWidgets/ButtonWidget.hpp>

#include <MultiWidgets/StayInsideParentOperator.hpp>
#include <MultiWidgets/AfterIdleOperator.hpp>
#include <MultiWidgets/WidgetRemoveOperator.hpp>
#include <MultiWidgets/TimerDial.hpp>


#include <string.h>
#include <Radiant/Directory.hpp>

#include <MultiTouch/MultiTouch.hpp>

namespace CustomWidget
{
  ShoeWidget1080::ShoeWidget1080(MultiWidgets::Widget * parent)
      : Widget(parent)
  {
      slideOn = false;
  }

  ShoeWidget1080::~ShoeWidget1080()
  {}

  void ShoeWidget1080::setupTheShoeWidget1080(float x, float y, float rot)
  {
      bg = new MultiWidgets::ImageWidget(this);
      bg->load("shoeWidget/shoeWidget1080.png");
      bg->setSize(1630,1762);
      //bg->setSize(815,881);
      bg->setLocation(x-500, y-500);
      bg->setInputTransparent(true);
      bg->setDepth(0);
      bg->raiseFlag(MultiWidgets::Widget::LOCK_DEPTH);
      bg->addOperator(new MultiWidgets::StayInsideParentOperator());
      bg->setInputFlags(MultiWidgets::Widget::INPUT_DEFAULT | MultiWidgets::Widget::INPUT_PASS_TO_CHILDREN);
      bg->setScale(0.5);
      bg->setRotationAboutCenter(rot);
      bg->setName("bg");
      bg->setMomentum(momentumForAll);



      ti = new MultiWidgets::TimerDial(bg, 60, 20);
      ti->eventAddListener("timeout", "die", this);
      ti->hide();



      win = new MultiWidgets::ButtonWidget(bg);
      win->load("shoeWidget/win.png");
      win->setActiveImage("shoeWidget/winPress.png");
      win->setLocation(480,1285);
      win->setSize(352,355);
      win->setInputFlags(MultiWidgets::Widget::INPUT_USE_TAPS);
      win->eventAddListener("interactionbegin", "win", this);



      killer = new MultiWidgets::ImageWidget (bg);
      killer->load("shoeWidget/close.png");
      killer->setLocation(890,1540);
      killer->setSize(449,125);
      killer->setInputFlags(MultiWidgets::Widget::INPUT_USE_TAPS);
      killer->eventAddListener("interactionbegin", "die", this);


      CustomWidget::CustomSliderWidget * sl = new CustomWidget::CustomSliderWidget(bg);
      // Initial location
      sl->setLocation(0,0);
      sl->makeSlider(false, "1080");
      sl->hide();
  }

  void ShoeWidget1080::input(MultiWidgets::GrabManager & gm, float dt)
 {
   Widget::input(gm, dt);
   MultiTouch::Sample m_sample = gm.sample();

   if(bg->grabFingerCount())
   {
       ti->resetIdleTime();
   }
 }



  void ShoeWidget1080::processMessage(const char * id, Radiant::BinaryData & data)
      {
        if(strcmp(id, "die") == 0) {
            raiseFlag(DELETE_ME);

             noActiveWidgets--;

            for (ChildIterator it = childBegin(); it != childEnd(); ++it) {
              it->raiseFlag(DELETE_ME);
            }
        }

        if(strcmp(id, "win") == 0) {

            if(!slideOn)
            {
                slideOn = true;
                win->load("shoeWidget/back.png");
                killer->hide();
            }
            else
            {
                slideOn = false;
                win->load("shoeWidget/win.png");
                bg->load("shoeWidget/shoeWidget1080.png");
                killer->show();
            }
        }
      }

  void ShoeWidget1080::update(float dt)
  {
      Widget::update(dt);

      timeOfSlide += 1;

      if(slideOn)
      {
          if(timeOfSlide > 0)
          {
              bg->load("shoeWidget/eric.png");
          }
          if(timeOfSlide > 500)
          {
              bg->load("shoeWidget/reid.png");
          }
          if(timeOfSlide > 1000)
          {
              bg->load("shoeWidget/both.png");
          }
          if(timeOfSlide > 1500)
          {
              timeOfSlide = 0;
          }
      }
  }

  CUSTOM_WIDGET(ShoeWidget1080, "queue.shoewidget1080", "winkerVSbecks",
                "Shoe Widget 1080", "NewBalance");
}

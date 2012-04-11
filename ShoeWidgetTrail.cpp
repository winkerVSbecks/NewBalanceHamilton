#include "ShoeWidgetTrail.hpp"
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
  ShoeWidgetTrail::ShoeWidgetTrail(MultiWidgets::Widget * parent)
      : Widget(parent)
  {
      slideOn = false;
  }

  ShoeWidgetTrail::~ShoeWidgetTrail()
  {}

  void ShoeWidgetTrail::setupTheShoeWidgetTrail(float x, float y, float rot)
  {
      bg = new MultiWidgets::ImageWidget(this);
      bg->load("shoeWidget/shoeWidgetTrail.png");
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



      ti = new MultiWidgets::TimerDial(bg, timerLength, 20);
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
      sl->makeSlider(false, "minimus-Trail");
      sl->hide();
  }

  void ShoeWidgetTrail::input(MultiWidgets::GrabManager & gm, float dt)
 {
   Widget::input(gm, dt);
   MultiTouch::Sample m_sample = gm.sample();

   if(bg->grabFingerCount())
   {
       ti->resetIdleTime();
   }
 }



  void ShoeWidgetTrail::processMessage(const char * id, Radiant::BinaryData & data)
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
                bg->load("shoeWidget/shoeWidgetTrail.png");
                win->load("shoeWidget/win.png");
                killer->show();
            }
        }
      }

  void ShoeWidgetTrail::update(float dt)
  {
      Widget::update(dt);

      timeOfSlide += 1;

      if(slideOn)
      {
          if(timeOfSlide > 0)
          {
              bg->load("shoeWidget/eric.png");
          }
          if(timeOfSlide > slide1)
          {
              bg->load("shoeWidget/reid.png");
          }
          if(timeOfSlide > slide2)
          {
              bg->load("shoeWidget/both.png");
          }
          if(timeOfSlide > slide3)
          {
              timeOfSlide = 0;
          }
      }
  }

  CUSTOM_WIDGET(ShoeWidgetTrail, "queue.shoewidgettrail", "winkerVSbecks",
                "Shoe Widget Trail", "NewBalance");
}

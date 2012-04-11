#include "ImageWithClose.hpp"
#include "Global.hpp"

#include <MultiWidgets/ImageWidget.hpp>

#include <MultiWidgets/StayInsideParentOperator.hpp>
#include <MultiWidgets/BringToTopOperator.hpp>


namespace CustomWidget
{
MultiWidgets::ImageWidget * myI;
MultiWidgets::ImageWidget * close;

  ImageWithClose::ImageWithClose(MultiWidgets::Widget * parent)
      : Widget(parent)
  {}

  ImageWithClose::~ImageWithClose()
  {}

  void ImageWithClose::setupTheImageWithClose(const char * filePath, float x, float y, float rot, float w, float h)
  {
      myI = new MultiWidgets::ImageWidget(parent());
      myI->setAutoBringToTop(true);
      myI->setDepth(99);
      myI->addOperator(new MultiWidgets::StayInsideParentOperator());
      myI->addOperator(new MultiWidgets::BringToTopOperator());

      close = new MultiWidgets::ImageWidget(myI);
      close->setAutoBringToTop(true);
      close->setDepth(100);
      close->setInputFlags(MultiWidgets::Widget::INPUT_USE_SINGLE_TAPS);
      close->load("shoeWidget/closeIM.png");
      close->setLocation(-20,-20);
      close->setSize(40,40);

      myI->setLocation(x,y);
      myI->setRotation(rot);
      myI->load(filePath);
      myI->setHeight(h);
      myI->resizeToFit(Nimble::Vector2(w,h));
      myI->setMomentum(momentumForAll);

      close->eventAddListener("interactionbegin", "close", myI);
  }

  void ImageWithClose::processMessage(const char * id, Radiant::BinaryData & data)
  {
        if(strcmp(id, "close") == 0)
        {
            raiseFlag(DELETE_ME);
            myI->raiseFlag(DELETE_ME);
            close->raiseFlag(DELETE_ME);
        }
   }
}

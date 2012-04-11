#ifndef CUSTOMWIDGET_IMAGE_WITH_CLOSE_HPP
#define CUSTOMWIDGET_IMAGE_WITH_CLOSE_HPP


#include <MultiWidgets/Widget.hpp>

namespace CustomWidget
{
  class ImageWithClose : public MultiWidgets::Widget
  {
  public:
    ImageWithClose(MultiWidgets::Widget * parent = 0);
    virtual ~ImageWithClose();
    void setupTheImageWithClose(const char * filePath, float x, float y, float rot, float w, float h);

  private:
    virtual void processMessage(const char * id, Radiant::BinaryData & data);
  };
}

#endif

#ifndef _GUIAPP_H_
#define _GUIAPP_H_

#include "wx/wx.h"

/** \brief brief
 *
 * detailed
 */
class GUIApp : public wxApp
{
public:
    GUIApp();
    virtual ~GUIApp();

private:
    virtual bool OnInit();
};

#endif /* _GUIAPP_H_ */

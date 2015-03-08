// PX2EditRenderView_PreView.hpp

#ifndef PX2EDITUIRENDERVIEW_PREVIEW_HPP
#define PX2EDITUIRENDERVIEW_PREVIEW_HPP

#include "PX2EditPre.hpp"
#include "PX2EditRenderView.hpp"
#include "PX2Polysegment.hpp"
#include "PX2UIObjectCtrl.hpp"
#include "PX2UIFrame.hpp"
#include "PX2UIPicBox.hpp"
#include "PX2UIText.hpp"
#include "PX2UIView.hpp"

namespace PX2
{

	class EditRenderView_PreView : public EditRenderView
	{
	public:
		EditRenderView_PreView();
		virtual ~EditRenderView_PreView();

		virtual bool InitlizeRendererStep(const std::string &name);

		virtual void Tick(double elapsedTime);

		void SetObject(PX2::Object *obj);

	protected:
		UIViewPtr mUIView;
		UIFramePtr mPicFrame;
		UIPicBoxPtr mUIPicBox;
		UITextPtr mUIText;

		NodePtr mModelNode;
		MovablePtr mModel;

	public:
		virtual void OnSize(const Sizef& size);
		virtual void OnLeftDown(const APoint &pos);
		virtual void OnLeftUp(const APoint &pos);
		virtual void OnMiddleDown(const APoint &pos);
		virtual void OnMiddleUp(const APoint &pos);
		virtual void OnMouseWheel(float delta);
		virtual void OnRightDown(const APoint &pos);
		virtual void OnRightUp(const APoint &pos);
		virtual void OnMotion(const APoint &pos);

		// Event
	public:
		virtual void DoExecute(Event *event);
	};

	typedef Pointer0<EditRenderView_PreView> EditRenderView_PreViewPtr;

}

#endif
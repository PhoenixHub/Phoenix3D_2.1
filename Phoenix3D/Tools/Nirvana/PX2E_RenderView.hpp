// PX2E_RenderView.hpp

#ifndef PX2E_RENDERVIEW_HPP
#define PX2E_RENDERVIEW_HPP

#include "PX2EditorPre.hpp"
#include "PX2EditRenderView.hpp"
#include "PX2EventHandler.hpp"
#include "PX2EditRenderView.hpp"

namespace PX2Editor
{

	class RenderView : public wxWindow, public PX2::EventHandler
	{
		DECLARE_DYNAMIC_CLASS(RenderView)

	public:
		RenderView(wxWindow *parent);
		virtual ~RenderView();

		void OnTimer(wxTimerEvent& event);
		void OnSize(wxSizeEvent& e);
		void OnPaint(wxPaintEvent& e);
		void OnEraseBackground(wxEraseEvent& rEvent);

		virtual void DoExecute(PX2::Event *event);

	protected:
		DECLARE_EVENT_TABLE()

		RenderView();
		void _Update(double detalSeconds);

	protected:
		bool mIsInited;

		wxTimer mCtrlTimer;
		PX2::EditRenderViewPtr mEditRenderView;
		float mCameraMoveSpeed;
		float mCurCameraMoveSpeed_W;
		float mCurCameraMoveSpeed_S;
		float mCurCameraMoveSpeed_A;
		float mCurCameraMoveSpeed_D;
	};

}

#endif
// PX2EditRenderView.hpp

#ifndef PX2EDITRENDERVIEW_HPP
#define PX2EDITRENDERVIEW_HPP

#include "PX2EditMapPre.hpp"
#include "PX2Node.hpp"
#include "PX2Renderable.hpp"
#include "PX2RenderStep.hpp"

namespace PX2
{

	class EditRenderView
	{
	public:
		EditRenderView();
		~EditRenderView();

		enum ViewType
		{
			VT_TOP,
			VT_FRONT,
			VT_LEFT,
			VT_PERSPECTIVE,
			VT_MAX_TYPE
		};
		void SetViewType(ViewType viewType);
		ViewType GetViewType();

		enum ViewDetail
		{
			VD_WIREFRAME,
			VD_SOLID,
			VD_TEXTURED
		};
		void SetViewDetail(ViewDetail viewDetail);
		ViewDetail GetViewDetail() const;

		RenderStep *GetRenderStep();

		void OnMoveHV(bool isAltDown, float h, float v);

	protected:
		void _CreateGridGeometry();
		void _MoveCamera(float horz, float vert);
		void _ZoomCamera(float zoom);

		ViewType mViewType;
		ViewDetail mViewDetail;

		PX2::RenderablePtr mGrid;
		PX2::NodePtr mGridNode;

		RenderStepPtr mRenderStep;
	};

	typedef Pointer0<EditRenderView> EditRenderViewPtr;

}

#endif
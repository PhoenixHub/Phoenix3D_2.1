// PX2PWinImpl.hpp

#ifndef PX2PWINIMPL_HPP
#define PX2PWINIMPL_HPP

#include "PX2PlatformUIPre.hpp"
#include "PX2SmartPointer.hpp"
#include "PX2Vector2.hpp"
#include "PX2Size.hpp"

namespace PX2
{
	
	class PWinImpl
	{
	public:
		PWinImpl();
		virtual ~PWinImpl();

		virtual void Create(PWinImpl *PWinImpl, const std::string &tilte,
			const Vector2f &pos, const Sizef &size) = 0;
		virtual void *GetWinHandle() = 0;

		virtual void Show(bool show, bool takeFocus) = 0;
		virtual void ShowModal() = 0;

		virtual void CenterWindow() = 0;

		virtual void Minimize() = 0;
		virtual void Maximize() = 0;
		virtual void Restore() = 0;
	};
	typedef Pointer0<PWinImpl> PWinImplPtr;

}

#endif
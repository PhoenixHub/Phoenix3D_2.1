// PX2CullProperty.hpp

#ifndef PX2CULLPROPERTY_HPP
#define PX2CULLPROPERTY_HPP

#include "PX2GraphicsPre.hpp"
#include "PX2Object.hpp"

namespace PX2
{

	class PX2_GRAPHICS_ITEM CullProperty : public Object
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_NAMES;
		PX2_DECLARE_PROPERTY;
		PX2_DECLARE_STREAM(CullProperty);

	public:
		CullProperty ();
		virtual ~CullProperty ();

		bool Enabled;   //< default: true
		bool CCWOrder;  //< default: true
	};

	PX2_REGISTER_STREAM(CullProperty);
	typedef Pointer0<CullProperty> CullPropertyPtr;

}

#endif

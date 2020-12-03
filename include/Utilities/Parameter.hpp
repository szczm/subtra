// SUBTRA Parameter class header
// 2020 Matthias Scherba @szczm_

#pragma once

#include "imgui.h"


namespace SUBTRA
{
	// Parameter exposes a value of the specified type to the user through IMGUI automagically.
	//
	// Unsupported types are added by implementing their respective UpdateIMGUI method in Parameter.cpp.
	template <typename ValueType>
	class Parameter
	{

	public:

		Parameter (const char* Label, ValueType InitialValue = {}, ValueType Step = {}, ValueType Min = {}, ValueType Max = {})
		: Label(Label),
			Value(InitialValue),
			Step(Step),
			Min(Min),
			Max(Max)
		{

		}

		// Easy value assignment semantic
		inline Parameter& operator= (ValueType Value)
		{
			this->Value = Value;
			return *this;
		}

		// Returns true if Value was changed through GUI interaction
		bool UpdateIMGUI ();


	private:
		const char* Label = nullptr;

	public:
		ValueType Value {};

	private:
		ValueType Step {};
		ValueType Min {};
		ValueType Max {};
	};
}
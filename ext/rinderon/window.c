#include "rinderon.h"

VALUE hello(VALUE self)
{
	return RB_STR("hello");
}

void Init_rinderon_window()
{
	RB_CLASS w = CLS_RINDERON_WINDOW;
	RB_DECLARE_METHOD_0(w, "hello", hello);
}

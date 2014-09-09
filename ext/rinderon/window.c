#include "rubyext.h"

#define RINDERON_MODULE_NAME		"Rinderon"
#define RINDERON_WINDOW_CLASS_NAME	"Window"
#define MOD_RINDERON				rb_define_module(RINDERON_MODULE_NAME)

#define DECL_RINDERON_CLASS(NAME)	rb_define_class_under(MOD_RINDERON, NAME, rb_cObject);

RB_CLASS rinderon_window_class()
{
	DECL_RINDERON_CLASS(RINDERON_WINDOW_CLASS_NAME);
}

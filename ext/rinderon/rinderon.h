#ifndef __GITHUB_MYUN2__RINDERON_H__
#define __GITHUB_MYUN2__RINDERON_H__

#include "rubyext.h"

/*  Module / Class names  */
#define RINDERON_MODULE_NAME		"Rinderon"
#define RINDERON_WINDOW_CLASS_NAME	"Window"

#define MOD_RINDERON				rb_define_module(RINDERON_MODULE_NAME)
#define DECL_RINDERON_CLASS(NAME)	rb_define_class_under(MOD_RINDERON, NAME, RB_CLASS_OBJECT)
#define CLS_RINDERON_WINDOW			DECL_RINDERON_CLASS(RINDERON_WINDOW_CLASS_NAME)

#endif//__GITHUB_MYUN2__RINDERON_H__

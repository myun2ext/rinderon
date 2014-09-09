#include "ruby.h"

VALUE wrap_hello(VALUE self)
{
  return rb_str_new2("hello");
}

void Init_rinderon()
{
  VALUE mod_rinderon = rb_define_module("Rinderon");
  rb_define_module_function(mod_rinderon, "hello", wrap_hello, 0);
}

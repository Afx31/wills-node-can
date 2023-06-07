#include "can.h"

NAN_METHOD(Hello) {
  Nan::HandleScope scope;

  v8::Local<v8::String> result = Nan::New("Reee this is from C++").ToLocalChecked();
  info.GetReturnValue().Set(result);
}

NAN_MODULE_INIT(Init) {
  Nan::Set(target,
  Nan::New("hello").ToLocalChecked(),
  Nan::GetFunction(Nan::New<v8::FunctionTemplate>(Hello)).ToLocalChecked());
}

NODE_MODULE(addon, Init)

#include "test.h"

NAN_METHOD(Hello) {
  Nan::HandleScope scope;

  v8::Local<v8::String> result = Nan::New("Reee! This is from C++!").ToLocalChecked();
  info.GetReturnValue().Set(result);
}

NAN_METHOD(HeresANumber) {
  Nan::HandleScope scope;
  
  v8::Local<v8::Int32> result = Nan::New(77);
  info.GetReturnValue().Set(result);
}

NAN_METHOD(AddTenToThisNumber) {
  Nan::HandleScope scope;

  if (info.Length() < 1 || !info[0]->IsNumber()) {
    Nan::ThrowTypeError("Invalid arguments. Expected an integer.");
    return;
  }

  int number = info[0].As<v8::Int32>()->Value();
  int result = number + 10;

  info.GetReturnValue().Set(Nan::New(result));
}

NAN_MODULE_INIT(Init) {
  Nan::Set(target, Nan::New("Hello").ToLocalChecked(),
    Nan::GetFunction(Nan::New<v8::FunctionTemplate>(Hello)).ToLocalChecked());
    
  Nan::Set(target, Nan::New("HeresANumber").ToLocalChecked(),
    Nan::GetFunction(Nan::New<v8::FunctionTemplate>(HeresANumber)).ToLocalChecked());
    
  Nan::Set(target, Nan::New("AddTenToThisNumber").ToLocalChecked(),
    Nan::GetFunction(Nan::New<v8::FunctionTemplate>(AddTenToThisNumber)).ToLocalChecked());
}

NODE_MODULE(Test, Init)
